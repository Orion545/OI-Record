#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=105;

int tst;
int n,a[maxn],tot,lst;
bool f[30005];

bool check(int cur,int x)
{
	for (int num=lst; num<=x; num++)
	{
		for (int i=1; i<cur; i++)
		{
			for (int j=1; j*a[i]<=num; j++)
			{
				if (f[num-(j*a[i])])
				{
					f[num]=true;
					break;
				}
			}
			if (f[num]) break;
		}
	}
	return f[x];
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	scanf("%d",&tst);
	while(tst--)
	{
		memset(f,false,sizeof(f));
		scanf("%d",&n);
		tot=n;
		for (int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		
		if (n==1) 
		{
			printf("1\n");
			continue;
		}
		
		sort(a+1,a+n+1);
		lst=1;
		for (int i=1; i<=n; i++)
		{
			if (check(i,a[i]))
			{
				tot--;
				f[a[i]]=true;
			}
			else f[a[i]]=true;
			lst=a[i]+1;
		}
		printf("%d\n",tot);
	}
	
	return 0;
}
