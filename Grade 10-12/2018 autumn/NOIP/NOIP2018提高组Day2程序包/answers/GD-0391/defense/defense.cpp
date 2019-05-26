#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n,m,k;char ch;
vector<int> g[100001];
int depth[100001],dp[100001][2],val[100001],vd[100001];
bool visit[100001];
void dfs1(int u){
	visit[u]=true;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!visit[v]){
			depth[v]=depth[u]+1;
			dfs1(v);
		}
	}
}

void dfs2(int u){
	visit[u]=true;vd[depth[u]]=val[u];
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!visit[v]){
			depth[v]=depth[u]+1;
			dfs2(v);
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int u;int v;
	int u1,v1;
	scanf("%d%d",&n,&m);
	cin>>ch;
	scanf("%d",&k);
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	if(ch=='A'){
		depth[1]=1;
		dfs1(1);u=0;v=1;
		for(int i=1;i<=n;i++){
			if(depth[i]>depth[v])u=depth[i],v=i;
		}
		depth[v]=1;
		memset(visit,0,sizeof(visit));
		dfs2(v);
		for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&u,&u1,&v,&v1);
		if(depth[u]>depth[v])swap(u,v),swap(u1,v1);
		if(depth[v]-depth[u]==1&&u1==0&&v1==0)cout<<-1<<'\n';
		//dp[1][1]=val[1];
		memset(dp,0x3f,sizeof(dp));
		for(int i=i;i<=n;i++){
			if(i==u){
				if(u1==0)dp[i][0]=min(dp[i][0],dp[i-1][1]);
				else dp[i][1]=min(dp[i-1][0]+val[i],dp[i-1][1]+val[i]);
			}
			if(i==v){
				if(v1==0)dp[i][0]=min(dp[i][0],dp[i-1][1]);
				else dp[i][1]=min(dp[i-1][0]+val[i],dp[i-1][1]+val[i]);
			}
			else{
				dp[i][0]=min(dp[i][0],dp[i-1][1]);
				dp[i][1]=min(dp[i-1][0]+val[i],dp[i-1][1]+val[i]);
			}
		}
		cout<<min(dp[n][0],dp[n][1])<<'\n';
		}
	}
} 
