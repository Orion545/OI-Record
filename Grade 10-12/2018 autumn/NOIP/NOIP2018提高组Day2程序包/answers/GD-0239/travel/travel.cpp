#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

bool vis[5005],inC[5005];
int n,m,x,y,k=2e9,tot=0,top=0;
int h[5005],deg[5005],ans[5005];
struct Edge{
	int x,next;
}e[100005];

inline void add_edge(int x,int y){
	e[++tot].x=y;
	e[tot].next=h[x],h[x]=tot;
	deg[y]++;
}

void top_sort(){
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(deg[i]==1)q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		vis[x]=true;
		for(int i=h[x];i;i=e[i].next){
			deg[e[i].x]--;
			if(deg[e[i].x]==1)q.push(e[i].x);
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])inC[i]=true;
		else vis[i]=false;
	}
}

void dfs(int x,int fa){
	ans[++top]=x,vis[x]=true;
	if(!inC[fa]&&inC[x]){
		k=0;
		for(int i=h[x];i;i=e[i].next){
			if(vis[e[i].x])continue;
			if(inC[e[i].x])k=max(k,e[i].x);
		}
	}else{
		if(inC[x])
			for(int i=h[x];i;i=e[i].next){
				if(vis[e[i].x])continue;
				if(!inC[e[i].x])k=max(k,e[i].x);
			}
	}
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i=h[x];i;i=e[i].next){
		if(vis[e[i].x])continue;
		q.push(e[i].x);
	}
	while(!q.empty()){
		int y=q.top();q.pop();
		if(vis[y])continue;
		if(inC[y]&&y>k){
			k=2e9; continue;
		}
		dfs(y,x);
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	if(m==n)top_sort();
	dfs(1,0);
	for(int i=1;i<=top;i++)
		printf("%d ",ans[i]);
	return 0;
}
