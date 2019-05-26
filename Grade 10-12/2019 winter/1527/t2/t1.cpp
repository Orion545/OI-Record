#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define next DEEP_DARK_FANTASY
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
int n;double k;
int a[500010],siz[500010],fa[500010],next[500010],ans[500010],vis[500010];
inline bool cmp(int l,int r){
	return l>r;
}
namespace seg{
	int seg[2000010],tag[2000010];
	inline void push(int l,int r,int num){
		if(l==r||!tag[num]) return ;
		tag[num<<1]+=tag[num];
		seg[num<<1]+=tag[num];
		tag[num<<1|1]+=tag[num];
		seg[num<<1|1]+=tag[num];
		tag[num]=0;
	}
	inline void build(int l,int r,int num){
		if(l==r){seg[num]=l;return;}
		int mid=(l+r)>>1;
		build(l,mid,num<<1);build(mid+1,r,num<<1|1);
		seg[num]=min(seg[num<<1],seg[num<<1|1]);
	}
	inline void insert(int l,int r,int ql,int qr,int num,int val){
		push(l,r,num);
		if(l>=ql&&r<=qr){seg[num]+=val;tag[num]+=val;return;}
		int mid=(l+r)>>1;
		if(mid>=ql) insert(l,mid,ql,qr,num<<1,val);
		if(mid<qr) insert(mid+1,r,ql,qr,num<<1|1,val);
		seg[num]=min(seg[num<<1],seg[num<<1|1]);
	}
	inline int query(int l,int r,int num,int lim){
//		cout<<"query "<<l<<' '<<r<<' '<<lim<<' '<<seg[num]<<' '<<seg[num<<1]<<'\n';
		if(l==r) return seg[num]>=lim?l:l+1;
		push(l,r,num);
		int mid=(l+r)>>1;
		if(seg[num<<1|1]>=lim) return query(l,mid,num<<1,lim);
		else return query(mid+1,r,num<<1|1,lim);
	}
}
int main(){
	n=read();scanf("%lf",&k);int i,j,tmp,cur;
	for(i=1;i<=n;i++){
		a[i]=read();
		siz[i]=1;
	}
	sort(a+1,a+n+1,cmp);
	for(i=n;i>=1;i--){
		fa[i]=floor((double)i/k);
		siz[fa[i]]+=siz[i];
		if(a[i]==a[i+1]) next[i]=next[i+1];
		else next[i]=i;
	}
	seg::build(1,n,1);
	for(i=1;i<=n;i++){
		if(fa[i]&&fa[i]!=fa[i-1]) seg::insert(1,n,ans[fa[i]],n,1,siz[fa[i]]-1);
		cur=seg::query(1,n,1,siz[i]);
		ans[i]=next[cur];
		seg::insert(1,n,ans[i],n,1,-siz[i]);
//		cout<<i<<' '<<fa[i]<<' '<<siz[i]<<' '<<ans[i]<<' '<<cur<<' '<<next[cur]<<'\n';
		assert(ans[i]>=1&&ans[i]<=n);
	}
	for(i=1;i<=n;i++) printf("%d ",a[ans[i]]);
	puts("");
}
