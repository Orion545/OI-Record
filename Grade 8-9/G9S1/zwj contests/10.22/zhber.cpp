#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define inf 0x7fffffff
#define ll long long
using namespace std;
const ll dx[5]={0,1,1,-1,-1},dy[5]={0,1,-1,1,-1};
ll n,m,a[160][160],b[160][160],dis[160][160],x1,x2,x3,y1,y2,y3;
bool vis[160][160];
long long ans1,ans2,ans3;
struct point{
	ll x,y;
	point(){
		x=y=0;
	}
	point(ll k1,ll k2){
		x=k1,y=k2;
	}
	inline bool operator <(const point &b) const{
		return dis[x][y]<dis[b.x][b.y];
	}
};
priority_queue<point>q;
ll spfa(ll sx,ll sy,ll tx,ll ty){
	ll i,j,k,limit,x,y,xx,yy;point tmp(sx,sy);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) dis[i][j]=inf;
	memset(vis,0,sizeof(vis));
	dis[sx][sy]=0;q.push(tmp);vis[sx][sy]=1;
	while(!q.empty()){
		tmp=q.top();q.pop();
		x=tmp.x;y=tmp.y;vis[x][y]=0;
//		cout<<"in "<<x<<ends<<y<<endl;
		if(abs(tx-x)+abs(ty-y)<=b[x][y]){
			 dis[tx][ty]=min(dis[tx][ty],dis[x][y]+a[x][y]);
		}
		else for(limit=1;limit<=min(b[x][y],max(max(n-x,x-1),max(m-y,y-1)));limit++){
			for(i=0,j=limit;i<=limit;i++,j--){
				for(k=1;k<=4;k++){
					xx=x+i*dx[k];yy=y+j*dy[k];
					if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&dis[xx][yy]>dis[x][y]+a[x][y]){
//						cout<<"	"<<x<<ends<<y<<" to "<<xx<<ends<<yy<<endl;
						dis[xx][yy]=dis[x][y]+a[x][y];
						if(!vis[xx][yy]){
							tmp.x=xx;tmp.y=yy;q.push(tmp);
							vis[xx][yy]=1;
						}
					}
				}
			}
		}
	}
//	cout<<"spfa "<<sx<<ends<<sy<<ends<<tx<<ends<<ty<<ends<<dis[tx][ty]<<endl;
//	system("pause");
	if(dis[tx][ty]!=inf) return dis[tx][ty];
	else return -2147483647;
}
int main(){
	freopen("zhber.in","r",stdin);
	freopen("zhber.out","w",stdout);
	ll i,j;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%lld",&b[i][j]);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%lld",&a[i][j]);
	scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3);
	ans1=spfa(x2,y2,x1,y1)+spfa(x3,y3,x1,y1);
	ans2=spfa(x1,y1,x2,y2)+spfa(x3,y3,x2,y2);
	ans3=spfa(x1,y1,x3,y3)+spfa(x2,y2,x3,y3);
//	cout<<ans1<<ends<<ans2<<ends<<ans3<<endl;
	if(ans1<0&&ans2<0&&ans3<0){
		printf("NO");return 0;
	}
	if(ans1<0) ans1=inf;
	if(ans2<0) ans2=inf;
	if(ans3<0) ans3=inf;
	if(ans1<ans2&&ans1<ans3){
		printf("X\n%d",ans1);
	}
	else{
		if(ans2<ans3){
			printf("Y\n%d",ans2);
		}
		else printf("Z\n%d",ans3);
	}
}
