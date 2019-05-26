#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
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
int n,Q,first[100010],cnte,dep[100010],st[100010][20],dfn[100010],lim[100010],back[100010],cntn;
int fa[100010];
struct edge{
	int to,next;
}e[200010];
inline void add(int u,int v){
	e[++cnte]=(edge){v,first[u]};first[u]=cnte;
	e[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;dep[u]=dep[f]+1;st[u][0]=f;fa[u]=f;
	dfn[u]=++cntn;back[cntn]=u;
//	cout<<"dfs "<<u<<' '<<f<<' '<<dfn[u]<<' '<<dep[u]<<'\n'; 
	for(i=first[u];~i;i=e[i].next){
		v=e[i].to;if(v==f) continue;
		dfs(v,u);
	}
	lim[u]=cntn;
//	cout<<"finish dfs "<<u<<' '<<dfn[u]<<' '<<lim[u]<<'\n';
}
void ST(){
	for(int j=1;j<=19;j++){
		for(int i=1;i<=n;i++) st[i][j]=st[st[i][j-1]][j-1];
	}
}
int lca(int l,int r){
	int i;
	if(dep[l]>dep[r]) swap(l,r);
	for(i=19;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
	if(l==r) return l;
	for(i=19;i>=0;i--){
		if(st[r][i]!=st[l][i]){
			l=st[l][i];
			r=st[r][i];
		}
	}
	return st[l][0];
}
//segment tree
int a[400010],lazy[400010];
void update(int num){
	a[num]=max(a[num<<1],a[num<<1|1]);
}
void push(int l,int r,int num){
	if(l==r||!lazy[num]) return;
	a[num<<1]+=lazy[num];a[num<<1|1]+=lazy[num];
	lazy[num<<1]+=lazy[num];lazy[num<<1|1]+=lazy[num];
	lazy[num]=0;
}
void build(int l,int r,int num){
	if(l==r){a[num]=dep[back[l]];return;}
	int mid=(l+r)>>1;
	build(l,mid,num<<1);build(mid+1,r,num<<1|1);
	update(num);
}
void change(int l,int r,int ql,int qr,int num,int ch){
//	cout<<"	change "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<ch<<'\n';
	push(l,r,num);
	if(l>=ql&&r<=qr){a[num]+=ch;lazy[num]+=ch;return;}
	int mid=(l+r)>>1;
	if(mid>=ql) change(l,mid,ql,qr,num<<1,ch);
	if(mid<qr) change(mid+1,r,ql,qr,num<<1|1,ch);
	update(num);
}
int query(int l,int r,int ql,int qr,int num){
	push(l,r,num);
//	cout<<"		query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<a[num]<<'\n';
	if(l>=ql&&r<=qr) return a[num];
	int mid=(l+r)>>1,re=-1e9;
	if(mid>=ql) re=max(re,query(l,mid,ql,qr,num<<1));
	if(mid<qr) re=max(re,query(mid+1,r,ql,qr,num<<1|1));
	return re;
}
//link cut tree
int ch[100010][2]={0},rt[100010];
int get(int pos){return ch[fa[pos]][1]==pos;}
void rotate(int x){
	int f=fa[x],ff=fa[f],son=get(x);
//	cout<<"		rotate "<<x<<' '<<f<<' '<<ff<<'\n';
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=x;ch[x][son^1]=f;
	fa[x]=ff;
	if(rt[f]) rt[x]=1,rt[f]=0;
	else ch[ff][ch[ff][1]==f]=x;
}
void splay(int pos){
	if(rt[pos]) return;
//	cout<<"	splay "<<pos<<'\n';
	for(int f;!rt[pos];rotate(pos)){
		if(!rt[f=fa[pos]])
			rotate((get(f)==get(pos))?f:pos);
	}
}
int pre(int pos){
	while(ch[pos][0]) pos=ch[pos][0];
	return pos;
}
void access(int pos){
	for(int tmp=0,tt;pos;tmp=pos,pos=fa[pos]){
//		cout<<"access "<<pos<<' '<<tmp<<'\n'; 
		splay(pos);
		if(ch[pos][1]){
			tt=pre(ch[pos][1]);
			change(1,n,dfn[tt],lim[tt],1,1);
		}
		rt[ch[pos][1]]=1;ch[pos][1]=tmp;rt[tmp]=0;
		if(tmp){
			tt=pre(tmp);
			change(1,n,dfn[tt],lim[tt],1,-1);
		}
	}
}
int main(){
//	freopen("paint1.in","r",stdin);
//	freopen("my.out","w",stdout);
	memset(first,-1,sizeof(first));
	n=read();Q=read();int i,t1,t2,t3,f;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs(1,0);ST();build(1,n,1);
	for(i=1;i<=n;i++) rt[i]=1;
	while(Q--){
		t1=read();
		if(t1==1){
			t2=read();access(t2);
		}
		if(t1==2){
			t2=read();t3=read();
			f=lca(t2,t3);
			printf("%d\n",query(1,n,dfn[t2],dfn[t2],1)+query(1,n,dfn[t3],dfn[t3],1)-2*query(1,n,dfn[f],dfn[f],1)+1);
		}
		if(t1==3){
			t2=read();
			printf("%d\n",query(1,n,dfn[t2],lim[t2],1)); 
		}
	}
}
/*
5 10
1 2
2 3
3 4
4 5

3 3
1 5
3 3
1 4
3 3
1 3
3 3
1 2
3 2
2 2 5


*/
