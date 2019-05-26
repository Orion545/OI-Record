#include<cstdio>
#include<cassert>
#include<cstring>
#include<algorithm>
#include<iostream>
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
int fa[600010],ch[600010][2],val[600010],minn[600010],rev[600010];
struct edge{
	int u,v;
}e[400010];
void update(int x){
	minn[x]=x;
	if(val[minn[x]]>val[minn[ch[x][0]]]) minn[x]=minn[ch[x][0]];
	if(val[minn[x]]>val[minn[ch[x][1]]]) minn[x]=minn[ch[x][1]];
//	cout<<"		update "<<x<<' '<<fa[x]<<' '<<ch[x][0]<<' '<<ch[x][1]<<' '<<minn[x]<<' '<<val[minn[x]]<<' '<<rev[x]<<'\n';
}
void pushrev(int x){
	if(!x) return;
	swap(ch[x][0],ch[x][1]);
	rev[x]^=1;
}
void pushdown(int x){
//	cout<<"								pushdown "<<x<<'\n';
	if(!rev[x]) return;
	pushrev(ch[x][0]);
	pushrev(ch[x][1]);
	rev[x]=0;
}
bool nroot(int x){return (ch[fa[x]][0]==x||ch[fa[x]][1]==x);}
int get(int x){return ch[fa[x]][1]==x;}
void push(int x){
	if(nroot(x)) push(fa[x]);
	pushdown(x);
}
void rotate(int x){
	int f=fa[x],ff=fa[f],son=get(x),nr=nroot(f);
//	cout<<"	rotate "<<x<<' '<<f<<' '<<ff<<' '<<son<<' '<<nr<<' '<<ch[x][0]<<' '<<ch[x][1]<<' '<<ch[f][0]<<' '<<ch[f][1]<<'\n';
	assert(f!=x);
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=x;ch[x][son^1]=f;
	fa[x]=ff;
	if(nr) ch[ff][ch[ff][1]==f]=x;
	update(f);update(x);
}
void splay(int x){
//	cout<<"splay "<<x<<'\n';
	push(x);
	for(int f;nroot(x);rotate(x)){
		f=fa[x];
		if(nroot(f))
			rotate((get(x)==get(f))?f:x);
	}
}
void access(int x){
//	cout<<"access "<<x<<'\n';
	for(int y=0;x;y=x,x=fa[x]){
//		cout<<"	doing access*** "<<y<<'\n';
		splay(x);ch[x][1]=y;update(x);
	}
}
void mroot(int x){
//	cout<<"***process mroot "<<x<<'\n';
	access(x);splay(x);pushrev(x);
}
void link(int u,int v){
	mroot(u);fa[u]=v;
}
void cut(int u,int v){
	mroot(u);access(v);splay(v);
//	cout<<"***************cut "<<u<<' '<<v<<'\n';
	fa[u]=ch[v][0]=0;update(v);
}
int query(int u,int v){
	mroot(u);access(v);splay(v);
	return minn[v];
}
int find(int u){
	access(u);splay(u);
	while(ch[u][0]) u=ch[u][0];
	return u;
}
int ntr[400010],root[400010];//what a sad story
int lc[4000010],rc[4000010];int seg[4000010],cnt;
int insert(int l,int r,int pos,int pre){
	int cur=++cnt,mid=(l+r)>>1;
	lc[cur]=lc[pre];rc[cur]=rc[pre];seg[cur]=seg[pre]+1;
	if(l==r) return cur;
	if(mid>=pos) lc[cur]=insert(l,mid,pos,lc[pre]);
	else rc[cur]=insert(mid+1,r,pos,rc[pre]);
	return cur;
}
int query(int l,int r,int ql,int qr,int pre,int cur){
//	cout<<"query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<pre<<' '<<cur<<'\n';
	if(l>=ql&&r<=qr) return seg[cur]-seg[pre];
	int mid=(l+r)>>1;int re=0;
	if(mid>=ql) re+=query(l,mid,ql,qr,lc[pre],lc[cur]);
	if(mid<qr) re+=query(mid+1,r,ql,qr,rc[pre],rc[cur]);
	return re;
}
int n,m,q;
void init(){
	n=read();m=read();q=read();cnt=0;memset(root,0,sizeof(root));memset(ntr,0,sizeof(ntr));
	val[0]=1e9;
	memset(lc,0,sizeof(lc));memset(rc,0,sizeof(rc));memset(seg,0,sizeof(seg));
	for(int i=1;i<=n;i++) fa[i]=0,rev[i]=0,ch[i][0]=ch[i][1]=0,minn[i]=i,val[i]=1e9;
}
int main(){
	int T=read(),i,t1,t2,tmp,id;
	while(T--){
		init();
		for(i=1;i<=m;i++){
			t1=read();t2=read();
			e[i]=(edge){t1,t2};
//			cout<<"input "<<t1<<' '<<t2<<'\n';
			if(t1==t2){ntr[i]=i;continue;}//how can someone ntr him/herself ......
			if(find(t1)==find(t2)){
				tmp=query(t1,t2);id=val[tmp];
				ntr[i]=id;
				cut(tmp,e[id].u);
				cut(tmp,e[id].v);
			}
			else ntr[i]=0;
			fa[n+i]=ch[n+i][1]=ch[n+i][0]=0;rev[n+i]=0;
			val[n+i]=i;minn[n+i]=n+i;
			link(n+i,t1);link(n+i,t2);
		}
//		for(i=1;i<=m;i++) cout<<i<<' '<<ntr[i]<<'\n';
		for(i=1;i<=m;i++) root[i]=insert(0,m,ntr[i],root[i-1]);
		while(q--){
			t1=read();t2=read();
			printf("%d\n",n-query(0,m,0,t1-1,root[t1-1],root[t2]));
		}
	}
}
