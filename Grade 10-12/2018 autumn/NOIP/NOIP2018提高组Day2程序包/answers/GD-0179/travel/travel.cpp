#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 5005
#define min(x,y) x < y ? x : y
#define ll long long
using namespace std;
struct edge{
	int to, next;
	bool vis;
}e[maxn*2];
int head[maxn], cnt = 0, ans[maxn], vis[maxn], num = 2;
void add(int u ,int v){
	e[cnt].next = head[u];
	e[cnt].to = v;
	head[u] = cnt++;
}
void dfs(int x){
	int minn = 9998999, now = 0;
	bool temp = true;
	while(temp){
		temp = false;
		minn = 9999999;
		now = 0;
		for(int i=head[x];~i;i = e[i].next){
			if((!e[i].vis) && (!vis[e[i].to])){
				minn = min(minn,e[i].to);
				if(minn == e[i].to){
					now = i;
				}
				temp = true;
			}
		}
		if(temp){
			ans[num++] = minn;
			e[now].vis = true;
			vis[e[now].to] = true;
			dfs(e[now].to);
		}
	}
}
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n , m;
	memset(ans,0,sizeof(ans));
	memset(e,0,sizeof(e));
	memset(head,255,sizeof(head));
	memset(vis,false,sizeof(vis));
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int u , v;
		scanf("%d %d",&u,&v);
		add(u,v);
		add(v,u);
	}
	ans[1] = 1;
	vis[1] = true;
	dfs(1);
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
