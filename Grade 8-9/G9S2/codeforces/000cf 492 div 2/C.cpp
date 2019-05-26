#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define mp make_pair
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
const int dx[5]={0,-1,0,1,0},dy[5]={0,0,-1,0,1};
int a[5][110],vis[110],tmp[5][110],stx[110],sty[110],edx[110],edy[110],prex[5][110],prey[5][110];
int r1[20010],r2[20010],r3[20010],ans=0;
int n,m;
bool bfs(int t){
//	cout<<"bfs "<<t<<'\n';
	int qx[210],qy[210],head=0,tail=1,x,y,xx,yy;
	memset(prex,0,sizeof(prex));memset(prey,0,sizeof(prey));
	tmp[stx[t]][sty[t]]=1;qx[0]=stx[t];qy[0]=sty[t];
	while(head<tail){
		x=qx[head],y=qy[head++];
//		cout<<"do "<<x<<' '<<y<<' '<<tmp[x][y]<<'\n';
		if(x==edx[t]&&y==edy[t]) return 1;
		for(int i=1;i<=4;i++){
			xx=x+dx[i];yy=y+dy[i];
			if(xx<2||xx>3||yy<1||yy>n||tmp[xx][yy]) continue;
			if((a[xx][yy]==0||a[xx][yy]==t)){
//				cout<<'	'<<x<<' '<<y<<" to "<<xx<<' '<<yy<<' '<<tmp[xx][yy]<<'\n';
				tmp[xx][yy]=1;
				qx[tail]=xx;qy[tail++]=yy;
				prex[xx][yy]=x;prey[xx][yy]=y;
			}
		}
	}
//	cout<<tmp[edx[t]][edy[t]]<<'\n';
	if(tmp[edx[t]][edy[t]]) return 1;
	else return 0;
}
vector<pair<int,int> >tt;
int main(){
	n=read(),m=read();int i,j,tot=m;
	for(i=1;i<=4;i++){
		for(j=1;j<=n;j++){
			a[i][j]=read();
			if(!a[i][j]) continue;
			if(i==1||i==4) stx[a[i][j]]=i,sty[a[i][j]]=j;
			if(i==2||i==3) edx[a[i][j]]=i,edy[a[i][j]]=j;
		}
	}
	while(tot){
		int ttot=tot;
		for(i=1;i<=m;i++){
			if(!vis[i]){
				memset(tmp,0,sizeof(tmp));
				if(bfs(i)){
					tot--;
					int tx=edx[i],ty=edy[i],ttx,tty;tt.clear();
					while(tx!=stx[i]||ty!=sty[i]){
						ttx=tx;tty=ty;
						tx=prex[ttx][tty];ty=prey[ttx][tty];
						tt.push_back(mp(tx,ty));
//						cout<<"add move "<<tx<<' '<<ty<<'\n';
					}
					for(j=0;j<tt.size();j++){
						ans++;
						r1[ans]=i;r2[ans]=tt[j].first;r3[ans]=tt[j].second;
					}
					vis[i]=1;a[edx[i]][edy[i]]=a[stx[i]][sty[i]]=0;
				}
			}
		}
		if(ttot==tot){
			puts("-1");return 0;
		}
	}
	printf("%d\n",ans);
	for(i=1;i<=ans;i++){
		printf("%d %d %d\n",r1[i],r2[i],r3[i]);
	}
}
