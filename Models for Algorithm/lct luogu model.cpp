#include<iostream>
#include<cstdio>
#include<cstring>
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
int n,m;
int fa[300010],ch[300010][2],w[300010],a[300010];
bool rev[300010],rt[300010];
inline void _swap(int &x,int &y){x^=y;y^=x;x^=y;}
inline void update(int x){if(!x) return;a[x]=w[x]^a[ch[x][0]]^a[ch[x][1]];}
inline void reverse(int x){_swap(ch[x][0],ch[x][1]);rev[x]^=1;}
inline void pushdown(int x){
	if(rev[x]){
		if(ch[x][0]) reverse(ch[x][0]);
		if(ch[x][1]) reverse(ch[x][1]);
		rev[x]=0;
	} 
}
inline void push(int x){if(!rt[x]) push(fa[x]);pushdown(x);}
inline bool get(int x){return x==ch[fa[x]][1];}
inline void rotate(int x){
	cout<<"rotate "<<x<<ends<<fa[x]<<ends<<fa[fa[x]]<<endl;
	int f=fa[x],ff=fa[f],son=get(x);
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=x;ch[x][son^1]=f;
	fa[x]=ff;
	if(rt[f]) rt[x]=1,rt[f]=0;
	else ch[ff][f==ch[ff][1]]=x;
	update(f);update(x);
	cout<<"finish rotate "<<f<<ends<<fa[f]<<ends<<fa[fa[f]]<<endl;
}
inline void splay(int x){
	cout<<"splay "<<x<<endl;
//	if(rt[x]) return;
	push(x);
	for(int f;!rt[x];rotate(x)){
		cout<<x<<ends<<fa[x]<<endl;
		if(!rt[f=fa[x]]) rotate((get(x)==get(f))?f:x); 
	}
		
	update(x);
}
inline void dfs(int u){
	if(!u) return;
	dfs(ch[u][0]);
	cout<<u<<ends<<w[u]<<ends<<a[u]<<ends<<ch[u][0]<<ends<<ch[u][1]<<endl;
	dfs(ch[u][1]);
}
inline void access(int x){
	cout<<"access "<<x<<endl;
	int y=0,xx=x;
	do{
		splay(x);
		rt[ch[x][1]]=1;
		rt[ch[x][1]=y]=0;
		x=fa[y=x];
		update(x);
	}while(x);
	dfs(xx);
}
inline void mroot(int x){
	access(x);splay(x);reverse(x);
}
inline bool judge(int x,int y){
	while(fa[x]) x=fa[x];
	while(fa[y]) y=fa[y];
	return x==y;
}
inline void link(int x,int y){
	if(judge(x,y)) return;
	cout<<"link "<<x<<ends<<y<<endl;
	mroot(x);fa[x]=y;splay(x);
}
inline void cut(int x,int y){
	if(!judge(x,y)) return;
	cout<<"cut "<<x<<ends<<y<<endl;
	mroot(x);splay(y);
	fa[ch[y][0]]=fa[y];
	rt[ch[y][0]]=1;
	fa[y]=0;ch[y][0]=0;
}
inline void split(int x,int y){
	mroot(x);access(y);splay(y);
	dfs(y);
}
int main(){
	int i,t1,t2,t3; 
	n=read();m=read();
	for(i=1;i<=n;i++) w[i]=read(),a[i]=w[i],rt[i]=1;
//	for(i=1;i<=n;i++) cout<<i<<ends<<w[i]<<endl;
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		if(t1==0){
			split(t2,t3);printf("%d\n",a[t3]);
		}
		if(t1==1) link(t2,t3);
		if(t1==2) cut(t2,t3);
		if(t1==3){
			access(t2);splay(t2);w[t2]=t3;update(t2);
		}
	}
//	system("pause");
}
/*
5 6
1
2
3
4
5
1 1 2
1 2 3
1 3 4
1 4 5
2 1 5
0 1 5

*/
