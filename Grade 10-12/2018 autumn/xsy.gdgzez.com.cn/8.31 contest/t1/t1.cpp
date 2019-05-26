#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define MOD 1000000007
#define rank DEEP_DARK_FANTASY
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
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
void add(ll &x,ll y){
//	cout<<"add "<<x<<' '<<y<<'\n';
	x+=y;
	if(x>=MOD)x-=MOD;
}
void dec(ll &x,ll y){
	x-=y;
	if(x<0) x+=MOD;
}
struct BIT{
	ll a[2010];
	BIT(){memset(a,0,sizeof(a));}
	int lowbit(int x){
		return x&(-x);
	}
	void update(int x,ll val){
		for(;x<=2000;x+=lowbit(x)) add(a[x],val);
	}
	ll sum(int x){
		ll re=0;
		for(;x>0;x-=lowbit(x)) add(re,a[x]);
		return re;
	}
}T[2010];
int n,a[2010],rank[2010];ll dp[2010][2010],ans[2010],tmp[2010];
ll f[2010],finv[2010];
inline bool cmp(int l,int r){
	return a[l]<a[r];
}
void init(){
	int i,len=2000;f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=len;i++) f[i]=f[i-1]*i%MOD;
	finv[len]=qpow(f[len],MOD-2);
	for(i=len;i>2;i--) finv[i-1]=finv[i]*i%MOD;
}
ll C(ll x,ll y){
//	cout<<"C "<<x<<' '<<y<<' '<<f[x]<<' '<<finv[y]<<' '<<finv[x-y]<<'\n';
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
int main(){
//	freopen("in.in","r",stdin);
	n=read();int i,j,cnt=0;ll re=0;
	init();
	for(i=1;i<=n;i++) a[i]=read(),rank[i]=i;
	sort(rank+1,rank+n+1,cmp);
	for(i=1;i<=n;i++){
		cnt++;
		while(a[rank[i]]==a[rank[i+1]]) a[rank[i]]=cnt,i++;
		a[rank[i]]=cnt;
	}
	for(i=1;i<=n;i++){
		for(j=i;j>=2;j--){
			dp[i][j]=T[j-1].sum(a[i]);
			T[j].update(a[i],dp[i][j]);
		}
		dp[i][1]=1ll;
		T[1].update(a[i],1ll);
//		for(j=1;j<=i;j++) cout<<i<<' '<<j<<' '<<dp[i][j]*f[n-j]%MOD<<'\n';
	}
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			add(tmp[i],dp[j][i]*f[n-i]%MOD);
	for(i=n;i>=1;i--){
		ans[i]=tmp[i];
//		cout<<i<<' '<<tmp[i]<<'\n';
		for(j=i+1;j<=n;j++)
			dec(ans[i],ans[j]*C(j,j-i)%MOD*f[j-i]%MOD);
		add(re,ans[i]);
//		cout<<i<<' '<<ans[i]<<'\n';
	}
	printf("%lld\n",re);
}
