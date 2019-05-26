#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=re*10+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,cnt,w[200010],p[200010],hash[200010];
int root[4000010],l[4000010],r[4000010],a[4000010];
bool cmp(int l,int r){return w[l]<w[r];}
inline void build(int &now,int ll,int rr,int p){
	int mid=(ll+rr)>>1;
	a[++cnt]=a[now]+1;l[cnt]=l[now];r[cnt]=r[now];
	now=cnt;
	if(ll==rr) return;
	if(mid>=p) build(l[now],ll,mid,p);
	else build(r[now],mid+1,rr,p);
}
inline int query(int i,int j,int ll,int rr,int k){
	int mid=(ll+rr)>>1;
	if(ll==rr) return ll;
	int tt=a[l[j]]-a[l[i]];
	if(tt>=k) return query(l[i],l[j],ll,mid,k);
	else return query(r[i],r[j],mid+1,rr,k-tt);
}
int main(){
	int i,t1,t2,t3;
	n=read();m=read();
	for(i=1;i<=n;i++) w[i]=read(),p[i]=i;
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++) hash[p[i]]=i;
	for(i=1;i<=n;i++){
		root[i]=root[i-1];
		build(root[i],1,n,hash[i]);
	}
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		printf("%d\n",w[p[query(root[t1-1],root[t2],1,n,t3)]]);
	}
}
