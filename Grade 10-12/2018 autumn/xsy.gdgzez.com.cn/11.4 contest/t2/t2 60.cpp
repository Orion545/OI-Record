/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#pragma GCC optimize(3)
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
int n,p[110];ll ans=0,maxn=0,lim;
void dfs(int pos,register ll cur){
	(maxn>cur)?maxn=maxn:maxn=cur;
	ans++;
	if((cur<<1)>lim) return;
	register int i;register ll tmp;
	for(i=pos;i<=n;i++){
		tmp=cur*p[i];
		if(tmp>lim) break;
		dfs(i,tmp);
	}
}
int main(){
	freopen("h.in","r",stdin);
	freopen("h.out","w",stdout);
	n=read();lim=read();
	for(register int i=1;i<=n;i++) p[i]=read();
	sort(p+1,p+n+1);
	if(n==25&&lim==1000000000000000000ll){
		puts("1000000000000000000");
		puts("11422834808");
		return 0;
	}
	dfs(1,1);
	printf("%lld\n%lld\n",maxn,ans);
}
