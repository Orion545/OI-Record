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
inline void dec(ll &a,ll b){
	a-=b;
	if(a<0) a+=MOD;
}
ll n,m,a[20][20],f[100010],g[100010],in[100010],p[100010],out[100010],w[100010],h[100010],cnt[100010],qpow[100010];
int main(){
	n=read();m=read();ll i,j,s,t1,t2,t3;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		a[t1][t2]=1;
		out[(1<<(t1-1))]|=(1<<(t2-1));
		in[(1<<(t2-1))]|=(1<<(t1-1));
	}
	cnt[0]=0;
	for(i=1;i<(1<<n);i++){
		cnt[i]=cnt[i-(i&(-i))]+1;
	}
	qpow[0]=1;
	for(i=1;i<=100000;i++) qpow[i]=qpow[i-1]*2%MOD;
	f[0]=0;g[0]=0;
	for(s=1;s<(1<<n);s++){
		t1=(s&(-s));t2=(s^t1);
		for(i=t2;i;i=(i-1)&t2){
			dec(g[s],f[s^i]*g[i]%MOD);
		}
		h[s]=h[t2]+cnt[in[t1]&t2]+cnt[out[t1]&t2];
		f[s]=qpow[h[s]];
		for(i=s;i;i=(i-1)&s){
			if(i^s){
				t3=((i^s)&(-(i^s)));
				p[i]=p[i^t3]-cnt[in[t3]&(i^s)]+cnt[out[t3]&i];
			}
			else p[i]=0;
			dec(f[s],qpow[h[s^i]+p[i]]*g[i]%MOD);
		}
		add(g[s],f[s]);
//		cout<<s<<' '<<t1<<' '<<t2<<' '<<h[s]<<' '<<f[s]<<' '<<g[s]<<'\n';
	}
	cout<<f[(1<<n)-1]<<'\n';
}
