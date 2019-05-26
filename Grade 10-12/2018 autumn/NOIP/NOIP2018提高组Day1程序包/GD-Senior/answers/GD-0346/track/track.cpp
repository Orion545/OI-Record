#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define ll long long
#define re register int
using namespace std;
const int N = 5e4+5;
const ll inf = 0x3f3f3f3f;
int head[N],du[N],cnt,n,m,minn=inf,sum;
ll dist[N],ans;
bool vis[N];
struct Edge{
	int v,nxt,w;
}edge[N<<1];
struct Node{
	int s;
	ll d;
	int pre;
	bool operator<(const Node &a)const {
		return d<a.d;
	}
};
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch == '-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
inline void addedge(int u,int v,int w){
	edge[++cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}
void dijkstra(int s){
	memset(dist,0,sizeof(dist));
	memset(vis,0,sizeof(vis));
	priority_queue<Node> q;
	dist[s] = 0;
	q.push((Node){s,0,0});
	re u,v;
	Node tmp;
	while(!q.empty()){
		tmp = q.top();
		u = tmp.s;
		q.pop();
		if(!vis[u]){
			vis[u] = 1;
			for(re i=head[u]; i!=-1;i=edge[i].nxt){
				v = edge[i].v;
				if(v == tmp.pre) continue;
				if(dist[v]<dist[u]+edge[i].w){
					dist[v] = dist[u]+edge[i].w;
					q.push((Node){v,dist[v],u});
				}
			}
		}
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n = read(); m=read();
	memset(head,-1,sizeof(head));
	for(re i=1,u,v,w; i<=n-1; i++){
		u=read(); v=read(); w=read();
		du[u]++;
		du[v]++;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for(re i=1; i<=n; i++){
		if(du[i] == 1){
			dijkstra(i);
			for(re i=1;i<=n; i++){
				ans = max(ans,dist[i]);
			}
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
