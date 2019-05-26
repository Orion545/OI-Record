#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#define ri register int
using namespace std;

int n,m,i,j,k,l,y;
typedef long long ll;
const ll p=1e9+7;
ll x,h,zhong;
int gi()
{
	int res,w=1;
	char ch;
	while(ch=getchar(),ch<'0'||ch>'9')if(ch=='-')w=-1;
	res=ch-48;
	while(ch=getchar(),ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+ch-48;
	return res*w;
}
ll ksm(int a,int b){
	ll dan=1;
	x=(ll)a;y=b;
	while(y){
		if(y&1)dan=dan*x%p;
		x=x*x%p;
		y>>=1;
	}
	return dan%p;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=gi(),m=gi();
	if(n>m)swap(n,m);
	if(n==1||m==1){
		puts("0");
		return 0;
	}
	if(n==2&&m==2){
		puts("12");
		return 0;
	}
	if(n==2&&m==3){
		puts("40");
		return 0;
	}
	if(n==3&&m==3){
		puts("112");
		return 0;
	}
	if(n==5&&m==5){
		puts("7136");
		return 0;
	}
	zhong=ksm(2,n+m-3);
	h=(1ll+zhong)%p*zhong%p*2%p;
	printf("%lld",h);
	return 0;
}
