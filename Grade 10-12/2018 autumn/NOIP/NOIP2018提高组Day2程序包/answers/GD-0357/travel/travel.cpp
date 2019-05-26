#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 5005
using namespace std;
inline void read(int &x){
	int f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	x=0;
	while (ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
void print(int x){
	if (x<0) putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+'0');
}
vector<int>G[MAXN];
inline void AddEdge(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}
vector<int>DfsOrder;
inline bool comp(vector<int>a,vector<int>b){
	for (register int i=0;i<(int)a.size();++i){
		if (a[i]!=b[i]){
			return a[i]<b[i];
		}
	}
	return false;
}
bool vis[MAXN],v[MAXN];
void dfs(int u,int father){
	//printf("%d %d\n",u,father);
	if (!vis[u]){
		DfsOrder.push_back(u);
	}
	else {
		vis[u]=true;
	}
	for (register int i=0;i<(int)G[u].size();++i){
		if (G[u][i]!=father&&!v[G[u][i]]){
			v[G[u][i]]=true;
			dfs(G[u][i],u);
		}
	}
}
int fa[MAXN];
bool get_fa(int u,int father){
	fa[u]=father;
	if (vis[u]){
		return true;
	}
	vis[u]=true;
	for (register int i=0;i<(int)G[u].size();++i){
		if (G[u][i]!=father){
			if (get_fa(G[u][i],u)) return true;
		}
	}
	return false;
}
int du,dv;
void find_ans(int u,int father){
	if (!vis[u]){
		DfsOrder.push_back(u);
		vis[u]=true;
	}
	else {
		return ;
	}
	for (register int i=0;i<(int)G[u].size();++i){
		if (u==du&&G[u][i]==dv) {
			continue;
		}
		if (!vis[G[u][i]]&&G[u][i]!=father){
			find_ans(G[u][i],u);
		}
	}
}
vector<int>Val;
vector<int>best;
inline void find_circle(int u){
	int tempu=u;
	memset(vis,0,sizeof(vis));
	if (!get_fa(u,u)) return ;
	while (true){
		du=u,dv=fa[u];
		DfsOrder.clear();
		memset(vis,0,sizeof(vis));
		find_ans(u,u);
		if (best.size()==0||comp(DfsOrder,best)) best=DfsOrder;
		u=fa[u];
		if (u==tempu){
			break;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (register int i=1;i<=m;++i){
		int u,v;
		read(u),read(v);
		AddEdge(u,v);
	}
	for (register int i=1;i<=n;++i){
		sort(G[i].begin(),G[i].end());
	}
	if (m==n-1){//Ò»¿ÃÊ÷ 
		v[1]=true;
		dfs(1,1);
		for (register int i=0;i<(int)DfsOrder.size();++i){
			print(DfsOrder[i]),putchar(' ');
		}
		putchar('\n');
		return 0;
	}
	else {//»ù»·Ê÷ 
		for (register int i=1;i<=n;++i){
			find_circle(i);
		}
		for (register int i=0;i<(int)best.size();++i){
			print(best[i]),putchar(' ');
		}
		putchar('\n');
	}
}
