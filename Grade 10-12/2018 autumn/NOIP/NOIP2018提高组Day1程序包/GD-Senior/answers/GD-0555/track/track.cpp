#include<cstdio>
#include<algorithm>
using namespace std;
int nxt[100010],last[50010],num[100010],to[100010];
int du[50010];
int a[50010];
long long f[50010];
int tot;
void insert(int x,int y,int z)
{
	tot++;
	nxt[tot]=last[x];
	last[x]=tot;
	num[tot]=z;
	to[tot]=y;
}
long long ans=0;
void dfs(int x,int fa)
{
	long long max1=0; long long max2=0;
	for (int i=last[x];i!=0;i=nxt[i])
		if (to[i]!=fa)
		{
			f[to[i]]=num[i];
			dfs(to[i],x);
			if (f[to[i]]>max1) max2=max1,max1=f[to[i]]; else
			if (f[to[i]]>max2) max2=f[to[i]];
		}
	f[x]+=max1;
	if (f[x]>ans) ans=f[x];
	if (max1+max2>ans) ans=max1+max2;
}
bool cmp(int x,int y)
{
	return (x>y);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int x,y,z;
	bool bz1=true;
	bool bz2=true;
	for (int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if (x!=1) bz1=false;
		if (y!=x+1) bz2=false;
		insert(x,y,z);
		insert(y,x,z);
		du[x]++;
		du[y]++;
	}
	if (m==1)
	{
		dfs(1,0);
		printf("%lld\n",ans);
		return 0;
	}
	if (bz1)
	{
		int len=0;
		for (int i=last[1];i!=0;i=nxt[i]) a[++len]=num[i];
		sort(a+1,a+len+1,cmp);
		long long ans1=1000000000000LL;
		if (n-1>=2*m)
		{	
			for (int i=1;i<=m;i++)
				if (a[i]+a[2*m-i+1]<ans1) ans1=a[i]+a[2*m-i+1];
			printf("%lld\n",ans1);
			return 0;
		} else
		{
			for (int i=1;i<=2*m-(n-1);i++) if (a[i]<ans1) ans1=a[i];
			int j=n-1;
			for (int i=2*m-(n-1)+1;i<j;i++)
			{
				if (a[i]+a[j]<ans1) ans1=a[i]+a[j];
				j--;
			}
			printf("%lld\n",ans1);
			return 0;
		}
	}
	return 0;
}
