#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define MOD 2147483647
#define ll long long
#define uint int
#define log logg
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,first[200010],dfn[200010],dep[200010],lim[200010],cnte,clk,fa[200010];
int euler[1000010],pos[200010],st[1000010][21],cntu,log[1000010];
struct edge{
	int to,next;
}a[400010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;dfn[u]=++clk;dep[u]=dep[f]+1;fa[u]=f;
	euler[++cntu]=u;pos[u]=cntu;
//	cout<<"enter dfs "<<u<<' '<<f<<' '<<dfn[u]<<' '<<dep[u]<<' '<<cntu<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);euler[++cntu]=u;
	}
	lim[u]=clk;
//	cout<<"finish dfs "<<u<<' '<<lim[u]<<' '<<cntu<<'\n';
}
void init(){
	log[1]=0;int i,j;
	for(i=2;i<=cntu;i++) log[i]=log[i/2]+1;
	for(i=1;i<=cntu;i++) st[i][0]=euler[i];
	for(j=1;j<=20;j++){
		for(i=1;i<=cntu-(1<<j)+1;i++){
			if(dep[st[i][j-1]]<=dep[st[i+(1<<(j-1))][j-1]]) st[i][j]=st[i][j-1];
			else st[i][j]=st[i+(1<<(j-1))][j-1];
		} 
	}
}
int getlca(int l,int r){
//	cout<<"	getlca "<<l<<' '<<r<<' '<<pos[l]<<' '<<pos[r]<<' ';
	l=pos[l];r=pos[r];
	if(l>r) swap(l,r);
	int k=log[r-l+1];
//	cout<<k<<' '<<st[l][k]<<' '<<st[r-(1<<k)+1][k]<<' '<<dep[st[l][k]]<<' '<<dep[st[r-(1<<k)+1][k]]<<'\n';
	if(dep[st[l][k]]<=dep[st[r-(1<<k)+1][k]]) return st[l][k];
	else return st[r-(1<<k)+1][k];
}
void merge(int &xl,int &xr,int yl,int yr){
	int lca;
	if(!xl&&!xr) return;
	if(dep[xl]<dep[yl]){
		lca=getlca(xr,yl);
		if(lca!=yl){xl=xr=0;return;}
		xl=yl;xr=getlca(xr,yr);
	}
	else{
		lca=getlca(xl,yr);
		if(lca!=xl){xl=xr=0;return;}
		xl=xl;xr=getlca(xr,yr);
	}
} 
struct BIT{
	uint val[200010];
	int lowbit(int x){
		return x&(-x);
	}
	void change(int pos,uint w){
		for(;pos<=n;pos+=lowbit(pos)) val[pos]+=w;
	}
	uint query(int pos){
		uint re=0;
		for(;pos;pos-=lowbit(pos)) re+=val[pos];
		return re&MOD;
	}
}T1,T2;
int l[10],r[10];
uint getval(int pos){
	if(!pos) return 0;
	return T2.query(dfn[pos])*(uint)dep[pos]-T1.query(dfn[pos]);
}
void solve(int num){
	int tmpl,tmpr,i,j;uint ans=0,ch;
	for(i=1;i<(1<<num);i++){
		ch=-1;tmpl=tmpr=-1;
		for(j=0;j<num;j++){
			if(!((1<<j)&i)) continue;
			ch=-ch;
			if(tmpl==-1&&tmpr==-1) tmpl=l[j],tmpr=r[j];
			else merge(tmpl,tmpr,l[j],r[j]);
		}
		ans+=ch*(getval(tmpr)-getval(fa[tmpl]));
//		cout<<"solving "<<i<<' '<<tmpl<<' '<<tmpr<<' '<<ans<<'\n';
	}
	printf("%d\n",(uint)(ans&MOD));
}
int main(){
//	freopen("8.in","r",stdin);
//	freopen("my.out","w",stdout); 
	memset(first,-1,sizeof(first));
	n=read();int i,t1,t2,t3;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs(1,0);init();
	int Q=read();
	while(Q--){
		t1=read();
		if(t1==0){
			t2=read();t3=read();
			T1.change(dfn[t2],t3*(dep[t2]-1));T1.change(lim[t2]+1,-t3*(dep[t2]-1));
			T2.change(dfn[t2],t3);T2.change(lim[t2]+1,-t3);
		}
		else{
			t2=read();
			for(i=0;i<t2;i++){
				l[i]=read(),r[i]=read();
				if(dep[l[i]]>=dep[r[i]]) swap(l[i],r[i]);
			}
			solve(t2);
		}
	}
}
