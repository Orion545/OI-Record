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
int fa[400010],siz[400010],ch[400010][2],w[400010],rev[400010],root[400010],cnt;
void update(int x){
	if(!x) return;
	assert(siz[0]==0&&fa[0]==0&&ch[0][0]==0&&ch[0][1]==0&&rev[0]==0&&w[0]==0);
	siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
}
int newnode(int val,int f){
	cnt++;w[cnt]=val;fa[cnt]=f;siz[cnt]=1;return cnt;
}
int get(int x){return ch[fa[x]][1]==x;}
void pushrev(int x){
	if(!x) return;
	swap(ch[x][0],ch[x][1]);
	rev[x]^=1;
}
void push(int x){
	if(!x) return;
	if(rev[x]){
		pushrev(ch[x][0]);pushrev(ch[x][1]);
		rev[x]=0;
	}
}
void rotate(int x){
	int f=fa[x],ff=fa[f],son=get(x);
	push(f);push(x);
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=x;ch[x][son^1]=f;
	fa[x]=ff;
	if(ff) ch[ff][ch[ff][1]==f]=x;
	update(f);update(x);
}
void splay(int x,int to,int tr){
	if(x==to||!x) return;
	for(int f;(f=fa[x])!=to;rotate(x)){
		if(fa[f]!=to)
			rotate((get(f)==get(x))?f:x);
	}
	if(!to) root[tr]=x;
}
int pre(int x){
	push(x);
	while(ch[x][0]) x=ch[x][0],push(x);
	return x;
}
int suf(int x){
	push(x);
	while(ch[x][1]) x=ch[x][1],push(x);
	return x;
}
void insert(int tr,int t,int val){
//	cout<<"insert "<<tr<<' '<<root[tr]<<' '<<val<<' '<<t<<'\n';
	if(!root[tr]){
		root[tr]=newnode(val,0);return;
	}
	int x;
	if(t) x=suf(root[tr]);
	else x=pre(root[tr]);
	splay(x,0,tr);
	if(t) ch[x][1]=newnode(val,x);
	else ch[x][0]=newnode(val,x);
	update(x);
}
void del(int tr,int t){
	if(!root[tr]){
		puts("-1");return;
	}
	int x;
	if(t) x=suf(root[tr]);
	else x=pre(root[tr]);
//	cout<<"del "<<tr<<' '<<t<<' '<<root[tr]<<' '<<siz[root[tr]]<<' '<<x<<' '<<w[x]<<' '<<ch[x][0]<<' '<<ch[x][1]<<'\n';
	splay(x,0,tr);printf("%d\n",w[x]);
	if(t) fa[ch[x][0]]=0,root[tr]=ch[x][0];
	else fa[ch[x][1]]=0,root[tr]=ch[x][1];
	ch[x][0]=ch[x][1]=w[x]=siz[x]=fa[x]=rev[x]=0;
}
void add(int tr1,int tr2,int t){
	if(!root[tr2]) return;
	if(t) pushrev(root[tr2]);
	if(!root[tr1]){
		root[tr1]=root[tr2];root[tr2]=0;return;
	}
	int x=suf(root[tr1]);
//	cout<<"add "<<tr1<<' '<<tr2<<' '<<root[tr1]<<' '<<root[tr2]<<' '<<siz[root[tr2]]<<'\n';
	fa[root[tr2]]=x;ch[x][1]=root[tr2];update(x);
	root[tr2]=0;
}
int n,m;
int main(){
	int t1,t2,t3,t4;
	while(~scanf("%d%d",&n,&m)){
//		cout<<"begin "<<n<<' '<<m<<'\n';
		memset(root,0,sizeof(root));memset(fa,0,sizeof(fa));memset(ch,0,sizeof(ch)); 
		memset(w,0,sizeof(w));memset(siz,0,sizeof(siz));cnt=0;
		while(m--){
			t1=read();
			if(t1==1){
				t2=read();t3=read();t4=read();
				insert(t2,t3,t4);
			}
			if(t1==2){
				t2=read();t3=read();
				del(t2,t3);
			}
			if(t1==3){
				t2=read();t3=read();t4=read();
				add(t2,t3,t4);
			}
		}
	}
}
/*
2 20
1 1 0 1
1 1 0 10
1 1 0 100
1 1 1 1000
2 1 1
2 1 1
2 1 0
2 1 0
2 1 0
1 1 0 1
1 1 0 10
1 1 0 100
1 1 1 1000
1 2 1 10000
3 2 1 1
2 2 1
2 2 1
2 2 1
2 2 1
2 2 1

2 10
1 1 0 1
3 2 1 1
3 1 2 1
3 2 1 0
3 1 2 0
2 1 0

*/
