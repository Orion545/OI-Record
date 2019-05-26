#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int tot,tot1,n,m;
struct hh{
	int nex,v;
}e[10100];
bool vis[10100];
int head[10100],ans[10100],tmp[10010];
priority_queue<int,vector<int>,greater<int> > q[15];
//queue<int> q[15];

void readin()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
}

void add(int u,int v)
{
	e[++tot].v=v;
	e[tot].nex=head[u];
	head[u]=tot;
}

void bfs(int s,int d)
{
	vis[s]=true;
	q[d].push(s);
	while(!q[d].empty())
	{
		int u=q[d].top();
		ans[++tot1]=u;
		q[d].pop();
		int k,p=0;
		if(!q[d].empty())
			k==q[d].top();
		else
			k=0;
		bool check=false;
		for(int i=head[u];~i;i=e[i].nex)
		{
			int v=e[i].v;
			if(!vis[v])
			{
				if(k>v)
					check=true;
				tmp[++p]=v;
			}
		}
		if(check)
			bfs(u,d+1);
		else
			for(int i=1;i<=p;i++)
			{
				vis[tmp[i]]=true;
				q[d].push(tmp[i]);
			}
	}
}

int main()
{
	readin();
	
	int u,v;
	tot1=tot=0;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	bfs(1,1);
	
	for(int i=1;i<=tot1;i++)
		printf("%d ",ans[i]);
}
