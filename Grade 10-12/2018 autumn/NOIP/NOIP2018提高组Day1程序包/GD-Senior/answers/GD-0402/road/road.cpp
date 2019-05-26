#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int lowbit(int x)
{
	return x&-x;
}
int s[110000];
int n;
void add(int x,int k)
{
	while(x<=n+1)
	{
		s[x]+=k;
		x+=lowbit(x);
	}
}
int getsum(int x)
{
	int ret=0;
	while(x)
	{
		ret+=s[x];
		x-=lowbit(x);
	}
	return ret;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		add(i,x);add(i+1,-x);
	}
	int ans=0;
	bool bk=true;
	while(bk)
	{
		bk=false;
		int minn=999999999,last=0;
		for(int i=1;i<=n+1;i++)
		{
			int x=getsum(i);
			if(x==0)
			{
				if(last!=i-1)
				{
					add(last+1,-minn);
					add(i,minn);
					ans+=minn;
					minn=999999999;
				}
				last=i;
			}
			else if(x!=0)
			{
				minn=min(minn,x);
				bk=true;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
