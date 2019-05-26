#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<iostream>
#define Mod 1000000007
using namespace std;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long sum;
	long n,m,i;
	scanf("%ld%ld",&n,&m);
	if (n>m)swap(n,m);
	for (i=1,sum=1;i<n;i++){
		sum=(sum*(i+1))%Mod;
		sum=(sum*(i+1))%Mod;
	}
	for (i=1;i<=m-n+1;i++)sum=(sum*(n+1))%Mod;
	printf("%lld\n",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
