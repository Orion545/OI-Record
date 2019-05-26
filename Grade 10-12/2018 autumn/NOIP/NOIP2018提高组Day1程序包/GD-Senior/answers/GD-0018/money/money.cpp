#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int a[110],jl[25010];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(jl,0,sizeof(jl));
		int n,maxn=0,ans,step=0,pd=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			maxn=max(maxn,a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int t1=1;t1<=maxn/a[i]+1;t1++)
				{
					for(int t2=1; ;t2++)
					{
						step++;
						if(step==10000000)
						{
							pd=1;
							break;
						}
						if(a[i]*t1+a[j]*t2>maxn) break;
						jl[a[i]*t1+a[j]*t2]=1;
					}	
					if(pd==1) break;
				}
				if(pd==1) break;
			}
			if(pd==1) break;
		}
		ans=n;
		if(pd!=1)
		{
			for(int i=1;i<=n;i++)
				if(jl[a[i]]) ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
