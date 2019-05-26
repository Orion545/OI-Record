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
ll n,T,a[200010];
ll rk[200010],sum[200010],pre[200010],pl[200010];
inline bool cmp(ll l,ll r){
	return a[l]<a[r];
}
int main(){
	n=read();T=read();ll i,j,k;
	for(i=1;i<=n;i++){
		a[i]=read();pre[i]=pre[i-1]+a[i];
		rk[i]=i;
	}
	sort(rk+1,rk+n+1,cmp);
	for(i=1;i<=n;i++) pl[rk[i]]=i;
	for(i=1;i<=n;i=j+1){
		j=i;
		while(a[rk[j+1]]==a[rk[i]]) j++;
		for(k=i;k<=j;k++){
			sum[k]=sum[i-1]+a[rk[k]]*(j-i+1);
		}
	}
	ll cur=n,pos=1,ans=0;
	while(cur){
//		cout<<cur<<' '<<T<<' '<<pos<<'\n';
		ans+=(T/sum[cur])*cur;
		T-=(T/sum[cur])*sum[cur];
		while(T>=a[pos]){
			T-=a[pos];ans++;
			pos++;
			if(pos==n+1) pos=1;
		}
		while(a[rk[cur]]>=a[pos]) cur--;
		if(!cur) break;
		while(pl[pos]>cur){
			pos++;
			if(pos==n+1) pos=1;
		}
	}
	cout<<ans<<'\n';
}
