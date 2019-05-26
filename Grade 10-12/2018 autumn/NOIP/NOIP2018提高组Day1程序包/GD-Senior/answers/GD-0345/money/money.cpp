#include <cstdio>
using namespace std;
int T,n,nums[110];

void fun()
{
	int del[110]={0};
	for (int i=0;i<n;i++) //if(!del[i])
		for (int k=i+1;k<n;k++) //if(!del[k])
			{
				for (int j=0;j<n;j++)
					if (!del[j]&&j!=i&&j!=k)
					{
						for (int a=0;a*nums[i]<=nums[j];a++)
						{
							if ((nums[j]-a*nums[i])%nums[k]==0) del[j]=1;
						}
					}
			}

	int delc=0;
	for (int i=0;i<n;i++)
		delc+=del[i];
	
	printf("%d\n",n-delc);
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d",&n);
		for (int j=0;j<n;j++)
		{
			scanf("%d",nums+j);
		}
		fun();
	}
	
	return 0;
}
