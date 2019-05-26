#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
inline int read()
{
	int ret=0;
	char s=getchar();
	while(s>'9'||s<'0')s=getchar();
	while(s>='0'&&s<='9')
	{
		ret=ret*10+s-'0';
		s=getchar();
	}
	return ret;
}
int en,head[100005],tot,sum;
int qs[50005];
int dis[50005];
bool mmp[50005];
bool flag1;
bool flag2;
struct edge
{
	int nex;
	int to;
	int val;
}e[100005];
void add(int fro,int t,int v)
{
	en++;
	e[en].nex=head[fro];
	e[en].to=t;
	e[en].val=v;
	head[fro]=en;
}
bool cmp(int a,int b)
{
	return a>b;
}
int m,n,ai,bi,l,rans;
int nex_l[50005];
bool judge1(int c)
{
	int eg=qs[n-m-1]+qs[n-m];
	if(min(eg,qs[n-m-2])>=c)return true;
	return false;
}
bool judge2(int c)
{
	int now=0;
	int ans=0;
	for(int i=1;i<=n-1;i++)
	{   now+=nex_l[i];
		if(now>=c)
		{
			now=0;ans++;
		}
		if(ans>=m)return true;
	}
	return false;
}
void spfa(int s)
{
	memset(dis,0,sizeof(dis));
	memset(mmp,0,sizeof(mmp));
	queue<int>q;
	dis[s]=0;
	mmp[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int j=head[u];j;j=e[j].nex)
		{
			int v=e[j].to;
			if(dis[v]<=dis[u]+e[j].val&&!mmp[v])
			{
				dis[v]=dis[u]+e[j].val;
				mmp[v]=1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		rans=max(rans,dis[i]);
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n-1;i++)
	{
		ai=read();
		if(ai!=1)flag1=1;
		bi=read();
		if(bi!=ai+1)flag2=1;
		l=read();
		nex_l[ai]=l;
		sum+=l;
		add(ai,bi,l);
		add(bi,ai,l);
	}
	if(!flag1)
	{
		for(int i=head[1];i;i=e[i].nex)
		{
			qs[++tot]=e[i].val;
		}
		sort(qs+1,qs+n,cmp);
		if(m==n-1)
		{
			cout<<qs[n];
			return 0;
		}
		int lef=1;int rig=qs[1]+qs[2];
		while(lef<rig)
		{
			int mid=(lef+rig+1)/2;
			if(judge1(mid))lef=mid;
			else rig=mid-1;
		}
		cout<<lef;
		return 0;
	}
	if(!flag2)
	{
		int lef=1;int rig=sum;
		while(lef<rig)
		{
			int mid=(lef+rig+1)/2;
			if(judge2(mid))lef=mid;
			else rig=mid-1;
		}
		cout<<lef;
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)spfa(i);
		cout<<rans;
		return 0;
	}
	return 0;
}
