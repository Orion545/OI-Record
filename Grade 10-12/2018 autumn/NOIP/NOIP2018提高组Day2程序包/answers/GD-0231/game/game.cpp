#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
LL f[1100000];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	LL n,m,anss=1,anss2=0;scanf("%lld%lld",&n,&m);
	if (n>m){LL t=n;n=m;m=t;}
	if (n==1){
		for (LL i=1;i<=m;i++)anss=(anss*2)%LL(1000000007);
		printf("%lld\n",anss);
		return 0;
	}
	if (n==2){
		for (LL i=1;i<=m-1;i++)anss=(anss*3)%LL(1000000007);
		anss=(anss*4)%LL(1000000007);
		printf("%lld\n",anss);
		return 0;
	}
	if (n==3){
		anss=(anss*2*3*2)%LL(1000000007);
		
		f[m-1]=1;for (LL i=m-2;i>=1;i--)f[i]=(f[i+1]*3)%LL(1000000007);
		anss2=(anss2+2*2*2*2*f[2]*4)%LL(1000000007);
		for (LL i=1;i<=m-2;i++){
			anss=(anss)%LL(1000000007);
			anss2=(anss2+3*(f[i+1])*anss)%LL(1000000007);
		}
		printf("%lld\n",(anss+anss2)%LL(1000000007),anss,anss2);
		return 0;
	}
	
	
	return 0;
}
/*LL anss=1;
	for (LL i=1;i<=max(m,n)-min(m,n)+1;i++){
		anss=(anss*(min(n,m)+1))%LL(1000000007);
	}
	for (LL j=1;j<=min(n,m)-1;j++){
		anss=(anss*(j+1))%LL(1000000007);
	}
	for (LL j=1;j<=min(n,m)-1;j++){
		anss=(anss*(j+1))%LL(1000000007);
	}
	printf("%lld\n",anss);*/
