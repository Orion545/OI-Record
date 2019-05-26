#include<algorithm>

#include<iostream>

#include<cstring>

#include<cstdio>

#include<cmath>

#define LL long long

#define M

using namespace std;

LL read(){

	LL nm=0,fh=1;char cw=getchar();

	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;

	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');

	return nm*fh;

}

LL n,m,K,S,t1,t2,k1,k2;

LL gcd(LL x,LL y){return (!y)?x:gcd(y,x%y);}

int main(){

	//freopen(".in","r",stdin);

	//freopen(".out","w",stdout);

	n=read(),m=read(),K=read();

	if(n*m*2ll%K>0||K==1){puts("NO");return 0;}

	puts("YES"),puts("0 0");

	if(K==2){
		
		printf("%lld 0\n0 %lld\n",n,m);

		return 0;

	}

	t1=gcd(n,K),t2=gcd(m,K);

	if(t1*t2>=K){

		t2=K/t1;

		t1=n/t1,t2=m/t2;

		if(t1+t1<=n) t1<<=1;

		else t2<<=1;

		printf("%lld 0\n",t1);

		printf("0 %lld\n",t2);

		return 0;

	}

	k1=n/t1,k2=m/t2;

	printf("%lld 0\n0 %lld\n",k1,k2);

	

	return 0;

}

