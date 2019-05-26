#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define N
#define ll long long
#define mo (1000000007ll)
ll n,m;
void rd(ll &x){
	static char ch;ll F=1;
	while(!isdigit(ch=getchar()))if(ch=='-')F=-1;
	for(x=0;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	x*=F;
}
void rd(int &x){
	static ll T_T;
	rd(T_T);x=T_T;
}
ll pw(ll di,ll mi){
	ll ans=1,ch=di;
	while(mi){
		if(mi&1)(ans*=ch)%=mo;
		ch=ch*ch%mo;
		mi>>=1;
	}
	return ans;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	rd(n),rd(m);
	if(n>m)swap(n,m);
	if(n==1)printf("%lld\n",pw(2,m));
	if(n==2)printf("%lld\n",2*2*pw(3,m-1)%mo);
	if(n==3){
		ll ans=0;
		for(int i=2;i<=m;++i){
			ans+=pw(2,i-1)%mo*pw(3,m-i)%mo*2*2%mo;
		}
		cout<<ans<<endl;
	}
}


