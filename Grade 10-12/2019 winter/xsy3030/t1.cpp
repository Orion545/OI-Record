#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 998244353
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,a[1000010],pri[1000010],cntp,dep[1000010],cnt[1000010];bool vis[1000010];
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
inline void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
int main(){
	n=read();int i,j,k;
	for(i=1;i<=n;i++) a[i]=read();
	for(i=2;i<=n;i++){
		if(!vis[i]) pri[++cntp]=i,dep[i]=1,cnt[i]=1;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>n) break;
			vis[k]=1;dep[k]=dep[i]+1;
			if(i%pri[j]) cnt[k]=cnt[i]+1;
			else{cnt[k]=cnt[i];break;}
		}
	}
	ll tot=0,sum=0,ans=0;
	for(i=1;i<=n;i++) tot=(tot+1ll*a[i]*cnt[i])%MOD;
	for(i=1;i<=n;i++) if(dep[i]&1) sum^=a[i];
	for(i=1;i<=n;i++){
//		cout<<"enter "<<i<<' '<<a[i]<<' '<<dep[i]<<' '<<cnt[i]<<' '<<(sum^a[i])<<'\n';
		if((dep[i]&1)==0) continue;
		if((sum^a[i])<a[i]) add(ans,cnt[i]);
		else for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>n) break;
			if(a[k]&&(sum^a[i])<a[i]+a[k]) add(ans,1);
		}
	}
	printf("%lld\n",ans*qpow(tot,MOD-2)%MOD);
}
