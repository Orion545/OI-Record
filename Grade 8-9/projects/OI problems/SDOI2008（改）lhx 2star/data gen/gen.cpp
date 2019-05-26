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
int model[1010];
int main(){
	freopen("10.in","w",stdout);
	int n=1000,lim=200,lim2=1000,delta=1000;
	srand(time(NULL));
	printf("%d\n",n);
	int lem=random(1,lim/2);
	for(int i=1;i<=lem;i++) model[i]=random(1,lim2);
	for(int i=1;i<=n;i++){
		int m=random(lim/2,lim),d=random(0,delta);
		printf("%d ",m);
		for(int j=1;j<=lem;j++) printf("%d ",model[j]+d);
		for(int j=lem+1;j<=m;j++) printf("%lld ",random(1,lim2+delta));
	}
}
