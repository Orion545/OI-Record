#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=5e4+5,MAXM=MAXN<<1;
const int INF=0x7fffffff;

int head[MAXM],nxt[MAXM],v[MAXM],w[MAXM],cnt;

int depth[MAXN],dad[MAXN],dp[MAXN];

int root;
int n,m;

inline void Addline(int x,int y,int z)
{
	v[cnt]=y,w[cnt]=z;
	nxt[cnt]=head[x],head[x]=cnt++;
	
	return;
}

inline void Make(int x,int from)
{
	depth[x]=depth[from]+1,dad[x]=from;
	for(int i=head[x];~i;i=nxt[i])
		if(v[i]!=from)
			dp[v[i]]=dp[x]+w[i],Make(v[i],x);
	
	return;
}

int d=0,dis[MAXN];

inline void DFS(int x,int from)
{
	int max1=0,max2=0;
	for(int i=head[x];~i;i=nxt[i])
		if(v[i]!=from)
		{
			DFS(v[i],x);
			if(dis[v[i]]+w[i]>=max1)
				max2=max1,max1=dis[v[i]]+w[i];
			else if(dis[v[i]]+w[i]>=max2)
				max2=dis[v[i]]+w[i];
		}
	
	d=max(d,max1+max2);
	dis[x]=max1;
	
	return;
}

inline void SubWork1(void)
{
	DFS(root,0);
	printf("%d\n",d);
	
	return;
}

struct Road
{
	int x,y,dis;
}road[200*200+200000];
int tail;

inline int Cal(int x,int y)
{
	int ans=0,X=x,Y=y;
	
	if(depth[x]<depth[y])
		swap(x,y);
	
	while(depth[x]!=depth[y])
		x=dad[x];
	
	while(x!=y)
		x=dad[x],y=dad[y];
	
	return dp[X]+dp[Y]-2*dp[x];
}

inline bool Compare(Road a,Road b)
{
	return a.dis<b.dis;
}

int tag[1005],id;

inline void Mark(int x,int y)
{
	if(depth[x]<depth[y])
		swap(x,y);
	
	while(depth[x]!=depth[y])
		tag[x]=id,x=dad[x];
	while(dad[x]!=dad[y])
		tag[x]=id,tag[y]=id,x=dad[x],y=dad[y];
	
	return;
}

inline bool Check(int x,int y)
{
	if(depth[x]<depth[y])
		swap(x,y);
	
	while(depth[x]!=depth[y])
	{
		if(tag[x]==id)
			return false;
		x=dad[x];
	}
	
	while(dad[x]!=dad[y])
	{
		if(tag[x]==id||tag[y]==id)
			return false;
		x=dad[x],y=dad[y];
	}
		
	return true;
}

inline bool Judge(int x)
{
	id++;
	Mark(road[x].x,road[x].y);
	
	int ans=0;
	for(int i=x+1;i<=tail;i++)
	{
		if(ans==m-1)
			return true;
		if(Check(road[i].x,road[i].y))
			ans++,Mark(road[i].x,road[i].y);
	}
	
	return false;
}

inline void SubWork2(void)
{
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			road[++tail].x=i,road[tail].y=j,road[tail].dis=Cal(i,j);
	
	sort(road+1,road+tail+1,Compare);
	
	int l=1,r=tail,ans=0;
	while(l<=r)
	{
		int mid=((l+r)>>1);
		if(Judge(mid))
			ans=mid,l=mid+1;
		else
			r=mid-1;
	}
	
	cout<<road[ans].dis<<endl;
	
	return;	
}

signed main(void)
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,-1,sizeof head);
	
	cin>>n>>m;
	for(int i=1,x,y,z;i<n;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		Addline(x,y,z);
		Addline(y,x,z);
	}
	
	Make(root=rand()%n+1,0);
	
	if(m==1)
		SubWork1();
	else if(n<=1000)
		SubWork2();
	
	return 0;
}
