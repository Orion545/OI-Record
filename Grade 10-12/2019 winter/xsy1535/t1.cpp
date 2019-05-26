#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define mp make_pair
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
int n,m,a[100010],len,ans[100010],le[100010],ri[100010];
pair<int,int>sl[100010],sr[100010];int top;
struct seg{
	int l,r,blk,num;
}q[100010];
inline bool cmp(seg l, seg r){
	return (l.blk==r.blk)?l.r<r.r:l.l<r.l;
}
int main(){
	n=read();m=read();int i,j,tmp,l,r,curl,curr,re;
	for(i=1;i<=n;i++) a[i]=read();
	len=sqrt(n);
	for(i=1;i<=m;i++){
		q[i].l=read();q[i].r=read();
		q[i].blk=(q[i].l/len)+1;
		q[i].num=i;
	}
	sort(q+1,q+m+1,cmp);
	l=r=re=0;
	for(i=1;i<=m;i++){
		//(l,r]
		l=len*q[i].blk;
		if(q[i].blk!=q[i-1].blk){
			r=l;re=0;
			memset(le,0,sizeof(le));
			memset(ri,0,sizeof(ri));
		}
		while(r<q[i].r){
			r++;
			curl=a[r]-le[a[r]-1];
			curr=a[r]+ri[a[r]+1];
			re=max(re,le[curr]=ri[curl]=le[a[r]-1]+ri[a[r]+1]+1);
		}
		l=min(l,q[i].r);ans[q[i].num]=re;
		while(l>=q[i].l){
			curl=a[l]-le[a[l]-1];
			curr=a[l]+ri[a[l]+1];
			top++;
			sl[top]=mp(curr,le[curr]);
			sr[top]=mp(curl,ri[curl]);
			ans[q[i].num]=max(ans[q[i].num],le[curr]=ri[curl]=le[a[l]-1]+ri[a[l]+1]+1);
			l--;
		}
		while(top){
			le[sl[top].first]=sl[top].second;
			ri[sr[top].first]=sr[top].second;
			top--;
		}
	}
	for(i=1;i<=m;i++) printf("%d\n",ans[i]);
}
