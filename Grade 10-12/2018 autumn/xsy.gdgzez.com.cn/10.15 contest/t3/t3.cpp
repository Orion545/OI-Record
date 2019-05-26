#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 1000000007
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
int n,tot,top,ttop,s[110],ss[110];
int lis[110],val[110];
ll up[110],down[110],ans=0;
int calc(int x,int y,int z){
	if(z==-3) return lis[val[x]]<lis[val[y]];
	if(z==-2) return x&y;
	if(z==-1) return x|y;
}
void check(){
	int i;
	for(i=1;i<=tot;i++) lis[i]=i;
	do{
		ttop=0;
		for(i=1;i<=top;i++){
			if(s[i]>=0) ss[++ttop]=s[i];
			else ttop--,ss[ttop]=calc(ss[ttop],ss[ttop+1],s[i]);
		}
		if(ss[ttop]) (ans+=up[tot]*down[tot]%MOD)%=MOD;
	}while(next_permutation(lis+1,lis+tot+1));
}
void dfs(int cur){
//	cout<<"dfs "<<cur<<'\n';
	if(cur==7){check();return;}
	for(int i=1;i<=tot;i++){
		val[cur]=i;
		dfs(cur+1);
		val[cur]=0;
	}
	val[cur]=++tot;
	dfs(cur+1);
	tot--;val[cur]=0;
}
int main(){
	char ch=getchar();
	while(ch!='\n'){
//		cout<<"do "<<ch<<' '<<top<<' '<<ttop<<'\n';
		if(ch==' '){ch=getchar();continue;}
		if(ch>='a'&&ch<='z') s[++top]=ch-'a';
		if(ch=='(') ss[++ttop]=0;
		if(ch==')'){
			while(ss[ttop]) s[++top]=-ss[ttop--];
			ss[ttop--]=0;
		}
		if(ch=='<'){
			while(ss[ttop]>=3) s[++top]=-ss[ttop--];
			ss[++ttop]=3;
		}
		if(ch=='&'){
			while(ss[ttop]>=2) s[++top]=-ss[ttop--];
			ss[++ttop]=2;
		}
		if(ch=='|'){
			while(ss[ttop]>=1) s[++top]=-ss[ttop--];
			ss[++ttop]=1;
		}
		ch=getchar();
	}
	while(ttop) s[++top]=-ss[ttop--];
	n=read();
	down[1]=1;up[1]=n;
	for(int i=2;i<=7;i++){
		down[i]=down[i-1]*qpow(i,MOD-2)%MOD;
		up[i]=up[i-1]*(ll)(n-i+1)%MOD;
	}
	dfs(0);
	printf("%lld\n",ans);
}
