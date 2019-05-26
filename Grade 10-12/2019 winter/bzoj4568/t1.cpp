#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
struct lb{
	ll a[61];int cnt;
	lb(){cnt=0;memset(a,0,sizeof(a));}
	inline void insert(ll x){
		for(int i=60;~i;i--){
			if((1ll<<i)&x){
//				cout<<"insert "<<x<<' '<<i<<' '<<(1ll<<i)<<' '<<((1ll<<i)&x)<<'\n';
				if(!a[i]){a[i]=x;cnt++;break;}
				else x^=a[i];
			}
			if(!x) return;
		}
	}
	inline ll query(){
		ll ans=0;
		for(int i=60;~i;i--){
			if(a[i]) ans=max(ans,ans^a[i]);
//			if(a[i]) cout<<"query "<<i<<' '<<a[i]<<' '<<ans<<'\n';
		}
		return ans;
	}
}b[20010][15];
lb merge(lb x,lb y){
	if(x.cnt>y.cnt){
		for(int i=60;~i;i--) if(y.a[i]) x.insert(y.a[i]);
		return x;
	}
	else{
		for(int i=60;~i;i--) if(x.a[i]) y.insert(x.a[i]);
		return y;
	}
}
int n,m,first[20010],cnte=-1;
struct edge{
	int to,next;
}a[40010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int st[20010][15],dep[20010];ll val[20010];
void dfs(int u,int f){
	int i,v;
	st[u][0]=f;dep[u]=dep[f]+1;
	b[u][0].insert(val[u]);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
	}
}
void ST(){
	int i,j;
	for(j=1;j<15;j++){
		for(i=1;i<=n;i++){
			st[i][j]=st[st[i][j-1]][j-1];
			b[i][j]=merge(b[i][j-1],b[st[i][j-1]][j-1]);
		}
	}
}
ll getlca(int l,int r){
	int i;lb re;
	if(dep[l]>dep[r]) swap(l,r);
//	cout<<"begin lca "<<l<<' '<<r<<' '<<re.query()<<'\n';
	for(i=14;i>=0;i--) if(dep[st[r][i]]>=dep[l]){
		re=merge(re,b[r][i]);
		r=st[r][i];
	}
//	cout<<"middle "<<l<<' '<<r<<' '<<re.query()<<'\n';
	if(l==r) return merge(re,b[r][0]).query();
	for(i=14;i>=0;i--){
		if(st[l][i]==st[r][i]) continue;
		re=merge(re,b[l][i]);l=st[l][i];
		re=merge(re,b[r][i]);r=st[r][i];
	}
//	cout<<"end "<<l<<' '<<r<<' '<<re.query()<<'\n';
	return merge(b[l][0],merge(b[r][0],merge(re,b[st[l][0]][0]))).query();
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2;
	for(i=1;i<=n;i++) val[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs(1,0);
	ST();
	while(m--){
		t1=read();t2=read();
		printf("%lld\n",getlca(t1,t2));
	}
}
