#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,cnt,root,num[200010],ch[200010][2],fa[200010],siz[200010],w[200010];
int ins[200010],re[200010];
inline void update(int x){siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+num[x];}
inline bool get(int x){return x==ch[fa[x]][1];}
inline void rotate(int x){
	int f=fa[x],ff=fa[f],son=get(x);
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	ch[x][son^1]=f;fa[f]=x;
	fa[x]=ff;
	if(ff) ch[ff][ch[ff][1]==f]=x;
	else root=x;
	update(f);update(x);
}
inline void splay(int x){
	for(int f;f=fa[x];rotate(x))
		if(fa[f])
			rotate((get(x)==get(f))?f:x);
}
inline int rank(int x,int pos){
//	cout<<"rank "<<x<<ends<<w[x]<<ends<<siz[x]<<ends<<siz[ch[x][0]]<<endl;
	if(siz[ch[x][0]]<pos&&siz[ch[x][0]]+num[x]>=pos){
		splay(x);return w[x];
	}
	if(siz[ch[x][0]]>=pos) return rank(ch[x][0],pos);
	else return rank(ch[x][1],pos-siz[ch[x][0]]-num[x]);
}
inline void insert(int x,int pos){
//	cout<<"insert "<<x<<ends<<pos<<ends<<siz[pos]<<ends<<ch[pos][0]<<ends<<ch[pos][1]<<endl;
	if(!pos){
		root=++cnt;num[cnt]=siz[cnt]=1;w[cnt]=x;return;
	}
	if(w[pos]==x){
		num[pos]++;splay(pos);return;
	}
	if(w[pos]>x){
		if(ch[pos][0]) insert(x,ch[pos][0]);
		else{
			ch[pos][0]=++cnt;
			fa[cnt]=pos;num[cnt]=siz[cnt]=1;
			w[cnt]=x;
			splay(pos);
		}
	}
	if(w[pos]<x){
		if(ch[pos][1]) insert(x,ch[pos][1]);
		else{
			ch[pos][1]=++cnt;
			fa[cnt]=pos;num[cnt]=siz[cnt]=1;
			w[cnt]=x;
			splay(pos);
		}
	}
}
int main(){
	int i,j,pos=0;
	m=read();n=read();
	for(i=1;i<=m;i++) ins[i]=read();
	for(i=1;i<=n;i++) re[i]=read();
	j=1;
	for(i=1;i<=m;i++){
		insert(ins[i],root);
		while(re[j]==i){
			printf("%d\n",rank(root,++pos));
			j++;
		}
	}
}
