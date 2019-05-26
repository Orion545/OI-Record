#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
ll n,m,a[1010][1010],dp[1010];
int main(){
	n=read();m=read();dp[0]=1;ll i,j,lim,t1,t2;
	for(i=1;i<=n;i++) a[i][n+1]=a[n+1][i]=1;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		t1++;t2++;
		a[t1][t2]=a[t2][t1]=1;
	}
	for(i=1;i<=n;i++){
		lim=n+1;
		for(j=i-1;j>=0;j--){
			if(!a[j][i]&&(a[lim][i]||a[j][lim])) dp[i]+=dp[j],lim=j;
		}
	}
	lim=n+1;ll ans=0;
	for(i=n;i>0;i--){
		if(a[i][lim]) ans+=dp[i],lim=i; 
	}
	cout<<ans;
}
