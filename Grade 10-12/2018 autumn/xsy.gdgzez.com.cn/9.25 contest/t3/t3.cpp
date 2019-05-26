#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ull unsigned long long
#define MOD 19260817ull
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int fa[300010],ch[300010][2],siz[300010],cnt,root;ull w[300010],a[300010];
ull p[300010];
int newnode(int f,ull val){
	cnt++;
	fa[cnt]=f;siz[cnt]=1;w[cnt]=val;a[cnt]=val;
	return cnt;
}
void update(int x){
	siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
	a[x]=a[ch[x][0]]*p[siz[ch[x][1]]+1]+w[x]*p[siz[ch[x][1]]]+a[ch[x][1]];
//	cout<<"		update "<<x<<' '<<ch[x][0]<<' '<<ch[x][1]<<' '<<siz[x]<<' '<<a[x]<<'\n';
}
int get(int x){
	return ch[fa[x]][1]==x;
}
void rotate(int x){
	int f=fa[x],ff=fa[f],son=get(x);
//	cout<<"	rotate "<<x<<' '<<f<<' '<<ff<<' '<<son<<'\n';
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=x;ch[x][son^1]=f;
	fa[x]=ff;
	if(ff) ch[ff][ch[ff][1]==f]=x;
	update(f);update(x);
}
void splay(int x,int to){
	if(x==to) return;
	for(int f;(f=fa[x])!=to;rotate(x)){
		if(fa[f]!=to)
			rotate((get(x)==get(f))?f:x);
	}
	if(!to) root=x;
}
int getpos(int x,int rk){
//	cout<<"	getpos "<<x<<' '<<siz[x]<<' '<<siz[ch[x][0]]<<' '<<rk<<'\n';
//	assert(rk>=1);
//	assert(siz[x]>=siz[ch[x][0]]);
	if(siz[ch[x][0]]+1==rk) return x;
	if(siz[ch[x][0]]>=rk) return getpos(ch[x][0],rk);
	else return getpos(ch[x][1],rk-siz[ch[x][0]]-1);
}
void insert(int x,ull val){
	int l=getpos(root,x+1),r=getpos(root,x+2);
	splay(l,0);splay(r,l);
	ch[r][0]=newnode(r,val);
	update(r);update(l);
}
void change(int x,ull val){
	int l=getpos(root,x),r=getpos(root,x+2);
	splay(l,0);splay(r,l);
	w[ch[r][0]]=a[ch[r][0]]=val;
	update(r);update(l);
}
ull query(int l,int r){
//	cout<<"query "<<l<<' '<<r<<'\n';
	int x=getpos(root,l),y=getpos(root,r+2);
	splay(x,0);splay(y,x);
//	cout<<"ans query "<<l<<' '<<r<<' '<<x<<' '<<y<<' '<<siz[x]<<' '<<siz[y]<<' '<<a[ch[y][0]]<<'\n';
	return a[ch[y][0]];
}
char s[200010];
int build(int l,int r,int fa){
	if(l>r) return 0;
	int mid=(l+r)>>1,cur=newnode(fa,s[mid-1]);
	if(l==r) return cur;
	ch[cur][0]=build(l,mid-1,cur);
	ch[cur][1]=build(mid+1,r,cur);
	update(cur);
	return cur;
}
int main(){
	scanf("%s",s);int n=strlen(s);
	int t1,t2;char s1[10],s2[10];
	int i;p[0]=1;
	for(i=1;i<=300000;i++) p[i]=p[i-1]*MOD;
	root=build(0,n+1,0);
	int Q=read();
	while(Q--){
		scanf("%s",s1);
		if(s1[0]=='Q'){
			t1=read();t2=read();
			int l=0,r=min(n-t1+1,n-t2+1),mid;
			while(l<r){
				mid=(l+r)>>1;mid++;
//				cout<<"binary "<<l<<' '<<r<<' '<<mid<<'\n';
				if(query(t1,t1+mid-1)==query(t2,t2+mid-1)) l=mid;
				else r=mid-1;
			}
			printf("%d\n",l);
		}
		if(s1[0]=='R'){
			t1=read();scanf("%s",s2);
			change(t1,s2[0]);
		}
		if(s1[0]=='I'){
			t1=read();scanf("%s",s2);
			insert(t1,s2[0]);
			n++;
		}
	}
}

