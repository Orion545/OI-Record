#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<map>
#define MOD 65521
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
inline ll qpow(ll a,ll b){
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
int siz[10]={1,1,1,3,16,125,1296,0,0,0};
ll n,m;
ll a[110][110],b[110][110],t[110][110];
ll cnt,lis[110];
map<ll,ll>mp;
void mul1(){
	ll i,j,k;
	memset(t,0,sizeof(t));
	for(k=1;k<=cnt;k++){
		for(i=1;i<=cnt;i++){
			for(j=1;j<=cnt;j++){
				add(t[i][j],b[i][k]*b[k][j]%MOD);
			}
		}
	}
	memcpy(b,t,sizeof(t));
}
void mul2(){
	ll i,j;
	memset(t,0,sizeof(t));
	for(i=1;i<=cnt;i++){
		for(j=1;j<=cnt;j++){
			add(t[1][i],a[1][j]*b[j][i]%MOD);
		}
	}
	memcpy(a[1],t[1],sizeof(t[1]));
}
void qpow(ll tim){
	/*
	cout<<"begin pow\n";
	for(int i=1;i<=cnt;i++) cout<<a[1][i]<<' ';
	cout<<'\n';
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			cout<<b[i][j]<<' ';
		}
		cout<<'\n';
	}
	*/
	while(tim){
		if(tim&1) mul2();
		mul1();tim>>=1;
	}
}
ll tnum[10];
void dfs(ll u,ll s){
	ll i,tmp,j;
//	cout<<"dfs "<<u<<' '<<s<<'\n';
	if(u==m+1){
		a[1][++cnt]=1;
		memset(tnum,0,sizeof(tnum));
		for(i=1;i<=m;i++){
			tnum[(s>>(i*3-3))&7]++;
//			cout<<"	"<<i<<' '<<((s>>(i*3-3))&7)<<'\n';
		}
		for(i=1;i<=m;i++) (a[1][cnt]*=(siz[tnum[i]]))%=MOD;
		lis[cnt]=s;
		mp[s]=cnt;
//		cout<<"****find "<<cnt<<' '<<s<<' '<<a[1][cnt]<<'\n';
		return;
	}
	tmp=0;
	for(i=1;i<u;i++) tmp=max(tmp,((s>>(i*3-3))&7));
	for(i=1;i<=tmp+1;i++) dfs(u+1,s<<3|i);
}
ll ufs[10],vis[10];
inline ll find(ll x){return ((ufs[x]==x)?x:ufs[x]=find(ufs[x]));}
ll gets(){
	ll i,tot=0,re=0,j;
	memset(vis,0,sizeof(vis));
	for(i=m+1;i>=2;i--){
		if(!vis[i]){
			tot++;
			vis[i]=1;
			re|=(tot<<(i*3-6));
//			cout<<"	TRANS new "<<i<<' '<<find(i)<<'\n';
			for(j=i-1;j>=2;j--){
				if(find(i)==find(j)){
					vis[j]=1;
					re|=(tot<<(j*3-6));
//					cout<<"		same "<<j<<'\n';
				}
			}
		}
	}
	return re;
}
void trans(ll op,ll e){
	ll i,j,fi,fj,s=lis[op];
	for(i=1;i<=m+1;i++) ufs[i]=i;
//	cout<<"begin trans "<<op<<' '<<e<<'\n';
	for(i=1;i<=m;i++){
		for(j=i+1;j<=m;j++){
			if(((s>>(i*3-3))&7)==((s>>(j*3-3))&7)){
				fi=find(i);
				fj=find(j);
				if(fi==fj) continue;
				ufs[fj]=fi;
			}
		}
	}
	for(i=1;i<=m;i++){
		if(e&(1<<(i-1))){
			fi=find(i);
			fj=find(m+1);
			if(fi==fj) return;
			ufs[fj]=fi;
		}
	}
//	cout<<"pass1\n";
	bool f=0;
	for(i=2;i<=m+1;i++) if(find(i)==find(1)) f=1;
	if(!f) return;
//	cout<<"pass2\n";
	b[op][mp[gets()]]++;
//	cout<<"trans "<<op<<' '<<e<<' '<<gets()<<' '<<mp[gets()]<<'\n';
}
int main(){
	m=read();n=read();ll i,j,k;
	dfs(1,0);
	for(i=1;i<=cnt;i++){
		for(j=0;j<(1<<m);j++){
			trans(i,j);
		}
	}
	qpow(n-m);
	cout<<a[1][1]<<'\n';
}
