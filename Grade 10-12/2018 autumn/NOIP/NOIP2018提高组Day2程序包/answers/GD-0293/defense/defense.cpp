#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

vector<int> point[100001];
int n,m,w[100001],fa[100001][18],dep[100001],x,y,a,b;
long long f[100001][2],g[100001][2];
char str[10];

void dfs(int u){
	for(int i=1;i<=18;++i)if(fa[u][i-1])fa[u][i]=fa[fa[u][i-1]][i-1];else break;
	f[u][1]=w[u];
	for(int i=0;i<point[u].size();++i){
		int v=point[u][i];
		if(v!=fa[u][0])dep[v]=dep[fa[v][0]=u]+1,dfs(v),f[u][0]+=f[v][1],f[u][1]+=min(f[v][0],f[v][1]);
	}
}

inline void jump(int &v,int d){for(int i=0;i<=18;++i)if(d&(1<<i))v=fa[v][i];}

int lca(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	jump(v,dep[v]-dep[u]);
	if(u==v)return u;
	for(int i=18;i>=0;--i)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}

void change(int u,int a){
	u=fa[u][0];
	while(u!=a){
		g[u][0]=0,g[u][1]=w[u];
		for(int i=0;i<point[u].size();++i){
			int v=point[u][i];
			if(v!=fa[u][0])g[u][0]+=g[v][1],g[u][1]+=min(g[v][0],g[v][1]);
		}
		if(g[u][1]==f[u][1]&&min(g[u][1],g[u][0])==min(f[u][1],f[u][0]))return;
		u=fa[u][0];
	}
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,str);for(int i=1;i<=n;++i)scanf("%d",w+i);
	for(int i=1;i<n;++i)scanf("%d%d",&x,&y),point[x].push_back(y),point[y].push_back(x);
	dfs(1);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(x==0&&y==0&&(fa[a][0]==b||fa[b][0]==a)){puts("-1");continue;}
		int A=lca(a,b);
		memcpy(g,f,sizeof(f)),g[a][x^1]=g[b][y^1]=10000000000ll;
		change(a,A),change(b,A);
		g[A][0]=0,g[A][1]=w[A];
		for(int i=0;i<point[A].size();++i){
			int v=point[A][i];
			if(v!=fa[A][0])g[A][0]+=g[v][1],g[A][1]+=min(g[v][0],g[v][1]);
		}
		change(A,1);
		printf("%lld\n",min(g[1][0],g[1][1]));
	}
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
