#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=100010;
int n,d[maxn];
int ans,sign;

int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		d[i]=read();
	}
	ans=d[1];
	sign=d[1];
	//printf("%d\n",ans);
	for(int i=2;i<=n;i++)
	{
		if(d[i-1]>=d[i])
		{
			sign=d[i];
			continue;
		}
		ans+=(d[i]-sign);
		sign=d[i];
	}
	printf("%d\n",ans);
	return 0;
}
