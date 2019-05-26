#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
long long f[100002][1<<8],ans;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for (int i=0; i<=(1<<n)-1; i++)
		f[1][i]=1;
	for (int i=1; i<m; i++)
	{
		for (int j=0; j<=(1<<n)-1; j++)
		{
			if (f[i][j])
			{
				for (int k=0; k<=(1<<n)-1; k++)
				{
					int del=1<<(n-1)-1,tmp;
					tmp=(k&del)<<1;
					if ((tmp|j)==j)
					{
						f[i+1][k]+=f[i][j];
					}
				}
			}
		}
	}
	
	ans=0;
	for (int i=0; i<=(1<<n)-1; i++)
	{
		if (f[m][i]) 
		{
			ans+=f[m][i];
		}
	}
	
	printf("%lld\n",ans);
	
	return 0;
}
