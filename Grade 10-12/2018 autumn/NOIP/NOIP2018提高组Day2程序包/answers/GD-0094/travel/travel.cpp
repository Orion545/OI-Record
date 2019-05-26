#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>

#define N (5000+5)

using namespace std;

int n,m,i,u,v,k,t,bu,bv,num;
bool vis[N];
vector<int> g[N];
int res[N],ans[N];

struct edge{
	int u;
	int v;
}e[N];

void dfs(int u){
	int i,v;
	vis[u]=1;
	res[++num]=u;
	if (num==n){
		i=1;
		while (res[i]==ans[i]) i++;
		if (res[i]<ans[i]) 
		memcpy(ans,res,sizeof res);
		return;
	}
	for (i=0;i<g[u].size();i++) {
		v=g[u][i];
		if (!((u==bu&&v==bv)||(u==bv&&v==bu)))
			if (!vis[v]) dfs(v);			
	}
}
bool cmp(const edge&a,const edge&b){
	return (a.u<b.u)|(a.u==b.u&a.v<b.v);
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		if (u>v) swap(u,v);
		e[i].u=u;
		e[i].v=v;
	}
	sort(e+1,e+1+m,cmp);
	for (i=1;i<=m;i++){
		g[e[i].u].push_back(e[i].v);
		g[e[i].v].push_back(e[i].u);
	}
	for (i=1;i<=n;i++)
		ans[i]=n;
	if (m==n-1)  dfs(1); 
	else {
		for (i=1;i<=m;i++) {
			bu=e[i].u;
			bv=e[i].v;
			if (g[bu].size()>1&&g[bv].size()>1) {
				num=0;
				memset(vis,0,sizeof vis);
				dfs(1);
			}
		}
	}
	for (i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
