#include<iostream>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
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
int ufs[100010];
int find(int x){
	return ((ufs[x]==x)?x:ufs[x]=find(ufs[x]));
}
int fa[100010],ch[100010][2],siz[100010],w[100010];
void update(int x){
	siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
}
bool get(int x){
	return ch[fa[x]][1]==x;
}
void rotate(int x){
	int f=fa[x],ff=fa[f],son=get(x);
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=x;ch[x][son^1]=f;
	fa[x]=ff;
	if(ff) ch[ff][ch[ff][1]==f]=x;
	update(f);update(x);
}
void splay(int x){
	for(int f;(f=fa[x]);rotate(x))
		if(fa[f])
			rotate((get(f)==get(x))?f:x);
}
int getrank(int x,int val){
//	cout<<"	getrank "<<x<<' '<<val<<' '<<siz[ch[x][0]]<<' '<<siz[ch[x][1]]<<'\n';
	assert(x);
	if(siz[ch[x][0]]+1==val) return x;
	if(siz[ch[x][0]]+1<val) return getrank(ch[x][1],val-siz[ch[x][0]]-1);
	else return getrank(ch[x][0],val);
}
void insert(int x,int y){
//	cout<<"insert "<<x<<' '<<y<<' '<<ch[x][0]<<' '<<ch[x][1]<<'\n';
	assert(x!=y);
	if(w[y]<w[x]){
		if(ch[x][0]) insert(ch[x][0],y);
		else{
			ch[y][0]=ch[y][1]=0;fa[y]=x;ch[x][0]=y;siz[y]=1;
		}
	}
	else{
		if(ch[x][1]) insert(ch[x][1],y);
		else{
			ch[y][0]=ch[y][1]=0;fa[y]=x;ch[x][1]=y;siz[y]=1;
		}
	}
	update(x);
//	cout<<"finish insert "<<x<<' '<<siz[x]<<'\n';
}
void dfs(int x,int y){
	int lc=ch[x][0],rc=ch[x][1];
//	cout<<"	dfs "<<x<<' '<<y<<' '<<lc<<' '<<rc<<'\n';
	if(lc) dfs(lc,y);
	insert(y,x);
	if(rc) dfs(rc,y);
}
void merge(int l,int r){
	int x=find(l),y=find(r);
	splay(x);splay(y);
	if(x==y) return;
//	cout<<"merge "<<x<<' '<<y<<' '<<l<<' '<<r<<' '<<siz[x]<<' '<<siz[y]<<'\n';
	if(siz[x]>siz[y]) swap(x,y);
	ufs[x]=y;
	dfs(x,y);
}
int ask(int x,int val){
	int f=find(x);splay(f);
//	cout<<"ask "<<x<<' '<<f<<' '<<siz[f]<<'\n';
	if(siz[f]<val) return -1;
	else return getrank(f,val);
}
int n,m,Q;
int main(){
	n=read();m=read();int i,t1,t2;char s[10];
	for(i=1;i<=n;i++) w[i]=read(),siz[i]=1,ufs[i]=i;
	for(i=1;i<=m;i++){
		t1=read(),t2=read();
		merge(t1,t2);
	}
	Q=read();
	while(Q--){
		scanf("%s",s);
			t1=read();t2=read();
		if(s[0]=='Q') printf("%d\n",ask(t1,t2));
		else merge(t1,t2);
//		system("pause");
	}
}
/*
10 0
1 2 3 4 5 6 7 8 9 10
1000
B 1 2
B 2 3
B 3 4
Q 1 4

*/
