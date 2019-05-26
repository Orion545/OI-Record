#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#define MOD 1000000007
#define ll long long
#define mp make_pair
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
ll fac[1010],finv[1010];
void init(){
	int i,len=1000;
	fac[0]=fac[1]=finv[0]=finv[1]=1;
	for(i=2;i<=len;i++) fac[i]=fac[i-1]*i%MOD;
	finv[len]=qpow(fac[len],MOD-2);
	for(i=len;i>2;i--) finv[i-1]=finv[i]*i%MOD;
}
ll C(int x,int y){
	return fac[x]*finv[y]%MOD*finv[x-y]%MOD;
}
int n,m,x[1010],y[1010],A,B;
vector<pair<int,int> >r,g,b;
inline void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
ll val[1010][1010];
int main(){
	init();
	n=read();A=read();B=read();m=read();int i,j,k,t1,t2;
	for(i=1;i<=n;i++) x[i]=read(),y[i]=read();
	for(i=0;i<=m;i++){
		for(j=0;j<=m;j++){
			if(i+j>m||(m-i-j)&1) continue;
			val[i][j]=0;
			for(k=0;k<=(m-i-j)/2;k++){
				t1=i+k;t2=j+(m-i-j)/2-k;
				add(val[i][j],C(m,t1)*C(m-t1,k)%MOD*C(m-t1-k,t2)%MOD);
			}
//			cout<<i<<' '<<j<<' '<<val[i][j]<<'\n';
		}
	}
	if(n==3){
		for(i=x[1]-20;i<=x[1]+20;i++){
			for(j=y[1]-20;j<=y[1]+20;j++){
				k=abs(x[1]-i)+abs(y[1]-j);
				if(k>m||(m-k)&1) continue;
				r.push_back(mp(i,j));
			}
		}
		for(i=x[2]-20;i<=x[2]+20;i++){
			for(j=y[2]-20;j<=y[2]+20;j++){
				k=abs(x[2]-i)+abs(y[2]-j);
				if(k>m||(m-k)&1) continue;
				g.push_back(mp(i,j));
			}
		}
		for(i=x[3]-20;i<=x[3]+20;i++){
			for(j=y[3]-20;j<=y[3]+20;j++){
				k=abs(x[3]-i)+abs(y[3]-j);
				if(k>m||(m-k)&1) continue;
				b.push_back(mp(i,j));
			}
		}
		ll ans=0;
		for(i=0;i<r.size();i++){
			for(j=0;j<g.size();j++){
				for(k=0;k<b.size();k++){
					if(r[i]==g[j]||r[i]==b[k]||g[j]==b[k]) continue;
					add(ans,val[abs(x[1]-r[i].first)][abs(y[1]-r[i].second)]*val[abs(x[2]-g[j].first)][abs(y[2]-g[j].second)]%MOD*val[abs(x[3]-b[k].first)][abs(y[3]-b[k].second)]%MOD);
				}
			}
		}
		printf("%lld\n",ans);
	}
}
