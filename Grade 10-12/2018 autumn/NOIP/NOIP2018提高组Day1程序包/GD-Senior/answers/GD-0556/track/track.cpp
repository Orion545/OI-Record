#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int i,j,n,m,le,maxx,l1,r1,mid,l2,js,x,y,c,ans;
int l[50001],f[30001],a[50001];
bool b,b1;
struct edge
{
	int y,c,n;
}e[99998];
struct edge1
{
	int x,y,c;
}e1[50000];
inline void ae(int x,int y,int c)
{
	e[++le].y=y;
	e[le].c=c;
	e[le].n=l[x];
	l[x]=le;
	return;
}
inline bool comp(edge1 a,edge1 b)
{
	return a.x<b.x;
}
int dfs1(int x)
{
	int maxx,max1=0,max2=0;
	for (int i=l[x];i^-1;i=e[i].n)
	{
		int y=e[i].y;
		if (y^f[x])
		{
			f[y]=x;
			maxx=dfs1(y);
			if (max1<maxx+e[i].c)
			{
				max2=max1;
				max1=maxx+e[i].c;
			}
			else
				if (max2<maxx+e[i].c) max2=maxx+e[i].c;
		}
	}
	if (ans<max1+max2) ans=max1+max2;
	return max1;
}
int main()
{
	freopen("track.in","rb",stdin);
	freopen("track.out","wb",stdout);
	scanf("%d%d\n",&n,&m);
	if (m^1)
	{
		le=-1;
		memset(l,-1,sizeof(l));
		maxx=0;
		b=true;
		b1=true;
		for (i=1;i<n;++i)
		{
			scanf("%d%d%d\n",&x,&y,&c);
			e1[i].x=x;
			e1[i].y=y;
			e1[i].c=c;
			ae(x,y,c);
			ae(y,x,c);
			maxx+=c;
			if (b)
				if (x^1) b=false;
				else a[i]=c;
			if (b1)
				if (y^(x+1)) b1=false;
		}
		if (b)
		{
			if ((n-1)>>1>=m)
			{
				ans=0x3F3F3F3F;
				c=n-2*m-1;
				for (i=1;i<=m;++i)
					if (ans>a[i+c]+a[n-i]) ans=a[i+c]+a[n-i];
			}
			else
			{
				ans=0x3F3F3F3F;
				c=2*n-2*m-1;
				for (i=1;i<=n-m-1;++i)
					if (ans>a[i]+a[c-i]) ans=a[i]+a[c-i];
				for (i<<=1,--i;i<n;++i) 
					if (ans>a[i]) ans=a[i];
			}
			printf("%d\n",ans);
		}
		else
			if (b1)
			{
				sort(e1+1,e1+n,comp);
				l1=0;
				r1=maxx;
				while (l1<=r1)
				{
					mid=(l1+r1)>>1;
					js=0;
					l2=0;
					for (i=1;i<n;++i)
					{
						l2+=e1[i].c;
						if (l2>=mid)
						{
							l2=0;
							++js;
						}
					}
					if (l2>=mid) ++js;
					if (js>=m) l1=mid+1;
					else r1=mid-1;
				}
				printf("%d\n",l1-1);
			}
	}
	else
	{
		le=-1;
		memset(l,-1,sizeof(l));
		for (i=1;i<n;++i)
		{
			scanf("%d%d%d\n",&x,&y,&c);
			ae(x,y,c);
			ae(y,x,c);
		}
		f[1]=0;
		ans=0;
		dfs1(1);
		printf("%d\n",ans);
	}
	return 0;
}
