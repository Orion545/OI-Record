#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<unordered_map>
#define MOD 20120427
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
unordered_map<ll,ll>mp;
ll sf[20],sg[20],f[20][100010],g[20][100010],p[20],cnt,s[100010],top;
void init(){
	ll i,j,k,cur,num,id,pos;
	p[0]=1;
	for(i=1;i<19;i++) p[i]=p[i-1]*10%MOD;
	for(i=0;i<10;i++){
		mp[i]=++cnt;s[++top]=i;
		f[1][cnt]=1;g[1][cnt]=i;
	}
	for(i=1,cur=top;i<18;i++,top=cur){
//		cout<<"INIT "<<i<<' '<<top<<'\n';
		for(j=1;j<=top;j++){
			num=s[j];id=mp[num];
			for(k=0;k<10;k++){
				if(!mp[num*k]){
					mp[num*k]=++cnt;
					s[++cur]=num*k;
				}
				pos=mp[num*k];
				add(f[i+1][pos],f[i][id]);
				add(g[i+1][pos],(f[i][id]*k*p[i]+g[i][id])%MOD);
			}
		}
	}
//	cout<<"INIT "<<cnt<<'\n';
	for(i=1;i<19;i++){
		for(j=1;j<=top;j++){
			add(sf[i],f[i][j]);
			add(sg[i],g[i][j]);
		}
	}
}
ll t[20],len;
ll dfs0(ll x,ll val,ll num,ll lim,ll pre){
//	cout<<"dfs0 "<<x<<' '<<val<<' '<<num<<' '<<lim<<' '<<pre<<'\n';
	if(!x) return (num?val:0);
	if(!lim&&!pre){
		ll t1=(!num?f[x][1]:sf[x]),t2=(!num?g[x][1]:sg[x]);
		return (t2+t1*p[x]%MOD*val)%MOD;
	}
	ll up=(lim?t[x]:9),re=0,i;
	for(i=0;i<=up;i++) add(re,dfs0(x-1,(val*10ll+i)%MOD,num|!i&!pre,lim&&(i==up),pre&&!i));
	return re;
}
ll dfs(ll x,ll val,ll num,ll lim,ll pre){
//	cout<<"dfs "<<x<<' '<<val<<' '<<num<<' '<<lim<<' '<<pre<<'\n';
	if(!x) return (num==1?val:0);
	ll id=mp[num];if(!id) return 0;
//	cout<<"	id "<<id<<' '<<f[x][id]<<' '<<g[x][id]<<'\n';
	if(!lim&&!pre) return (g[x][id]+f[x][id]*val%MOD*p[x])%MOD;
	ll up=(lim?t[x]:9),re=0,i;
	if(pre) add(re,dfs(x-1,val,num,lim&&!up,1));
	for(i=1;i<=up;i++){
		if(num%i) continue;
		add(re,dfs(x-1,(val*10ll+i)%MOD,num/i,lim&&(i==up),0));
	}
	return re;
}
ll solve(ll x,ll k){
	len=0;ll tmp=x;memset(t,0,sizeof(t));
	while(tmp){
		t[++len]=tmp%10;
		tmp/=10;
	}
	if(k) return dfs(len,0,k,1,1);
	else return dfs0(len,0,0,1,1);
}
int main(){
	init();ll T=read(),n,m,k;
	while(T--){
		n=read();m=read();k=read();
		printf("%lld\n",(solve(m,k)-solve(n-1,k)+MOD)%MOD);
	}
}
