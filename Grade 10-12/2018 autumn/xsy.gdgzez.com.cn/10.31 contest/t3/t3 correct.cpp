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
#include<queue>
#define ll long long
#define mp make_pair
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
priority_queue<pair<ll,int> >hole;
priority_queue<ll>mouse;
pair<ll,int>a[2000010];
ll ans=0;
void solveh(pair<ll,int>cur){
	ll delta;
	while(cur.second&&!mouse.empty()&&cur.first<mouse.top()){
		delta=cur.first-mouse.top();
		ans+=delta;cur.second--;
		mouse.pop();
		hole.push(mp(cur.first+delta,1));
	}
	if(cur.second) hole.push(cur);
}
void solvem(pair<ll,int>cur){
	ll val=1e16;
	if(!hole.empty()){
		pair<ll,int>tmp=hole.top();hole.pop();
		val=cur.first-tmp.first;
		tmp.second--;
		if(tmp.second) hole.push(tmp);
	}
	mouse.push(cur.first+val);
	ans+=val;
}
int n,m;
int main(){
	n=read();m=read();int i,t1,t2;ll tot=0;
	for(i=1;i<=n;i++){
		t1=read();a[i]=mp(t1,-2e9);
	}
	for(i=1;i<=m;i++){
		t1=read();t2=read();tot+=t2;
		a[i+n]=mp(t1,t2);
	}
	if(tot<n){puts("-1");return 0;}
	sort(a+1,a+n+m+1);
	for(i=1;i<=n+m;i++){
		if(a[i].second>-2e9) solveh(a[i]);
		else solvem(a[i]);
	}
	printf("%lld\n",ans);
}
