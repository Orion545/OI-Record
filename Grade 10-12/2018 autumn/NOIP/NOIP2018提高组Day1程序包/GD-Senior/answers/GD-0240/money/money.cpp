#include<iostream>
#include<cstdio>
#include<algorithm>
#include<list>
#include<queue>
#include<functional>
#include<cstring>
#include<deque>
#include<map>
#include<set>
using namespace std;
int t,n,a[105],gj,mi;
int gcd(int a,int b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		if(n==2)
		{
	    gj=gcd(a[1],a[2]);
		mi=min(a[1],a[2]);
		if(gj==mi)
		{
			printf("1\n");
		}
		else
		{
		    printf("2\n");
	    }
	    }
	    else
	    {
	    	printf("%d\n",n);
	    }
	}
	return 0;
}
