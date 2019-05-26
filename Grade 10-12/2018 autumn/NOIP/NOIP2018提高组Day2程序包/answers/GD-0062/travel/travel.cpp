#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <limits>
using namespace std;

int n,m,pos;
int u[5000+1];
int v[5000+1];
int seq[5000+1];
int vis[5000+1];
int flag[5000+1];
int ansseq[5000+1];
int posarr[5000+1];
int seqarr[5000+1][5000+1];
vector<vector<int> > e;

int cmp(int x,int y)
{
	return x<y;
}

void dfs1(int now,int last)
{
	seq[++pos]=now;
	if (e[now].size()==1)
	{
		if (e[now][0]==last)
			return;
	}
	sort(&e[now][0],&e[now][e[now].size()],cmp);
	for (int i=0;i<e[now].size();i++)
		if (e[now][i]!=last)
			dfs1(e[now][i],now);
}

void work1()
{
	e.clear();
	e.resize(n+1);
	for (int i=1;i<=m;i++)
	{
		e[u[i]].push_back(v[i]);
		e[v[i]].push_back(u[i]);
	}
	pos=0;
	dfs1(1,0);
	for (int i=1;i<=pos;i++)
		printf("%d ",seq[i]);
	printf("\n");
}

void dfs2(int now,int last,int num,int &flag)
{
	if (vis[now]==1||e[now].size()==0)
	{
		flag=0;
		return;
	}
	vis[now]=1;
	seqarr[num][++posarr[num]]=now;
	if (e[now].size()==1)
	{
		if (e[now][0]==last)
			return;
	}
	sort(&e[now][0],&e[now][e[now].size()],cmp);
	for (int i=0;i<e[now].size()&&flag;i++)
	{
		if (e[now][i]!=last)
			dfs2(e[now][i],now,num,flag);
	}
}

int cmpseq(int *a,int *b,int maxpos) //<
{
	for (int i=1;i<=maxpos;i++)
		if (a[i]>b[i])
			return 0;
		else if (a[i]<b[i])
			return 1;
	return 1;
}

void work2()
{
	int maxpos=0;
	memset(posarr,0,sizeof(posarr));
	for (int i=1;i<=m;i++)
	{
		e.clear();
		e.resize(n+1);
		for (int j=1;j<=m;j++)
			if (i!=j)
			{
				e[u[j]].push_back(v[j]);
				e[v[j]].push_back(u[j]);
			}
		flag[i]=1;
		memset(vis,0,sizeof(vis));
		dfs2(1,0,i,flag[i]);
		if (flag[i])
			maxpos=max(maxpos,posarr[i]);
	}
	for (int i=1;i<=maxpos;i++)
		ansseq[i]=(numeric_limits<int>::max)();
	for (int i=1;i<=m;i++)
	{
		if (flag[i]&&posarr[i]==maxpos)
			if (cmpseq(seqarr[i],ansseq,maxpos))
				memcpy(ansseq,seqarr[i],sizeof(ansseq));
	}
	for (int i=1;i<=maxpos;i++)
		printf("%d ",ansseq[i]);
	printf("\n");
}

void work()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d",&u[i],&v[i]);
	if (m==n-1)
		work1();
	else
		work2();
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
