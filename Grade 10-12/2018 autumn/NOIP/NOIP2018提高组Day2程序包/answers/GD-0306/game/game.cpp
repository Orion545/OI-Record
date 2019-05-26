#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<bitset>
using namespace std;

#define N 10
#define P 1000000007
#define LL long long

int f[N][1024];
int n,m;
LL ans;

bool pd(int x,int y)
{
	for (int i=2;i<=m;i++)
	  if (((x&(1<<(i-1)))!=0) && ((y&(1<<(i-2)))==0)) 
			return false;
	return true;
}

LL ksm(LL x,int k)
{
	if (k==0) return 1;
	if (k==1) return x;
	LL t=ksm(x,k/2);
	if (k%2==0) return t*t%P;
	  else return t*t%P*x%P;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	memset(f,0,sizeof(f));
	scanf("%d%d",&n,&m);
	if (n==1)
	{
		ans=(1<<m)%P;
		printf("%lld\n",ans);
		return 0;
	}
	if (n==2)
	{
		ans=ksm(3,m-1);
		ans=ans*4%P;
		printf("%lld\n",ans);
		return 0;
	}
	f[0][0]=1;
	ans=0;
	for (int i=1;i<=n;i++)
	  for (int j=0;j<=(1<<m)-1;j++)
	    for (int k=0;k<=(1<<m)-1;k++)
	      if (pd(k,j)==true) f[i][j]=(f[i][j]+f[i-1][k])%P;
	for (int i=0;i<=(1<<m)-1;i++)
	  ans=(ans+f[n][i])%P;
	printf("%d\n",ans);	    
	return 0;
}

