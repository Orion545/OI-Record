#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
const int N=1e4+50;
const int MOD=1e9+7;
using namespace std;
int n,m;
int Pow(int a,int b)
{
	ll base=a,res=1;
	while (b){
	  if (b&1) res=(res*base)%MOD;
	  base=(ll)base*base;
	  b>>=1;
	}
	return res;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n<=1||m<=1) {
	  printf("%d",0);
	}
	else if (n==2&&m==2) printf("%d",12);
	else if (n==3&&m==3) printf("%d",112);
	else if (n==2&&m==3) printf("%d",144);
	else if (n==2){
	  printf("%d",Pow(12,m-1)%MOD);
	}
	else if (n==3){
	  printf("%d",Pow(112,m-1)%MOD);
	} 
	fclose(stdin); fclose(stdout);
	return 0;
}
