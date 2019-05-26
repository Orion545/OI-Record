#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
struct edge{int x,y,d,next;};
edge s[111000];
int first[51100];
int a[51100];
int f[51100];
int fa[51100];
int n,m;
int len=0;
bool tf=false;
int ans=0;
int minn=10000;

void ins(int x,int y,int d)
{
	len++;
	s[len].x=x;s[len].y=y;s[len].d=d;
	s[len].next=first[x];first[x]=len;
}

void dfs(int x)
{
	for (int i=first[x];i;i=s[i].next)
	{
		int y=s[i].y;
		if (y!=fa[x])
		{
			fa[y]=x;
			dfs(y);
		}
	}
}

void dfs1(int x)
{
	int max1=0,max2=0;
	for (int i=first[x];i;i=s[i].next)
	{
		int y=s[i].y;
		if (y!=fa[x])
		{
			if (f[y]==0) dfs1(y);
			if (f[y]+s[i].d>max1)
			{
				max2=max1;
				max1=f[y]+s[i].d;
			}
		}
	}
	f[x]=max1;
	if (max1+max2>ans) ans=max1+max2;
}

bool pd(int x)
{
	int c=0,t=0;
	for (int i=1;i<n;i++)
	{
		t=t+a[i];
		if (t>=x)
		{
			t=0;
			c++;
		}
	}
	if (c>=m) return true;
	return false;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int l=0,r=0;
	scanf("%d %d",&n,&m);
	for (int i=1;i<n;i++)
	{
		int x,y,d;
		scanf("%d %d %d",&x,&y,&d);
		ins(x,y,d);
		ins(y,x,d);
		if (y!=x+1) tf=true;
		r=r+d;
		if (d<minn) minn=d;
	}
	if (tf==false)
	{
		for (int i=1;i<=len;i=i+2)
			a[s[i].x]=s[i].d;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (pd(mid))
			{
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
	else if (m==1)
	{
		memset(f,0,sizeof(f));
		dfs(1);
		dfs1(1);
		printf("%d\n",ans);
	}
	else if (m==n-1) printf("%d\n",minn);
	else printf("%d\n",r/m-1);
}
/*
9 3
1 2 6
2 3 3
3 4 5
4 5 10
6 2 4
7 2 9
8 4 7
9 4 4
*/
