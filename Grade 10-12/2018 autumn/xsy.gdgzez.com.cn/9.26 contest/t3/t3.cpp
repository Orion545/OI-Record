#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define end DEEP_DARK_FANTASY
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
int n,m,realn,Q,fa[400010],val[400010],cir[400010],vis[400010],rt[400010],cntr;
int first[400010],cnte;
struct edge{
	int to,next;
}a[800010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
}
void build(int u){//double nodes on circle
//	cout<<"build "<<u<<'\n';
	if(!fa[u]){rt[++cntr]=u;vis[u]=2;return;}
	if(vis[fa[u]]==1){
		int x=u,c;
		for(c=fa[u];c!=u;c=fa[c]){
			n++;cir[c]=n;
			val[n]=val[c];
			add(n,x);
			fa[x]=n;x=n;
		}
		cir[u]=++n;add(n,x);
		fa[x]=n;rt[++cntr]=n;vis[u]=2;
		return;
	}
	vis[u]=1;
	if(!vis[fa[u]]) build(fa[u]);
	add(fa[u],u);
	vis[u]=2;
	return;
}
int dfn[400010],end[400010],maxn[400010][20],st[400010][20],dep[400010],clk;
void dfs(int u,int f){
	int i,v;
	st[u][0]=f;
	dfn[u]=++clk;
	maxn[u][0]=val[u];
	dep[u]=dep[f]+1;
//	cout<<"dfs "<<u<<' '<<dfn[u]<<' '<<val[u]<<' '<<dep[u]<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
//		cout<<"	to "<<v<<' '<<" from "<<u<<'\n';
		dfs(v,u);
	}
	end[u]=clk;
}
void ST(){
	int i,j;
	for(j=1;j<=19;j++)
		for(i=1;i<=n;i++)
			st[i][j]=st[st[i][j-1]][j-1];
	for(j=1;j<=19;j++)
		for(i=1;i<=n;i++){
			if(dep[i]>(1<<j)) maxn[i][j]=max(maxn[i][j-1],maxn[st[i][j-1]][j-1]);
//			cout<<"maxn "<<i<<' '<<j<<' '<<st[i][j]<<' '<<maxn[i][j]<<'\n';
		}
}
int qlist[1000010],cntq,seg[1600010],lazy[1600010],limt;
void push(int l,int r,int num){
	if(l==r||!lazy[num]) return;
	seg[num<<1]=seg[num<<1|1]=lazy[num<<1]=lazy[num<<1|1]=lazy[num];
	lazy[num]=0;
}
void change(int l,int r,int ql,int qr,int num){
//	cout<<"change "<<l<<' '<<r<<' '<<ql<<' '<<qr<<'\n';
	if(l>=ql&&r<=qr){seg[num]=lazy[num]=cntq;return;}
	push(l,r,num);
	int mid=(l+r)>>1;
	if(mid>=ql) change(l,mid,ql,qr,num<<1);
	if(mid<qr) change(mid+1,r,ql,qr,num<<1|1);
	seg[num]=max(seg[num<<1],seg[num<<1|1]);
}
int query(int l,int r,int pos,int num){
	if(l==r) return seg[num];
	push(l,r,num);
	int mid=(l+r)>>1;
	if(mid>=pos) return query(l,mid,pos,num<<1);
	else return query(mid+1,r,pos,num<<1|1);
}
int ask(int u){
	int pre=query(1,n,dfn[u],1),re=0;
	if(pre<=limt) return 1e9;
	pre=qlist[pre];
	for(int i=19;i>=0;i--){
//		cout<<"try "<<u<<' '<<i<<' '<<st[u][i]<<' '<<pre<<' '<<dep[st[u][i]]<<' '<<dep[pre]<<'\n';
		if(dep[st[u][i]]>=dep[pre]){
			re=max(re,maxn[u][i]);
			u=st[u][i];
		}
	}
	return re;
}
int tlist[2000010],cntt;
inline bool cmp(int l,int r){
	return dep[l]<dep[r];
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2;
	for(i=1;i<=m;i++){
		t1=read();t2=read();fa[t2]=t1;
		val[t2]=i;
	}
	realn=n;
	for(i=1;i<=realn;i++) if(!vis[i]) build(i);
	for(i=1;i<=cntr;i++) dfs(rt[i],0);
	ST();
	Q=read();
	while(Q--){
		t1=read();cntt=0;
		for(i=1;i<=t1;i++){
			t2=read();tlist[++cntt]=t2;
			if(cir[t2]) tlist[++cntt]=cir[t2];
		}
		sort(tlist+1,tlist+cntt+1,cmp);
		limt=cntq;
		for(i=1;i<=cntt;i++){
			qlist[++cntq]=tlist[i];
			change(1,n,dfn[tlist[i]],end[tlist[i]],1);
		}
		t1=read();int ans=1e9;
		for(i=1;i<=t1;i++){
			t2=read();
			ans=min(ans,ask(t2));
		}
		if(ans<1e9) printf("%d\n",ans);
		else puts("OK");
	}
}
