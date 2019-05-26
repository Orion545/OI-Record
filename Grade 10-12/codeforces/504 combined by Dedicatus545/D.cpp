#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int n,q,x[200010];
struct segtree{
	int a[800010],lazy[800010];
	inline void update(int num){
		a[num]=min(a[num<<1],a[num<<1|1]); 
	}
	void build(int l,int r,int num){
		if(l==r){
			a[num]=((x[l]==0)?1e9:x[l]);
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,num<<1);build(mid+1,r,num<<1|1);
		update(num);
	}
	void change(int l,int r,int ql,int qr,int num,int val){
		if(l>=ql&&r<=qr){
			lazy[num]=val;return;
		}
		int mid=(l+r)>>1;
		if(mid>=ql) change(l,mid,ql,qr,num<<1,val);
		if(mid<qr) change(mid+1,r,ql,qr,num<<1|1,val);
	}
	int query(int l,int r,int ql,int qr,int num){
		int mid=(l+r)>>1,re=1e9;
		if(l>=ql&&r<=qr) return a[num];
		if(mid>=ql) re=min(re,query(l,mid,ql,qr,num<<1));
		if(mid<qr) re=min(re,query(mid+1,r,ql,qr,num<<1|1));
		return re; 
	}
	int ask(int l,int r,int num,int pos){
		if(l==r) return lazy[num];
		int mid=(l+r)>>1;
		if(mid>=pos) return max(lazy[num],ask(l,mid,num<<1,pos));
		else return max(lazy[num],ask(mid+1,r,num<<1|1,pos));
	}
}T;
int l[200010],r[200010];
int main(){
	n=read();q=read();int i;
	for(i=1;i<=q;i++) l[i]=n+1;
	for(i=1;i<=n;i++) x[i]=read(),l[x[i]]=min(l[x[i]],i),r[x[i]]=max(r[x[i]],i);
	T.build(1,n,1);
	for(i=q;i>=1;i--){
		if(l[i]>r[i]) continue;
		if(T.query(1,n,l[i],r[i],1)<i){
			puts("NO");return 0;
		}
	}
	memset(T.a,0,sizeof(T.a));
	for(i=1;i<=q;i++){
		if(l[i]>r[i]) continue;
		T.change(1,n,l[i],r[i],1,i);
	}
	puts("YES");
	for(i=1;i<=n;i++){
		if(x[i]) printf("%d ",x[i]);
		else{
			int tmp=T.ask(1,n,1,i);
			if(!tmp) tmp++;
			printf("%d ",tmp); 
		}
	}
}
