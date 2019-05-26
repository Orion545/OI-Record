#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N=5005;

struct node{
	int u;
	int v;
	node(int i,int j){
		u=i;v=j;
	}
};

int n,m,cnt=0,d1,d2,scnt=0;
int fa[N],in[N],ans[N];
bool vis[N],inq[N][N];
vector<int> g[N];
priority_queue<int> que[N];
queue<int> q;
queue<node> q2;
queue<int> srt[N];

template <class T> inline void qread(T &x){
	x=0;
	char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}

template <class T> inline void qprint(T x){
	if (x>=10) qprint(x/10);
	putchar(x%10+'0');
}

template <class T> inline void qput(T x){
	qprint(x);
	putchar(' ');
}

void dfs(int u){
	if (m==n-1) qput(u);
	else srt[scnt].push(u);
	while (que[u].size()){
		int v=-que[u].top();que[u].pop();
		if (v==fa[u]) continue;
		if ((m==n)&&((d1==u&&d2==v)||(d1==v&&d2==u))) continue;
		fa[v]=u;
		dfs(v);		
	}
}

void dfs2(int u){
	for (int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if (vis[v]||inq[u][v]) continue;
		q2.push(node(u,v));
		inq[u][v]=1;
		inq[v][u]=1;
		dfs2(v);
		break;
	}
}

void topo(){
	for (int i=1;i<=n;i++) if (in[i]==1) q.push(i),vis[i]=1;
	while (!q.empty()){
		int u=q.front();q.pop();
		in[u]--;
		for (int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if (vis[v]) continue;
			in[v]--;
			if (in[v]==1) q.push(v),vis[v]=1;
		}
	}
	for (int i=1;i<=n;i++){
		if (vis[i]) continue;
		dfs2(i);
		break;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	qread(n);qread(m);
	memset(in,0,sizeof(in));
	for (int i=1;i<=m;i++){
		int x,y;
		qread(x);qread(y);
		que[x].push(-y);
		que[y].push(-x);
		g[x].push_back(y);
		g[y].push_back(x);
		in[x]++;in[y]++;
	}
	if (m==n-1){
		memset(fa,0,sizeof(fa));
		dfs(1);
	}
	else{
		memset(vis,0,sizeof(vis));
		memset(ans,0x3f,sizeof(ans));
		memset(inq,0,sizeof(inq));
		topo();
		while (!q2.empty()){
			memset(fa,0,sizeof(fa));
			d1=q2.front().u;
			d2=q2.front().v;
			q2.pop();
			scnt++;
			dfs(1);
			for (int i=1;i<=n;i++){
				for (int j=0;j<g[i].size();j++){
					que[i].push(-g[i][j]);
				}
			}
		}
		for (int i=1;i<=scnt;i++){
			int l=srt[i].size();
			for (int j=1;j<=l;j++){
				bool flag=0;
				int u=srt[i].front();
				srt[i].pop();
				if ((!flag)&&u>ans[j]) break;
				if (u<ans[j]) flag=1;
				ans[j]=u;
			}
		}
		for (int i=1;i<=n;i++) qput(ans[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
