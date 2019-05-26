#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define min(a,b) (((a)<(b))?(a):(b))
#define INF ((~(1<<31))/3)
#define maxn 50010
using namespace std;
vector<long>b[maxn];
vector<long>w[maxn];
long n,m,ans;

long spfa(long s)
{
	queue<long>q;
	bool v[maxn];
	memset(v,0,sizeof(v));
	long dis[maxn],i,now;
	for(i=0;i<=n+1;i++) dis[i]=-INF;
	dis[s]=0;
	v[s]=true;
	q.push(s);
	while (!q.empty())
	{
		now=q.front();
		q.pop();
		for(i=0;i<b[now].size();i++)
			if (!v[b[now][i]]&&dis[now]+w[now][i]<dis[b[now][i]])
			{
				dis[b[now][i]]=dis[now]+w[now][i];
				v[b[now][i]]=true;
				q.push(b[now][i]);
				/*if (!v[b[now][i]])
				{
					v[b[now][i]]=true;
					q.push(b[now][i]);
				}*/
			}
		v[b[now][i]]=false;
	}
	long minn=0;
	for(i=1;i<=n;i++)
		minn=min(minn,dis[i]);
	return (-minn);
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	long i,w,x,y;
	scanf("%ld%ld",&n,&m);
	long w1=INF;
	for(i=1;i<n;i++)
	{
		scanf("%ld%ld%ld",&x,&y,&w);
		w1=min(w,w1);
		b[x].push_back(y);
		b[y].push_back(x);
		b[x].push_back(-w);
		b[y].push_back(-w);
	}
	ans=0;
	if (m==1) 
		for(i=1;i<=n;i++)
			if (spfa(i)>ans) ans=spfa(i);
	else 
		printf("%ld\n",w1);
	printf("%ld\n",ans);
	return 0;
}
