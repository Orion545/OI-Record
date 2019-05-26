#include<cstdio>
#include<iostream>
#include<algorithm>

//using namespace std;

#define N 105
#define MAX 500005
 
int n,m,t,i,j,k,u,w,amax,amin,nwh,ans;
int a[MAX],can[MAX],is[MAX],now[MAX];

void check(int x)
{
	int i;
	for (i=1; i<=n; i++)
	{
		if (a[i]%x==0) can[i]=0;
	}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for (u=1; u<=t; u++)
	{
		scanf("%d",&n);
		for (i=1; i<=n; i++)
		{
			scanf("%d",&a[i]);
		}
		std::sort(a+1,a+n+1);
		amin=a[1]; amax=a[n];
		for (i=now[0]; i>=0; i--) now[i]=0;
		for (i=1; i<=n; i++)
			can[i]=1;
		for (i=1; i<=amax; i++)
			is[i]=1;
		ans=1;
		for (i=1; i<=amax; i++)
		{
			if (i*a[1]>amax) break;
			is[i*a[1]]=0;
			now[0]++;
			now[now[0]]=i*a[1];
			check(now[now[0]]);
		}
		for (w=2; w<=n; w++)
		{
			if (can[w])
			{
				ans++;
				nwh=now[0];
				for (k=1; k<=nwh; k++)
				{
					for (j=1; j<=amax; j++)
					{
						if (a[w]*j+now[k]>amax) break;
						if (is[a[w]*j+now[k]])
						{
							is[a[w]*j+now[k]]=0;
							now[0]++; now[now[0]]=a[w]*j+now[k];
							check(now[now[0]]);
						}
					}	
				}
				for (j=1; j<=amax; j++)
				{
					if (a[w]*j>amax) break;
					if (is[a[w]*j])
					{
						now[0]++; now[now[0]]=a[w]*j;
						is[a[w]*j]=0;
						check(now[now[0]]);
					}
				}
			}
		}
		if (n==0) ans=0;
		printf("%d\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
