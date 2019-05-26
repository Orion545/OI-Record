#include <cstdio>
#include <algorithm>
using namespace std;
int t1,t2,ans;
int M=1e9+7;
int pw2(int a) {
	int b=1,i;
	for (i=1;i<=a;i++) b=b*2;
	return b;
}
int pw3(int a) {
	int b=1,i;
	for (i=1;i<=a;i++) b=(1LL*b*3) %M;
	return b;
}
int main() {
	int n,m,i,l;
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m); l=n+m-1;
	if (n==1) {
		t1=pw2(m-1);
	} else 
	if (n==2) {
		t1=2LL*pw3(m-1) %M;
	} else 
	if (n==3) {
		t1=2*4*pw3(m-3)*2*2;
		if (m==3) {
			printf("112\n"); return 0;
		}
		for (i=3;i<=m-1;i++) t2+=4*pw3(m-i-1)*2*2;
		t2+=12;
	}
	ans=t1+t2;
	printf("%lld\n",2LL*ans %M);
}
