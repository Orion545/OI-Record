#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
ll baka[2010],vis[2010],getb[2010],cnt,cntb,L,R;
void search(ll t,ll val){
	if(!t){
		getb[++cntb]=val;return;
	}
	search(t-1,val*10+2);
	search(t-1,val*10+9);
}
void getbaka(){
	ll k;
	for(k=1;k<=9;k++){
		search(k,0);
	}
} 
ll ans=0;
ll gcd(ll x,ll y){
	if(y==0) return x;
	else return gcd(y,x%y);
}
void dfs(ll x,ll bit,ll val){
//	cout<<"dfs "<<x<<' '<<bit<<' '<<val<<'\n';
	if(x>cnt){
		if(bit) ans+=(R/val)-((L-1)/val);
		else if(val!=1) ans-=(R/val)-((L-1)/val);
		return;
	}
	dfs(x+1,bit,val);
	ll tmp=val/gcd(val,baka[x])*baka[x];
	if(tmp<=R) dfs(x+1,bit^1,tmp);
}
int main(){
	L=read(),R=read();ll i,j;getbaka();
	sort(getb+1,getb+cnt+1);
	for(i=1;i<=cntb;i++){
		for(j=i+1;j<=cntb;j++){
			if(getb[j]%getb[i]==0) vis[j]=1;
		}
	}
	for(i=1;i<=cntb;i++) if(!vis[i]) baka[++cnt]=getb[i];
//	for(i=1;i<=cnt;i++) cout<<baka[i]<<'\n';
//	cout<<cnt<<'\n';
	dfs(1,0,1);printf("%lld\n",ans);
}

