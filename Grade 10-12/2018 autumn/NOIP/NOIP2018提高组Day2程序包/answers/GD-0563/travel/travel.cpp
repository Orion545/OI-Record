#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m;
#define Maxn 5005
int dfn[Maxn],low[Maxn],bel[Maxn],st[Maxn],top=0,dfk=0,cnt=0;
struct Edge{
	int a,b;
}edge[Maxn];
vector<int> graph[Maxn];
int fr,to;
int ans[Maxn];

void tarjan(int u,int f){
	dfn[u]=low[u]=++dfk;
	st[++top]=u;
	for(int i=0;i<graph[u].size();++i)
		if(!dfn[graph[u][i]]){
			tarjan(graph[u][i],u);
			low[u]=min(low[u],low[graph[u][i]]);
		}else if(graph[u][i]!=f)low[u]=min(low[u],dfn[graph[u][i]]);
	if(dfn[u]==low[u]){
		cnt++;
		int x;
		do{
			x=st[top];top--;
			bel[x]=cnt;
		}while(x!=u);
	}
}

int seq[Maxn],len;
void dfs(int u,int f){
	seq[++len]=u;
	for(int i=0;i<graph[u].size();++i)
	if(graph[u][i]!=f){
		if(fr==u&&to==graph[u][i])continue;
		if(fr==graph[u][i]&&to==u)continue;
	    dfs(graph[u][i],u);
    }
}
inline void solve(int ed){
	fr=edge[ed].a;to=edge[ed].b;
	len=0;
	dfs(1,0);
	for(int i=1;i<=n;++i)
	if(seq[i]<ans[i])break;
	else if(seq[i]>ans[i])return;
	for(int i=1;i<=n;++i)ans[i]=seq[i];
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	edge[0].a=edge[0].b=0;
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;++i)ans[i]=n+1;
	int s,e;
	for(register int i=1;i<=m;++i){
	    scanf("%d%d",&edge[i].a,&edge[i].b);
	    graph[edge[i].a].push_back(edge[i].b);
	    graph[edge[i].b].push_back(edge[i].a);
    }
    for(register int i=1;i<=n;++i)sort(graph[i].begin(),graph[i].end());
	if(m==n){
        tarjan(1,0);
        for(register int i=1;i<=m;++i)
        if(bel[edge[i].a]==bel[edge[i].b])solve(i);
    }else solve(0);
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;    
}
