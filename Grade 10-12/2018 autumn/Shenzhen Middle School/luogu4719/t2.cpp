#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
struct mat{
	int a00,a01,a10,a11;
	mat(){a00=a01=a10=a11=0;}
	void init(int aa,int bb){a00=a01=aa;a10=bb;a11=-1e9;}
	inline mat operator *(const mat &b)const{
		mat re;
		re.a00=max(a00+b.a00,a01+b.a10);
		re.a01=max(a00+b.a01,a01+b.a11);
		re.a10=max(a10+b.a00,a11+b.a10);
		re.a11=max(a10+b.a01,a11+b.a11);
		return re;
	}
};
int n,m,first[100010],w[100010],cnte=1,dp[100010][2],g[100010][2];
struct edge{
	int to,next;
}a[200010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
namespace lct{
	int ch[100010][2],fa[100010],rev[100010],f[100010][2];
	mat a[100010];
	inline void update(int cur){
		a[cur].init(f[cur][0],f[cur][1]);
		if(ch[cur][0]) a[cur]=a[ch[cur][0]]*a[cur];
		if(ch[cur][1]) a[cur]=a[cur]*a[ch[cur][1]];
	}
	inline void pushrev(int cur){
		if(!cur) return;
		swap(ch[cur][0],ch[cur][1]);
		rev[cur]^=1;
	}
	inline void pushdown(int cur){
		if(!rev[cur]) return;
		pushrev(ch[cur][0]);
		pushrev(ch[cur][1]);
		rev[cur]=0;
	}
	inline bool nroot(int cur){return (ch[fa[cur]][0]==cur||ch[fa[cur]][1]==cur);}
	inline void push(int cur){
		if(nroot(cur)) push(fa[cur]);
		pushdown(cur);
	}
	inline bool get(int cur){return ch[fa[cur]][1]==cur;}
	inline void rotate(int cur){
		int f=fa[cur],ff=fa[f],son=get(cur),nr=nroot(f);
//		cout<<"rotate "<<cur<<' '<<f<<' '<<ff<<' '<<son<<'\n';
		ch[f][son]=ch[cur][son^1];
		if(ch[f][son]) fa[ch[f][son]]=f;
		fa[f]=cur;ch[cur][son^1]=f;
		fa[cur]=ff;
		if(nr) ch[ff][ch[ff][1]==f]=cur;
		update(f);update(cur);
	}
	inline void splay(int x){
		push(x);
		for(int f=fa[x];nroot(x);rotate(x)){
			f=fa[x];
//			cout<<"splay "<<x<<' '<<f<<' '<<nroot(f)<<'\n';
			if(nroot(f))
				rotate((get(f)==get(x))?f:x);
		}
	}
	inline void access(int x){
		for(int y=0;x;y=x,x=fa[x]){
			splay(x);
			if(ch[x][1]){
				f[x][0]+=max(a[ch[x][1]].a00,a[ch[x][1]].a10);
				f[x][1]+=a[ch[x][1]].a00;
			}
			if(y){
				f[x][0]-=max(a[y].a00,a[y].a10);
				f[x][1]-=a[y].a00;
			}
			ch[x][1]=y;update(x);
		}
	}
}
void dfs(int u,int f){
	int i,v;
	dp[u][0]=0;dp[u][1]=w[u];
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
		dp[u][0]+=max(dp[v][0],dp[v][1]);
		dp[u][1]+=dp[v][0];
	}
	lct::a[u].init(dp[u][0],dp[u][1]);
	lct::fa[u]=f;
	lct::rev[u]=lct::ch[u][0]=lct::ch[u][1]=0;
	lct::f[u][0]=dp[u][0];
	lct::f[u][1]=dp[u][1];
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2;
	for(i=1;i<=n;i++) w[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs(1,0);
	while(m--){
		t1=read();t2=read();
		lct::access(t1);
		lct::splay(t1);
		lct::f[t1][1]+=t2-w[t1];
		w[t1]=t2;
		lct::update(t1);
		lct::splay(1);
		printf("%d\n",max(lct::a[1].a00,lct::a[1].a10));
	}
}
