#include<cstdio>
#include<cstring>
#include<algorithm>
#define Inf 0x3F3F3F3F
using namespace std;
int n,m,tb,i,qh,qt,x,y,z;
bool b,b1;
int l[5001],q[5001],d[5001],f[5001];
bool v[5001],b2[5001];
struct edge
{
	int e[5001];
}a[5001];
inline void bfs()
{
	qh=0;
	qt=1;
	q[0]=1;
	memset(d,0,sizeof(d));
	d[1]=1;
	f[1]=0;
	b1=true;
	while (qh^qt && b1)
	{
		x=q[qh++];
		for (i=0;i<=l[x];++i)
			if (a[x].e[i]^f[x])
			{
				y=a[x].e[i];
				if (d[y])
				{
					b1=false;
					break;
				}
				d[y]=d[x]+1;
				f[y]=x;
				q[qt++]=y;
			}
	}
	memset(b2,false,sizeof(b2));
	while (d[x]>d[y])
	{
		b2[x]=true;
		x=f[x];
	}
	while (d[x]<d[y])
	{
		b2[y]=true;
		y=f[y];
	}
	while (x^y)
	{
		b2[x]=b2[y]=true;
		x=f[x];
		y=f[y];
	}
	b2[x]=true;
	return;
}
void dfs(int x)
{
	printf("%d ",x);
	if (b && b2[x] && ((l[x]-d[x]==1 && b2[a[x].e[d[x+1]]]) || (l[x]-d[x]==2 && ((a[x].e[d[x+1]]==f[x] && b2[a[x].e[d[x+2]]]) || (a[x].e[d[x+2]]==f[x] && b2[a[x].e[d[x+1]]])))))
	{
		z=f[x];
		while (l[z]==d[z] || (l[z]-d[z]==1 && a[z].e[l[z]]==f[z])) z=f[z];
		z=a[z].e[d[z]+1];
		if (z==f[z])
		{
			z=f[z];
			z=a[z].e[d[z]+2];
		}
		y=a[x].e[0];
		if (y==f[x]) y=a[x].e[1];
		if (z<y)
		{
			b=false;
			return;
		}
	}
	for (int& i=d[x];i<=l[x];++i)
	{
		y=a[x].e[i];
		if (!v[y])
		{
			v[y]=true;
			f[y]=x;
			dfs(y);
		}
	}
	return;
}
int main()
{
	freopen("travel.in","rb",stdin);
	freopen("travel.out","wb",stdout);
	scanf("%d%d\n",&n,&m);
	if (n>m) b=false;
	else b=true;
	memset(l,-1,sizeof(l));
	for (i=1;i<=m;++i)
	{
		scanf("%d%d\n",&x,&y);
		a[x].e[++l[x]]=y;
		a[y].e[++l[y]]=x;
	}
	for (i=1;i<=n;++i) sort(a[i].e,a[i].e+l[i]+1);
	if (b) bfs();
	memset(v,false,sizeof(v));
	v[1]=true;
	memset(d,0,sizeof(d));
	f[1]=0;
	dfs(1);
	printf("\n");
	return 0;
}
