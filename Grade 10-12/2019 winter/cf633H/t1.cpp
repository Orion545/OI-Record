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
int n,MOD,a[100010],val[100010],Q,tot,len,ans[100010];
inline int add(int xx,int yy){
	xx+=yy;
	if(xx>=MOD) xx-=MOD;
	return xx;
}
struct query{
	int l,r,blk,num;
}q[30010];
inline bool cmp(query l,query r){
	return (l.blk==r.blk)?l.r<r.r:l.l<r.l;
}
int t00[30010],t01[30010],t10[30010],t11[30010];
void init(){
	int i,j;
	t00[0]=t11[0]=1;
	t01[1]=t10[1]=t11[1]=1;
	for(i=2;i<=n+3;i++){
		t00[i]=t01[i-1];
		t01[i]=add(t00[i-1],t01[i-1]);
		t10[i]=t11[i-1];
		t11[i]=add(t10[i-1],t11[i-1]);
	}
}
namespace seg{
	int seg0[200010],seg1[200010],siz[200010];
	void insert(int l,int r,int pos,int num){
//		cout<<"insert "<<l<<' '<<r<<' '<<pos<<' '<<val[pos]<<'\n';
		if(l==r){seg0[num]=seg1[num]=val[pos];siz[num]=1;return;}
		int mid=(l+r)>>1;
		if(mid>=pos) insert(l,mid,pos,num<<1);
		else insert(mid+1,r,pos,num<<1|1);
		siz[num]=siz[num<<1]+siz[num<<1|1];
		seg0[num]=add(seg0[num<<1],(seg0[num<<1|1]*t00[siz[num<<1]]+seg1[num<<1|1]*t01[siz[num<<1]])%MOD);
		seg1[num]=add(seg1[num<<1],(seg0[num<<1|1]*t10[siz[num<<1]]+seg1[num<<1|1]*t11[siz[num<<1]])%MOD);
	}
	void del(int l,int r,int pos,int num){
//		cout<<"insert "<<l<<' '<<r<<' '<<pos<<' '<<val[pos]<<'\n';
		if(l==r){seg0[num]=seg1[num]=0;siz[num]=0;return;}
		int mid=(l+r)>>1;
		if(mid>=pos) del(l,mid,pos,num<<1);
		else del(mid+1,r,pos,num<<1|1);
		siz[num]=siz[num<<1]+siz[num<<1|1];
		seg0[num]=add(seg0[num<<1],(seg0[num<<1|1]*t00[siz[num<<1]]+seg1[num<<1|1]*t01[siz[num<<1]])%MOD);
		seg1[num]=add(seg1[num<<1],(seg0[num<<1|1]*t10[siz[num<<1]]+seg1[num<<1|1]*t11[siz[num<<1]])%MOD);
	}
}
int cnt[1000010];
inline void add(int w){cnt[w]++;if(cnt[w]==1) seg::insert(1,n,w,1);}
inline void del(int w){cnt[w]--;if(cnt[w]==0) seg::del(1,n,w,1);}
int main(){
	n=read();MOD=read();int i;
	len=sqrt(n);
	for(i=1;i<=n;i++) val[i]=a[i]=read();
	sort(val+1,val+n+1);
	for(i=1;i<=n;i++) a[i]=lower_bound(val+1,val+n+1,a[i])-val;
	Q=read();
	init();
	for(i=1;i<=Q;i++){
		q[i].l=read();q[i].r=read();
		q[i].blk=(q[i].l/len)+1;
		q[i].num=i;
	}
	sort(q+1,q+Q+1,cmp);
	int curl=0,curr=0;
	for(i=1;i<=Q;i++){
		while(curr<q[i].r) add(a[++curr]);
		while(curr>q[i].r) del(a[curr--]);
		while(curl<q[i].l) del(a[curl++]);
		while(curl>q[i].l) add(a[--curl]);
		ans[q[i].num]=seg::seg0[1];
	}
	for(i=1;i<=Q;i++) printf("%d\n",ans[i]);
}
