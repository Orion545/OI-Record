#include<bits/stdc++.h>
#define sz 100010
using namespace std;
typedef long long ll;
int n,m;
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}
#define go(x) for (int i=head[x];i;i=edge[i].nxt)
#define v edge[i].t
ll dp[sz][2];//当前没有/有 
ll w[sz];
int A,X,B,Y;
void dfs(int x,int fa)
{
	dp[x][0]=0;dp[x][1]=w[x];
	go(x) if (v!=fa) dfs(v,x);
	if (B==x) swap(A,B),swap(X,Y);
	if (A==x)
	{
		dp[x][!X]=233333333333333ll;
		if (X==0){
			go(x) if (v!=fa) dp[x][0]+=dp[v][1];
		}else{
			go(x) if (v!=fa) dp[x][1]+=min(dp[v][1],dp[v][0]);
		}
		return;
	}
	go(x) 
		if (v!=fa){
			dp[x][1]+=min(dp[v][1],dp[v][0]),
			dp[x][0]+=dp[v][1];
		}
}
int main()
{
//	freopen("a.txt","r",stdin);
	freopen("defense.in","r",stdin);freopen("defense.out","w",stdout);
	int i,x,y,Q;string _;
	scanf("%d %d",&n,&Q);cin>>_;
	for (i=1;i<=n;i++) scanf("%lld",&w[i]);
	for (i=1;i<n;i++) scanf("%d %d",&x,&y),make_edge(x,y);
	while (Q--)
	{
		scanf("%d %d %d %d",&A,&X,&B,&Y);
		dfs(1,0);
		ll ans;
//		cout<<(((ans=min(dp[1][0],dp[1][1]))>=233333333333333ll)?-1ll:ans)<<'\n';
		printf("%lld\n",(((ans=min(dp[1][0],dp[1][1]))>=233333333333333ll)?-1ll:ans));
	}
}

