#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,m,a[200010],p1,p2;
namespace BIT{
	ll s1[200010],s2[200010];
	int lowbit(int x){
		return x&(-x);
	}
	void add(int x,ll val){
//		cout<<"add "<<x<<' '<<val<<'\n';
		for(int i=x;i<=n;i+=lowbit(i)) s1[i]+=val,s2[i]+=(ll)x*val;
	}
	ll sum(int x){
		ll re=0;
//		cout<<"sum "<<x<<' ';
		for(int i=x;i>0;i-=lowbit(i)){
			re+=(ll)(x+1)*s1[i]-s2[i];
		}
//		cout<<re<<'\n';
		return re;
	}
}
struct ques{
	int l,r,pos,num,flag;
}q[400010];
inline bool cmp(ques l,ques r){
	return l.pos<r.pos;
}
int s[200010],top,L[200010],R[200010];ll ans[200010];
struct add{
	int pos,l,r,val;
}x[600010];
inline bool cmpa(add l,add r){
	return l.pos<r.pos;
}
int main(){
	n=read();m=read();p1=read();p2=read();int i;
	int t1=1,t2=1;
	for(i=1;i<=n;i++) a[i]=read(),L[i]=0,R[i]=n+1;
	for(i=1;i<=n;i++){
		while(top&&a[s[top]]<a[i]) R[s[top]]=i,s[top--]=0;
		L[i]=s[top];
		s[++top]=i;
	}
	while(top) s[top--]=0;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		ans[i]+=(t2-t1)*p1;
		q[i].l=q[i+m].l=t1;
		q[i].r=q[i+m].r=t2;
		q[i].pos=t1-1;q[i].flag=-1;q[i].num=i;
		q[i+m].pos=t2;q[i+m].flag=1;q[i+m].num=i;
	}
	sort(q+1,q+m*2+1,cmp);
	int tot=0;
	for(i=1;i<=n;i++){
//		cout<<"check "<<i<<' '<<L[i]<<' '<<R[i]<<'\n';
		if(L[i]>=1&&R[i]<=n) x[++tot]=(add){R[i],L[i],L[i],p1};
		if(L[i]>=1&&R[i]>i+1) x[++tot]=(add){L[i],i+1,R[i]-1,p2};
		if(L[i]<i-1&&R[i]<=n) x[++tot]=(add){R[i],L[i]+1,i-1,p2};
	}
	sort(x+1,x+tot+1,cmpa);
	t1=1;t2=1;
	while(q[t1].pos==0) t1++;
	for(i=1;i<=n;i++){
		while(t2<=tot&&x[t2].pos<=i){
//			cout<<"getadd "<<x[t2].pos<<' '<<x[t2].l<<' '<<x[t2].r<<'\n';
			BIT::add(x[t2].l,x[t2].val);
			BIT::add(x[t2].r+1,-x[t2].val);
			t2++;
		}
		while(t1<=m*2&&q[t1].pos<=i){
			ans[q[t1].num]+=q[t1].flag*(BIT::sum(q[t1].r)-BIT::sum(q[t1].l-1));
			t1++;
		}
	}
	for(i=1;i<=m;i++) printf("%lld\n",ans[i]);
}
