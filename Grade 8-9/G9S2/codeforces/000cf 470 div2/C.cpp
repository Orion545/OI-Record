#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
inline ll read(){
	ll re=0,flag=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='0') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
} 
ll n,v[100010],t[100010],sum[100010],ans[100010],buff[100010];
int main(){
	ll i,l,r,mid,tmp,pos;
	n=read();
	for(i=1;i<=n;i++) v[i]=read();
	for(i=1;i<=n;i++) t[i]=read(),sum[i]=sum[i-1]+t[i];
	for(i=1;i<=n;i++){
		tmp=v[i]+sum[i-1];
		pos=upper_bound(sum+i,sum+n+1,tmp)-sum;
//		cout<<i<<ends<<pos<<ends<<tmp<<ends<<sum[pos]<<endl;
		ans[i]++;ans[pos]--;buff[pos]+=tmp-sum[pos-1];
	}
	ll tans=0;
	for(i=1;i<=n;i++){
		tans+=ans[i];
		printf("%I64d ",tans*t[i]+buff[i]);
	}
	printf("\n");
}
