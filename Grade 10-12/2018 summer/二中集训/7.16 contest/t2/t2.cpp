#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
ll n,m,first[100010],f[100010],cnte,cnta,dep[100010],st[100010][20];
ll find(ll x){return ((f[x]==x)?x:(f[x]=find(f[x])));}
void join(ll x,ll y){
	ll fx=find(x),fy=find(y);
	f[fx]=fy;
}
struct edge1{
	ll from,to,w;
}e[600010];
inline void add1(ll u,ll v,ll w){
	e[++cnte]=(edge1){u,v,w};
}
bool cmp(edge1 l,edge1 r){
	return l.w<r.w;
}
int ch[4000010][2],siz[4000010],cnt;
ll insert(ll l,ll r,ll pre,ll pos){
	ll cur=++cnt,mid=(l+r)>>1;
//	assert(cnt<=4000000);assert(l<=pos&&pos<=r);
	siz[cur]=siz[pre]+1;ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];
	if(l==r) return cur;
	if(mid>=pos) ch[cur][0]=insert(l,mid,ch[pre][0],pos);
	else ch[cur][1]=insert(mid+1,r,ch[pre][1],pos);
	return cur;
}
ll getval(ll l,ll r,ll ql,ll qr,ll u,ll v,ll lca){
	ll mid=(l+r)>>1,re=0;
	if(l>=ql&&r<=qr) return siz[u]+siz[v]-2*siz[lca];
	if(mid>=ql) re+=getval(l,mid,ql,qr,ch[u][0],ch[v][0],ch[lca][0]);
	if(mid<qr) re+=getval(mid+1,r,ql,qr,ch[u][1],ch[v][1],ch[lca][1]);
	return re;
}
ll getmax(ll l,ll r,ll u,ll v,ll lca){
	ll mid=(l+r)>>1,tmp=siz[ch[u][1]]+siz[ch[v][1]]-2*siz[ch[lca][1]];
	if(l==r) return l;
	if(tmp) return getmax(mid+1,r,ch[u][1],ch[v][1],ch[lca][1]);
	else return getmax(l,mid,ch[u][0],ch[v][0],ch[lca][0]);
}
ll query(ll l,ll r,ll u,ll v,ll lca,ll pos,ll tmpval,ll tsum){
//	assert(u&&v&&lca);
	ll mid=(l+r)>>1,tmpl;
	tmpl=siz[ch[u][0]]+siz[ch[v][0]]-2*siz[ch[lca][0]];
//	cout<<"query "<<l<<' '<<r<<' '<<u<<' '<<v<<' '<<lca<<' '<<pos<<'\n';
//	cout<<"son "<<ch[u][0]<<' '<<ch[u][1]<<' '<<ch[v][0]<<' '<<ch[v][1]<<' '<<ch[lca][0]<<' '<<ch[lca][1]<<'\n';
//	cout<<"val "<<tmpval<<' '<<tsum<<' '<<tmpl<<'\n';
	if(mid>=pos) return query(l,mid,ch[u][0],ch[v][0],ch[lca][0],pos,tmpval,tsum);
	if(mid<pos){
		if(!(tsum-tmpl-tmpval)) return getmax(l,mid,ch[u][0],ch[v][0],ch[lca][0]);
		else return query(mid+1,r,ch[u][1],ch[v][1],ch[lca][1],pos,tmpval,tsum-tmpl);
	}
}
struct edge{
	ll to,next,w;
}a[200010];ll rt[100010];
inline void add(ll u,ll v,ll w){
//	cout<<"add "<<u<<' '<<v<<' '<<w<<'\n';
	a[++cnta]=(edge){v,first[u],w};first[u]=cnta;
	a[++cnta]=(edge){u,first[v],w};first[v]=cnta; 
}
//int dfsclk=0;
void dfs(ll u,ll f,ll prew){
	ll i,v;dep[u]=dep[f]+1;st[u][0]=f;
//	dfsclk++;if(dfsclk%1000==0) cout<<dfsclk<<'\n';
//	if(dfsclk>=23000) cout<<"dfs "<<u<<' '<<f<<' '<<prew<<'\n';
	if(u!=1) rt[u]=insert(0,1e9,rt[f],prew);
//	assert(prew<65282);
//	assert(u);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
//		if(dfsclk>=23000) cout<<"	dfs "<<u<<' '<<v<<'\n';
		dfs(v,u,a[i].w);
	}
}
void ST(){
	ll i,j;
	for(j=1;j<=19;j++)
		for(i=1;i<=n;i++) st[i][j]=st[st[i][j-1]][j-1];
}
ll lca(ll l,ll r){
	ll i;
	if(dep[l]>dep[r]) swap(l,r);
	for(i=19;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
	if(l==r) return l;
	for(i=19;i>=0;i--){
		if(st[l][i]!=st[r][i]){
			l=st[l][i];
			r=st[r][i];
		}
	}
	return st[l][0];
}
ll in[300010],ans;
int main(){
//	freopen("7.in","r",stdin);
//	freopen("my.out","w",stdout);
	n=read();m=read();ll i,t1,t2,t3,tans=1e9;
	for(i=1;i<=n;i++) f[i]=i;
	memset(first,-1,sizeof(first));
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add1(t1,t2,t3);
	}
	sort(e+1,e+m+1,cmp);
	for(i=1;i<=m;i++){
		if(find(e[i].from)==find(e[i].to)) continue;
//		cout<<"do "<<i<<'\n';
		add(e[i].from,e[i].to,e[i].w);join(e[i].from,e[i].to);in[i]=1;
		ans+=e[i].w;
	}
	dfs(1,0,0);
//	cout<<"finish dfs\n";
	for(i=1;i<=m;i++){
		t1=e[i].from;t2=e[i].to;t3=lca(t1,t2);
		if(in[i]) continue;
//		cout<<"do edge "<<i<<'\n';
		tans=min(tans,e[i].w-query(0,1e9,rt[t1],rt[t2],rt[t3],e[i].w,getval(0,1e9,e[i].w,e[i].w,rt[t1],rt[t2],rt[t3]),getval(0,1e9,0,e[i].w,rt[t1],rt[t2],rt[t3])));
	}
	printf("%lld\n",tans+ans);
} 
