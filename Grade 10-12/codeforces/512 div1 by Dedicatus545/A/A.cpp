#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,m,k;
int main(){
	n=read();m=read();k=read();
	if(k==1||((n*m*2)%k!=0)){
		puts("NO");return 0;
	}
	if(k==2){
		puts("YES");
		puts("0 0");
		printf("%lld 0\n",n);
		printf("0 %lld\n",m);
		return 0;
	}
	ll a=n*m*2/k;
	if(k%2==0){
		k/=2;
		ll g=__gcd(n,k),a,b;
		if(g==1){
			g=__gcd(m,k);
			b=m/g,a=n/(k/g);
		}
		else{
			a=n/g,b=m/(k/g);
		}
		puts("YES");
		puts("0 0");
		printf("%lld 0\n",a);
		printf("0 %lld\n",b);
		return 0;
	}
	else{
//			cout<<"ckp\n";
		ll g=__gcd(n,k),a,b;
		if(g==1){
//			cout<<"ckp\n";
			g=__gcd(m,k);
			b=m/g;a=n/(k/g);
			if(b*2<max(n,m)) b*=2;
			else a*=2;
		}
		else{
			a=n/g;b=m/(k/g);
			if(b*2<max(n,m)) b*=2;
			else a*=2;
		}
		puts("YES");
		puts("0 0");
		printf("%lld 0\n",a);
		printf("0 %lld\n",b);
		return 0;
	}
}
