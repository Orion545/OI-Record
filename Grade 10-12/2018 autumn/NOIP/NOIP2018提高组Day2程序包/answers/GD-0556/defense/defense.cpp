#include<cstdio>
#include<cstring>
#define Inf 0x3F3F3F3F
using namespace std;
int n,m,i,x,x1,y,y1,a1,b1,minn,le;
int l[2001],d[2001][2][2],f[2001],a[2001];
char c1,c2;
struct edge
{
	int y,n;
}e[4000];
inline int min(int a,int b)
{
	return a<b?a:b;
}
inline void ae(int x,int y)
{
	e[++le].y=y;
	e[le].n=l[x];
	l[x]=le;
	return;
}
void dfs(int x)
{
	for (int i=l[x];i;i=e[i].n)
	{
		int y=e[i].y;
		if (y^f[x])
		{
			f[y]=x;
			dfs(y);
		}
	}
	return;
}
void dfs1(int x)
{
	for (int i=l[x];i;i=e[i].n)
	{
		int y=e[i].y;
		if (y^f[x]) dfs1(y);
	}
	if (a1==x)
	{
		if (x1)
		{
			d[x][0][1]=a[x];
			for (int i=l[x];i;i=e[i].n)
			{
				int y=e[i].y;
				if (y==f[x]) continue;
				d[x][0][1]+=min(min(d[y][0][0],d[y][0][1]),d[y][1][0]);
				if (d[x][0][1]>Inf)
				{
					d[x][0][1]=Inf;
					break;
				}
			}
			d[x][0][0]=a[x];
			d[x][1][0]=Inf;
		}
		else
		{
			d[x][1][0]=0;
			for (int i=l[x];i;i=e[i].n)
			{
				int y=e[i].y;
				if (y==f[x]) continue;
				d[x][1][0]+=d[y][0][0];
				minn=min(minn,d[y][0][1]-d[y][0][0]);
			}
			d[x][0][0]=d[x][1][0]+minn;
		}
		return;
	}
	if (b1==x)
	{
		if (y1)
		{
			d[x][0][1]=a[x];
			for (int i=l[x];i;i=e[i].n)
			{
				int y=e[i].y;
				if (y==f[x]) continue;
				d[x][0][1]+=min(min(d[y][0][0],d[y][0][1]),d[y][1][0]);
				if (d[x][0][1]>Inf)
				{
					d[x][0][1]=Inf;
					break;
				}
			}
			d[x][0][0]=a[x];
			d[x][1][0]=Inf;
		}
		else
		{
			d[x][1][0]=0;
			minn=Inf;
			for (int i=l[x];i;i=e[i].n)
			{
				int y=e[i].y;
				if (y==f[x]) continue;
				d[x][1][0]+=d[y][0][0];
				if (d[x][1][0]>Inf)
				{
					d[x][1][0]=Inf;
					break;
				}
				minn=min(minn,d[y][0][1]-d[y][0][0]);
			}
			if (minn^Inf) d[x][0][0]=d[x][1][0]+minn;
			if(d[x][0][0]>Inf) d[x][0][0]=Inf;
		}
		return;
	}
	d[x][0][1]=a[x];
	for (int i=l[x];i;i=e[i].n)
	{
		int y=e[i].y;
		if (y==f[x]) continue;
		d[x][0][1]+=min(min(d[y][0][0],d[y][0][1]),d[y][1][0]);
		if (d[x][0][1]>Inf)
		{
			d[x][0][1]=Inf;
			break;
		}
	}
	d[x][1][0]=0;
	minn=Inf;
	for (int i=l[x];i;i=e[i].n)
	{
		int y=e[i].y;
		if (y==f[x]) continue;
		d[x][1][0]+=d[y][0][0];
		if (d[x][1][0]>Inf)
		{
			d[x][1][0]=Inf;
			break;
		}
		minn=min(minn,d[y][0][1]-d[y][0][0]);
	}
	if (minn^Inf) d[x][0][0]=d[x][1][0]+minn;
	if(d[x][0][0]>Inf || minn==Inf) d[x][0][0]=Inf;
	return;
}
int main()
{
	freopen("defense.in","rb",stdin);
	freopen("defense.out","wb",stdout);
	scanf("%d%d %c%c\n",&n,&m,&c1,&c2);
	for (i=1;i<=n;++i) scanf("%d",&a[i]);
	le=0;
	memset(l,0,sizeof(l));
	for (i=1;i<n;++i)
	{
		scanf("%d%d\n",&x,&y);
		ae(x,y);
		ae(y,x);
	}
	memset(f,0,sizeof(f));
	dfs(1);
	for (i=1;i<=m;++i)
	{
		scanf("%d%d%d%d\n",&a1,&x1,&b1,&y1);
		dfs1(1);
		minn=min(d[1][0][0],d[1][0][1]);
		if (minn^Inf) printf("%d\n",minn);
		else printf("-1\n");
	}
	return 0;
}
