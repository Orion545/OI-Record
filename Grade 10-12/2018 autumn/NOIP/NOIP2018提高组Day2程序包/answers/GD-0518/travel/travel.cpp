#include <cstdio>
#include <algorithm>
using namespace std;
const int N=10005;
const int M=20005;
int n,m;
int u,v;
int h[N],nx[M],to[M],cnt;
int dfn[N],low[N],idx;
int s[N],t;
bool vis[N];
int loop[N],lcnt;
bool inloop[N],pass[N];
int f[N],scnt,fir,lim,cut;
int mv[N];
bool forbid[M];
void addedge(int u,int v)
{
	cnt++;
	to[cnt]=v;
	nx[cnt]=h[u];
	h[u]=cnt;
}
void greedy(int u,int p)
{
	printf("%d ",u);
	int las,cnt,cur;
	las=0;
	cnt=0;
	cur=0;
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=p)
			cnt++;
	for (int i=1;i<=cnt;i++)
	{
		cur=n+1;
		for (int j=h[u];j;j=nx[j])
			if (to[j]!=p)
				if (to[j]>las)
					if (to[j]<cur)
						cur=to[j];
		greedy(cur,u);
		las=cur;
	}
}
void findloop(int u,int las)
{
	idx++;
	dfn[u]=low[u]=idx;
	t++;
	s[t]=u;
	vis[u]=1;
	for (int i=h[u];i;i=nx[i])
		if (i!=(las^1))
			if (!vis[to[i]])
			{
				findloop(to[i],i);
				if (low[to[i]]<low[u])
					low[u]=low[to[i]];
			}
			else
				if (dfn[to[i]]<low[u])
					low[u]=dfn[to[i]];
	if (dfn[u]==low[u])
	{
		if (s[t]==u)
			t--;
		else
		{
			while (s[t]!=u)
			{
				lcnt++;
				loop[lcnt]=s[t];
				t--;
			}
			lcnt++;
			loop[lcnt]=u;
			t--;
		}
	}
}
void flag(int u,int p)
{
	if (u==1)
		pass[u]=1;
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=p&&inloop[to[i]]==0)
		{
			flag(to[i],u);
			pass[u]|=pass[to[i]];
		}
}
void dfs(int u,int p)
{
	printf("%d ",u);
	int las,cnt,cur;
	las=0;
	cnt=0;
	cur=0;
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=p&&forbid[i]==0)
			cnt++;
	for (int i=1;i<=cnt;i++)
	{
		cur=n+1;
		for (int j=h[u];j;j=nx[j])
			if (to[j]!=p&&forbid[j]==0)
				if (to[j]>las)
					if (to[j]<cur)
						cur=to[j];
		dfs(cur,u);
		las=cur;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	cnt++;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	if (n>m)
	{
		greedy(1,0);
		printf("\n");
	}
	else
	{
		findloop(1,0);
		for (int i=1;i<=lcnt;i++)
			inloop[loop[i]]=1;
		flag(loop[lcnt],0);
		for (int i=1;i<=lcnt;i++)
			for (int j=h[loop[i]];j;j=nx[j])
				if (pass[to[j]]==0&&inloop[to[j]]==0)
					if (to[j]>mv[loop[i]])
						mv[loop[i]]=to[j];
		scnt=0;
		for (int i=h[loop[lcnt]];i;i=nx[i])
			if (!pass[to[i]])
			{
				scnt++;
				f[scnt]=to[i];
			}
		sort(f+1,f+scnt+1);
		for (fir=1;fir<=scnt;fir++)
			if (inloop[f[fir]])
				break;
		lim=f[fir+1];
		if (f[fir]==loop[1])
		{
			for (cut=1;cut<lcnt;cut++)
				if (loop[cut+1]>lim||cut+1==lcnt)
					break;
				else
					if (mv[loop[cut]]>lim)
						lim=mv[loop[cut]];
			for (int i=h[loop[cut]];i;i=nx[i])
				if (to[i]==loop[cut+1])
					forbid[i]=1;
			for (int i=h[loop[cut+1]];i;i=nx[i])
				if (to[i]==loop[cut])
					forbid[i]=1;
		}
		else
		{
			loop[0]=loop[lcnt];
			for (cut=lcnt-1;cut>0;cut--)
				if (loop[cut-1]>lim||cut-1==0)
					break;
				else
					if (mv[loop[cut]]>lim)
						lim=mv[loop[cut]];
			for (int i=h[loop[cut]];i;i=nx[i])
				if (to[i]==loop[cut-1])
					forbid[i]=1;
			for (int i=h[loop[cut-1]];i;i=nx[i])
				if (to[i]==loop[cut])
					forbid[i]=1;
		}
		dfs(1,0);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
