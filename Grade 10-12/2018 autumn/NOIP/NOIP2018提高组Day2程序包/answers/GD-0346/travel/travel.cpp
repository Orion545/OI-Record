#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define re register int
using namespace std;
const int N = 5e3+5;
int n,m,dfn[N],cnt,a[N];
bool vis[N][N];
priority_queue<int,vector<int>,greater<int> > q[N];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
struct Node{
	int u,pre;
};
queue<Node> que;
void bfs(){
	que.push((Node){1,0}); 
	Node tmp;
	re u,v,pre;
	while(!que.empty()){
		tmp =que.front();
		u = tmp.u;
		pre = tmp.pre;
		que.pop();
		while(!q[u].empty()){
			v = q[u].top();
			q[u].pop();
			if(v == pre) continue;
			if(!dfn[v]){
				dfn[v] = cnt;
				cnt++;	
			}else{
				if(dfn[u]>dfn[v]&&u<v){
					int t=dfn[u];
					dfn[u] = dfn[v];
					dfn[v] = t;
				}
			}
			que.push((Node){v,u});
		}
	}
}
inline bool cmp(int a,int b){
	return dfn[a]<dfn[b];
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(); m=read();
	for(re i=1,u,v; i<=m; i++){
		u=read(); v=read();
		q[u].push(v);
		q[v].push(u); 
	}
	dfn[1] = 1;
	cnt = 2;
	bfs();
	for(re i=1; i<=n; i++){
		a[i] = i;
	}
	sort(a+1,a+n+1,cmp);
	for(re i=1; i<=n; i++){
		printf("%d ",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}




