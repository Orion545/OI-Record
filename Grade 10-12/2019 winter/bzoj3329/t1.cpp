#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 1000000007
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1ll)+(re<<3ll)+ch-'0',ch=getchar();
	return re*flag;
}
ll T,n,f[110][2],t00,t01,t10,t11,a00,a01,a10,a11,b00,b01;
ll qpow(ll b){
	assert(b>=0);
	while(b>0){
		if(b&1ll){
			t00=(b00*a00+b01*a10)%MOD;
			t01=(b00*a01+b01*a11)%MOD;
			b00=t00;b01=t01;
		}
		t00=(a00*a00+a01*a10)%MOD;
		t01=(a00*a01+a01*a11)%MOD;
		t10=(a10*a00+a11*a10)%MOD;
		t11=(a10*a01+a11*a11)%MOD;
		a00=t00;a01=t01;a10=t10;a11=t11;
		b>>=1ll;
		assert(b>=0);
	}
}
int main(){
	T=read();ll i,ans1,ans2;
	f[0][0]=1;f[0][1]=0;
	f[1][0]=f[1][1]=1;
	for(i=2;i<=63;i++){
		f[i][0]=f[i-1][0]+f[i-1][1];
		f[i][1]=f[i-1][0];
	}
	while(T--){
		n=read();
		assert(n>=0);
		ans1=ans2=0;
		a00=a01=a10=1;a11=0;
		b00=b01=1;
		if(n>0){
			assert(n>0);
			qpow(n-1ll);
			ans2=(b00+b01)%MOD;
		}
		else ans2=1;
		n++;
		assert(n>=0);
		for(i=63;i>=0;i--){
			if(n&(1ll<<(i-1))){
				ans1+=f[i][0];
				if(n&(1ll<<i)) break;
			}
		}
		printf("%lld\n%lld\n",ans1-1,ans2);
	}
}
