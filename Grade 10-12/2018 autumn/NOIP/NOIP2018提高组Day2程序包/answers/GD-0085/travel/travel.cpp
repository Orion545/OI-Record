#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5005;
int n,m,x,y,tot,num,a[N][N],b[N][N],c[N],d[N],bo[N];
bool bz[N];
bool pd()
{
	if (num!=n) return 0;
	for (int i=1;i<=n;i++)
	{
		if (c[i]<d[i]) return 1;
		if (c[i]>d[i]) return 0;
	}
}
void dg(int x)
{
	c[++num]=x;
	for (int i=1;i<=a[x][0];i++)
	if (!bz[b[x][i]] && bo[a[x][i]]!=bo[x])
	{
		bo[a[x][i]]=bo[x];
		dg(a[x][i]);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) 
	{
		scanf("%d%d",&x,&y);
		a[x][++a[x][0]]=y;
		a[y][++a[y][0]]=x;
		b[x][a[x][0]]=i;
		b[y][a[y][0]]=i;
	}
	for (int i=1;i<=n;i++) sort(a[i]+1,a[i]+a[i][0]+1);
	if (m==n-1)
	{
		num=0;
		bo[1]=1;
		dg(1);
		for (int i=1;i<=n;i++) printf("%d ",c[i]);
		return 0;
	}
	d[1]=n+1;
	for (int i=1;i<=m;i++)
	{
		bz[i]=1;
		num=0;
		bo[1]=i;
		dg(1);
		if (pd())
		{
			for (int j=1;j<=n;j++) d[j]=c[j];
		}
		bz[i]=0;
	}
	for (int i=1;i<=n;i++) printf("%d ",d[i]);
	return 0;
}
