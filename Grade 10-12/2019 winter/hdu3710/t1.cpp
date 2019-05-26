#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#define ll long long
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
int n,m,base;
int dep[100010],siz[100010],son[100010],fa[100010],dfn[100010],back[1000010],clk,top[100010],re[100010],st[100010][20];
namespace ufs{
	int f[100010];
	void init(int s){for(register int i=1;i<=s;i++) f[i]=-1;}
	inline int find(int x){return ((f[x]<0)?x:(f[x]=find(f[x])));}
	inline int join(int x,int y){
		x=find(x);y=find(y);
		if(x==y) return 0;
		f[y]+=f[x];f[x]=y;return -f[y];
	}
}
namespace seg{
	int seg[400010];
	void build(int l,int r,int num){
		seg[num]=1e9;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,num<<1);build(mid+1,r,num<<1|1);
	}
	void change(int l,int r,int ql,int qr,int num,int val){
		if(l>=ql&&r<=qr){seg[num]=min(seg[num],val);return;}
		int mid=(l+r)>>1;
		if(mid>=ql) change(l,mid,ql,qr,num<<1,val);
		if(mid<qr) change(mid+1,r,ql,qr,num<<1|1,val);
	}
	int query(int l,int r,int pos,int num){
		if(l==r) return seg[num];
		int mid=(l+r)>>1;
		if(mid>=pos) return min(query(l,mid,pos,num<<1),seg[num]);
		else return min(query(mid+1,r,pos,num<<1|1),seg[num]);
	}
}
namespace t{
	int first[100010],cnte=-1;
	void init(){
		memset(first,-1,sizeof(first));
		cnte=-1;clk=0;
		memset(re,0,sizeof(re));memset(dfn,0,sizeof(dfn));
		memset(back,0,sizeof(back));memset(top,0,sizeof(top));
		memset(st,0,sizeof(st));
	}
	struct edge{
		int to,next,w;
	}a[200010];
	inline void add(int u,int v,int w){
//		cout<<"tree addedge "<<u<<' '<<v<<' '<<w<<'\n';
		a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
		a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
	}
	void dfs1(int u,int f){
		int i,v;
		dep[u]=dep[f]+1;fa[u]=f;st[u][0]=f;
		siz[u]=1;son[u]=0;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			dfs1(v,u);
			siz[u]+=siz[v];
			if(siz[son[u]]<siz[v]) son[u]=v;
		}
	}
	void dfs2(int u,int t){
		int i,v;
		top[u]=t;
		dfn[u]=++clk;back[clk]=u;
		if(son[u]) dfs2(son[u],t);
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==fa[u]||v==son[u]) continue;
			dfs2(v,v);
		}
	}
	void ST(){
		for(int j=1;j<=18;j++){
			for(int i=1;i<=n;i++) st[i][j]=st[st[i][j-1]][j-1];
		}
	}
	int getlca(int l,int r){
		if(l==r) return l;
		while(top[l]!=top[r]){
			if(dep[top[l]]>=dep[top[r]]) swap(l,r);
			r=fa[top[r]];
		}
		if(dep[l]>dep[r]) swap(l,r);
		return l;
	}
	void solve(int l,int r,int val){
		int lca=getlca(l,r),tmp,i;
		if(dep[l]>dep[lca]+1){
			tmp=l;
			for(i=18;i>=0;i--) if(dep[st[tmp][i]]>dep[lca]+1) tmp=st[tmp][i];
			while(top[l]!=top[tmp]){
				seg::change(1,n,dfn[top[l]],dfn[l],1,val);
				l=fa[top[l]];
			}
			seg::change(1,n,dfn[tmp],dfn[l],1,val);
		}
		if(dep[r]>dep[lca]+1){
			tmp=r;
			for(i=18;i>=0;i--) if(dep[st[tmp][i]]>dep[lca]+1) tmp=st[tmp][i];
			while(top[r]!=top[lca]){
				seg::change(1,n,dfn[top[r]],dfn[r],1,val);
				r=fa[top[r]];
			}
			seg::change(1,n,dfn[tmp],dfn[r],1,val);
		}
	}
}
namespace ori{
	int cnte=-1;
	int id[100010],belong[100010];
	struct edge{
		int from,to,w,flag;
	}a[100010];
	vector<edge>e[100010];
	void init(){
		cnte=-1;
		memset(id,0,sizeof(id));
		memset(a,0,sizeof(a));
	}
	inline bool cmp(edge l,edge r){return l.w<r.w;}
	inline void add(int u,int v,int w){
//		cout<<"original add "<<u<<' '<<v<<' '<<w<<'\n';
		a[++cnte]=(edge){u,v,w,0};
	}
	int kruskal(){
		int i,u,v,ans=0,tmp,debug=0;
		sort(a,a+cnte+1,cmp);
		ufs::init(n);
		for(i=0;i<=cnte;i++){
			u=a[i].from;v=a[i].to;
			if(tmp=ufs::join(u,v)){
				a[i].flag=1;debug++;
				t::add(u,v,a[i].w);
				ans+=a[i].w;
				if(tmp==n) break;
			}
		}
		assert(debug==n-1);
		return ans;
	}
	void solve(){
		int i,tmp;
		for(i=0;i<=cnte;i++){
			if(a[i].flag) continue;
			tmp=t::getlca(a[i].from,a[i].to);
			if(tmp!=a[i].from&&tmp!=a[i].to) e[tmp].push_back(a[i]);
			t::solve(a[i].from,a[i].to,a[i].w);
		}
	}
	inline int findb(int x){return ((belong[x]==x)?x:(belong[x]=findb(belong[x])));}
	void getans(int u,int fromw){
		int i,v,tot=0,x,y,cur=0,tmp=(n!=1),pre=e[u].size();
		if(u!=1) id[fa[u]]=++tot;
		for(i=t::first[u];~i;i=t::a[i].next){
			v=t::a[i].to;if(v==fa[u]) continue;
			getans(v,t::a[i].w);
			id[v]=++tot;
			fromw+=t::a[i].w;
//			cout<<"receiving new son of "<<u<<" from son "<<v<<", giving id of "<<id[v]<<'\n';
			if(u!=1&&seg::query(1,n,dfn[v],1)!=1e9) e[u].push_back((edge){id[fa[u]],id[v],seg::query(1,n,dfn[v],1),0});
		}
		for(i=0;i<pre;i++){
			e[u][i].from=id[findb(e[u][i].from)];
			e[u][i].to=id[findb(e[u][i].to)];
		}
		sort(e[u].begin(),e[u].end(),cmp);
//		if(u==29) cout<<"check edges when digged node "<<u<<'\n';
//		if(u==29) for(i=0;i<e[u].size();i++) cout<<'	'<<i<<' '<<e[u][i].from<<' '<<e[u][i].to<<' '<<e[u][i].w<<'\n';
		ufs::init(tot);
		for(i=0;i<e[u].size();i++){
			x=e[u][i].from;y=e[u][i].to;
			assert(x<=tot);
			assert(y<=tot);
			if(tmp=ufs::join(x,y)){
				cur+=e[u][i].w;
				if(tmp==tot) break;
			}
		}
//		if(u==29) cout<<"finish getans "<<u<<' '<<base<<' '<<fromw<<' '<<cur<<'\n';
		if(tot==1||tmp==tot) re[u]=base-fromw+cur;
		else re[u]=1e9;
		e[u].clear();
		for(i=t::first[u];~i;i=t::a[i].next) if(t::a[i].to!=fa[u]) belong[t::a[i].to]=u;
	}
}

int main(){
	int T=read(),i,j,t1,t2,t3,t4,tmp;
	while(T--){
		n=read();m=read();
		ori::init();t::init();
		for(i=1;i<=n;i++) ori::belong[i]=i;
		for(i=1;i<=m;i++){
			t1=read();t2=read();t3=read();t4=read();
			ori::add(t1,t2,t3*(1-t4));
		}
		base=ori::kruskal();
		t::dfs1(1,0);
		t::dfs2(1,1);
		t::ST();
		seg::build(1,n,1);
		ori::solve();
		ori::getans(1,0);
		for(i=1;i<=n;i++){
			if(re[i]!=1e9) printf("%d\n",re[i]);
			else puts("inf");
		}
		fflush(stdout);
	}
}
