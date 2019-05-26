#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<iomanip>
using namespace std;

#define maxn 50050
#define maxm 50050
#define inf 0x3f3f3f3f

int l=1,r=inf,mid,minn=inf,n,m,head[maxn],total,d1[maxn],d2[maxn],ans=-inf;
int value[maxm];
bool visit[maxn],type,type2;
struct Edge
{
	int start,end,value,next;
}edge[maxm<<1];

inline void insert(int u,int v,int w)
{
	edge[++total].start = u;
	edge[total].end = v;
	edge[total].value = w;
	edge[total].next = head[u];
	head[u] = total;
}

inline void input()
{
	memset(head,0,sizeof(head));
	total=0;
	type = type2 = true;
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<n;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		if(u > v)
			swap(u,v);
		insert(u,v,w);
		insert(v,u,w);
		minn = ((w < minn) ? w : minn);
		type = (type && v == u+1);
		type2 = (type2 && u == 1);
		value[i] = w;
	}
	return;
}

void dp(int now)
{
	bool son = false;
	int i,v;
	d1[now] = d2[now] = -inf;
	for(i=head[now],v=edge[i].end ;i;i=edge[i].next,v=edge[i].end)
	{
		if(!visit[v])
		{
			visit[v] = true;
			son = true;
			dp(v);
			if(d1[v]+edge[i].value > d1[now])
			{
				d2[now] = d1[now];
				d1[now] = d1[v]+edge[i].value;
			}
			else if (d1[v]+edge[i].value > d2[now])
				d2[now] = d1[v]+edge[i].value;
		}
	}
	if(!son)
		d1[now] = d2[now] = 0;
}

int sum;

void dfs(int now,int rest)
{
	if(rest >= mid)
		++sum,rest = 0;
	int i,v;
	for(i=head[now],v=edge[i].end ;i;i=edge[i].next,v=edge[i].end)
		if(!visit[v])
		{
			visit[v] = true;
			dfs(v,rest+edge[i].value);
		}
}

bool check()
{
	memset(visit,false,sizeof(visit));
	visit[1] = true;
	sum = 0;
	dfs(1,0);
	return sum >= m;
}

bool cmp(int a,int b)
{
	return a > b;
}

bool check2()
{
	int i=1,res=0;
	while(value[i] >= mid && i < n)
	{
		++res;
		++i;
	}
	while(value[i]+value[i+1] >= mid && i < n)
	{
		++res;
		i += 2;
	}
	return res >= m;
}

bool check3()
{
	memset(visit,false,sizeof(visit));
	visit[1] = true;
	sum=0;
	dfs(1,0);
	return sum >= m;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	input();
	if(m == 1)
	{
		memset(visit,false,sizeof(visit));
		visit[1]  = true;
		dp(1);
		for(int i=1;i<=n;++i)
			ans = max(ans,d1[i]+d2[i]);
		printf("%d\n",ans);
	}
	else if(m == n-1)
		printf("%d\n",minn);
	else if(type)
	{
		while(l<=r)
		{
			mid = l + ((r-l)>>1);
			if(check())
			{
				ans = mid;
				l = mid+1;
			}
			else
				r = mid-1;
		}
		printf("%d\n",ans);
	}
	else if(type2)
	{
		sort(value+1,value+n,cmp);
		while(l<=r)
		{
			mid = l + ((r-l)>>1);
			if(check2())
			{
				ans = mid;
				l = mid+1;
			}
			else
				r = mid-1;
		}
		printf("%d\n",ans);
	}
	else
	{
		while(l<=r)
		{
			mid = l + ((r-l)>>1);
			if(check3())
			{
				ans = mid;
				l = mid+1;
			}
			else
				r = mid-1;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
