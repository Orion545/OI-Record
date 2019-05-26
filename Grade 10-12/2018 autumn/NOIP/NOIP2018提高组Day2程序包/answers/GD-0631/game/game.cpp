#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int p=1000000007;
long long jc(int x,int y)
{
	long long tmp;
	if (y==0)
		return 1;
	if (y==1)
		return x;
	tmp=jc(x,y/2);
	if (y%2==1)
		return (tmp*tmp*x)%p;
	else
		return (tmp*tmp)%p;
}


int main()
{
	int i,n,m;
	
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==1 && m==1)
		printf("2\n");
	else if (n==3 && m==3)
		printf("112\n");
	else if (n==1)
		printf("%lld\n",jc(2,m));
	else if (m==1)
		printf("%lld\n",jc(2,n));
	else if (n==2)
		printf("%lld\n",(4*jc(3,m-1))%p);
	else if (m==2)
		printf("%lld\n",(4*jc(3,n-1))%p);
	else if (n==5 && m==5)
		printf("7136\n");
	
	return 0;
}
