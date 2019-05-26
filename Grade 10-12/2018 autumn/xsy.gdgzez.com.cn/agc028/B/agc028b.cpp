/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
#define ll long long
#define MOD 1000000007
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
ll n,a[100010],inv[100010],sum[100010],f[1000010];
int main(){
	n=read();ll i,ans=0;inv[1]=1;f[0]=1;
	for(i=1;i<=n;i++){
		a[i]=read();
		f[i]=f[i-1]*i%MOD;
		if(i>1) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
		sum[i]=(sum[i-1]+inv[i])%MOD;
	}
	for(i=1;i<=n;i++){
		ans=(ans+(sum[i]+sum[n-i+1]-sum[1])*a[i])%MOD;
	}
	ans=ans*f[n]%MOD;
	printf("%lld\n",ans);
}
