#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
} 
int n,a[100010],t[100010],sum[100010];
int main(){
	n=read();int k=read();int i,j;int ans=0,maxn=0;
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<=n;i++) t[i]=read(),sum[i]=sum[i-1]+(t[i]==0)*a[i],ans+=t[i]*a[i];
	for(i=1;i<=n-k+1;i++) maxn=max(maxn,sum[i+k-1]-sum[i-1]);
	cout<<ans+maxn;
}
