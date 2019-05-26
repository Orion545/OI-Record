#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<vector>
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
int a[800010],lazy[800010];
void update(int num){
	a[num]=max(a[num<<1],a[num<<1|1]);
}
void push(int l,int r,int num){
	if(l==r||!lazy[num]) return;
	a[num<<1]+=lazy[num];lazy[num<<1]+=lazy[num];
	a[num<<1|1]+=lazy[num];lazy[num<<1|1]+=lazy[num];
	lazy[num]=0;
}
void build(int l,int r,int num){
	if(l==r){
		a[num]=l;return;
	}
	int mid=(l+r)>>1;
	build(l,mid,num<<1);build(mid+1,r,num<<1|1);
	update(num);
}
void change(int l,int r,int ql,int qr,int num,int val){
	push(l,r,num);
	if(l>=ql&&r<=qr){
		a[num]+=val;lazy[num]+=val;return;
	} 
	int mid=(l+r)>>1;
	if(mid>=ql) change(l,mid,ql,qr,num<<1,val);
	if(mid<qr) change(mid+1,r,ql,qr,num<<1|1,val);
	update(num);
}
int query(int l,int r,int ql,int qr,int num){
	push(l,r,num);
	if(l>=ql&&r<=qr) return a[num];
	int mid=(l+r)>>1,re=0;
	if(mid>=ql) re=max(re,query(l,mid,ql,qr,num<<1));
	if(mid<qr) re=max(re,query(mid+1,r,ql,qr,num<<1|1));
	return re;
}
int n,m;
vector<int>q[200010];
int main(){
	n=read();m=read();int i,j,t1,t2;
	for(i=1;i<=n;i++){
		t1=read();t2=read();
		q[t1].push_back(t2);
	}
	build(1,m+1,1);
	int ans=1e9;
	for(i=0;i<=m;i++){
		for(j=0;j<q[i].size();j++) change(1,m+1,1,q[i][j],1,1);
		ans=min(ans,i+m+1-query(1,m+1,i+1,m+1,1));
	}
	ans+=n;ans=min(ans,min(n,m));
	printf("%d\n",n-ans);
}
