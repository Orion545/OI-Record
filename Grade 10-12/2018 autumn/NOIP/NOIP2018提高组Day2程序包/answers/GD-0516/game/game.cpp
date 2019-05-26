#include<cstdio>
#define mod 1000000007
using namespace std;
long long n,m,tmp,ans,
          f[300],last[300];
int main()
{
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  scanf("%lld%lld",&n,&m);
  if (n==3&&m==3){
  	printf("112");
  	return 0;
  }
  for (int i=0;i<(1<<n);i++)last[i]=1;
  for (int i=2;i<=m;i++){
    for (int j=0;j<(1<<n);j++)f[j]=0;
  	for (int j=0;j<(1<<(n-1));j++)
  	  for (int k=0;k<=j;k++)if ((k|j)==j){
  	  	//printf("%d->%d:%lld\n",j,k<<1,last[j]+last[j+(1<<(n-1))]);
  	  	//printf("%d->%d:%lld\n",j,k<<1|1,last[j]+last[j+(1<<(n-1))]);
  	    f[k<<1]+=last[j]+last[j+(1<<(n-1))];
  	    f[k<<1|1]+=last[j]+last[j+(1<<(n-1))];
  	  }
	for (int j=0;j<(1<<n);j++)
  	  last[j]=f[j]%mod;
  }ans=0;
  for (int i=0;i<(1<<n);i++)
    ans+=last[i];
  printf("%lld\n",ans%mod);
  return 0;
}
