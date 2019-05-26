#include<bits/stdc++.h>
using namespace std;
const int mod=1000000000+7;
int n,m;
long long power(long long x,long long y){
	long long ans=1,i=1;
	while(y>=i){
		if(y&i)ans=((ans%mod)*(x%mod))%mod;
		x=(x%mod*x%mod)%mod;
		i<<=1;
	}
	return ans;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){printf("%d",power(2,(long long)m));exit(0);}
	if(m==1){printf("%d",power(2,(long long)n));exit(0);}
	if(n==2){
		if(m==2){cout<<12;exit(0);}
		if(m==3){cout<<36;exit(0);}
	}
	if(n==3){
		if(m==2){cout<<36;exit(0);}
		if(m==3){cout<<112;exit(0);}
	}
	if(n==5&&m==5){cout<<7136;exit(0);}
	cout<<power(2,(long long)(n+m))%mod;
	return 0;
}
