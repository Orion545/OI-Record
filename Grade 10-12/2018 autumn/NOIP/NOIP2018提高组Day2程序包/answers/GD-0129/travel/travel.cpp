#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
int tot[5005];
int mapp[5005][5005];
bool vis[5005];
int low[5005];
int dfn[5005];
int q[5005];
int idx,top;
int sc;
int scc[5005];
int tott[5005];
int idxx;
int t;
int n,m;
void dfs1(int x,int fa){
	printf("%d ",x);
	vis[x]=true;
	if(scc[x]==idxx&&scc[fa]!=idxx){
		int tmp=0;
		for(int i=1;i<=n;++i){
			if(scc[mapp[x][i]]==idxx){
				++tmp;
				if(tmp==2) {
					t=mapp[x][i];
					break;
				}
			}
		}
	}
	for(int i=1,v;i<=tot[x];++i){
		v=mapp[x][i];
		if(v!=fa&&scc[x]==idxx&&scc[v]==idxx&&v>t) return;
		if(v!=fa&&!vis[v]){
			if(t==v) t=0x7fffffff;
			dfs1(v,x);
		}
	}
}
void dfs(int x,int fa){
	printf("%d ",x);
	vis[x]=true;
	for(int i=1,v;i<=tot[x];++i){
		v=mapp[x][i];
		if(v!=fa&&!vis[v]) {
			dfs(v,x);
		}
	}
}
void tarjan(int x,int fa){
	low[x]=dfn[x]=++idx;
	q[++top]=x;
	for(int i=1,v;i<=tot[x];++i){
		v=mapp[x][i];
		if(v!=fa){
			if(!dfn[v]) {
				tarjan(v,x);
				low[x]=min(low[v],low[x]);
			}	
			else if(!scc[v]){
				low[x]=min(low[v],low[x]);
			}
		}
		if(idxx) return;
	}
	if(dfn[x]==low[x]){
		++sc;
		int now=0;
		while(now!=x){
			now=q[top--];
			scc[now]=sc;
			++tott[sc];
		}
		if(tott[sc]>1) idxx=sc;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		++tot[x];
		++tot[y];
		mapp[x][tot[x]]=y;
		mapp[y][tot[y]]=x;
	}
	for(int i=1;i<=n;++i){
		sort(mapp[i]+1,mapp[i]+1+tot[i]);
	}
	if(m==n){
		tarjan(1,0);
		dfs1(1,0);
	}
	else dfs(1,0);
	return 0;
}
