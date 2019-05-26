#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define maxn 100005
#define inf 0x7fffffffLL
using namespace std;
int n,m,p[maxn];
char s[5];
vector<int>G[maxn];
ll dpu[maxn][2],dpd[maxn][2],dp[maxn][2];
int a,x,b,y;
ll P=0;
inline void dfs(int u,int f){
	dp[u][0]=0;
	dp[u][1]=p[u];
	for(int i=0;i<G[u].size();++i){
		int v=G[u][i];
		if(v!=f){
			dfs(v,u);
			dp[u][0]+=dp[v][1];
			dp[u][1]+=min(dp[v][0],dp[v][1]);
		}
	}
	if(u==a){
		if(x)dp[u][0]=inf;
		else dp[u][1]=inf;
	}else if(u==b){
		if(y)dp[u][0]=inf;
		else dp[u][1]=inf;
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	for(int i=1;i<=n;++i){
		scanf("%d",&p[i]);
		P+=p[i];
	}
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(dpu,0x3f,sizeof(dpu));
	memset(dpd,0x3f,sizeof(dpd));
	dpd[n][0]=0;
	dpd[n][1]=p[n];
	for(int i=n-1;i;--i){
		dpd[i][0]=dpd[i+1][1];
		dpd[i][1]=min(dpd[i+1][1],dpd[i+1][0])+p[i];
	}
	dpu[1][0]=0;
	dpu[1][1]=p[1];
	for(int i=2;i<=n;++i){
		dpu[i][0]=dpu[i-1][1];
		dpu[i][1]=min(dpu[i-1][1],dpu[i-1][0])+p[i];
	}
	if(n<=2000){
		while(m--){
			scanf("%d%d%d%d",&a,&x,&b,&y);
			dfs(1,0);
			ll ans=min(dp[1][0],dp[1][1]);
			if(ans>P)puts("-1");
			else printf("%lld\n",ans);
		}
	}else{
		while(m--){
			scanf("%d%d%d%d",&a,&x,&b,&y);
			if(a>b)swap(a,b),swap(x,y);
			if(x){
				if(y){
					printf("%lld\n",dpu[x][1]+dpd[y][1]);
				}else{
					printf("%lld\n",dpu[x][1]+dpd[y][0]);
				}
			}else{
				if(y){
					printf("%lld\n",dpu[x][0]+dpd[y][1]);
				}else{
					puts("-1");
				}
			}
		}
	}
	return 0;
}
