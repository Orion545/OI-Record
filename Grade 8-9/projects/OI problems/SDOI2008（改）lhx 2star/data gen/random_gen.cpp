#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
ll random(ll l,ll r){
	ll x=rand(),y=rand();
	return (x*y)%(r-l+1)+l; 
}
int main(){
	freopen("3.in","w",stdout);
	int n=10,lim=10,lim2=2;
	srand(time(NULL));
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		int m=random(lim/2,lim);
		printf("%d ",m);
		for(int j=1;j<=m;j++) printf("%lld ",random(1,lim2));
		puts("");
	}
}
