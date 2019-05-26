/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
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
ll n,m,S;
namespace BIT{
	ll a[1000010],cnt[1000010],lim=1000000;
	void init(){
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
	}
	void add(ll x,ll val){
		for(;x<=lim;x+=(x&(-x))) a[x]+=val,cnt[x]++;
	}
	ll sumval(ll x){
		ll re=0;
		for(;x;x^=(x&(-x))) re+=a[x];
		return re;
	}
	ll sumcnt(ll x){
		ll re=0;
		for(;x;x^=(x&(-x))) re+=cnt[x];
		return re;
	}
}
ll w[200010],v[200010];
struct query{
	ll pos,f,ori,re,cnt;
}q[400010];
int bl[200010],br[200010];
inline bool cmp(query l,query r){
	return l.pos<r.pos;
}
ll check(ll lim){
	if(lim<=0) return 1e15;
//	cout<<"check "<<lim<<'\n';
	BIT::init();
	ll i,j=1,re=0;
	while(j<=m*2&&q[j].pos==0) j++;
	for(i=1;i<=n;i++){
		BIT::add(w[i],v[i]);
		while(j<=m*2&&q[j].pos==i){
			q[j].re=(BIT::sumval(1e6)-BIT::sumval(lim-1))*q[j].f;
			q[j].cnt=(BIT::sumcnt(1e6)-BIT::sumcnt(lim-1))*q[j].f;
//			cout<<"	do query "<<j<<' '<<q[j].pos<<' '<<q[j].f<<' '<<q[j].re<<' '<<q[j].cnt<<'\n';
			j++;
		}
	}
	for(i=1;i<=m;i++){
//		cout<<"	chk prob "<<i<<' '<<bl[i]<<' '<<br[i]<<'\n';
		re+=(q[br[i]].re+q[bl[i]].re)*(q[br[i]].cnt+q[bl[i]].cnt);
	}
	return re;
}
int main(){
	freopen("in.in","r",stdin);
	n=read();m=read();S=read();ll i;
	for(i=1;i<=n;i++){
		w[i]=read();v[i]=read();
	}
	for(i=1;i<=m;i++){
		q[i].pos=read();q[i].f=-1;q[i].pos--;
		q[i+m].pos=read();q[i+m].f=1;
		q[i].ori=q[i+m].ori=i;
	}
	sort(q+1,q+m*2+1,cmp);
	for(i=1;i<=m*2;i++){
//		cout<<"check query "<<i<<' '<<q[i].pos<<' '<<q[i].f<<'\n';
		if(~q[i].f) br[q[i].ori]=i;
		else bl[q[i].ori]=i;
	}
//	system("pause");
	ll l=0,r=1e6,mid;
	while(l<r-1){
		mid=(l+r)>>1;
		if(check(mid)>=S) l=mid;
		else r=mid;
	}
	printf("%lld\n",min(min(abs(S-check(l-1)),abs(S-check(r+1))),min(abs(S-check(l)),abs(S-check(r)))));
}
