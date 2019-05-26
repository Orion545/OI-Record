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
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
inline ll qpow(ll a,ll b){
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
ll n,m,len,dp[5010],f[5010],cnt[30];
ll s[5010],c[5010];
int main(){
	freopen("poetry.in","r",stdin);
	freopen("poetry.out","w",stdout);
	n=read();m=read();len=read();ll i,j,tmp,ans=1;char str[10];
	for(i=1;i<=n;i++) s[i]=read(),c[i]=read();
	dp[0]=1;
	for(i=1;i<len;i++){
		for(j=1;j<=n;j++){
			if(s[j]>i) continue;
//			cout<<"	add "<<i<<' '<<j<<' '<<s[j]<<'\n';
			add(dp[i],dp[i-s[j]]);
		}
//		cout<<i<<' '<<dp[i]<<'\n';
	}
	for(i=1;i<=n;i++) add(f[c[i]],dp[len-s[i]]);
//	for(i=1;i<=n;i++) cout<<i<<' '<<f[i]<<'\n';
	for(i=1;i<=m;i++){
		scanf("%s",str);
		cnt[str[0]-'A'+1]++;
	}
	for(i=1;i<=26;i++){
		if(!cnt[i]) continue;
		tmp=0;
		for(j=1;j<=n;j++) add(tmp,qpow(f[j],cnt[i]));
		ans=(ans*tmp)%MOD;
	}
	cout<<ans<<'\n';
}
