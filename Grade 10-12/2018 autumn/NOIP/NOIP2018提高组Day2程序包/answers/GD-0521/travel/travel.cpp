#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct edge{
	int to,next;
}e[10010];
int h[5010],tot=0;
inline void add(int u,int v){
	e[++tot].to=v;e[tot].next=h[u];h[u]=tot;
	e[++tot].to=u;e[tot].next=h[v];h[v]=tot;
}
vector<int> vec[5010];
int n,m,u,v;
void dfs(int now,int fa){
	printf("%d ",now);
	for(int i=h[now];~i;i=e[i].next)
		if(e[i].to!=fa)
			vec[now].push_back(e[i].to);
	sort(vec[now].begin(),vec[now].end());
	for(vector<int>::iterator i=vec[now].begin();i!=vec[now].end();i++)
		dfs(*i,now);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(h,-1,sizeof(h));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	dfs(1,0);
	puts("");
	return 0;
}