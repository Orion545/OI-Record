#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<set>
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
namespace SIEVE{
	int vis[100010],pri[100010],cntp,phi[100010];
	void init(){
		int i,j,k,len=100000;
		for(i=2;i<=len;i++){
			if(!vis[i]) pri[++cntp]=i,phi[i]=i-1;
//			if(i<=20) cout<<i<<' '<<vis[i]<<' '<<phi[i]<<endl;
			for(j=1;j<=cntp;j++){
				k=i*pri[j];if(k>len) break;
				vis[k]=1;
				if(i%pri[j]) phi[k]=phi[i]*(pri[j]-1);
				else{phi[k]=phi[i]*pri[j];break;}
			}
		}
	}
}
int n,m,MOD,a[100010],p[30],cntp,*p1[30][210],*p2[30][210];
inline int mulmod(int a,int b){
	if(a>=b) a=a%b+b;
	return a;
}
namespace BIT{
	int n,a1[30010],a2[30010];
	void ADD(int x,int val){
		int p=1ll*x*val%MOD;
		for(;x<=n;x+=(x&(-x))){
			(a1[x]+=val)%=MOD;
			(a2[x]+=p)%=MOD;
		}
	}
	void add(int l,int r,int val){
		ADD(l,val);
		ADD(r+1,-val);
	}
	int SUM(int x){
		int re1=0,re2=0,tmp=x+1;
		for(;x;x^=(x&(-x))){
			(re1+=a1[x])%=MOD;
			(re2+=a2[x])%=MOD;
		}
		return (1ll*re1*tmp%MOD-1ll*re2)%MOD;
	}
	int sum(int l,int r){
		return ((SUM(r)-SUM(l-1))%MOD+MOD)%MOD;
	}
}
void initpow(){
	cntp=0;p[cntp]=MOD;
	while(p[cntp]!=1){
//		cout<<"cur "<<cntp<<' '<<p[cntp]<<' '<<SIEVE::phi[p[cntp]]<<endl;
		cntp++;
		p[cntp]=SIEVE::phi[p[cntp-1]];
//		assert(p[cntp]);
//		cout<<cntp<<' '<<p[cntp]<<endl;
	}
	int i,j,k,tmp;
	for(i=0;i<=cntp;i++){
		for(j=0;j<200;j++){
			p1[i][j]=new int[p[i]];
			p2[i][j]=new int[p[i]];
		}
	}
	for(i=0;i<=cntp;i++){
		for(k=0;k<p[i];k++){
			p1[i][0][k]=1;
			for(j=1;j<200;j++) p1[i][j][k]=mulmod(p1[i][j-1][k]*k,p[i]);
			p2[i][0][k]=1;
			tmp=mulmod(p1[i][199][k]*k,p[i]);
			for(j=1;j<200;j++) p2[i][j][k]=mulmod(p2[i][j-1][k]*tmp,p[i]);
		}
	}
}
inline int getpow(int x,int y,int id){
	int re=mulmod(p1[id][y%200][x%p[id]]*p2[id][y/200][x%p[id]],p[id]);
	if(y&&(x>=p[id])&&(re<p[id])) re+=p[id];
	return re;
}
struct ele{
	int s[30];
	inline void init(int val){
		for(int i=0;i<=cntp;i++) s[i]=mulmod(val,p[i]);
	}
	inline void change(int val){
		for(int i=0;i<=cntp;i++) s[i]=getpow(val,s[i+1],i);
	}
	inline int get(){return s[0];}
	friend inline bool operator ==(ele l,ele r){
		for(int i=0;i<=cntp;i++) if(l.s[i]!=r.s[i]) return 0;
		return 1;
	}
}d[100010];
int ed[100010];
set<int>s;
void init(){
	int i;
	n=read();m=read();MOD=read();
	SIEVE::init();
//	cout<<"finish sieve"<<endl;
	initpow();
//	cout<<"finish init"<<endl;
	for(i=1;i<=n;i++) a[i]=read();
	BIT::n=n+1;
	for(i=1;i<=n;i++){
		d[i].init(a[i]);
		ed[i]=i;
		s.insert(i);
		BIT::add(i,i,a[i]);
	}
}
set<int>::iterator split(int pos){
	set<int>::iterator it=s.upper_bound(pos);
	it--;
	if(*it==pos) return it;
	d[pos]=d[*it];
	ed[pos]=ed[*it];
	ed[*it]=pos-1;
	return s.insert(pos).first;
}
void change(int l,int r,int c){
	set<int>::iterator il=split(l),ir=split(r+1),it=il,tmp;
	int pre;
	while(it!=ir){
		pre=d[*it].get();
		d[*it].change(c);
		BIT::add(*it,ed[*it],(d[*it].get()-pre)%MOD);
		if(it!=il&&d[*tmp]==d[*it]){
			ed[*tmp]=ed[*it];
			it=s.erase(it);
		}
		else tmp=it,it++;
	}
}
int main(){
	init();int t1,t2,t3,t4;
	while(m--){
		t4=read();
		if(t4==0){
			t1=read();t2=read();t3=read();
			change(t1,t2,t3);
		}
		else{
			t1=read();t2=read();
			printf("%d\n",BIT::sum(t1,t2));
		}
	}
}
