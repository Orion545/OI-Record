#include <bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
int head[N],cnt=0,p[N],fa[N];
ll f[N][2],g[N][2],inf;
char s[3];
struct ed{
	int v,nxt;
}e[N<<1];
void add(int u,int v){
	e[++cnt]=(ed){v,head[u]},head[u]=cnt;
	e[++cnt]=(ed){u,head[v]},head[v]=cnt;	
}
void rd(int &x){
	int y=0;char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9') y=y*10+c-'0',c=getchar();
	x=y;
}
void dp(int x){
	for(int i=head[x];i;i=e[i].nxt){
		if(e[i].v==fa[x]) continue;
		fa[e[i].v]=x;
		dp(e[i].v);
		f[x][0]+=f[e[i].v][1];
		f[x][1]+=min(f[e[i].v][0],f[e[i].v][1]);
		g[x][0]=f[x][0],g[x][1]=f[x][1];
	}
}
void change(int x,int son){
	if(!x) return;
	f[x][0]=f[x][0]-g[son][1]+f[son][1];
	f[x][1]=f[x][1]-min(g[son][0],g[son][1])+min(f[son][1],f[son][0]);
	change(fa[x],x);
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,u,v,op1,op2,i;
	for(i=0;i<=N;++i) f[i][0]=f[i][1]=1ll*N*N+9;
	inf=f[0][0];
	scanf("%d %d %s",&n,&m,s);
	for(i=1;i<=n;++i) rd(p[i]),f[i][0]=0,f[i][1]=p[i];
	for(i=1;i<n;++i) rd(u),rd(v),add(u,v);
	dp(1);
	if(s[0]=='B' || n<=2000){
		while(m--){
			scanf("%d%d%d%d",&u,&op1,&v,&op2);
			if((op1==0 &&op2==0) && (fa[u]==v || fa[v]==u)){
				printf("-1\n");
				continue;
			}
			f[u][op1^1]=f[v][op2^1]=inf;
			change(fa[u],u),change(fa[v],v);
			printf("%lld\n",min(f[1][0],f[1][1]));
		}
	}
}
