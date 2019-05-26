#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010;
typedef long long ll;
int n,m,a,b,x,y,tot,p[N],head[N],to[N*2],nxt[N*2];
ll dp[N][2];
char s[N];
void add_edge(int u,int v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
	return;
}
void dfs(int u,int father){
	dp[u][0]=0;
	dp[u][1]=p[u];
	bool ck=0;
	for(int i=head[u];~i;i=nxt[i]){
		int v=to[i];
		if(v==father)
			continue;
		ck=1;
		dfs(v,u);
		dp[u][0]+=dp[v][1];
		dp[u][1]+=min(dp[v][0],dp[v][1]);
	}
	if(u==a)
		dp[u][x^1]=1e18;
	if(u==b)
		dp[u][y^1]=1e18;
	return;
}
int main(){
	freopen("denfense.in","r",stdin);
	freopen("denfense.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",p+i);
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	while(m--){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		dfs(1,0);
		ll ans;
		if(a==1)
			ans=dp[a][x];
		else if(b==1)
			ans=dp[b][x];
		else ans=min(dp[1][0],dp[1][1]);
		if(ans>=1e18){
			puts("-1");
			continue;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
5 3 C3
2 4 1 3 9
1 5
5 2
5 3
3 4
1 0 3 0
2 1 3 1
1 0 5 0
*/
