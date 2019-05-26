#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define N 110
using namespace std;
int T,n,sum,a[N];
bool v[N];

bool is_prime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0) return false;
	}
	return x!=1;
}

void solve()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n && j!=i;j++)
		{
			if(a[i]%a[j]==0)
			{
				v[i]=false;
				goto end;
			}
			for(int k=1;k<=n;k++)
			{
				for(int m=1;m*a[j]<=a[i];m++)
				{
					for(int n=1;m*a[j]+n*a[k]<=a[i];n++)
					{
						if(a[i]==m*a[j]+n*a[k])
						{
							v[i]=false;
							goto end;
						}
					}
				}
			}
			for(int k=1;k<=n;k++)
			{
				for(int x=1;x!=k;x++)
				{
					for(int m=1;m*a[j]<=a[i];m++)
					{
						for(int n=1;m*a[j]+n*a[k]<=a[i];n++)
						{
							for(int y=1;m*a[j]+n*a[k]+y*a[x]<=a[i];y++)
							{
								if(a[i]==m*a[j]+n*a[k]+y*a[x])
								{
									v[i]=false;
									goto end;
								}
							}
						}
					}
				}
			}
		}
		end:;
	}
	return;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		sum=0;
		int nump=0;
		memset(a,0,sizeof(a));
		for(int i=0;i<N;i++)
			v[i]=true;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(is_prime(a[i]))
			{
				nump++;
			}
		}
		sort(a+1,a+n+1);
		solve();
		for(int i=1;i<=n;i++)
			if(v[i]) sum++;
		printf("%d\n",sum);
	}
	return 0;
}
