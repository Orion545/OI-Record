#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,INF=5e8+10;
struct Tedge{
	int v,w,nxt;
}e[N*2];
queue<int> q;
int dis[N],head[N],a[N],val[N];
int n,m,tot,flag1,flag2;
inline int read()
{
	char ch=getchar();int x=0,f=0;
	for(; ch<'0'||ch>'9' ;ch=getchar())	if(ch=='-')	f=1;
	for(;'0'<=ch&&ch<='9';ch=getchar())	x=(x<<3)+(x<<1)+(ch^48);
	return f?-x:x;
}
void add(int u,int v,int w)
{
	e[++tot]=(Tedge){v,w,head[u]};head[u]=tot;
	e[++tot]=(Tedge){u,w,head[v]};head[v]=tot;
}
int bfs(int s)
{
	memset(dis,-1,sizeof dis);
	int maxx=s;
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		if(dis[u]>dis[maxx])	maxx=u;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if(dis[v]==-1)
			{
				dis[v]=dis[u]+w;
				q.push(v);
			}
		}
	}
	return maxx;
}
void solve1()
{
	int x=bfs(1);
	int y=bfs(x);
	cout<<dis[y]<<endl;
}
int judge(int x)
{
	int cnt=0,sum=0;
	for(int i=1;i<n;i++)
	{
		sum+=a[i];
		if(sum>=x)
		{
			sum=0,cnt++;
		}
	}
	return cnt>=m;
}
void solve2()
{
	int l=0,r=INF;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(judge(mid))	l=mid;
			else		r=mid;
	}
	cout<<l<<endl;
}
int pd(int x)
{
	int i=1,j=n-1,cnt=0;
	while(i<=j)
	{
		if(val[j]>=x)
		{
			j--;
			cnt++;
		}else
		if(val[i]+val[j]>=x&&i!=j)
		{
			i++;
			j--;
			cnt++;
		}else
		i++;
	}
	return cnt>=m;
}
void solve3()
{
	sort(val+1,val+n);
	int l=0,r=INF;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(pd(mid))	l=mid;
			else	r=mid;
	}
	cout<<l<<endl;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);a[u]=w;val[i]=w;
		if(u+1!=v)	flag1=1;
		if(u!=1)	flag2=1;
	}
	if(m==1)	solve1();else
	if(!flag1)	solve2();else
	if(!flag2)	solve3();
	return 0;
}
