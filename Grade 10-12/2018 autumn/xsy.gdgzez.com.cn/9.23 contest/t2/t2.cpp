#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,fa[200010],ch[200010][2],siz[200010],vir[200010],rev[200010];
inline void update(int cur){
	siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]]+1+vir[cur];
//	cout<<"			update "<<cur<<' '<<siz[cur]<<' '<<vir[cur]<<' '<<ch[cur][0]<<' '<<siz[ch[cur][0]]<<' '<<ch[cur][1]<<' '<<siz[ch[cur][1]]<<'\n';
}
inline bool nroot(int cur){return ((ch[fa[cur]][0]==cur)||(ch[fa[cur]][1]==cur));}
inline bool get(int cur){return ch[fa[cur]][1]==cur;}
inline void rotate(int cur){
	int f=fa[cur],ff=fa[f],son=get(cur),nr=nroot(f);
//	cout<<"		rotate "<<cur<<' '<<f<<' '<<ff<<' '<<son<<' '<<nr<<'\n';
	ch[f][son]=ch[cur][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	ch[cur][son^1]=f;fa[f]=cur;
	fa[cur]=ff;
	if(nr) ch[ff][ch[ff][1]==f]=cur;
	update(f);update(cur);
}
void pushrev(int x){
	if(!x) return;
	swap(ch[x][0],ch[x][1]);
	rev[x]^=1;
}
void pushdown(int x){
	if(rev[x]){
		pushrev(ch[x][0]);
		pushrev(ch[x][1]);
		rev[x]=0;
	}
}
void push(int x){
	if(nroot(x)) push(fa[x]);
	pushdown(x);
}
void splay(int x){
	push(x);
	for(int f;nroot(x);rotate(x)){
		f=fa[x];
		if(nroot(f))
			rotate((get(x)==get(f))?f:x);
	}
}
void access(int x){
	for(int y=0;x;y=x,x=fa[x]){
		splay(x);
		vir[x]+=(siz[ch[x][1]]);
		ch[x][1]=y;
		vir[x]-=(siz[y]);
		update(x);
	}
}
void mroot(int x){
	access(x);splay(x);pushrev(x);
}
void cut(int x,int y){
//	cout<<"cut "<<x<<' '<<y<<' '<<siz[x]<<' '<<siz[y]<<'\n';
	mroot(x);access(y);splay(y);
	ch[y][0]=0;fa[x]=0;update(y);
}
ll link(int x,int y){
	mroot(x);mroot(y);
//	cout<<"link "<<x<<' '<<y<<' '<<siz[x]<<' '<<siz[y]<<'\n';
	ll re=(ll)siz[x]*(ll)siz[y];
	fa[y]=x;vir[x]+=(siz[y]);update(x);
	return re;
}
struct edge{
	int u,v,w,f;
}a[400010];
inline bool cmp(edge l,edge r){
	if(l.w==r.w) return l.f<r.f;
	return l.w<r.w;
}
int main(){
	n=read();int i,t1,t2,t3,t4;ll ans=0;
	for(i=1;i<=n;i++) siz[i]=1,vir[i]=0,fa[i]=ch[i][0]=ch[i][1]=rev[i]=0;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();t4=read();
		a[i]=(edge){t1,t2,t3,0};
		a[n+i-1]=(edge){t1,t2,t4,1};
	}
	sort(a+1,a+(n<<1)-1,cmp);
//	for(i=1;i<=((n-1)<<1);i++) cout<<i<<' '<<a[i].u<<' '<<a[i].v<<' '<<a[i].w<<' '<<a[i].f<<'\n';
	for(i=1;i<=((n-1)<<1);i++){
		if(!a[i].f) ans+=link(a[i].u,a[i].v);
		else cut(a[i].u,a[i].v);
	}
	printf("%lld\n",ans);
}
