#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
long long ans=0,n,d[1000010];
bool pd = false;
void work(LL l,LL r,LL minn)
{
	int ls=0,rs=0;
	bool pdd=0;
	ans+=minn;
	if(l==r) return ;
	for(int i=l;i<=r;i++)
	{
		d[i]-=minn;
		if(pdd==0&&d[i]!=0)
		{
			pdd=1;
			ls=i;
		}
	}
	if(ls==0) return ;
	minn=99999999;
	for(int i=ls;i<=r;)
	{
		if(d[i]!=0)
		{
			minn=min(minn,d[i]);
		}
		if(d[i+1]==0)
		{
			work(ls,i,minn);
			minn=9999999999;
			i++;
			while(d[i]==0 && i<=n) i++;
			ls=i;
		}
		else i++;
	}
}
long long minn=999999999,l,r;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld" , &n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		minn=min( d[i] , minn );
	}
	d[n+1] = 0;
	ans=minn;
	for(int i=1;i<=n;i++)
	{
		d[i]-=minn;
		if( !pd && d[i]!=0) 
		{
			l=i;
			pd=1;
		}
	}
	 minn=999999999;
	for(int i=l;i<=n;i++)
	{
		if( minn>d[i] && d[i]!=0  ) minn=d[i];
		if(d[ i + 1 ]==0)
		{
			if( l != n+1 )	
			{
				work( l , i , minn );
				minn=9999999999;
				i++;
				while(d[i]==0) i++;
				l=i;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
