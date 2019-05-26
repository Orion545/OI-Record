#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int re=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re;
}
int n,m,cnt,root;
int ch[100010][2]={0},fa[100010]={0},re[100010]={0},w[100010]={0},siz[100010]={0};
void _swap(int &l,int &r){l^=r;r^=l;l^=r;}
void update(int x){siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;}
void rev(int x){
//	cout<<"rev "<<x<<"\n";
	if(!x) return;
	_swap(ch[x][0],ch[x][1]);
	re[x]^=1;
}
void push(int x){
//	cout<<"push "<<x<<"\n";
	if(!x) return;
	if(re[x]){
		rev(ch[x][0]);rev(ch[x][1]);
		re[x]=0;
	}
}
int get(int x){return ch[fa[x]][1]==x;}
void rotate(int x){
	int f=fa[x],ff=fa[f],son=get(x);
	push(f);push(x);
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	ch[x][son^1]=f;fa[f]=x;
	fa[x]=ff;
	if(ff) ch[ff][ch[ff][1]==f]=x;
	update(f);update(x);
}
void splay(int x,int to){
//	cout<<"splay "<<x<<ends<<to<<endl;
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
int rank(int k,int pos){
	push(pos);
//	printf("rank %d %d %d %d\n",k,pos,siz[pos],siz[ch[pos][0]]);
//	if(pos==0) system("pause");
	if(siz[ch[pos][0]]+1==k) return pos;
	if(siz[ch[pos][0]]>=k) return rank(k,ch[pos][0]);
	else return rank(k-siz[ch[pos][0]]-1,ch[pos][1]);
}
void rev(int l,int r){
	int x=rank(l,root),y=rank(r+2,root);
	splay(x,0);splay(y,x);
	rev(ch[y][0]);
}
int build(int l,int r,int f){
//	cout<<"build "<<l<<ends<<r<<ends<<f<<endl;
	if(l>r) return 0;
	if(l==r){
		fa[++cnt]=f;w[cnt]=l;siz[cnt]=1;return cnt;
	}
	int mid=(l+r)>>1,cur=++cnt;
	fa[cur]=f;w[cur]=mid;
	ch[cur][0]=build(l,mid-1,cur);
	ch[cur][1]=build(mid+1,r,cur);
	update(cur);
	return cur;
}
void dfs(int u){
	if(!u) return;
	push(u);
	dfs(ch[u][0]);
	if(w[u]>0&&w[u]<=n) printf("%d ",w[u]);
	dfs(ch[u][1]);
}
int main(){
	int i,t1,t2,j;
	n=read();m=read();
	root=build(0,n+1,0);
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		rev(t1,t2);
	}
	dfs(root);
} 
