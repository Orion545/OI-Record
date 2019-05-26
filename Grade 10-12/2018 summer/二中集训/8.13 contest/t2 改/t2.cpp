#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define MOD 1000000007
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,m,k,first[110],cnte=1,dfn[110],low[110],clk,ans=1;
struct edge{
	ll from,to,next,vis;
}a[210];
ll sta[210];ll top;
inline void add(ll u,ll v){
	a[++cnte]=(edge){v,u,first[v],0};first[v]=cnte;
	a[++cnte]=(edge){u,v,first[u],0};first[u]=cnte;
}
ll vis[210],mi[210];
ll gcd(ll l,ll r){
	if(r==0) return l;
	else return gcd(r,l%r);
}
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll f[210],finv[210];
void init(){
	ll i;
	mi[0]=f[1]=f[0]=finv[1]=finv[0]=1;
	for(i=1;i<=200;i++) mi[i]=mi[i-1]*k%MOD;
	for(i=2;i<=200;i++) f[i]=f[i-1]*i%MOD;
	finv[200]=qpow(f[200],MOD-2);
	for(i=200;i>2;i--) finv[i-1]=finv[i]*i%MOD;
}
void tarjan(ll u){
//	cout<<"tarjan "<<u<<'\n';
	dfn[u]=low[u]=++clk;
	ll i,v,j;
	for(i=first[u];~i;i=a[i].next){
		if(a[i].vis||a[i^1].vis) continue;
		sta[++top]=i;v=a[i].to;a[i].vis=a[i^1].vis=1;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
//				cout<<"	find bcc "<<u<<' '<<v<<' '<<i<<' '<<sta[top]<<'\n';
				bool cir=1;ll cnt=0;ll val=0;
				for(j=top;sta[j+1]!=i;cnt++,j--){
					if(vis[a[sta[j]].to]) cir=0;
					else vis[a[sta[j]].to]=1;
				}
				if(cir){
					for(j=1;j<=cnt;j++) val=(val+mi[gcd(cnt,j)])%MOD;
					val=val*qpow(cnt,MOD-2)%MOD;
				}
				else val=f[cnt+k-1]*finv[cnt]%MOD*finv[k-1]%MOD;
				ans=ans*val%MOD;
//				cout<<"	finish calc bcc "<<v<<' '<<val<<' '<<ans<<' '<<cnt<<' '<<cir<<'\n';
				while(sta[top+1]!=i) vis[a[sta[top]].to]=0,top--;
			} 
		}
		else low[u]=min(low[u],dfn[v]);
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();k=read();ll i,t1,t2;
	init();
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	for(i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	printf("%lld\n",ans);
}
