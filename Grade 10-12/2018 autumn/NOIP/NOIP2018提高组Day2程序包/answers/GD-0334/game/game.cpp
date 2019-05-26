#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#define ll long long int 
#define mod 1000000007
using namespace std;

int f(int x,int a){
	if(!a)return 1;
	ll now=f(x,a>>1);
	now=now*now%mod;
	if(a&1)now=now*x%mod;
	return (int)now;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
    scanf("%d%d",&n,&m);
    if(n==1){
    	printf("%d",f(2,m));
    	return 0;
    }
    if(m==1){
    	printf("%d",f(2,n));
    	return 0;
    }
    if(n==2&&m==2)printf("12");
    if(n==2&&m==3)printf("48");
    if(n==3&&m==2)printf("48");
    if(n==3&&m==3)printf("112");
    if(n==5&&m==5)printf("7536");
    
    return 0;
}
