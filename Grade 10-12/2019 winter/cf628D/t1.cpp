#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 1000000007
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
inline void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
ll f[2010][2010],t[2010];
ll a[2010],b[2010],n,m,d,mod;
void init(){
	ll i,j,k;
	t[1]=1;
	for(i=2;i<=2000;i++) t[i]=t[i-1]*10ll%mod;
	f[1][d%mod]=1;
	f[0][0]=1;
	for(i=0;i<=2000;i++){
		for(j=0;j<mod;j++){
			if(!f[i][j]) continue;
			for(k=0;k<10;k++){
				if(k!=d) add(f[i+2][(j+t[i+1]*k+t[i+2]*d)%mod],f[i][j]);
			}
//			if(i<=100) cout<<"init "<<i<<' '<<j<<' '<<f[i][j]<<'\n';
		}
	}
}
ll dfsa(){
	ll i,j,re=0;if(n==1&&a[1]==0) return 0;
	for(i=1;i<n;i++){
		for(j=1;j<10;j++){
			if(j!=d) add(re,f[i-1][(mod-t[i]*j%mod)%mod]);
		}
	}
//	cout<<"dfsa "<<re<<'\n';
	ll now=0;
	for(i=n;i>=1;i--){
		if((i^n)&1){
			if(a[i]>d) add(re,f[i][(mod-now)%mod]);
			if(a[i]!=d) break;
		}
		else{
			for(j=(i==n);j<a[i];j++){
//				if(j!=d) cout<<i<<' '<<j<<' '<<f[i-1][(mod-t[i]*j%mod)%mod]<<'\n';
				if(j!=d) add(re,f[i-1][(mod+mod-now-t[i]*j%mod)%mod]);
			}
			if(a[i]==d) break;
		}
		now=(now+t[i]*a[i])%mod;
	}
	if(!i&&!now) add(re,1);
//	cout<<"dfsa "<<re<<'\n';
	return re;
}

ll dfsb(){
	ll i,j,re=0;if(m==1&&b[1]==0) return 0;
	for(i=1;i<m;i++){
		for(j=1;j<10;j++){
			if(j!=d) add(re,f[i-1][(mod-t[i]*j%mod)%mod]);
		}
	}
//	cout<<"dfsb "<<re<<'\n';
	ll now=0;
	for(i=m;i>=1;i--){
//		cout<<i<<' '<<now<<'\n';
		if((i^m)&1){
			if(b[i]>d) add(re,f[i][(mod-now)%mod]);
			if(b[i]!=d) break;
		}
		else{
			for(j=(i==m);j<b[i];j++){
//				if(j!=d) cout<<i<<' '<<j<<' '<<f[i-1][(mod+mod-now-t[i]*j%mod)%mod]<<'\n';
				if(j!=d) add(re,f[i-1][(mod+mod-now-t[i]*j%mod)%mod]);
			}
			if(b[i]==d) break;
		}
		now=(now+t[i]*b[i])%mod;
	}
	if(!i&&!now) add(re,1);
//	cout<<"dfsb "<<re<<'\n';
	return re;
}
int main(){
	ll i,ans=0;char s[2010];mod=read();d=read();
	scanf("%s",s);
	n=strlen(s);

	for(i=0;i<n;i++) a[n-i]=(s[i]-'0');
	a[1]--;
	for(i=1;i<=n;i++) if(a[i]<0) a[i]+=10,a[i+1]--;
	if(n>1&&a[n]==0) n--;
//	cout<<n<<' '<<a[1]<<' '<<a[2]<<'\n';

	scanf("%s",s);
	m=strlen(s);
	for(i=0;i<m;i++) b[m-i]=(s[i]-'0');
//	cout<<m<<' '<<b[1]<<' '<<b[2]<<'\n';
	
	init();
	ll ansb=dfsb();
	ll ansa=dfsa();
	cout<<(ans+ansb-ansa+MOD)%MOD<<'\n';
}
