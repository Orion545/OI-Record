#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
struct node{
	ll rk,t,c;
	node(){rk=t=c=0;}
	friend inline bool operator <(node l,node r){
		return l.rk>r.rk;
	}
}a[100010];ll n,enter[100010],out[100010];
inline bool cmp(node l,node r){
	return l.t<r.t;
}
priority_queue<node>q;
int main(){
	freopen("convention2.in","r",stdin);
	freopen("convention2.out","w",stdout);
	n=read();ll i;
	for(i=1;i<=n;i++){
		a[i].rk=i;
		a[i].t=read();
		a[i].c=read();
	}
	sort(a+1,a+n+1,cmp);
	ll cur=a[1].t,j;node tmp;
	for(i=1,j=0;i<=n;i++){
		if(i>j&&a[j+1].t>cur) cur=a[i].t;
		while(j<n&&a[j+1].t<=cur) j++,enter[a[j].rk]=a[j].t,q.push(a[j]);
//		cout<<i<<' '<<j<<' '<<q.size()<<' '<<cur<<'\n';
		tmp=q.top();q.pop();
		out[tmp.rk]=cur;cur+=tmp.c;
	}
	ll ans=0;
	for(i=1;i<=n;i++) ans=max(ans,out[i]-enter[i]);
	cout<<ans<<'\n';
}
