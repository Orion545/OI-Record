#include<bits/stdc++.h>
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
ll n,m,rt,cnt,p[10000010],ans;
ll ch[2][10000010];
const ll inv=2;
void change(ll &x,ll l,ll r,ll pos){
	ll mid=(l+r)/inv;
	if(!x) x=++cnt;
	p[x]++;
	if(l==r) return;
	if(pos<=mid) change(ch[0][x],l,mid,pos);
	else change(ch[1][x],mid+1,r,pos);
}
ll query(ll x,ll l,ll t,ll pos);
int main(){
	n=read();m=read();
	change(rt,0,200000000000002ll*2,200000000000002ll);
	ll cur=0,sum=0;
	for(ll i=1;i<=n;i++){
	    cur=read();
		sum+=cur;
	    ans+=query(rt,0,200000000000002ll*2,sum-m+200000000000002ll);
	    change(rt,0,200000000000002ll*2,sum+200000000000002ll);
	}
	cout<<ans<<'\n';
	return 0;
}
ll query(ll x,ll l,ll r,ll pos){
	ll mid=(l+r)/inv;
	if(r<=pos||!x) return 0;
	if(l>pos) return p[x];
	return query(ch[0][x],l,mid,pos)+query(ch[1][x],mid+1,r,pos);
}
