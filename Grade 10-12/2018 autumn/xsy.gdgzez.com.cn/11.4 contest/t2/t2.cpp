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
ll n,lim,half,p[30],cntp,q[30],cntq,l[15000000],r[15000000],cntl,cntr,ans,maxn;
void dfs1(int pos,register ll cur){
	l[++cntl]=cur;
//	cout<<"dfs1 "<<' '<<cur<<' '<<cur*p[1]<<' '<<lim<<'\n';
//	assert(cur==1000000000000ll);
	if((cur*p[1])>lim) return;
	register int i;
	register long double tmp;
	for(i=pos;i<=cntp;i++){
//		cout<<"	try "<<i<<' '<<p[i]<<'\n';
		tmp=(long double)cur*(long double)p[i];
//		tmp=(ll)(tmp+0.1);
		if(tmp>lim) break;
		dfs1(i,tmp);
	}
}
void dfs2(int pos,register ll cur){
	r[++cntr]=cur;
	if((cur*q[1])>lim) return;
	register int i;
	register long double tmp;
	for(i=pos;i<=cntq;i++){
		tmp=(long double)cur*(long double)q[i];
//		tmp=(ll)(tmp+0.1);
		if(tmp>lim) break;
		dfs2(i,tmp);
	}
}
int main(){
//	freopen("in.in","r",stdin);
	n=read();lim=read();half=sqrt(lim);
	int i,pos;
	for(i=1;i<=n;i++){
		pos=read();
		if(pos<=20) p[++cntp]=pos;
		else q[++cntq]=pos;
	}
	sort(p+1,p+cntp+1);
	sort(q+1,q+cntq+1);
	dfs1(1,1);dfs2(1,1);
//	cout<<"get "<<cntl<<' '<<cntr<<' '<<l[cntl]<<' '<<r[cntr]<<'\n';
	if(cntl<cntr){
		sort(r+1,r+cntr+1);
		for(i=1;i<=cntl;i++){
			pos=upper_bound(r+1,r+cntr+1,lim/l[i])-r-1;
			ans+=pos;
			maxn=max(maxn,l[i]*r[pos]);
		}
	}
	else{
		sort(l+1,l+cntl+1);
		for(i=1;i<=cntr;i++){
			pos=upper_bound(l+1,l+cntl+1,lim/r[i])-l-1;
//			cout<<"get "<<i<<' '<<r[i]<<' '<<pos<<' '<<l[pos]<<'\n';
			ans+=pos;
			maxn=max(maxn,r[i]*l[pos]);
		}
	}
	printf("%lld\n%lld\n",maxn,ans);
}
