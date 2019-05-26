#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int ch[100010][2],fa[100010],siz[100010],vir[100010],rev[100010];
void update(int cur){
	siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]]+vir[cur]+1;
//	cout<<"update "<<cur<<' '<<ch[cur][0]<<' '<<ch[cur][1]<<' '<<vir[cur]<<' '<<siz[cur]<<'\n';
}
void pushrev(int cur){
	if(!cur) return;
	swap(ch[cur][0],ch[cur][1]);
	rev[cur]^=1;
}
void pushdown(int cur){
	if(!rev[cur]) return;
	pushrev(ch[cur][0]);
	pushrev(ch[cur][1]);
	rev[cur]=0;
}
bool nroot(int cur){return (ch[fa[cur]][0]==cur)||(ch[fa[cur]][1]==cur);}
int get(int cur){return ch[fa[cur]][1]==cur;}
void push(int cur){
	if(nroot(cur)) push(fa[cur]);
	pushdown(cur);
}
void rotate(int x){
	int f=fa[x],ff=fa[f],son=get(x),nr=nroot(f);
//	cout<<"rotate "<<x<<' '<<f<<' '<<ff<<' '<<son<<' '<<nr<<'\n';
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=x;ch[x][son^1]=f;
	fa[x]=ff;
	if(nr) ch[ff][ch[ff][1]==f]=x;
	update(f);update(x);
}
void splay(int x){
	push(x);
	for(int f;nroot(x);rotate(x)){
		f=fa[x];
		if(nroot(f))
			rotate((get(f)==get(x))?f:x);
	}
}
void access(int x){
	for(int y=0;x;y=x,x=fa[x]){
		splay(x);
		vir[x]+=siz[ch[x][1]];
		ch[x][1]=y;
		vir[x]-=siz[ch[x][1]];
		update(x);
	}
}
void mroot(int x){
	access(x);splay(x);pushrev(x);
}
void link(int u,int v){
	mroot(u);mroot(v);
	fa[u]=v;vir[v]+=siz[u];
}
ll query(int u,int v){
	mroot(u);access(v);splay(v);
//	cout<<"query "<<u<<' '<<v<<' '<<siz[u]<<' '<<siz[v]<<'\n';
	return (ll)((ll)(siz[v]-siz[u])*(ll)siz[u]);
}
int n,Q;
int main(){
	n=read();Q=read();int i,t1,t2;char s[10];
	for(i=1;i<=n;i++) fa[i]=ch[i][0]=ch[i][1]=0,siz[i]=1,vir[i]=rev[i]=0;
	while(Q--){
		scanf("%s",s);t1=read();t2=read();
		if(s[0]=='A') link(t1,t2);
		else printf("%lld\n",query(t1,t2));
	}
}
