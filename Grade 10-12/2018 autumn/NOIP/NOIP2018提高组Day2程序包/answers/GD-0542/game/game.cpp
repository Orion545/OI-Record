#include<bits/stdc++.h>
using namespace std;
const int q=1e9+7;
inline int Multi(int x,int y) {return 1ll*x*y%q;}
inline int& Me(int &x,int y) {return x=1ll*x*y%q;}
int mi(int x,int y) {
	int ret(1);
	for (;y;y>>=1,Me(x,x)) if (y&1) Me(ret,x);
	return ret;
}
int answer(int n,int m) {
	if (n>m) swap(n,m);
	if (n==1) return mi(2,m);
	if (n==2) return Multi(12,mi(3,m-2));
	if (n==3) return Multi(112,mi(3,m-3));
	if (n==4) return Multi(912,mi(3,m-4));
	if (n==5) return Multi(7136,mi(3,m-5));
	return 0;
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",answer(n,m));
	return 0;
}
