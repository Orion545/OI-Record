/*

宣告——
汝身在我之下，托付吾之命运于汝之剑，
遵从圣杯之名，若汝遵从此意志此理，回应吧。
在此起誓，吾是成就世间一切行善之人，吾是肃清世间一切罪恶之人，
被狂乱之槛所囚的囚徒。吾是此锁链的操纵者，
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 998244353
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
ll cnt[100010];ll ans=0,n,m;
void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
int main(){
//	freopen("in.in","r",stdin);
	n=read();m=read();
	ll i,j,lim,t1,t2,t3,k,orz=sqrt(m);
	for(i=1;i<=n;i++){
		lim=read();
		cnt[lim]++;
	}
	for(i=1;i<=orz;i++){
		for(j=1;j<=i;j++){
			t1=i*i-j*j;t3=i*i+j*j;t2=2*i*j;
			if(t3>m) break;
			if(__gcd(t3,__gcd(t1,t2))>1) continue;
			for(k=1;k*t3<=m;k++){
				add(ans,cnt[t1*k]*cnt[t2*k]*cnt[t3*k]%MOD);
			}
		}
	}
	
	cout<<ans<<'\n';
}
