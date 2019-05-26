#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define MOD 1000000007
using namespace std;
int n,m;
inline ll powr(ll bas,int x){
	ll ret=1;
	while(x){
		if(x&1)ret=ret*bas%MOD;
		x>>=1;
		bas=bas*bas%MOD;
	}
	return ret;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		printf("%d\n",powr(2,m));
	}
	if(n==2){
		printf("%d\n",4LL*powr(3,m-1));
	}
	if(n==3){
		if(m==1)puts("8");
		else if(m==2)puts("36");
		else if(m==3)puts("112");
		else printf("%d\n",332LL*powr(3,m-4));
	}
	return 0;
}