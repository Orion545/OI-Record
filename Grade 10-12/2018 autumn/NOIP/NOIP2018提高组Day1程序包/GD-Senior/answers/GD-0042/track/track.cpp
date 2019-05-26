#include<cstdio>
#define max(a,b) ((a>b)?a:b)
using namespace std;
int i,n,m,x,y,z;
long long l,r,mid,f[60000],g[60000],h[60000],len[100000];
int tov[100000],pre[100000],las[60000];
int Link(int a,int b,int c)
{
	++m;
	tov[m]=b;
	len[m]=c;
	pre[m]=las[a];
	las[a]=m;
}
int dfs(int p,int q)
{
	int i=las[p];
	long long x1=0,x2=0;
	for(;i;i=pre[i])
		if(tov[i]^q)
		{
			dfs(tov[i],p);
			f[p]=max(f[p],f[tov[i]]+len[i]);
			h[p]=max(h[p],h[tov[i]]);
			if(x2<f[tov[i]]+len[i])
			{
				x2=f[tov[i]]+len[i];
				if(x1<x2)
				{
					x2=x1;
					x1=f[tov[i]]+len[i];
				}
			}
		}
	g[p]=x1+x2;
	h[p]=max(max(f[p],g[p]),h[p]);
	return 0;
}
int qsort(int l,int r)
{
	int i=l,j=r,mid=(l+r)>>1;
	long long k;
	while(i<=j)
	{
		while(f[i]<f[mid]) ++i;
		while(f[j]>f[mid]) --j;
		if(i<=j)
		{
			k=f[i];
			f[i]=f[j];
			f[j]=k;
			k=g[i];
			g[i]=g[j];
			g[j]=k;
			k=h[i];
			h[i]=h[j];
			h[j]=k;
			++i;
			--j;
		}
	}
	if(l<j) qsort(l,j);
	if(i<r) qsort(i,r);
	return 0;
}
int check(long long p)
{
	int i=1,j=0,k=0;
	for(;i<n;++i)
		if(h[i]-h[j]>=p)
		{
			++k;
			j=i;
		}
	return (k<m)?0:1;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		for(i=1,m=0;i<n;++i)
		{
			scanf("%d%d%d",&x,&y,&z);
			Link(x,y,z),Link(y,x,z);
		}	
		dfs(1,0);
		printf("%lld",h[1]);
	}
	else
	{
		for(i=1;i<n;++i) scanf("%lld%lld%lld",&f[i],&g[i],&h[i]);
		qsort(1,n-1);
		for(i=1;i<n;++i) h[i]+=h[i-1];
		l=1,r=f[n-1];
		while(l^r)
		{
			mid=(l+r)/2+1;
			if(check(mid)) l=mid;
				else r=mid-1;
		}
		printf("%lld",l);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
