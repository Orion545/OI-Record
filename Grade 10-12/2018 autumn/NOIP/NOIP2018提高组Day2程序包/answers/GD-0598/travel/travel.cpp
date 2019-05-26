#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int n,m;
struct node{int x,y,next;};
node s[10010];
int fa[5010];
int first[5010];
int len=0;
int ed=1;
int ans[5010];
bool v[5010],t[5010];
int p[5010];
int sum[5010];
int hu[5010];
int g=1;
bool gg=false;

struct hz{
	int x;
	bool operator <(const hz &hh) const
	{
		return x>hh.x;
	}
};
priority_queue <hz> a;

void dfs(int x);


void ins(int x,int y)
{
	len++;
	s[len].x=x;s[len].y=y;
	s[len].next=first[x];first[x]=len;
}

void work(int x)
{
	bool tf=false;
	hz c;
	c.x=x;
	a.push(c);
	while (a.size())
	{
		int min=5001;
		int xx=a.top().x;
		if (tf==true)
		{
			ed++;ans[ed]=xx;v[xx]=true;
		}
		else tf=true;
		a.pop();
		for (int i=first[xx];i;i=s[i].next)
		{
			int y=s[i].y;
			if (y!=fa[x] && v[y]==false)
			{
				if (t[y]==true)
				{
					hz k;
					k.x=y;
					a.push(k);
					t[y]=false;
				}
				else if (y<min) min=y;
			}
		}
		if (min<a.top().x)
		{
			v[min]=true;
			dfs(min);
		}
	}
	while (1)
	{
		int min=5001,baba;
		for (int i=1;i<=g;i++)
		{
			for (int k=first[hu[i]];k;k=s[k].next)
			{
				int y=s[k].y;
				if (!v[y] && !t[y]) if (y<min) min=y,baba=hu[i];
			}
		}
		if (min==5001) break;
		else
		{
			v[min]=true;fa[min]=baba;
			ans[++ed]=min;
			dfs(min);
		}
	}
}

void dfs(int x)
{
	if (ed==n)
	{
		for (int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		exit(0);
	}
	int min=5001;
	for (int i=first[x];i;i=s[i].next)
	{
		int y=s[i].y;
		if (y!=fa[x] && v[y]==false)
		{
			if (y<min) min=y;
		}
	}
	if (min<5001)
	{
		ed++;ans[ed]=min;
		v[min]=true;fa[min]=x;
		if (t[min]==true && gg==false)
		{
			gg=true;
			work(min);
		}
		else dfs(min);
	}
	else dfs(fa[x]);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y,d;
		scanf("%d %d",&x,&y);
		ins(x,y);
		ins(y,x);
		sum[x]++;sum[y]++;
	}
	ans[1]=1;
	if (m==n-1)
	{
		v[1]=true;fa[1]=1;
		dfs(1);
	}
	else
	{
		for (int k=1;k<=n;k++)
		{
			int min=999999,x;
			for (int i=1;i<=n;i++)
				if (sum[i]!=0 && sum[i]<min) min=sum[i],x=i;
			if (min>=2)
			{
				hu[1]=x;t[x]=true;
				for (int i=1;i<=n;i++)
					if (sum[i]==2 && i!=x)
					{
						g++;hu[g]=i;
						t[i]=true;
					}
				break;
			}
			else
			{
				for (int i=first[x];i;i=s[i].next)
				{
					int y=s[i].y;
					sum[x]--;sum[y]--;
				}
			}
		}
		v[1]=true;fa[1]=1;
		dfs(1);
		for (int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	}
	return 0;
}
/*
6 6
1 3
2 3
2 5
3 4
4 5
4 6
*/
