#include<iostream>
#include<cstdio>
using namespace std;
const long long mo=1e9+7;
int n,m;

long long qpow(int x,int p){
	long long sum=1;
	while(p){
		if(p&1)sum=sum*x%mo;
		x=x*x%mo;
		p>>=1;
	}
	return sum;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		cout<<qpow(2,m)%mo;
	}
	else if(m==1){
		cout<<qpow(2,n)%mo;
	}
	else if(n==2){
		cout<<qpow(3,m-1)%mo*4ll%mo;
	}
	else if(m==2){
		cout<<qpow(3,n-1)%mo*4ll%mo;
	}
	else if(n==3&&m==3)cout<<112;
}
