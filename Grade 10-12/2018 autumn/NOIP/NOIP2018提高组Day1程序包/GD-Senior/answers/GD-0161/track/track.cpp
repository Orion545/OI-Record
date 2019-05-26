#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=50010;
int n,m,tot,ans,head[N],to[N*2],nxt[N*2],val[N*2],dp[N][2];
void add_edge(int u,int v,int w){
	nxt[++tot]=head[u];
	to[tot]=v;
	val[tot]=w;
	head[u]=tot;
	return;
}
void dfs(int u,int father,int k){
	set<int>S;
	for(int i=head[u];~i;i=nxt[i]){
		int v=to[i],w=val[i];
		if(v==father)
			continue;
		dfs(v,u,k);
		dp[u][0]+=dp[v][0];
		if(dp[v][1]+w<k)
			S.insert(dp[v][1]+w);
		else dp[u][0]++;
	}
	for(set<int>::iterator iter=S.begin();iter!=S.end();){
		set<int>::iterator iter2=S.upper_bound(k-(*iter)-1);
		if(iter==iter2)
			iter2++;
		if(iter2==S.end()){
			iter++;
			continue;
		}
		set<int>::iterator tmp=iter;
		iter++;
		if(iter==iter2)
			iter++;
		S.erase(tmp);
		S.erase(iter2);
		dp[u][0]++;
	}
	if(S.empty())
		dp[u][1]=0;
	else dp[u][1]=(*(S.rbegin()));
	return;
}
bool check(int k){
	memset(dp,0,sizeof(dp));
	dfs(1,0,k);
	return dp[1][0]>=m;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	int l=1,r=500000000;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
