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
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,ori[100010],root;
namespace t{
	int fa[200010],ch[200010][2],siz[200010],maxn[200010],minn[200010],minc[200010],w[200010],c[200010],cnt;
	inline void update(int cur){
		if(!cur) return;
		if(cur!=n+1&&cur!=n+2) maxn[cur]=minn[cur]=w[cur],minc[cur]=c[cur];
		else maxn[cur]=0,minn[cur]=minc[cur]=2e9;
		siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]]+1;
		maxn[cur]=max(maxn[cur],max(maxn[ch[cur][0]],maxn[ch[cur][1]]));
		if(ch[cur][0]) minn[cur]=min(minn[cur],minn[ch[cur][0]]);
		if(ch[cur][1]) minn[cur]=min(minn[cur],minn[ch[cur][1]]);
		if(ch[cur][0]) minc[cur]=min(minc[cur],minc[ch[cur][0]]);
		if(ch[cur][1]) minc[cur]=min(minc[cur],minc[ch[cur][1]]);
	}
	inline bool get(int cur){return ch[fa[cur]][1]==cur;}
	inline void rotate(int cur){
		int f=fa[cur],ff=fa[f],son=get(cur);
		ch[f][son]=ch[cur][son^1];
		if(ch[f][son]) fa[ch[f][son]]=f;
		fa[f]=cur;ch[cur][son^1]=f;
		fa[cur]=ff;
		if(ff) ch[ff][ch[ff][1]==f]=cur;
		else root=cur;
		update(f);update(cur);
	}
	inline void splay(int cur,int to){
		if(cur==to||fa[cur]==to) return;
		for(int f;(f=fa[cur])&&(f!=to);rotate(cur)){
			if(fa[f]!=to)
				rotate((get(f)==get(cur))?f:cur);
			if(fa[cur]==to) break;
		}
		if(!to) root=cur;
		update(cur);
	}
	void build(int &cur,int f,int l,int r){
		if(l>r){cur=0;return;}
		int mid=(l+r)>>1;
		if(mid==0||mid==n+1){
			cur=n+1+(mid==n+1);
			fa[cur]=f;siz[cur]=1;ch[cur][0]=ch[cur][1]=0;
			maxn[cur]=0;minn[cur]=2e9;minc[cur]=2e9;
		}
		else{
			cur=++cnt;
			fa[cur]=f;siz[cur]=1;ch[cur][0]=ch[cur][1]=0;
			w[cur]=ori[mid];c[cur]=abs(ori[mid+1]-ori[mid]);
		}
		build(ch[cur][0],cur,l,mid-1);
		build(ch[cur][1],cur,mid+1,r);
		update(cur);
//		cout<<"finish build "<<l<<' '<<r<<' '<<mid<<' '<<ori[mid]<<' '<<cur<<' '<<w[cur]<<' '<<c[cur]<<' '<<maxn[cur]<<' '<<minn[cur]<<' '<<minc[cur]<<'\n';
	}
	inline int findrank(int cur,int lim){
		if(siz[ch[cur][0]]+1==lim) return cur;
		if(siz[ch[cur][0]]>=lim) return findrank(ch[cur][0],lim);
		else return findrank(ch[cur][1],lim-siz[ch[cur][0]]-1);
	}
	void merge(int pos,int val){
		int x=findrank(root,pos),y=findrank(root,pos+3);
		splay(x,0);splay(y,root);
//		cout<<"merge "<<pos<<' '<<val<<' '<<x<<' '<<w[x]<<' '<<y<<' '<<w[y]<<'\n';
		int cur=++cnt;
		ch[cur][0]=ch[cur][1]=0;fa[cur]=y;siz[cur]=1;
		w[cur]=maxn[cur]=minn[cur]=val;
		c[cur]=minc[cur]=abs(w[y]-val);
		if(x!=n+1&&x!=n+2) c[x]=abs(val-w[x]);
		ch[y][0]=cur;
		update(y);update(x);
//		cout<<"finish merge x "<<x<<' '<<siz[x]<<' '<<maxn[x]<<' '<<minn[x]<<' '<<minc[x]<<'\n';
//		cout<<"finish merge y "<<y<<' '<<siz[y]<<' '<<maxn[y]<<' '<<minn[y]<<' '<<minc[y]<<'\n';
	}
	void insert(int pos,int val){
		int x=findrank(root,pos+1),y=findrank(root,pos+2);
		splay(x,0);splay(y,root);
		int cur=++cnt;
		ch[cur][0]=ch[cur][1]=0;fa[cur]=y;siz[cur]=1;
		w[cur]=maxn[cur]=minn[cur]=val;
		c[cur]=minc[cur]=abs(w[y]-val);
		c[x]=abs(val-w[x]);
		ch[y][0]=cur;
		update(y);update(x);
	}
	inline int getmax(int l,int r){
		int x=findrank(root,l),y=findrank(root,r+2);
		splay(x,0);splay(y,root);
		return maxn[ch[y][0]]-minn[ch[y][0]];
	}
	inline int getmin(int l,int r){
		int x=findrank(root,l),y=findrank(root,r+1);
		splay(x,0);splay(y,root);
		return minc[ch[y][0]];
	}
}
int main(){
	n=read();m=read();int i,j,t1,t2;char s[10];
	for(i=1;i<=n;i++) ori[i]=read();
	ori[n+1]=2e9;
	t::build(root,0,0,n+1);t::cnt=n+2;
	while(m--){
		scanf("%s",s);t1=read();t2=read();
		if(s[1]=='e') t::merge(t1,t2);
		if(s[1]=='n') t::insert(t1,t2);
		if(s[1]=='a') printf("%d\n",t::getmax(t1,t2));
		if(s[1]=='i') printf("%d\n",t::getmin(t1,t2));
	}
}
