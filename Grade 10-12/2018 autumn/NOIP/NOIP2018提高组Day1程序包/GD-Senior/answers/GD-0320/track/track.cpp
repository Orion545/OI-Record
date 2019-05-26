#include<queue>
#include<cstdio>
using namespace std;
inline int read(){
	int f = 1,x = 0;
	char c = getchar();
	while(c > '9' || c < '0'){if(c == '-')f = -1;c = getchar();}
	while(c <= '9' && c >= '0'){x = x*10 + c-'0';c = getchar();}
	return x*f;
}
const int MAXN = 50005*2;
const int MAXM = 50005;
int n,m,ans;

struct Edge{
	int next,to,val;
}edge[MAXN];
int head[MAXM],cnt;
void addedge(int from,int to,int v){
	edge[++cnt].next = head[from];
	edge[cnt].to = to;
	edge[cnt].val = v;
	head[from] = cnt;
}

struct node{
	int pos,dis;
	bool operator <(const node &x)const{
		return dis < x.dis;
	}
};
int dist[MAXM];
priority_queue<node> que;
int dij(int x){
	int maxdi = 0;
	for(int i = 1;i <= MAXM;i++) dist[i] = 0;
	que.push(node{x,0});
	while(!que.empty()){
		node temp = que.top();
		que.pop();
		int d = temp.dis,p = temp.pos;
		if(d != dist[p]) continue;
		for(int i = head[p];i;i = edge[i].next){
			int t = edge[i].to,r = edge[i].val;
			if(dist[t] < dist[p] + r){
				dist[t] = dist[p] + r;
				que.push(node{t,dist[t]});
				if(dist[t] > maxdi) maxdi = dist[t];
			}	
		}
	}
	return maxdi;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n = read();m = read();
	for(int i = 0;i < n-1;i++){
		int a = read(),b = read(),l = read();
		addedge(a,b,l);
		addedge(b,a,l);
	}
	for(int i = 1;i <= n;i++){
		if(edge[head[i]].next != 0) continue;
		int q = dij(i);
		if(q > ans) ans = q;
	}
	printf("%d",ans);
	return 0;
}
