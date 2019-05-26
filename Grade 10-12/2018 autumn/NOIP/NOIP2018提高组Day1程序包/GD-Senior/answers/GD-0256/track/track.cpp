#include<cstdio>
using namespace std;
const int N=50010;
int head[N],next[N*2][3],tot=0;
bool vis[N];
int max=0,min=100000000;
int index=0;
long long sum=0;
int n,m;
int a[N],cnt=0;
void connect(int,int,int);
void dfs(int,int);
void dfs2(int);
int check(long long);
void dfs3(int);
int check2(long long);
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int flag=1;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		connect(u,v,w);
		if(w<min) min=w;
		sum+=w;
		if(u!=1&&v!=1) flag=0;
	}
	if(m==1)
	{
		vis[1]=1;
		dfs(1,0);
		vis[1]=0;
		int x=index;
		max=0;
		vis[x]=1;
		dfs(x,0);
		printf("%d\n",max);
	}
	else if(m==n-1)
	{
		printf("%d\n",min);
	}
	else if(flag==1)
	{
		vis[1]=1;
		dfs3(1);
		vis[1]=0;
		long long l=1,r=sum;
		sort(a+1,a+1+n);
		while(l<r)
		{
			long long mid=(l+r)/2;
			if(check2(l))
			{
				if(mid==l)
					break;
				else l=mid;
			}
			else r=mid-1;
		}
		printf("%lld\n",l);
	}
	else
	{
		vis[1]=1;
		dfs(1,0);
		vis[1]=0;
		int x=index;
		vis[x]=1;
		dfs2(x);
		vis[x]=0;
		long long l=1,r=sum;
		while(l<r)
		{
			long long mid=(l+r)/2;
			if(check(mid))
			{
				if(mid==l)
					break;
				else l=mid;
			}
			else r=mid-1;
		}
		printf("%lld\n",l);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
int check2(long long mid)
{
	int p=m;
	int num=cnt;
	while(a[num]>=mid&&num>0)
	{
		num--;
		p--;
		if(p==0) return 1;
	}
	while(p--)
	{
		int x1;
		int flag=1;
		for(int i=num;i>=1;i--)
		{
			if(vis[i]) continue;
			vis[i]=1;
			x1=a[i];
			break;
		}
		for(int i=1;i<=num;i++)
		{
			if(vis[i]) continue;
			if(a[i]+x1>=mid)
			{
				vis[i]=1;
				flag=0;
			}
		}
		if(flag) return 0;
	}
	return 1;
}
void dfs3(int x)
{
	for(int p=head[x];p;p=next[p][0])
	{
		if(vis[next[p][1]]) continue;
		vis[next[p][1]]=1;
		a[++cnt]=next[p][2];
		dfs3(next[p][1]);
		vis[next[p][1]]=0;
	}
}
int check(long long mid)
{
	long long temp=0;
	int p=m;
	for(int i=1;i<=cnt;i++)
	{
		temp+=a[i];
		if(temp>=mid)
		{
			p--;
			temp=0;
		}
		if(p<=0)
		return 1;
	}
	return 0;
}
void dfs2(int x)
{
	for(int p=head[x];p;p=next[p][0])
	{
		if(vis[next[p][1]]) continue;
		a[++cnt]=next[p][2];
		vis[next[p][1]]=1;
		dfs2(next[p][1]);
		vis[next[p][1]]=0;
	}
}
void dfs(int x,int depth)
{
	if(depth>max)
	{
		max=depth;
		index=x;
	}
	for(int p=head[x];p;p=next[p][0])
	{
		if(vis[next[p][1]]) continue;
		vis[next[p][1]]=1;
		dfs(next[p][1],depth+next[p][2]);
		vis[next[p][1]]=0;
	}
}
void connect(int u,int v,int w)
{
	next[++tot][0]=head[u];
	head[u]=tot;
	next[tot][1]=v;
	next[tot][2]=w;
	next[++tot][0]=head[v];
	head[v]=tot;
	next[tot][1]=u;
	next[tot][2]=w;
}
