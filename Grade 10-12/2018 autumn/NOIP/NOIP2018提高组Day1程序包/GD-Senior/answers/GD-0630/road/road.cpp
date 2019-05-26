#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
long long shu[200000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&shu[i]);
	long long sum=shu[1];
	for(int i=2;i<=n;i++)sum+=max(((long long)0),shu[i]-shu[i-1]);
	printf("%lld\n",sum);
	fclose(stdin);fclose(stdout);
	return 0;
}
