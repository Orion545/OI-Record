#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char s=getchar();
	while(s>'9'||s<'0')
	{
		if(s=='-') f=-1;
		s=getchar();
	}
	while(s<='9'&&s>='0') x=x*10+s-48,s=getchar();
	return x*f;
}
struct node{int x,y,c,next;}a[110000],b[51000];int len=0,last[110000];
void ins(int x,int y,int c)
{
	++len;
	a[len].x=x;a[len].y=y;a[len].c=c;a[len].next=last[x];last[x]=len;
}
int d1[51000],d2[51000],d[51000],sum[51000],n,m;
bool v[51000];
priority_queue<int,vector<int>,greater<int> >q;
bool cmp(node x,node y){return x.c>y.c;}
bool cmp1(int x,int y){return x>y;}
void dfs(int x)
{
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(!v[y])
		{
			v[y]=1;
			dfs(y);
			d1[x]=max(d1[x],d2[x]+a[k].c+d2[y]);
			d2[x]=max(d2[x],d2[y]+a[k].c);
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();bool pd1=0,pd2=0;
	for(int i=1;i<n;i++)
	{
		int x,y,c;scanf("%d%d%d",&x,&y,&c);
		b[i].x=x;b[i].y=y;b[i].c=c;
		if(x!=1&&y!=1) pd1=1;
		if(x!=y-1) pd2=1;
		else d[y]=c;
		ins(x,y,c);ins(y,x,c);
	}
	if(!pd1)
	{
		sort(b+1,b+n,cmp);
		for(int i=1;i<n;i++)
		{
			bool pd=0;
			for(int j=i+1;j<n;j++)
			{
				if(q.size()<m) pd=1,q.push(b[i].c+b[j].c);
				else
				{
					if(q.top()<b[i].c+b[j].c) pd=1,q.pop(),q.push(b[i].c+b[j].c);
					else continue;
				}
			}
			if(!pd) break;
		}
		printf("%d\n",q.top());
	}
	else if(!pd2)
	{
		sum[1]=0;
		for(int i=2;i<=n;i++) sum[i]=sum[i-1]+d[i];
		for(int pp=n;pp>=1;pp--)
		{
			int ed=n-pp+1;
			for(int i=1;i<=ed;i++)
			{
				int r=i+pp-1,c=sum[r]-sum[i];
				if(q.size()>=m)
				{
					if(q.top()<c) q.pop(),q.push(c);
					else continue;
				}
				else q.push(c);
			}
			if(q.size()==m) break;
		}
		printf("%d\n",q.top());
	}
	else if(m==1)
	{
		v[1]=1;dfs(1);
		int maxx=0;
		for(int i=1;i<=n;i++) maxx=max(maxx,d1[i]);
		printf("%d\n",maxx);
	}
	else 
	{
		v[1]=1;dfs(1);
		sort(d1+1,d1+n+1,cmp1);
		printf("%d\n",d1[m]);
	}
	return 0;
}
