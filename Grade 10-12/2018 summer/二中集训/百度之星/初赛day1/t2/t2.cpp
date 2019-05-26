#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define rank rk
#define inf 0x7fffffff
using namespace std;
int n,m,root[400010],cnt,tmp[400010];
int fa[400010],ch[400010][2],w[400010],siz[400010];
int minn[400010],lazy1[400010];
void _swap(int &l,int &r){l^=r;r^=l;l^=r;}
int _min(int l,int r){return (l>r)?r:l;}
void clear(int x){
	fa[x]=ch[x][0]=ch[x][1]=w[x]=siz[x]=lazy1[x]=0;
}
void add(int x,int f){
	cnt++;
	fa[cnt]=f;ch[cnt][0]=ch[cnt][1]=0;w[cnt]=minn[cnt]=x;siz[cnt]=1;lazy1[cnt]=0;
}
int get(int x){
	return ch[fa[x]][1]==x;
}
void update_rev(int x){
	if(!x) return;
	_swap(ch[x][0],ch[x][1]);
	lazy1[x]^=1;
}
void update(int x){
	if(!x) return;
	siz[x]=1;minn[x]=w[x];
	if(ch[x][0]) siz[x]+=siz[ch[x][0]],minn[x]=_min(minn[x],minn[ch[x][0]]);
	if(ch[x][1]) siz[x]+=siz[ch[x][1]],minn[x]=_min(minn[x],minn[ch[x][1]]);
}
void push(int x){
	if(!x) return;
	if(lazy1[x]){
		update_rev(ch[x][0]);
		update_rev(ch[x][1]);
		lazy1[x]=0;
	} 
}
void rotate(int x){
	int f=fa[x],ff=fa[f],son=get(x);
	push(f);push(x);
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	ch[x][son^1]=f;
	fa[f]=x;
	if(ff) ch[ff][ch[ff][1]==f]=x;
	fa[x]=ff;
	update(f);update(x);
}
void splay(int x,int to,int tr){
	push(x);
	if(x==to||fa[x]==to) return;
	for(int f;(f=fa[x])&&f!=to;rotate(x)){
		push(fa[fa[x]]);push(fa[x]);push(x);
		if(fa[f]!=to)
			rotate((get(x)==get(f))?f:x);
		if(fa[x]==to) break;
	}
	update(x);
	if(to==0) root[tr]=x;
}
int rank(int k,int pos){
	push(pos);
	if(siz[ch[pos][0]]+1==k) return pos;
	if(siz[ch[pos][0]]>=k) return rank(k,ch[pos][0]);
	else return rank(k-siz[ch[pos][0]]-1,ch[pos][1]);
}
void rev(int l,int r,int tr){
	int x=rank(l,root[tr]),y=rank(r+2,root[tr]);
	splay(x,0,tr);splay(y,x,tr);
	lazy1[ch[y][0]]^=1;
	_swap(ch[ch[y][0]][0],ch[ch[y][0]][1]);
}
int pre(int pos){
	while(ch[pos][0]) pos=ch[pos][0];
	return pos;
}
int suf(int pos){
	while(ch[pos][1]) pos=ch[pos][1];
	return pos;
}
void ins(int p,int k,int tr){
	if(p) p=siz[root[tr]];
	int x=rank(p+1,root[tr]),y=rank(p+2,root[tr]);
	splay(x,0,tr);splay(y,x,tr);
	add(k,y);ch[y][0]=cnt;
	push(y);update(y);
	push(x);update(x);
	splay(y,0,tr);
}
void insert(int tr1,int tr2,int k){
	if(k) rev(0,siz[root[tr2]],tr2);
	int p=suf(root[tr1]);splay(p,0,tr1);
	ch[p][1]=root[tr2];fa[root[tr2]]=p;update(p); 
}
void del(int p,int tr){
	if(p) p=siz[root[tr]];
	int x=rank(p,root[tr]),y=rank(p+2,root[tr]);
	splay(x,0,tr);splay(y,x,tr);
	clear(ch[y][0]);ch[y][0]=0;
	update(y);update(x); 
}
int main(){
	int i,t1,t2,t3,t4;char s[10];
	while(scanf("%d%d",&n,&m)){
		for(i=1;i<=m;i++){
			memset(fa,0,sizeof(fa));memset(ch,0,sizeof(ch));memset(siz,0,sizeof(siz));
			memset(w,0,sizeof(w));memset(minn,0,sizeof(minn));memset(lazy1,0,sizeof(lazy1));
			memset(root,0,sizeof(root));cnt=0;
			scanf("%d",&t1);
			if(t1==1){
				scanf("%d%d%d",&t2,&t3,&t4);
				ins(t3,t4,t2);
			}
			if(t1==2){
				scanf("%d%d",&t2,&t3);
				if(t3) printf("%d",suf(root[t2]));
				else printf("%d",pre(root[t2]));
				del(t3,t2);
			}
			if(t1==3){
				scanf("%d%d%d",&t2,&t3,&t4);
				insert(t2,t3,t4);
			}
		}
	}
}
