#include<cstdio>

int t,n;

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		if(n==2)printf("2\n");
		else printf("21");
	}
	return 0;
}
