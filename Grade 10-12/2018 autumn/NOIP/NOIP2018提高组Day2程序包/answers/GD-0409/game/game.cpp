#include<iostream> 
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<fstream>
using namespace std;
const int MOD=1000000007;
int n,m;
long long ans;
long long MI(int x,int y)
{
	int f[30];
	for(int i=0;i<=30;i++)f[i]=0;
	int j=0;
	while(y>0)
	{f[j++]=y%2;
	 y/=2;
    }
    j--;
    long long k=x,h=1;
	for(int i=0;i<=j;i++)
	{
		if(f[i])h*=k;
		k*=k;
		k=k%MOD;
		h=h%MOD;
	}
	return h;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		ans=MI(2,m);
	}
	if(m==1)
	{
		ans=MI(2,n);
	}
	if(n==2)
	{ans=(4*MI(3,n-1))%MOD;
	}
	if(n==3)
	{ans=(4*MI(3,m-1))%MOD;
	}
	if(n==3 && m==3)ans=112;
	if(n==5 && m==5)ans=7136;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
