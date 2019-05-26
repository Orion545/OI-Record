#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,cnt;
int w[200010],p[200010],hash[200010],root[200010];
int a[4000010],l[4000010],r[4000010];
inline int cmp(int l,int r){return w[l]<w[r];}
inline void build(int &now,int ll,int rr,int x){
	int mid=(ll+rr)>>1;
//	cout<<"build "<<ll<<ends<<rr<<ends<<x<<endl;
	a[++cnt]=a[now]+1;l[cnt]=l[now];r[cnt]=r[now];
	now=cnt;
	if(ll==rr) return;
	if(mid>=x) build(l[now],ll,mid,x);
	else build(r[now],mid+1,rr,x);
}
inline int query(int i,int j,int ll,int rr,int k){
//	cout<<"query "<<i<<ends<<j<<ends<<l[i]<<ends<<l[j]<<ends<<r[i]<<ends<<r[j]<<ends<<ll<<ends<<rr<<ends<<k<<endl;
	int mid=(ll+rr)>>1;
	if(ll==rr) return ll;
	int tt=a[l[j]]-a[l[i]];
	if(tt>=k) return query(l[i],l[j],ll,mid,k);
	else return query(r[i],r[j],mid+1,rr,k-tt);
}
int main(){
	int i,t1,t2,t3,tmp;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&w[i]),p[i]=i;
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++) hash[p[i]]=i;
	for(i=1;i<=n;i++){
		root[i]=root[i-1];
		build(root[i],1,n,hash[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		tmp=query(root[t1-1],root[t2],1,n,t3);
//		cout<<tmp<<endl;
		printf("%d\n",w[p[tmp]]);
	}
}
