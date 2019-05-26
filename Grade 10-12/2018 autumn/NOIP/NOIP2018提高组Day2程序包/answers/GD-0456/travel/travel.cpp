#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
#include <string.h>
#include <algorithm>
#define N 5005
using namespace std;
int a[N],al[N],ap[N],cnt,an,n,m;
int ans[N];
priority_queue<int> g[N];
void addedge(int x,int y){
	an++;a[an]=y;al[an]=ap[x];ap[x]=an;
}
void dfs(int u,int v){
	int p=ap[u];ans[++cnt]=u;
	while(p!=0){
		if(a[p]!=v)dfs(a[p],u);
		p=al[p];
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		g[x].push(y);g[y].push(x);
	}
	for(int i=1;i<=n;i++){
		while(!g[i].empty()){
			int u=g[i].top();g[i].pop();
			addedge(i,u);
		}
	}
	cnt=0;
	dfs(1,1);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}
