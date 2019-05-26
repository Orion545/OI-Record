#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,x[100010],a[100010],sum1[100010],sum2[100010];
int main(){
	n=read();x[n+1]=read();ll i;
	for(i=1;i<=n;i++) x[i]=read(),a[i]=x[i]-x[i-1];
	a[n+1]=x[n+1]-x[n];n++;
	ll ans=0,sum=0;
	for(i=n;i>=1;i--){
		sum1[i]=sum1[i+1],sum2[i]=sum2[i+1];
		if(i%2) sum1[i]+=a[i],sum+=a[i];
		else sum2[i]+=a[i];
	}
	ans=sum;
	for(i=1;i<=n;i++){
		if(a[i]==1) continue;
		ll tmp;
		if(i%2){
			tmp=sum+sum2[i+1]-sum1[i+2]-1;
			ans=max(ans,tmp);
		}
		else{
			tmp=sum+sum2[i]-sum1[i+1]-1;
			ans=max(ans,tmp);
		}
	}
	cout<<ans;
}
