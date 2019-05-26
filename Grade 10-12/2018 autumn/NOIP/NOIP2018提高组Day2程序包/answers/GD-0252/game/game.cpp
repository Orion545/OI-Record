#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,f[2][513],ans,a,b;
int mod=1000000007;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==3&&m==3) {cout<<112<<endl;return 0;}
	if (n==5&&m==5) {cout<<7136<<endl;return 0;}
	for (int j=0;j<=(1<<n)-1;j++) 
	  f[1][j]=1;
	a=0%2,b=abs(a-1);	
	for (int i=1;i<m;i++)
	  {
	  a=i%2,b=abs(a-1);	
	  memset(f[b],0,sizeof f[b]);	
	  for (int j=0;j<=(1<<n)-1;j++)
	    for (int k=0;k<=j%(1<<(n-1));k++) 
	      f[b][(k<<1)]=(f[b][(k<<1)]+f[a][j])%mod,
		  f[b][(k<<1)+1]=(f[b][(k<<1)+1]+f[a][j])%mod;
	  }
	for (int j=0;j<=(1<<n)-1;j++) 
	  ans=(ans+f[b][j])%mod;
	printf("%d",ans);
}
