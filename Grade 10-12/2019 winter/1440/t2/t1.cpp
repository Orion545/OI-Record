#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define MOD 1000000009
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
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
inline void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
inline void dec(ll &a,ll b){
	a-=b;
	if(a<0) a+=MOD;
}
int n,lens,lenc;char str[10010];
ll a0[110][110],a1[110][110];
ll b[110],c[110],ans[110][110];
inline void mul(ll *x,ll*y,ll len1,ll len2){
	static ll re[110];
	memset(re,0,sizeof(ll)*(len2+len1+1));
	int i,j;
	for(i=0;i<=len1;i++) add(x[i],MOD);
	for(i=0;i<=len2;i++) add(y[i],MOD);
	for(i=0;i<=len1;i++){
		for(j=0;j<=len2;j++){
			add(re[i+j],x[i]*y[j]%MOD);
		}
	}
	for(i=0;i<=len1+len2;i++) x[i]=re[i];
}
inline void mod(ll *x,ll *y,ll len1,ll len2){
	int i,j;ll tmp,inv=qpow(y[len2],MOD-2);
	for(i=len1-len2;i>=0;i--){
		tmp=x[i+len2]*inv%MOD;
		if(!tmp) continue;
		add(tmp,MOD);
		for(j=0;j<=len2;j++) dec(x[i+j],y[j]*tmp%MOD);
	}
	for(i=0;i<=len1;i++) add(x[i],MOD);
}
inline void mat(ll x[110][110],ll y[110][110]){
	int i,j,k;ll tmp;
	static ll re[110][110];
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			tmp=0;
			for(k=1;k<=n;k++) add(tmp,x[i][k]*y[k][j]%MOD);
			re[i][j]=tmp;
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			x[i][j]=re[i][j];
}
inline ll gauss(ll a[110][110]){
	int i,j,k;ll re=1,pos,tmp,inv;
	/*
	cout<<"	BEGIN gauss\n";
	for(i=1;i<=n;i++){
		cout<<"		";
		for(j=1;j<=n;j++) cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	*/
	for(i=1;i<=n;i++){
		pos=i;
		if(!a[i][i]) for(j=i+1;j<=n;j++) if(a[j][i]){pos=j;break;}
		if(pos!=i) swap(a[i],a[pos]),re*=-1;
		if(!a[i][i]) return 0;
		inv=qpow(a[i][i],MOD-2);re=re*a[i][i]%MOD;
		for(j=i+1;j<=n;j++){
			if(!a[j][i]) continue;
			tmp=a[j][i]*inv%MOD;
			for(k=i;k<=n;k++) dec(a[j][k],a[i][k]*tmp%MOD);
		}
	}
	/*
	cout<<"	finish gauss\n";
	for(i=1;i<=n;i++){
		cout<<"		";
		for(j=1;j<=n;j++) cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	*/
	add(re,MOD);
	return re;
}
inline void pre(){
	static ll y[110];
	int i,j,k,x;ll pos,inv,len1,len2;
	for(x=0;x<=n;x++){
		memcpy(a1,a0,sizeof(a0));
		for(i=1;i<=n;i++) dec(a1[i][i],x);
		y[x]=gauss(a1);
//		cout<<"doing pre "<<x<<' '<<y[x]<<'\n';
	}
	for(i=0;i<=n;i++){
		static ll tmp[110];
		len1=0;inv=1;
		tmp[0]=1;
		for(j=0;j<=n;j++){
			if(i==j) continue;
			static ll t2[110];
			len2=1;
			t2[0]=MOD-j;t2[1]=1;
			mul(tmp,t2,len1++,len2);
			inv=inv*(i-j)%MOD;
		}
		add(inv,MOD);
		inv=y[i]*qpow(inv,MOD-2)%MOD;
		for(j=0;j<=n;j++)
			add(b[j],tmp[j]*inv%MOD);
	}
//	cout<<"finish pre\n";
//	for(i=0;i<=n;i++) cout<<i<<' '<<b[i]<<'\n';
}
inline void solve(){
	int i,j;static ll p[110];
	lenc=0;c[0]=1;p[1]=1;
	for(i=lens-1;i>=0;i--){
		if(str[i]=='1'){
			mul(c,p,n-1,n-1);
			mod(c,b,(n-1)<<1,n);
		}
		mul(p,p,n-1,n-1);
		mod(p,b,(n-1)<<1,n);
	}
//	cout<<"finish solve\n";
//	for(i=0;i<n;i++) cout<<i<<' '<<c[i]<<'\n';
}
inline void getans(){
	int i,j,k;
	static ll tmp[110][110];
	for(i=1;i<=n;i++) tmp[i][i]=1;
	for(k=0;k<n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				add(ans[i][j],tmp[i][j]*c[k]%MOD);
			}
		}
		if(k<n-1) mat(tmp,a0);
	}
}
int main(){
	n=read();int i,j,k;
	scanf("%s",str);lens=strlen(str);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			a0[i][j]=read();
		}
	}
	pre();
	solve();
	getans();
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%lld ",ans[i][j]);
		}
		puts("");
	}
}
