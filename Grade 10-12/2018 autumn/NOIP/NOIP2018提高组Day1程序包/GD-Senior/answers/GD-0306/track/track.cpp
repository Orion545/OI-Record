#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

#define N 50050
#define INF 0x7ffffff

struct note
{
	int y,c,next;
};

note side[N*2];
int last[N],t[N],dis[N],fa[N];
int n,m,l=0;

void add(int x,int y,int c)
{
	l++;
	side[l].y=y; side[l].c=c;
	side[l].next=last[x];
	last[x]=l;
}

void init()
{
	scanf("%d%d",&n,&m);
	int x,y,c;
	for (int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		add(x,y,c);
		add(y,x,c);
	}
}

void dfs(int x)
{
	for (int i=last[x];i!=0;i=side[i].next)
	{
		int j=side[i].y;
		if (j==fa[x]) continue;
		fa[j]=x;
		dis[j]=dis[x]+side[i].c;
		dfs(j);
	}
}

queue<int> Q;
void spfa(int x)
{
	memset(t,0,sizeof(t));
	dis[x]=0;  t[x]=1;
	Q.push(x);
	while (!Q.empty())
	{
		int now=Q.front(); Q.pop();
		for (int i=last[now];i!=0;i=side[i].next)
		{
			int j=side[i].y;
			if (t[j]==1) continue;
			t[j]=1;
			dis[j]=dis[now]+side[i].c;
			Q.push(j);
		}
	}
}

void sol1()
{
	int s,ans;
	spfa(1);
	s=1;
	for (int i=2;i<=n;i++)
	  if (dis[s]<dis[i]) s=i;
	spfa(s);
	ans=1;
	for (int i=2;i<=n;i++)
	  if (dis[ans]<dis[i]) ans=i;
	printf("%d\n",dis[ans]);
}

bool pd2()
{
	for (int i=2;i<=l;i+=2)
	  if (side[i].y!=1) return false;
	return true;
}

bool comp(int x,int y)
{
	return x>y;
}

void sol2()
{
	for (int i=1;i<=n-1;i++)
	  t[i]=side[i*2].c;
	sort(t+1,t+n,comp);
	int ans=t[1]+t[2*m];
	for (int i=2;i<=m;i++)
	  ans=min(ans,t[i]+t[2*m-i+1]);
	printf("%d\n",ans);
}

bool pd3()
{
	for (int i=2;i<=n;i++)
	  if (fa[i]!=i-1) return false;
	return true;
}

bool pd(int x)
{
	int s=0,p=0; 
	for (int i=2;i<=n;i++)
	{
		s+=dis[i]-dis[i-1];
		if (s>=x) {s=0; p++;}
	}
	if (p>=m) return true;
	  else return false;
}

void sol3()
{
	int l,r,mid,ans=0;
	l=1; r=n*10000;
	while (l<=r)
	{
		mid=(l+r)/2;
		if (pd(mid)==true) {ans=max(ans,mid); l=mid+1;}
		  else r=mid-1;
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	init();
	dis[1]=0; fa[1]=0;
	dfs(1);
	if (m==1) {sol1(); return 0;}
	if (pd2()==true) {sol2(); return 0;}
	if (pd3()==true) {sol3(); return 0;}
	return 0;
}


