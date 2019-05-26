#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define LL long long
#define rg register
#define N 5010
using namespace std;
int n,m,tot,top,answer,last[N],ans[N],ans2[N],s[N][N];
bool vis[N];
struct edge{
	int to,pre;
}e[N<<1];
struct rec{
	int u,v;
}r[N];
inline int read(){
	int k=0,f=1; char c=getchar();
	while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while('0'<=c&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
void dfs(int x){
	ans[++answer]=x; int cnt=0; vis[x]=1;
	for(rg int i=last[x],to;i;i=e[i].pre)if(!vis[to=e[i].to]){
		s[x][++cnt]=to;
	}
	sort(s[x]+1,s[x]+1+cnt);
	for(rg int i=1;i<=cnt;i++) dfs(s[x][i]);
}
inline void calc(){
	bool ok=0;
	for(rg int i=1;i<=n;i++)
		if(ans2[i]==0||ans2[i]>ans[i]){
			ok=1; break;
		}
		else if(ans2[i]<ans[i]){
			ok=0; break;
		}
	if(ok==1) for(rg int i=1;i<=n;i++) ans2[i]=ans[i];
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(); m=read();
	for(rg int i=1;i<=m;i++) r[i].u=read(),r[i].v=read();
	if(m==n-1){
		for(rg int i=1;i<=m;i++){
			int u=r[i].u,v=r[i].v;
			e[++tot]=(edge){u,last[v]}; last[v]=tot;
			e[++tot]=(edge){v,last[u]}; last[u]=tot;
		}
		dfs(1);
		for(rg int i=1;i<=n;i++) printf("%d ",ans[i]); puts("");
	}
	else{
		for(rg int cut=1;cut<=m;cut++){
			answer=0; tot=0; 
			memset(last,0,sizeof(last));
			memset(vis,0,sizeof(vis));
			for(rg int i=1;i<=m;i++)if(i!=cut){
				int u=r[i].u,v=r[i].v;
				e[++tot]=(edge){u,last[v]}; last[v]=tot;
				e[++tot]=(edge){v,last[u]}; last[u]=tot;
			}
			dfs(1);
			if(answer>=n) calc();
		}
		for(rg int i=1;i<=n;i++) printf("%d ",ans2[i]); puts("");
	}
	return 0;
}
