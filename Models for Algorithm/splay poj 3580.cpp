#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
int n,m,root,cnt,tmp[300010];
int fa[300010],ch[300010][2],w[300010],siz[300010];
int minn[300010],lazy1[300010],lazy2[300010];
void _swap(int &l,int &r){l^=r;r^=l;l^=r;}
int _min(int l,int r){return (l>r)?r:l;}
void clear(int x){
	fa[x]=ch[x][0]=ch[x][1]=w[x]=siz[x]=lazy1[x]=lazy2[x]=0;
}
void add(int x,int f){
	cnt++;
	fa[cnt]=f;ch[cnt][0]=ch[cnt][1]=0;w[cnt]=minn[cnt]=x;siz[cnt]=1;lazy1[cnt]=lazy2[cnt]=0;
}
int get(int x){
	return ch[fa[x]][1]==x;
}
void update_add(int x,int k){
	if(x) lazy2[x]+=k,minn[x]+=k,w[x]+=k;
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
	if(lazy2[x]){
		update_add(ch[x][0],lazy2[x]);
		update_add(ch[x][1],lazy2[x]);
		lazy2[x]=0;
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
void splay(int x,int to){
	push(x);
	if(x==to||fa[x]==to) return;
	for(int f;(f=fa[x])&&f!=to;rotate(x)){
		push(fa[fa[x]]);push(fa[x]);push(x);
		if(fa[f]!=to)
			rotate((get(x)==get(f))?f:x);
		if(fa[x]==to) break;
	}
	update(x);
	if(to==0) root=x;
}
int build(int l,int r,int f){
	int mid=(l+r)>>1,tt;
	add(tmp[mid],f);tt=cnt;
	if(mid>l) ch[tt][0]=build(l,mid-1,tt);
	if(mid<r) ch[tt][1]=build(mid+1,r,tt);
	update(tt);
	return tt;
}
int rank(int k,int pos){
	push(pos);
	if(siz[ch[pos][0]]+1==k) return pos;
	if(siz[ch[pos][0]]>=k) return rank(k,ch[pos][0]);
	else return rank(k-siz[ch[pos][0]]-1,ch[pos][1]);
}
void add(int l,int r,int k){
	int x=rank(l,root),y=rank(r+2,root);
	splay(x,0);splay(y,x);
	update_add(ch[y][0],k);
}
void rev(int l,int r){
	int x=rank(l,root),y=rank(r+2,root);
	splay(x,0);splay(y,x);
	lazy1[ch[y][0]]^=1;
	_swap(ch[ch[y][0]][0],ch[ch[y][0]][1]);
}
void res(int l1,int r1,int l2,int r2){
	int x=rank(l2,root),y=rank(r2+2,root);
	splay(x,0);splay(y,x);
	int tt=ch[y][0];
	ch[y][0]=0;fa[tt]=0;
	x=rank(l1,root);y=rank(l1+1,root);
	splay(x,0);splay(y,x);
	ch[y][0]=tt;fa[tt]=y;
}
void ins(int p,int k){
	int x=rank(p+1,root),y=rank(p+2,root);
	splay(x,0);splay(y,x);
	add(k,y);ch[y][0]=cnt;
	push(y);update(y);
	push(x);update(x);
	splay(y,0);
}
void del(int p){
	int x=rank(p,root),y=rank(p+2,root);
	splay(x,0);splay(y,x);
	clear(ch[y][0]);ch[y][0]=0;
	update(y);update(x); 
}
int getmin(int l,int r){
	int x=rank(l,root),y=rank(r+2,root);
	splay(x,0);splay(y,x);
	return minn[ch[y][0]];
}
int main(){
	int i,t1,t2,t3;char s[10];
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&tmp[i]);
	tmp[0]=tmp[n+1]=inf;
	root=build(0,n+1,0);
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%s",s);
		if(s[0]=='A'){
			scanf("%d%d%d",&t1,&t2,&t3);
			add(t1,t2,t3);
		}
		if(s[0]=='R'){
			if(s[3]=='O'){
				scanf("%d%d%d",&t1,&t2,&t3);
				t3=(t3%(t2-t1+1)+t2-t1+1)%(t2-t1+1);
				if(t3==0) continue; 
				res(t1,t2-t3,t2-t3+1,t2);
			}
			else{
				scanf("%d%d",&t1,&t2);
				rev(t1,t2);
			}
		}
		if(s[0]=='I'){
			scanf("%d%d",&t1,&t2);
			ins(t1,t2);
		}
		if(s[0]=='D'){
			scanf("%d",&t1);
			del(t1);
		}
		if(s[0]=='M'){
			scanf("%d%d",&t1,&t2);
			printf("%d\n",getmin(t1,t2));
		}
	}
//	system("pause"); 
}
