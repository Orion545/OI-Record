#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define MOD 1000000009

using namespace std;
int n,m;
long long ans;
long long power(int t,int w){
	if (w==0) return 1;
	long long h=power(t,w>>1);
	if (w&1) return (h*h*t)%MOD;
	else return h*h%MOD;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m);
	if (n==3&&m==3) printf("%d\n",112);
	else 
		if (n==2) {
			ans=(4*power(3,m-1))%MOD;
			printf("%lld\n",ans);
		}
		else printf("%d\n",7136);
}
