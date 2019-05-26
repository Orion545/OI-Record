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
int n,m,cnt[1000010];ll ans[200010];ll a[200010];int len;ll ANS;
struct query{
	int l,r,blk,num;
}q[200010];
inline bool cmp(query l,query r){
	return (l.blk==r.blk)?(l.r<r.r):(l.l<r.l);
}
inline void add(int w){
	ANS-=1ll*cnt[w]*cnt[w]*w;
	cnt[w]++;
	ANS+=1ll*cnt[w]*cnt[w]*w;
}
inline void del(int w){
	ANS-=1ll*cnt[w]*cnt[w]*w;
	cnt[w]--;
	ANS+=1ll*cnt[w]*cnt[w]*w;
}
int main(){
	n=read();m=read();int i;
	len=sqrt(n);
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<=m;i++){
		q[i].l=read();q[i].r=read();
		q[i].blk=(q[i].l/len)+1;
		q[i].num=i;
	}
	sort(q+1,q+m+1,cmp);
	int curl=0,curr=0;
	for(i=1;i<=m;i++){
		while(curr<q[i].r) add(a[++curr]);
		while(curr>q[i].r) del(a[curr--]);
		while(curl<q[i].l) del(a[curl++]);
		while(curl>q[i].l) add(a[--curl]);
		ans[q[i].num]=ANS;
	}
	for(i=1;i<=m;i++) printf("%lld\n",ans[i]);
}
