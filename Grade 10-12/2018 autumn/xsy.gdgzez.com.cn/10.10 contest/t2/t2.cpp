#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
ll n,m;
const long double pi=acos(-1.0);
long double trans(long double x){
	return x*pi/180.0;
}
long double Sin(long double x){
	return sin(trans(x));
}
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	scanf("%lld%lld",&m,&n);
	if(n==m){puts("1.0000000");return 0;}
	ll k=m/gcd(n,m);
	long double ans=sin(pi/(long double)n)*cos(pi/(long double)(n*k))/(sin(pi/m)*cos(pi/n));
	printf("%.10lf",(double)ans);
}
