#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#define ll long long int 
#define MAXN 5005
#define MAXM 10010
#define INF 0x3f3f3f3f
using namespace std;

struct edge{
	int u,v,next;
}e[MAXM],ne[MAXM];

int n,m,cnt=0,head[MAXN],out[MAXN],vis[MAXN];
int dfn[MAXN],low[MAXN],color[MAXN],instack[MAXN],tot=0,colornum,num[MAXN];

int nhead[MAXN],ncnt=0,nout[MAXN];

stack<int>s;

inline void addedge(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
	out[u]++;
}

inline void naddedge(int u,int v){
	ne[++ncnt].v=v;
	ne[ncnt].u=u;
	ne[ncnt].next=nhead[u];
	nhead[u]=ncnt;
	nout[u]++;
}

void dfs(int now,int fa){
	printf("%d ",now);
	if(now!=fa&&out[now]==1)return;
	int nown=INF;
	for(int i=1;i<=out[now];i++){
		nown=INF;
		for(int i=head[now];i;i=e[i].next)
		 if(e[i].v!=fa&&!vis[e[i].v])nown=min(nown,e[i].v);
		if(nown==INF)continue;
		vis[nown]=1;
		dfs(nown,now);
	}	
}

/*int minn=INF;
int minnn;

void nndfs(int now,int fa){
	if(num[color[now]]>1&&now>minnn){
		return;
		vis[now]=0;
	}
	printf("%d ",now);
	if(now!=fa&&out[now]==1)return;
	int nown=INF;
	for(int i=1;i<=nout[now];i++){
		nown=INF;
		for(int i=nhead[now];i;i=ne[i].next)
		 if(ne[i].v!=fa&&!vis[ne[i].v])nown=min(nown,ne[i].v);
		if(nown==INF)continue;
		vis[nown]=1;
		dfs(nown,now);
	}	
}

void solve(int now){
	cout<<"ok";
	for(int i=nhead[now];i;i=ne[i].next){
		if(color[ne[i].v]!=now)continue;
		if(ne[i].v<minn){
			minn=ne[i].v;
			minnn=minn;
		}
	}
	nndfs(now,now);
}

void ndfs(int now,int fa){
	printf("%d ",now);
	if(num[color[now]]==4){
		cout<<"ok";
		solve(now);
	}
	if(now!=fa&&out[now]==1)return;
	int nown=INF;
	for(int i=1;i<=out[now];i++){
		nown=INF;
		for(int i=head[now];i;i=e[i].next)
		 if(e[i].v!=fa&&!vis[e[i].v])nown=min(nown,e[i].v);
		if(nown==INF)continue;
		vis[nown]=1;
		dfs(nown,now);
	}	
}

inline void print(int x){
	s.pop();
	instack[x]=0;
	color[x]=colornum;
	//if(x==6)cout<<color[x];
	num[colornum]++;
}

inline void tarjan(int x,int fa){
	dfn[x]=low[x]=++tot;
	s.push(x);
	//if(x==6)cout<<dfn[x]<<" "<<low[x]<<endl;
	instack[x]=1;
	for(int i=nhead[x];i;i=ne[i].next){
		int nown=ne[i].v;
		if(nown==fa)continue;
		if(!dfn[nown]){
			tarjan(nown,x);
			low[x]=min(low[x],low[nown]);
		}
		else if(instack[nown])low[x]=min(low[x],dfn[nown]);
	}
	//if(x==6)cout<<dfn[x]<<" "<<low[x]<<endl;
	if(dfn[x]==low[x]){
		colornum=x;
		while(s.top()!=x){
			print(s.top());
		}
		print(x);
	}
}*/

int minn;
int minnn;

void ndfs1(int x,int fa){
	if(vis[x])return;
	printf("%d ",x);
	vis[x]=1;
	for(int i=nhead[x];i;i=ne[i].next){
		if(ne[i].v==fa)continue;
		if(ne[i].v>minnn)return;
		ndfs1(ne[i].v,x);
	}
	return;
}

void ndfs2(int x,int fa){
	if(vis[x])return;
	printf("%d ",x);
	vis[x]=1;
	for(int i=nhead[x];i;i=ne[i].next){
		if(ne[i].v==fa)continue;
		ndfs2(ne[i].v,x);
	}
	return;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==n-1){
		int u,v;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		dfs(1,1);
		return 0;
	}
	if(m==n){
		int u,v;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			naddedge(u,v);
			naddedge(v,u);
		}
		/*for(int i=1;i<=n;i++){
			if(!dfn[i])tarjan(i,i);
		}*/
		/*for(int i=1;i<=m<<1;i++){
			u=ne[i].u,v=ne[i].v;
			if(color[u]!=color[v]){
				addedge(color[u],color[v]);
			} 
		}*/
		//cout<<num[3]<<endl;
		for(int i=nhead[1];i;i=ne[i].next){
			if(minnn!=0){
				if(ne[i].v>minnn){
					minn=minnn;
					minnn=ne[i].v;
				}
				else minn=ne[i].v;
			}
			else minnn=ne[i].v;
		}
		printf("1 ");
		//cout<<minn<<" "<<minnn;
		ndfs1(minn,1);
		ndfs2(minnn,1);
		return 0;
	}
}
