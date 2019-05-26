#include<iostream>
#include<cstring>
#include<cstdio>
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
int n,cnt=0,root=0,mouse=0;
int fa[1500010]={0},ch[1500010][2]={0},siz[1500010]={0};
char w[1500010]={0};
void update(int x){siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;}
int get(int x){return ch[fa[x]][1]==x;}
void rotate(int x){
	int f=fa[x],ff=fa[f],son=get(x);
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=x;ch[x][son^1]=f;
	fa[x]=ff;
	if(ff) ch[ff][ch[ff][1]==f]=x;
	update(f);update(x);
}
void splay(int x,int to){
//	cout<<"splay "<<x<<ends<<" "<<endl;
	if(x==to||fa[x]==to) return;
	if(to==0) root=x;
	for(int f;(f=fa[x])&&(f!=to);rotate(x)){
		if(fa[f]!=to)
			rotate(get(x)==get(f)?f:x);
	}
	update(x);
}
int rank(int x,int pos){
//	cout<<"rank "<<x<<ends<<siz[pos]<<ends<<siz[ch[pos][0]]<<ends<<pos<<endl;
//	if(pos==0) system("pause");
	if(siz[ch[pos][0]]+1==x){
		splay(pos,0);return pos;
	}
	if(siz[ch[pos][0]]>=x) return rank(x,ch[pos][0]);
	else return rank(x-siz[ch[pos][0]]-1,ch[pos][1]);
}
char s[2000010]={0};
int build(int l,int r,int f){
	if(l>r) return 0;
//	cout<<"build "<<l<<ends<<r<<ends<<f<<endl; 
	int mid=(l+r)>>1,cur=++cnt;
	fa[cur]=f;w[cur]=s[mid];
	ch[cur][0]=build(l,mid-1,cur);
	ch[cur][1]=build(mid+1,r,cur);
	update(cur);return cur;
}
void insert(int l,int len){
	int x=rank(l,root),y=rank(l+1,root);
	splay(x,0);splay(y,root);
	ch[y][0]=build(1,len,y);
	update(y);update(x);
}
void del(int l,int r){
	int x=rank(l,root),y=rank(r+2,root);
	splay(x,0);splay(y,root);
	ch[y][0]=0;update(y);update(x);
}
void dfs(int x){
	if(!x) return;
	dfs(ch[x][0]);
	printf("%c",w[x]);
	dfs(ch[x][1]);
}
void print(int l,int len){
	int x=rank(l,root),y=rank(l+len+1,root);
	splay(x,0);splay(y,root);
	dfs(ch[y][0]);puts("");
}
int main(){
//	freopen("editor20031.in","r",stdin);
//	freopen("editor2003.out","w",stdout);
	int i,j,t1;char op[10];char c;
	n=read();
	root=++cnt;w[cnt]=0;siz[cnt]=2;
	ch[cnt][1]=cnt+1;cnt++;fa[cnt]=cnt-1;w[cnt]=0;siz[cnt]=1;
	mouse=1;
	for(i=1;i<=n;i++){
		scanf("%s",op);
		if(op[0]=='I'){
			t1=read();
			for(j=1;j<=t1;j++){
				c=getchar();
				while(c=='\n'||c=='\r') c=getchar();
				s[j]=c;
			}
			insert(mouse,t1);
		}
		if(op[0]=='D'){
			t1=read();
			del(mouse,mouse+t1-1);
		}
		if(op[0]=='G'){
			t1=read();
			print(mouse,t1);
		}
		if(op[0]=='M'){
			t1=read();
			mouse=t1+1;
		}
		if(op[0]=='N') mouse++;
		if(op[0]=='P') mouse--;
	}
} 
