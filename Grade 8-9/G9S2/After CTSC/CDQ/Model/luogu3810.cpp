#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,lim,nn;
struct node{
	int a,b,c,w,ans;
}a[100010],t[100010];int out[100010];
inline bool cmp(node l,node r){
	if(l.a!=r.a) return l.a<r.a;
	if(l.b!=r.b) return l.b<r.b;
	return l.c<r.c;
}
struct bitree{
	int a[200010];
	int lowbit(int x){
		return x&(-x);
	}
	void add(int x,int val){
//		cout<<"add "<<x<<' '<<val<<'\n';
		for(;x<=lim;x+=lowbit(x)) a[x]+=val;
	}
	int query(int x){
//		cout<<"query "<<x<<'\n';
		int re=0;
		for(;x>=1;x-=lowbit(x)) re+=a[x];
		return re;
	}
}T;
void cdq(int l,int r){
//	cout<<"cdq "<<l<<' '<<r<<'\n';
	if(l==r ) return;
	int mid=(l+r)>>1,i=l,j=mid+1,p=l;
	cdq(l,mid);cdq(mid+1,r);
	while(i<=mid&&j<=r){
//		cout<<i<<' '<<j<<' '<<a[i].b<<' '<<a[j].b<<'\n';
		if(a[i].b<=a[j].b) T.add(a[i].c,a[i].w),t[p++]=a[i++];
		else a[j].ans+=T.query(a[j].c),t[p++]=a[j++];
	}
	while(i<=mid) T.add(a[i].c,a[i].w),t[p++]=a[i++];
	while(j<=r) a[j].ans+=T.query(a[j].c),t[p++]=a[j++];
	i--;
	while(i>=l) T.add(a[i].c,-a[i].w),i--;
	for(i=l;i<=r;i++) a[i]=t[i];
//	cout<<"end of cdq "<<l<<' '<<r<<'\n';
}
int main(){
//	freopen("cdq1.in","r",stdin);
//	freopen("cdq.out","w",stdout);
	int i;
	nn=read();lim=read();
	for(i=1;i<=nn;i++){
		a[i].a=read();
		a[i].b=read();
		a[i].c=read();
	}
	sort(a+1,a+nn+1,cmp);
	n=1;a[1].w=1;
	for(i=2;i<=nn;i++){
//		cout<<i<<' '<<n<<'\n';
		if(a[i].a==a[n].a&&a[i].b==a[n].b&&a[i].c==a[n].c) a[n].w++;
		else a[++n]=a[i],a[n].w=1;
	}
//	for(i=1;i<=n;i++) cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<' '<<a[i].w<<'\n';
	cdq(1,n);
//	for(i=1;i<=n;i++) cout<<i<<' '<<a[i].w<<' '<<a[i].ans<<' '<<a[i].ans+a[i].w-1<<'\n';
	for(i=1;i<=n;i++) out[a[i].ans+a[i].w-1]+=a[i].w;
	for(i=0;i<nn;i++) printf("%d\n",out[i]); 
}
