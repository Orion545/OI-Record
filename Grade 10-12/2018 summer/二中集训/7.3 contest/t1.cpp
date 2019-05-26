#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define ll long long
#define inf 1e15
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
ll n,m,cnt,first[100010];
struct edge{
	ll to,next,w;
}a[200010];
ll dis[100010],st[100010][20],fa[100010],dep[100010];
ll dfn[100010],re[100010],dcl;
inline void add(ll u,ll v,ll w){
	a[++cnt]={v,first[u],w};first[u]=cnt;
}
void dfs(ll u,ll f,ll w){
	fa[u]=st[u][0]=f;dis[u]=dis[f]+w;dep[u]=dep[f]+1;
	dfn[u]=++dcl;re[dcl]=u;
	ll i,v;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(v==f) continue;
		dfs(v,u,a[i].w);
	}
}
void init(){
	ll i,j;
	for(j=1;j<=19;j++){
		for(i=1;i<=n;i++) st[i][j]=st[st[i][j-1]][j-1];
	}
}
ll lca(ll l,ll r){
	ll i;
	l=re[l];r=re[r];
//	cout<<"lca "<<l<<' '<<r<<'\n';
	if(dep[l]>dep[r]) swap(l,r);
	for(i=19;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
//	cout<<"first "<<l<<' '<<r<<'\n';
	if(l==r) return l;
	for(i=19;i>=0;i--){
		if(st[r][i]!=st[l][i]){
			r=st[r][i];
			l=st[l][i];
		}
	}
//	cout<<"final "<<l<<' '<<r<<'\n';
	return fa[l];
}
inline ll getdis(ll l,ll r){
	ll ree=dis[re[l]]+dis[re[r]]-2*dis[lca(l,r)];
//	cout<<"ree "<<ree<<'\n';
	return ree;
}
set<ll>s;bool in[100010];
int main(){
	memset(first,-1,sizeof(first));
	set<ll>::iterator it,l,r;
	n=read();m=read();ll i,t1,t2,t3,tans=0;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);add(t2,t1,t3);
	}
	dfs(1,0,0);init();s.clear();
	for(i=1;i<=m;i++){
		t1=read();in[t1]=!in[t1];
		t2=t3=0;
		if(in[t1]){
			s.insert(dfn[t1]);
			it=s.find(dfn[t1]);
			if(it!=s.begin()) it--,l=it,it++,t2=*l;
			if((++it)!=s.end()) r=it,it--,t3=*r;
			if(t2&&t3) tans+=getdis(dfn[t1],t2)+getdis(dfn[t1],t3)-getdis(t2,t3);
			if(!t2&&t3) tans+=getdis(dfn[t1],t3);
			if(t2&&!t3) tans+=getdis(dfn[t1],t2);
			if(!t2&&!t3) tans=0;
		}
		else{
			it=s.find(dfn[t1]);
			if(it!=s.begin()) it--,l=it,it++,t2=*l;
			if((++it)!=s.end()) r=it,it--,t3=*r;
			if(t2&&t3) tans-=getdis(dfn[t1],t2)+getdis(dfn[t1],t3)-getdis(t2,t3);
			if(!t2&&t3) tans-=getdis(dfn[t1],t3);
			if(t2&&!t3) tans-=getdis(dfn[t1],t2);
			if(!t2&&!t3) tans=0;
			s.erase(dfn[t1]);
		}
//		cout<<s.size()<<' '<<tans<<'\n';
//		cout<<t2<<' '<<dfn[t1]<<' '<<t3<<'\n';
		if(s.size()){
			it=s.end();it--;
			printf("%lld\n",tans+getdis(*s.begin(),*it));
		} 
		else printf("%lld\n",tans);
	}
}
