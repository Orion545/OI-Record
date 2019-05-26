#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
//priority_queue<int,vector<int>,greater<int> >q;
int n,m,cnt=0;
int h[5010];
struct e{
	int t,nxt;
}ed[10100];
void addedge(int f,int t)
{
	ed[++cnt].t=t;
	ed[cnt].nxt=h[f];
	h[f]=cnt;
}
bool vis[5010]={false};
void dfs(int k)
{
	int nod[5010],c=0;
	vis[k]=true;
	printf("%d ",k);
	for (int i=h[k];i;i=ed[i].nxt)
	{
		if (!vis[ed[i].t])
		{
			nod[++c]=ed[i].t;
		}
	}
	sort(nod+1,nod+c+1);
	for (int i=1;i<=c;i++)
		dfs(nod[i]);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) 
	{
		int f,t;
		scanf("%d%d",&f,&t);
		addedge(f,t);
		addedge(t,f);
	}
	dfs(1);
	/*q.push(1);
	for (int i=1;i<=n;i++)
	{
		int now=q.top();q.pop();
		while (vis[now]) now=q.top(),q.pop();
		vis[now]=true;
		printf("%d ",now);
		for (int j=h[now];j;j=ed[j].nxt)
		{
			if (!vis[ed[j].t])
			{
				q.push(ed[j].t);
			}
		}
	}*/
	return 0;
}
