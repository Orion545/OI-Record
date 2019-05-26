#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
ll first[500010],cnt;
struct edge{
	ll to,next;
}a[1000010];
inline void add(ll u,ll v){
	a[++cnt]=(edge){v,first[u]};first[u]=cnt;
	a[++cnt]=(edge){u,first[v]};first[v]=cnt;
}
ll n,st,ed,root,siz[300010];
int dfs(ll u,ll f){
	ll i,v,re=(u!=ed),tmp;siz[u]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		tmp=dfs(v,u);
		re=re&tmp;
		if(tmp) siz[u]+=siz[v];
	}
	return re;
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();st=read();ed=read();ll i,t1,t2;
	root=st;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs(root,0);
	printf("%I64d",(n*(n-1)-siz[st]*siz[ed]));
}
