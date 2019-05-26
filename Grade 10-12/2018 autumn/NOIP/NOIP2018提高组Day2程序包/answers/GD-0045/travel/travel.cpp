#include<queue> 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
const int MAXN=5010;

int n,m;

struct E{int y,v,next;}e[MAXN*4];int len=1,last[MAXN];
void ins(int x,int y)
{
//	printf("ed %d %d\n",x,y);
	e[++len]=(E){y,true,last[x]};last[x]=len;
}

namespace work1//Ê÷ 
{
	priority_queue<int,vector<int>,greater<int> > q[MAXN];
	void solve(int x,int fa)
	{
		printf("%d ",x);
		for(int k=last[x];k;k=e[k].next)
		{
			int y=e[k].y;
			if(y==fa) continue;
			q[x].push(y);
		}
		while(!q[x].empty())
		{
			int y=q[x].top();q[x].pop();
			solve(y,x);
		}
	}
}

namespace work2//»ù»·Ê÷ 
{
	int begin;
	bool huan[MAXN];
	
	int id=0,low[MAXN],dfn[MAXN];
	int top=0,sta[MAXN];bool in[MAXN];
	int scc=0,bel[MAXN];
	void tarjan(int x,int fa)
	{
		dfn[x]=low[x]=++id;
		sta[++top]=x;in[x]=true;
		for(int k=last[x];k;k=e[k].next)
		{
			int y=e[k].y;
			if(y==fa) continue;
			if(!dfn[y])
			{
				tarjan(y,x);
				low[x]=min(low[x],low[y]);
			}
			else if(in[y]) low[x]=min(low[x],dfn[y]);
		}
		if(dfn[x]==low[x])
		{
			int i,cnt=0,tpp=top;
			do
			{
				i=sta[top--];
				in[i]=false;
				cnt++;
			}while(i!=x);
			if(cnt>1)
			{
				begin=x;
				do
				{
					i=sta[tpp--];
					huan[i]=true;
				}while(i!=x);
			}
		}
	}
	
	priority_queue<int,vector<int>,greater<int> > q[MAXN];
	int tot,a[MAXN],b[MAXN];
	int T=0,can[MAXN];
	void hh(int x)
	{
		can[x]=T;
		a[++tot]=x;
		for(int k=last[x];k;k=e[k].next) if(e[k].v)
		{
			int y=e[k].y;
			if(can[y]==T) continue;
			q[x].push(y);
		}
		while(!q[x].empty())
		{
			int y=q[x].top();q[x].pop();
			hh(y);
		}
	}
	
	void bj()
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>b[i]) return ;
			else if(a[i]<b[i])
			{
				swap(a,b);
				return ;
			}
		}
	}
	
	bool vis[MAXN];
	void dfs(int x)
	{
//		printf("%d )\n",x);
		vis[x]=true;
		if(x==begin)
		{
			for(int k=last[x];k;k=e[k].next)
			{
				int y=e[k].y;
				if(huan[y])
				{
					e[k].v=e[k^1].v=false;
					T++;tot=0;
					hh(1);
					bj();
					e[k].v=e[k^1].v=true;
					
					dfs(y);
				}
			}
		}
		else
		{
			for(int k=last[x];k;k=e[k].next)
			{
				int y=e[k].y;
				if(huan[y] && !vis[y])//debug vis[x]
				{
					e[k].v=e[k^1].v=false;
					T++;tot=0;
					hh(1);
					bj();
					e[k].v=e[k^1].v=true;
					
					dfs(y);
				}
			}
		}
	}
	
	void solve()
	{
		for(int i=1;i<=n;i++)
			if(!dfn[i]) tarjan(i,0);
		b[1]=n+1;
		dfs(begin);
		for(int i=1;i<=n;i++) printf("%d ",b[i]);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;scanf("%d %d",&x,&y);
		ins(x,y);ins(y,x);
	}
	if(m==n-1) work1::solve(1,0);
	else work2::solve();
	return 0;
}

