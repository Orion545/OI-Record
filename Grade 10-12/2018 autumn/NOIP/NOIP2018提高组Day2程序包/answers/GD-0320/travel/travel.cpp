#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int read(){
	int f = 1,x = 0;
	char c = getchar();
	while(c > '9' || c < '0'){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(c <= '9' && c >= '0'){
		x = x*10 + c - '0';
		c = getchar();
	}
	return x*f;
}
const int MAXN = 5005;
int n,m,vis[MAXN];
vector<int> ans;
struct Edge{
	int next,to;
	bool operator <(const Edge &x)const{
		return to > x.to;
	}
}edge[MAXN*2];
int ecnt,head[MAXN];
void addedge(int from,int to){
	edge[++ecnt].next = head[from];
	edge[ecnt].to = to;
	head[from] = ecnt;
}
priority_queue<Edge> que;
void work(int x){
	vis[x] = 1;
	ans.push_back(x);
	for(int i = head[x];i;i = edge[i].next)
		que.push(edge[i]);
	while(ans.size() < n){
		Edge temp = que.top();
		que.pop();
		int t = temp.to;
		if(vis[t]) continue;
		vis[t] = 1;
		ans.push_back(t);
		for(int i = head[t];i;i = edge[i].next){
			if(!vis[edge[i].to])
				que.push(edge[i]);
		}
	}	
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n = read();m = read();
	for(int i = 0;i < m;i++){
		int a = read();
		int b = read();
		addedge(a,b);
		addedge(b,a);
	}
	work(1);
	for(int i = 0;i < n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
