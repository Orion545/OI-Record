#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define MOD 998244353
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,opl[50010],opr[50010],opx[50010],a[100010],cntn=0;
ll ans=0,inv[100010];
int main(){
	n=read();ll i,j,k;
	inv[1]=1;
	for(i=2;i<=100000;i++) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(i=1;i<=n;i++){
		opl[i]=read();opr[i]=read()+1;opx[i]=read();
		a[++cntn]=opl[i];
		a[++cntn]=opr[i];
	}
	sort(a+1,a+cntn+1);
	cntn=unique(a+1,a+cntn+1)-a-1;
	for(i=1;i<=n;i++){
		opl[i]=lower_bound(a+1,a+cntn+1,opl[i])-a;
		opr[i]=lower_bound(a+1,a+cntn+1,opr[i])-a;
		cout<<i<<' '<<opl[i]<<' '<<opr[i]<<'\n';
	}
	k=read();
	for(i=1;i<cntn;i++){
		ll cnt=0;ll tans=1;
		for(j=1;j<=n;j++) cnt+=(opl[j]<=i&&opr[j]>i);
		if(cnt<k) continue;
		for(j=1;j<=n;j++) if(opl[j]<=i&&opr[j]>i){
			cout<<"	get "<<cnt<<' '<<inv[cnt]<<' '<<cnt*inv[cnt]%MOD<<' '<<k<<' '<<cnt-k<<' '<<j<<' '<<opx[j]<<' '<<(MOD+1-opx[j])<<'\n';
			(tans*=(((max(k,cnt-k)*inv[cnt]%MOD)*opx[j]%MOD)+(min(k,cnt-k)*inv[cnt]%MOD*(MOD+1-opx[j])%MOD)))%=MOD;
		}
		cout<<i<<' '<<a[i]<<' '<<a[i+1]<<' '<<tans<<'\n';
		ans=(ans+tans*(a[i+1]-a[i]))%MOD;
	}
	cout<<ans<<'\n';
}
