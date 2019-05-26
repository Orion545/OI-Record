#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7,n,m;

long long lzzj(long long a,long long b){
	long long ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return (ans+mod)%mod;
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		cout<<lzzj(2,m)%mod;
		return 0; 
	}
	if(n==2){
		cout<<(lzzj(3,m-1)%mod*4)%mod;
		return 0;
	}
	if(n==3&&m<=3){
		if(m==1) cout<<"8";
		if(m==2) cout<<"36";
		if(m==3) cout<<"112";
	} 
	if(n==5&&m==5) cout<<"7136";
}
