#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3 + 10;
struct Edge{
	int x,y;
}e[maxn];
int dfn[maxn],low[maxn],vis[maxn],Super[maxn*2],Stack[maxn],sz[maxn*2],top,cnt,Deep;
bool ih[maxn];
bool visit[maxn];
bool Flag=1;
int ans[maxn];
int h1,h2,IN,sum;
vector <int>R[maxn];
vector <int>P[maxn];
int n,m;
bool cmp(Edge x,Edge y){
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
void Tarjan(int u,int f){
	dfn[u]=++Deep;
	low[u]=Deep;
	vis[u]=1;
	Stack[++top]=u;
	for(int i=0;i<(int)R[u].size();i++){
		int v=R[u][i];
		if(v==f) continue;
		if(!dfn[v]){
			Tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]) low[u]=min(low[u],low[v]);
	}
	if(low[u]==dfn[u]){
		cnt++;
		Super[u]=cnt+n;
		sz[cnt+n]=1;
		vis[u]=0;
		while(Stack[top]!=u){
			vis[Stack[top]]=0;
			Super[Stack[top--]]=cnt+n;
			sz[cnt+n]++;
		}
		top--;
	}
}

void dfs(int u,int f){
	if(!IN && ih[u]){
		for(int i=0;i<(int)P[u].size();i++){
			int v=P[u][i];
			if(v==f) continue;
			if(ih[v] && h1==0) h1=v;
			else if(ih[v] && h2==0) h2=v;
		}
		IN=1;
		if(h1>h2) swap(h1,h2);
	}
	if(Flag){
		if(ih[u] && f==h1) h1=u;
		if(u==h1 && h1>h2) {Flag=false;return;}
	}
	ans[++sum]=u;
	visit[u]=1;
	for(int i=0;i<(int)P[u].size();i++){
		int v=P[u][i];
		if(v==f || visit[v]) continue;
		dfs(v,u);
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&e[i].x,&e[i].y);
		if(e[i].x>e[i].y) swap(e[i].x,e[i].y);
		R[e[i].x].push_back(e[i].y);
		R[e[i].y].push_back(e[i].x);
	} 
	Tarjan(1,0);
	for(int i=1;i<=n;i++) if(sz[Super[i]]>1) ih[i]=1;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		P[e[i].x].push_back(e[i].y);
		P[e[i].y].push_back(e[i].x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
