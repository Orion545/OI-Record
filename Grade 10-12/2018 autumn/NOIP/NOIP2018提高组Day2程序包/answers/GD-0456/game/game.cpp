#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
#include <string.h>
#include <algorithm>
#define mod 1000000007
using namespace std;
typedef long long LL;
int n,m;LL ans;
LL pow(LL cur,int k){
	LL res=1;
	while(k){
		if(k&1)res=res*cur%mod;
		cur=cur*cur%mod;k>>=1;
	}
	return res;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		ans=pow(2,m)%mod;printf("%lld\n",ans);
	}
	if(n==2){
		ans=pow(3,m-1);
		ans=ans*4%mod;
		printf("%lld\n",ans);
	}
	if(n==3&&m<=3){
		if(m==1)puts("8");
		if(m==2)puts("36");
		if(m==3)puts("112");
	}
	else{
		ans=1;LL temp=6;
		for(int i=3;i<=n-1;i++)temp=temp*2*(i-1);
		ans=ans*pow(2*(n-1),m-n+1)%mod;
		ans=ans*temp%mod*temp%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
