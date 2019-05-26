#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 0x7fffffff
using namespace std;
ll n,m,kk,first[10010];
ll dis[10010][25];
struct edge{
	ll to,next,w;
}a[100010];
ll read(){
	ll re=0,flag=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') re=re*10+ch-'0',ch=getchar();
	return re*flag;
}
int qx[300010],qy[300010],head=1,tail=2,maxm=300000;
bool vis[10010][25];
void spfa(){
	int x,y,tx,ty,i;
	qx[1]=n;qy[1]=0;
	vis[n][0]=1;
	while(head!=tail){
		x=qx[head];y=qy[head];vis[x][y]=0;
//		if(x<=4000) cout<<"do "<<x<<ends<<y<<endl;
		head=(head+1)%maxm;
		for(i=first[x];~i;i=a[i].next){
			tx=a[i].to;
//			if(x<=4000) cout<<"	to "<<tx<<endl;
			if(y==kk) goto skip;
			ty=y+1;
			if(dis[tx][ty]>dis[x][y]){
				dis[tx][ty]=dis[x][y];
				if(!vis[tx][ty]){
					if(dis[tx][ty]<dis[qx[head]][qy[head]]){
						head=(head-1+maxm)%maxm;
						qx[head]=tx;qy[head]=ty;
						vis[tx][ty]=1;
					}
					else{
						qx[tail]=tx;qy[tail]=ty;
						tail=(tail+1)%maxm;
						vis[tx][ty]=1;
					}
				}
			}
			skip:
			ty=y;
			if(dis[tx][ty]>dis[x][y]+a[i].w){
				dis[tx][ty]=dis[x][y]+a[i].w;
				if(!vis[tx][ty]){
					if(dis[tx][ty]<dis[qx[head]][qy[head]]){
						head=(head-1+maxm)%maxm;
						qx[head]=tx;qy[head]=ty;
						vis[tx][ty]=1;
					}
					else{
						qx[tail]=tx;qy[tail]=ty;
						tail=(tail+1)%maxm;
						vis[tx][ty]=1;
					}
				}
			}
		}
	}
}
int main(){
//	freopen("testdata.in","r",stdin); 
	memset(first,-1,sizeof(first));
	ll i,j,t1,t2,t3;
	n=read();m=read();kk=read();
	for(i=1;i<=n;i++) 
		for(j=0;j<=kk;j++) 
			dis[i][j]=inf;
	for(i=1;i<=m;i++) {
		t1=read();t2=read();t3=read();
		a[(i<<1)-1].to=t2;a[(i<<1)-1].next=first[t1];first[t1]=(i<<1)-1;a[(i<<1)-1].w=t3;
		a[i<<1].to=t1;a[i<<1].next=first[t2];first[t2]=(i<<1);a[i<<1].w=t3;
//		cout<<"add edge "<<(i<<1)-1<<ends<<(i<<1)<<endl;
	}
	dis[n][0]=0;
	spfa();
	ll ans=inf;
	for(i=0;i<=kk;i++) ans=min(ans,dis[1][i]);
	printf("%lld",ans);
} 
