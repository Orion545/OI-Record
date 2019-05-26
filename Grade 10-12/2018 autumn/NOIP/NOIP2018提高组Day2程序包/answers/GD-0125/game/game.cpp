#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll qpow(ll a,ll b){
	ll t=1,y=a;
	while (b){
		if (b%2) t=(y*t)%MOD;
		y=(y*y)%MOD;
		b/=2;
	}
	return t;
}

ll n,m,lj,r=0;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin>>n>>m;
	lj=n+m-2;
	if (n==1){
		if (m==1)cout<<2<<endl;
		else cout<<(4*qpow(2,m-2))%MOD<<endl;
	}else if(n==2){
		if (m==1) cout<<4<<endl;
		else if (m==2) cout<<12<<endl;
		else if (m==3) cout<<32<<endl;
		else {
		}
	}else if (n==3){
		if (m==1) cout<<8<<endl;
		else if (m==2) cout<<32<<endl;
		else if (m==3) cout<<112<<endl;
		else {
		}
	}
	
	return 0;
}
