#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<set>
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
set<ll>s[200010];
ll n,p[200010],a[200010];
namespace seg{
	ll maxn[500010],sum[500010];
	ll comb(ll l,ll r,ll num,ll val){
//		cout<<"combine "<<l<<' '<<r<<' '<<num<<' '<<maxn[num]<<' '<<val<<'\n';
		if(maxn[num]<=val) return (r-l+1)*val;
		if(l==r) return sum[num];
		ll mid=(l+r)>>1;
		if(maxn[num<<1]<=val) return (mid-l+1)*val+comb(mid+1,r,num<<1|1,val);
		else return comb(l,mid,num<<1,val)+sum[num]-sum[num<<1];
	}
	void update(ll l,ll r,ll num){
		ll mid=(l+r)>>1;
		maxn[num]=max(maxn[num<<1],maxn[num<<1|1]);
		sum[num]=sum[num<<1]+comb(mid+1,r,num<<1|1,maxn[num<<1]);
//		cout<<"update "<<l<<' '<<r<<' '<<num<<' '<<maxn[num]<<' '<<sum[num]<<'\n';
	}
	void build(ll l,ll r,ll num){
		if(l==r){maxn[num]=sum[num]=p[l];return;}
		ll mid=(l+r)>>1;
		build(l,mid,num<<1);build(mid+1,r,num<<1|1);
		update(l,r,num);
	}
	void change(ll l,ll r,ll num,ll pos,ll val){
//		cout<<"change "<<l<<' '<<r<<' '<<num<<' '<<pos<<' '<<val<<'\n';
		if(l==r){maxn[num]=sum[num]=val;return;}
		ll mid=(l+r)>>1;
		if(mid>=pos) change(l,mid,num<<1,pos,val);
		else change(mid+1,r,num<<1|1,pos,val);
		update(l,r,num);
	}
}
int main(){
	n=read();ll i,t1,t2,t3;
	set<ll>::iterator it,pre,suf,ppre,ssuf;
	for(i=1;i<=n;i++) a[i]=read(),s[a[i]].insert(i);
	for(i=1;i<=n;i++){
		for(it=s[i].begin();it!=s[i].end();it++){
			if(it==s[i].begin()) continue;
			it--;pre=it;it++;
			p[(*it)]=*pre;
		}
	}
	seg::build(1,n,1);
	ll Q=read();
	while(Q--){
		t3=read();
		if(t3){
			t1=read();t2=read();

			it=s[a[t1]].find(t1);
			it++;suf=it;it--;
			if(suf!=s[a[t1]].end()){
				if(it!=s[a[t1]].begin()){
					it--;pre=it;it++;
					seg::change(1,n,1,(*suf),(*pre));
				}
				else seg::change(1,n,1,(*suf),0);
			}
			s[a[t1]].erase(it);

			s[t2].insert(t1);
			it=s[t2].find(t1);
			it++;suf=it;it--;
			if(suf!=s[t2].end()) seg::change(1,n,1,*suf,t1);
			if(it!=s[t2].begin()){
				it--;pre=it;it++;
				seg::change(1,n,1,t1,*pre);
			}
			else seg::change(1,n,1,t1,0);

			a[t1]=t2;
		}
		else printf("%lld\n",(ll)(n*(n+1)/2)-seg::sum[1]);
	}
}
