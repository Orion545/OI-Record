#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define MOD 1000000007
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
ll add(ll x,ll y){
	x+=y;
	return (x>=MOD)?x-MOD:x;
}
namespace n2{
	ll f[1000010],sum[1000010],g[1000010];
	void solve(int n,int m){
		int i;ll ans=0;
		for(i=0;i<=m;i++) f[i]=1;
		if(n==1){
			printf("%d\n",m+1);return;
		}
		for(i=m;i>=0;i--) sum[i]=add(sum[i+1],f[i]);
		for(i=0;i<=m;i++) g[i]=sum[max(i-1,0)],ans=add(ans,g[i]);
		printf("%lld\n",ans);
	}
} 
namespace m2{
	ll f[1000010][3];
	void solve(int n,int m){
		int i;
		f[1][0]=f[1][1]=1;
		if(m>1) f[1][2]=1;
		for(i=2;i<=n;i++){
			f[i][0]=add(f[i-1][0],f[i-1][1]);
			f[i][1]=add(f[i-1][0],f[i-1][1]);
			if(m>1){
				f[i][0]=add(f[i][0],f[i-1][2]);
				f[i][1]=add(f[i][1],f[i-1][2]);
				f[i][2]=add(f[i-1][1],f[i-1][2]);
			}
		}
		ll ans=add(f[n][0],f[n][1]);
		if(m>1) ans=add(ans,f[n][2]);
		printf("%lld\n",ans);
	}
}
namespace brute{
	ll f[1000010],sum[1000010]={0};
	void solve(int n,int m){
		int i,j;
		for(i=0;i<=m;i++) f[i]=1;
		for(i=2;i<=n;i++){
			for(j=m;j>=0;j--) sum[j]=add(sum[j+1],f[j]);
			for(j=0;j<=m;j++) f[j]=sum[max(0,j-1)]/*,cout<<i<<' '<<j<<' '<<f[j]<<'\n'*/; 
		}
		ll ans=0;
		for(i=0;i<=m;i++) ans=add(ans,f[i]);
		printf("%lld\n",ans);
	}
}
int main(){
	int n=read(),m=read();
	if(m<=2) m2::solve(n,m);
	else if(n<=2) n2::solve(n,m);
	else brute::solve(n,m);
}
