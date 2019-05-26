#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,x[20],dp[20],a[20];
int main(){
	freopen("inverse1.in","r",stdin);
	freopen("inverse.out","w",stdout);
	int T=read();int i,l,r,mid,maxn;
	while(T--){
		n=read();int ans=0;
		for(i=1;i<=n;i++) x[i]=read();
		while(next_permutation(x+1,x+n+1)){
			dp[1]=1;a[1]=x[1];maxn=1;
			for(i=2;i<=n;i++){
				l=1,r=maxn;
				while(l<r){
					mid=(l+r)>>1;mid++;
					if(x[i]>=a[mid]) l=mid-1;
					else r=mid;
				}
				dp[i]=l+1;a[l+1]=x[i];
				maxn=max(maxn,l+1);
			}
			if(maxn<3) ans++;
		}
		cout<<ans<<'\n';
	}
}

