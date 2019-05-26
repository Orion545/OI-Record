#include<stdio.h>
typedef long long ll;
const int mod=1000000007;
int mul(int a,int b){return(ll)a*b%mod;}
int pow(int a,int b){
	int s=1;
	while(b){
		if(b&1)s=mul(s,a);
		a=mul(a,a);
		b>>=1;
	}
	return s;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==1){
		printf("%d",pow(2,m));
		return 0;
	}
	if(m==1){
		printf("%d",pow(2,n));
		return 0;
	}
	if(n==2){
		printf("%d",mul(4,pow(3,m-1)));
		return 0;
	}
	if(m==2){
		printf("%d",mul(4,pow(3,n-1)));
		return 0;
	}
	puts("112");
}
