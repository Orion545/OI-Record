/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾 愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
ll n,w[100010];
namespace BIT{
	ll a[100010],b[100010];
	void add(int x,ll val){
//		cout<<"add "<<x<<' '<<val<<'\n';
		for(int i=x;i<=n;i+=i&(-i)) a[i]+=val,b[i]+=(ll)x*val;
	}
	ll sum(int x){
		ll re=0;
		for(int i=x;i;i^=i&(-i)) re+=(ll)(x+1)*a[i]-b[i];
		return re;
	}
}
int main(){
	n=read();int i,m=read(),t1,t2;char s[110];
	for(i=1;i<=n;i++) w[i]=read(),BIT::add(i,w[i]);
	while(m--){
		scanf("%s",s);
		if(s[0]=='M'){
			t1=read();t2=read();
			BIT::add(t1,t2-w[t1]);w[t1]=t2;
		}
		else{
			t1=read();
			printf("%lld\n",BIT::sum(t1));
		}
	}
}
