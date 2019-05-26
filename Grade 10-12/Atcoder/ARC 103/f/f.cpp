#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<vector>
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
ll n;
struct node{
	ll num,dis;
}a[100010];
ll siz[100010],fa[100010],d[100010],dep[100010];
vector<ll>son[100010];
bool cmp(node l,node r){
	return l.dis<r.dis;
}
void dfs(ll u,ll f){
	ll i;dep[u]=dep[f]+1;
//	cout<<u<<' '<<dep[u]<<"***\n";
	for(auto v:son[u]){
		if(v!=f) dfs(v,u);
	}
}
int main(){
	n=read();ll i;
	for(i=1;i<=n;i++) a[i].dis=read(),a[i].num=i;
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++) d[i]=a[i].dis;
	for(i=n;i>=2;i--){
		siz[a[i].num]++;
		ll tmp=d[i]-(n-2*siz[a[i].num]);
		ll pos=lower_bound(d+1,d+i,tmp)-d;
//		cout<<i<<' '<<d[i]<<' '<<a[i].num<<' '<<siz[a[i].num]<<' '<<tmp<<' '<<pos<<' '<<a[pos].num<<' '<<d[pos]<<'\n';
		if(pos>=i||d[pos]!=tmp){
			puts("-1");return 0;
		}
		siz[a[pos].num]+=siz[a[i].num];fa[a[i].num]=a[pos].num;
	}
	std::ios::sync_with_stdio(false);
	for(i=1;i<=n;i++) if(fa[i]) son[fa[i]].push_back(i);
	dep[0]=-1;dfs(a[1].num,0);
	ll ans=0;
	for(i=1;i<=n;i++) ans+=dep[i];
	if(ans!=d[1]){
		puts("-1");return 0;
	}
	for(i=1;i<=n;i++) if(fa[i]) cout<<i<<' '<<fa[i]<<'\n';
} 
