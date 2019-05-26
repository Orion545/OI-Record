#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
using namespace std;
long long a[N],cf[N],sum;
int n;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%lld",&a[i]);
    	cf[i]=a[i]-a[i-1];
    	if(cf[i]>=0)
    	sum+=cf[i];
    }
    printf("%lld",sum);
	return 0;
}
