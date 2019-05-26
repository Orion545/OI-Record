#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
	if (!a) return b;
	return gcd(b%a,a); 
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T,n,x,y,z,h;
	scanf("%d",&T);
	for (;T;T--)
	{
		scanf("%d",&n);
		if (n==2)
		{
			scanf("%d%d",&x,&y);
			if (x>y) h=x,x=y,y=h;
			if (gcd(x,y)==1) printf("2\n");
			else printf("1\n");
		}
		else
		{
			printf("%d",n);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
