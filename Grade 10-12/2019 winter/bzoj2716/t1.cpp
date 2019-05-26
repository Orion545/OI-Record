#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define mymax(a,b) ((a>b)?a:b)
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
int len=0;
namespace BIT{
	int a[1000010];
	inline void add(int x,int val){
		for(;x<=len;x+=(x&(-x))) a[x]=max(a[x],val);
	}
	inline int getmax(int x){
		int re=0;
		for(;x;x-=(x&(-x))) re=max(re,a[x]);
		return re;
	}
	inline void clear(int x){
		for(;x<=len;x+=(x&(-x))) a[x]=0;
	}
}
struct node{
	int x,y,ty,id;
	inline bool operator <(const node r)const{
		if(x!=r.x) return x<r.x;
		return id<r.id;
	}
}a[1000010],tmp[1000010];
int n,m,ans[1000010];
void solve(int l,int r){
	if(l>=r){return;}
//	cout<<"solve "<<l<<' '<<r<<'\n';
	int i,j,cntl,cntr,mid=(l+r)>>1,cur;

	cntl=l-1;cntr=mid;
	for(i=l;i<=r;i++){
		if(a[i].id<=mid) tmp[++cntl]=a[i];
		else tmp[++cntr]=a[i];
	}
	for(i=l;i<=r;i++) a[i]=tmp[i];

	solve(l,mid);

	j=l;
	for(i=mid+1;i<=r;i++){
		if(a[i].ty==1) continue;
		for(;j<=mid&&a[j].x<=a[i].x;j++){
			if(a[j].ty==1) BIT::add(a[j].y,a[j].x+a[j].y);
		}
//		cout<<"				try ans "<<a[i].id<<' '<<a[i].x<<' '<<a[i].y<<' '<<ans[a[i].id]<<' '<<BIT::getmax(a[i].y)<<'\n';
		cur=BIT::getmax(a[i].y);
		if(cur) ans[a[i].id]=min(ans[a[i].id],a[i].x+a[i].y-cur);
	}
	for(i=l;i<j;i++) if(a[i].ty==1) BIT::clear(a[i].y);

	solve(mid+1,r);

	merge(a+l,a+mid+1,a+mid+1,a+r+1,tmp+l);
	for(i=l;i<=r;i++) a[i]=tmp[i];
}
int main(){
	n=read();m=read();int i,t1,t2,t3;
	for(i=1;i<=n;i++){
		t1=read();t2=read();
		a[i].x=t1+1;a[i].y=t2+1;
		a[i].ty=1;a[i].id=i;
		ans[i]=1e9;
		len=max(len,max(a[i].x,a[i].y));
	}
	for(i=n+1;i<=m+n;i++){
		t1=read();t2=read();t3=read();
		a[i].x=t2+1;a[i].y=t3+1;
		a[i].ty=t1;a[i].id=i;
		ans[i]=1e9;
		len=max(len,max(a[i].x,a[i].y));
	}
	t1=n;n=n+m;m=t1;
	len++;

	sort(a+1,a+n+1);
	solve(1,n);

	for(i=1;i<=n;i++) a[i].x=len-a[i].x;

	sort(a+1,a+n+1);
	solve(1,n);

	for(i=1;i<=n;i++) a[i].y=len-a[i].y;

	sort(a+1,a+n+1);
	solve(1,n);

	for(i=1;i<=n;i++) a[i].x=len-a[i].x;

	sort(a+1,a+n+1);
	solve(1,n);

	for(i=1;i<=n;i++) if(ans[i]!=1e9) printf("%d\n",ans[i]);
}
