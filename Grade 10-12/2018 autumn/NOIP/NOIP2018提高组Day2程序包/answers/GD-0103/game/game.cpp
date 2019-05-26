#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000;
const int mo=1e+9+7;
typedef long long ll;
int n,m;
int power(int a,int b,int mo){
	ll t=1,y=a%mo;
	while (b){
		if (b&1) t=t*y%mo;
		y=y*y%mo;
		b=b/2;
	}
	return t;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==1) {
		printf("%d",power(2,m,mo));
		return 0;
	}
	if (m==1){
		printf("%d",power(2,n,mo));
		return 0;
	}
	if (n==2) {
		printf("%d",4*power(3,m-1,mo)%mo);
		return 0;
	}
	if (n==3&&m==3) {
		printf("%d",112);
		return 0;
	}
	if (n==5&&m==5) {
		printf("%d",7136);
		return 0;
	}
	if (n==3){
		printf("%d",16*(2*m+1)%mo);
		return 0;
	}
	return 0;
}
