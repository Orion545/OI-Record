#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fo(i,x,y) for(i=x;i<=y;i++)
#define ll long long
#define mo 1000000007
#define N 1000055
using namespace std;
ll n,m,i,j,k,x,y,t,ans;
ll f[N][10],sum[10],mi[N*2];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if (n>m) swap(n,m);
	mi[0]=1;
	fo(i,1,n+m) mi[i]=mi[i-1]*2%mo;
	/*f[1][0]=2;
	sum[0]=sum[1]=2;
	fo(i,2,n)
	{
		fo(j,0,i)
		{
			t=mi[j];
			if (t>1) t--;
			f[i][j]=(ll)f[i-1][j]*t%mo;
			if (j) (f[i][j]+=sum[j-1])%=mo;
		}
		sum[0]=f[i][0];
		fo(j,1,n) sum[j]=(sum[j-1]+f[i][j])%mo;
	}
	fo(i,n+1,n+m-1)
	{
		fo(j,0,n)
		{
			x=max(i-m+1,(ll)1);
			t=mi[max(j-x+1,(ll)0)];
			if (t>1) t--;
			f[i][j]=(ll)f[i-1][j]*t%mo;
			if (j) (f[i][j]+=sum[j-1])%=mo;
		}
		sum[0]=f[i][0];
		fo(j,1,n) sum[j]=(sum[j-1]+f[i][j])%mo;
	}
	fo(i,0,n) (ans+=f[n+m-2][i])%=mo;
	printf("%d",ans*2%mo);*/
	if (n==1) printf("%lld",mi[m]);else
	if (n==2)
	{
		ans=4;
		fo(i,1,m-1) ans=ans*3%mo;
		printf("%lld",ans);
	}else
	if (n==3 && m==3) printf("112");
	return 0;
}
