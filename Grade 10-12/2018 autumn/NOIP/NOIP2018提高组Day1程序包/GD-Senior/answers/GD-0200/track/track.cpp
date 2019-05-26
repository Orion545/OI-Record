#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long n,m,i,j,k,s,ans,x,y,z,ma,type1,type2;
long long l[100005][3],next[100005],last[50005],tot;
long long dis[50005],bz[50005];
long long a[50005],ll,rr,mid;

void insert(long long x,long long y,long long z)
{
	tot++;
	l[tot][1]=y;
	l[tot][2]=z;
	next[tot]=last[x];
	last[x]=tot;
}

void dg(long long x)
{
	for (int i=last[x];i>0;i=next[i])
	{
		if (bz[l[i][1]]!=1)
		{
			dis[l[i][1]]=dis[x]+l[i][2];
			bz[l[i][1]]=1;
			dg(l[i][1]);
		}
	}	
}

int pd(long long x)
{
	long long i,bz,s;
	bz=0;
	s=0;
	for (i=n;i>=1;i--)
	{
		if (a[i]>=x)
		{
			s++;
		}
		else
		{
			while ((a[bz]+a[i]<x)&&(bz+1<=i))
			{
				bz++;
			}
			if (bz>=i) break;
			s++;
		}
	}
	if (s>=m) return 1;
	else return 0;
}

int pdd(long long x)
{
	long long s=0;
	long long ss=0;
	for (int i=1;i<=n;i++)
	{
		s+=a[i];
		if (s>=x)
		{
			s=0;
			ss++;
		}
	}
	if (ss>=m) return 1;
	else return 0;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	type1=1;
	type2=1;
	for (i=1;i<=n-1;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		if (x!=1) type1=0;
		if (y!=x+1) type2=0;
		insert(x,y,z);
		insert(y,x,z);
		a[i]=z;
	}
	if (type1==1)
	{
		sort(a+1,a+1+n);
		ll=0;
		rr=500000000;
		mid=(ll+rr+1)/2;
		while (ll<rr)
		{
			if (pd(mid))
			{
				ll=mid;
			}
			else
			{
				rr=mid-1;
			}
			mid=(ll+rr+1)/2;
		}
		printf("%lld",mid);
		return 0;
	}
	if (type2==1)
	{
		ll=0;
		rr=500000000;
		mid=(ll+rr+1)/2;
		while (ll<rr)
		{
			if (pdd(mid))
			{
				ll=mid;
			}
			else
			{
				rr=mid-1;
			}
			mid=(ll+rr+1)/2;
		}
		printf("%lld",mid);
		return 0;
	}
	if (m==1)
	{
		bz[1]=0;
		dg(1);
		ma=1;
		for (i=1;i<=n;i++)
		{
			if (dis[ma]<dis[i]) ma=i;
		}
		memset(bz,0,sizeof(bz));
		memset(dis,0,sizeof(dis));
		bz[ma]=1;
		dg(ma);
		for (i=1;i<=n;i++)
		{
			ans=max(ans,dis[i]);
		}
		printf("%lld",ans);
		return 0;
	}
}
