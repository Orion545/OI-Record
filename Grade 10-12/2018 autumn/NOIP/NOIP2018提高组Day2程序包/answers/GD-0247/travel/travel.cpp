#include<cstdio>
#include<queue>
#define maxn 5001
using namespace std;
int n,m;
bool map[maxn][maxn];
bool vis[maxn];
int cnt=1;
int ans[maxn];

struct myint;

struct myint {
	int v;
	myint(int &v):v(v){}
	bool operator <(const myint &n) const{
		return n.v<v;
	}
};

priority_queue<myint> bq;

void bfs(int s) {
	bq.push(myint(s));
	while(!bq.empty()) {
		int p=bq.top().v;
		bq.pop();
		if(vis[p])continue;
		vis[p]=1;
		ans[cnt++]=p;
		for(int i=1;i<=n;i++) {
			if(!vis[i]&&map[p][i]) {
				bq.push(myint(i));
			}
		}
	}
}

void dfs(int now) {
	vis[now]=1;
	ans[cnt++]=now;
	priority_queue<myint> q;
	for(int i=1;i<=n;i++) {
		if(!vis[i]&&map[now][i]) {
			q.push(myint(i));
		}
	}
	while(!q.empty()) {
		dfs(q.top().v);
		q.pop();
	}
}

void judge() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
}

int main() {
	judge();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		map[u][v]=true;
		map[v][u]=true;
	}
	if(n==m)
		bfs(1);
	else
		dfs(1);
	for(int i=1;i<n;i++) {
		printf("%d ",ans[i]);
	}
	printf("%d",ans[n]);
	
}

