#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,a,now=0,sum=0,i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		if(a>now) 
		{
		    sum=sum+a-now;
			now=a;	
        }
		else now=a;
	}
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
    return 0;
}
