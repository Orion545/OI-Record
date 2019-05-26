#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 1e8
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
int n,m,cnt,root;
int fa[100010]={0},ch[100010][2]={0},w[100010]={0};
int num[100010]={0};
inline int get(int x){return ch[fa[x]][1]==x;}
inline void rotate(int x){
	int f=fa[x],ff=fa[f],son=get(x);
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	ch[x][son^1]=f;fa[f]=x;
	fa[x]=ff;
	if(ff) ch[ff][ch[ff][1]==f]=x;
}
inline void splay(int x){
	for(int f;f=fa[x];rotate(x))
		if(fa[f])
			rotate((get(x)==get(f))?f:x);
	root=x;
}void insert(int x,int pos){
	if(pos==0){
		w[++cnt]=x;num[cnt]=1;root=cnt;return;
	}
	if(w[pos]==x){
		num[pos]++;splay(pos);return;
	} 
	if(w[pos]>x){
		if(ch[pos][0]) insert(x,ch[pos][0]);
		else{
			w[++cnt]=x;num[cnt]=1;fa[cnt]=pos;
			ch[pos][0]=cnt;splay(cnt);return;
		}
		
	}
	if(w[pos]<x){
		if(ch[pos][1]) insert(x,ch[pos][1]);
		else{
			w[++cnt]=x;num[cnt]=1;fa[cnt]=pos;
			ch[pos][1]=cnt;splay(cnt);return;
		}
	}
}
int pre(){
	if(num[root]>1) return w[root];
	int x=ch[root][0];
	while(ch[x][1]) x=ch[x][1];
	return w[x];
}
int suf(){
	if(num[root]>1) return w[root];
	int x=ch[root][1];
	while(ch[x][0]) x=ch[x][0];
	return w[x];
}
void dfs(int u){
	if(!u) return;
	dfs(ch[u][0]);
	printf("%d ",w[u]);
	dfs(ch[u][1]);
}
int main(){
	int i,t1,ans=0;
	n=read();
	insert(-inf,root);insert(inf,root);
//	dfs(root);puts("");
	t1=read();ans+=t1;insert(t1,root);
//	dfs(root);puts("");
//	printf("first check %d\n",ans);
	for(i=2;i<=n;i++){
		t1=read();insert(t1,root);
		ans+=min(t1-pre(),suf()-t1);
//		printf("check: %d %d %d %d\n",t1,pre(),suf(),ans);
//		dfs(root);puts("");
	}
	printf("%d\n",ans);
//	system("pause");
}
