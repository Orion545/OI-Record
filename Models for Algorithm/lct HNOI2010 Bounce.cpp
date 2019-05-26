#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int fa[200010],ch[200010][2],siz[200010],k[200010];
bool rt[200010];
inline void _swap(int &l,int &r){l^=r;r^=l;l^=r;}
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
inline void update(int x){
	if(!x) return;
	siz[x]=1;
	if(ch[x][0]) siz[x]+=siz[ch[x][0]];
	if(ch[x][1]) siz[x]+=siz[ch[x][1]];
}
inline int get(int x){
	return x==ch[fa[x]][1];
}
inline void rotate(int x){
//	cout<<"rotate "<<x<<endl;
//	if(x==2) system("pause");
	if(rt[x]) return;
	int f=fa[x],ff=fa[f],son=get(x);
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[x][son^1]]=f;
	fa[f]=x;ch[x][son^1]=f;
	fa[x]=ff;
	if(!rt[f]) ch[ff][ch[ff][1]==f]=x;
	else rt[x]=1,rt[f]=0;
	update(f);update(x);
}
inline void splay(int x){
//	cout<<"splay "<<x<<endl;
	for(int f;!rt[x];rotate(x)){
//		cout<<x<<ends<<fa[x]<<endl;
		if(!rt[f=fa[x]])
			rotate(get(f)==get(x)?f:x);
	}
}
inline void access(int x){
//	cout<<"access "<<x<<endl;
	int y=0;
	do{
		splay(x);
		rt[ch[x][1]]=1;
		rt[ch[x][1]=y]=0;
		update(x);
		x=fa[y=x];
	}while(x);
}
inline void link(int u,int v){
	if(v>n) v=0;
	access(u);splay(u);
	fa[ch[u][0]]=0;rt[ch[u][0]]=1;
	ch[u][0]=0;fa[u]=v;
	update(u);
}
int main(){
	int i,t1,t2,t3,j;
	n=read();
	for(i=1;i<=n;i++) rt[i]=siz[i]=1;
	for(i=1;i<=n;i++){
		k[i]=read();
		link(i,i+k[i]);
//		for(j=1;j<=n;j++) cout<<fa[j]<<ends;cout<<endl;
	}
	m=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();t2++;
		if(t1==1){
			access(t2);splay(t2);
			printf("%d\n",siz[ch[t2][0]]+1);
		}
		else{
			t3=read();
			k[t2]=t3;
			link(t2,t2+k[t2]);
		}
	}
} 
