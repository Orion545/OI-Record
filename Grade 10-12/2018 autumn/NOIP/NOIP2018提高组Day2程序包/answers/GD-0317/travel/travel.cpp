#include<bits/stdc++.h>
#define now edge[i].v
using namespace std;
const int sz=5e3+527;
int n,m;
int u,v,x,rt;
int cnt,T,lst;
int head[sz];
bool vis[sz];
struct Edge{
	int v,nxt;
}edge[sz<<1];
void add(int u,int v){
	edge[++cnt]=(Edge){v,head[u]};
	head[u]=cnt;
}
void dfs(int x){
	printf("%d ",x);
	vis[x]=1;
	int a[5001],tot=0;
	for(int i=head[x];i;i=edge[i].nxt)
		if(!vis[now]) a[++tot]=now;
	sort(a+1,a+tot+1);
	for(int i=1;i<=tot;i++) dfs(a[i]);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travle.out","w",stdout);
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
}
