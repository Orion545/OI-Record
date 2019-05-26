#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int pri[100010],cntp,vis[100010];
void sieve(){
	int i,j,k,len=100000;
	for(i=2;i<=len;i++){
		if(!vis[i]) pri[++cntp]=i;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) break;
			vis[k]=1;
			if(i%pri[j]==0) break;
		}
	}
}
int phi(int x){
	int i,re=x;
	for(i=1;pri[i]*pri[i]<=x;i++){
		if(x%pri[i]) continue;
		re=re-re/pri[i];
		while(x%pri[i]==0) x/=pri[i];
	}
	if(x>1) re=re-re/x;
	return re;
}
int n,m,c,P,p[110],cnt,a[100010],seg[400010],tim[400010];
namespace prep{
	int p1[110][100010],p2[110][100010],lim[110];
	void init(){
		int i,j;
		for(i=0;i<=cnt;i++){
			p1[i][0]=1;
			for(j=1;j<=100000;j++) p1[i][j]=1ll*p1[i][j-1]*c%p[i];
			p2[i][0]=1;
			for(j=1;j<=100000;j++) p2[i][j]=1ll*p2[i][j-1]*p1[i][100000]%p[i];
			if(p[i]==1) lim[i]=-1;
			else for(j=0;j<=100000;j++) if(1ll*p1[i][j]*c>=p[i]){lim[i]=j;break;}
//			cout<<"initp "<<i<<' '<<lim[i]<<' '<<j<<' '<<p1[i][j]<<'\n';
		}
	}
	inline int solve(int b,int dep){
//		cout<<"qpow "<<c<<' '<<b<<' '<<p[dep]<<' '<<p1[dep][b%10000]<<' '<<p2[dep][b/10000]<<' '<<lim[dep]<<'\n';
//		if(dep>cnt-2) return b>0;
		return 1ll*p1[dep][b%100000]*p2[dep][b/100000]%p[dep]+(b>lim[dep])*p[dep];
	}
}
inline int add(int aa,int b){
	aa+=b;
	if(aa>=P) aa-=P;
	return aa;
}
inline void update(int num){
	seg[num]=(seg[num<<1]+seg[num<<1|1])%P;
	tim[num]=min(tim[num<<1],tim[num<<1|1]);
}
void build(int l,int r,int num){
	if(l==r){seg[num]=a[l]%P;return;}
	int mid=(l+r)>>1;
	build(l,mid,num<<1);
	build(mid+1,r,num<<1|1);
	update(num);
}
int qpow(int a,int b,int MOD,int &f){
	int re=1;
//	cout<<"qpow "<<a<<' '<<b<<' '<<MOD<<'\n';
	while(b){
		if(b&1){
			f=f|(1ll*re*a>=MOD);
			re=1ll*re*a%MOD;
		}
		if(1ll*a*a>=MOD) f=1;
		a=1ll*a*a%MOD;b>>=1;
	}
	return re;
}
int calc(int val,int dep){
//	cout<<"calc "<<val<<' '<<dep<<'\n';
	int re=val;if(re>p[dep]) re=re%p[dep]+p[dep];
	while(dep--){
		re=prep::solve(re,dep);
//		cout<<"	doing "<<dep<<' '<<p[dep]<<' '<<re<<'\n';
	}
	return re%p[dep+1];
}
void change(int l,int r,int ql,int qr,int num){
//	cout<<"CHANGE "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<num<<' '<<tim[num]<<'\n';
	if(tim[num]>=cnt) return;
	if(l==r){
		tim[num]++;
		seg[num]=calc(a[l],tim[num]);
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ql) change(l,mid,ql,qr,num<<1);
	if(mid<qr) change(mid+1,r,ql,qr,num<<1|1);
	update(num);
}
int query(int l,int r,int ql,int qr,int num){
	if(l>=ql&&r<=qr) return seg[num];
	int mid=(l+r)>>1,re=0;
	if(mid>=ql) re=query(l,mid,ql,qr,num<<1);
	if(mid<qr) re=add(re,query(mid+1,r,ql,qr,num<<1|1));
	return re;
}
int main(){
	sieve();
	n=read();m=read();P=read();c=read();int i,t1,t2,t3;
	for(i=1;i<=n;i++) a[i]=read();
	build(1,n,1);
	
	p[0]=P;cnt=0;
	while(p[cnt]!=1) cnt++,p[cnt]=phi(p[cnt-1]);
	p[++cnt]=1;
	prep::init();
	
	while(m--){
		t1=read();t2=read();t3=read();
		if(!t1) change(1,n,t2,t3,1);
		else printf("%d\n",query(1,n,t2,t3,1));
	}
}
