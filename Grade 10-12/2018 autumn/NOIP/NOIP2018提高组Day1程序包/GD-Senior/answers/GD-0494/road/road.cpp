#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x;
	int sum=0;
	int mid=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x>mid)
		{
			mid=x-mid;
			sum=sum+mid;
		}else{
			mid=x;
			sum=sum+mid-x;
		}
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
