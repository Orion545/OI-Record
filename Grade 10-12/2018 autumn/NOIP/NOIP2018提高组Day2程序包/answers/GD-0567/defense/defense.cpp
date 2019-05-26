#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 100010
#define inf (1ll<<59)
#define LL long long
using namespace std;
struct edge{ int v,nt; } G[N<<1];
int n,m,d[N],h[N],cnt; LL f[N][2],p[N];
inline void dp(int x,int p){
	f[x][1]=::p[x]; f[x][0]=0;
	for(int v,i=h[x];i;i=G[i].nt)
		if((v=G[i].v)!=p){
			dp(v,x);
			f[x][0]+=f[v][1];
			f[x][1]+=min(f[v][1],f[v][0]);
		}
	if(d[x])
		f[x][2-d[x]]=inf;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%*s",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",p+i);
	for(int x,y,i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		G[++cnt]=(edge){y,h[x]}; h[x]=cnt;
		G[++cnt]=(edge){x,h[y]}; h[y]=cnt;
	}
	for(int x,a,y,b,i=1;i<=m;++i){
		scanf("%d%d%d%d",&x,&a,&y,&b);
		d[x]=a+1; d[y]=b+1;
		dp(1,0);
		if(min(f[1][0],f[1][1])>=inf) puts("-1");
		else printf("%lld\n",min(f[1][0],f[1][1]));
		d[x]=0; d[y]=0;
	}
}
		
