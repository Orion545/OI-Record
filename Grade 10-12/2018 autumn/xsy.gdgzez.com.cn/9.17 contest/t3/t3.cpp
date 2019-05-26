#include<iostream>
#include<cassert>
#include<cstring>
#include<algorithm>
#include<cstdio>
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
struct node{
	int x,y;
	node(int xx=0,int yy=0){x=xx;y=yy;}
}a[300010],b[300010],p[300010];
int topa,topb,seg[1200010],lazy[1200010],ans=0;
inline bool cmp(node l,node r){return ((l.x==r.x)?(l.y<r.y):(l.x<r.x));}
int n,w,h,ql,qr;
void change(int l,int r,int num,int val){
//	cout<<"	change "<<l<<' '<<r<<' '<<ql<<' '<<qr<<'\n';
	assert(ql<=qr);
	if(l>=ql&&r<=qr){seg[num]+=val;lazy[num]+=val;return;}
	int mid=(l+r)>>1;
	if(mid>=ql) change(l,mid,num<<1,val);
	if(mid<qr) change(mid+1,r,num<<1|1,val);
	seg[num]=max(seg[num<<1],seg[num<<1|1])+lazy[num];
}
void solve(){
	memset(seg,0,sizeof(seg));memset(lazy,0,sizeof(lazy));
	sort(p+1,p+n+1,cmp);
	topa=0;topb=0;int i,pre;
	for(i=1;i<n;i++){
//		cout<<"do "<<i<<' '<<p[i].x<<' '<<p[i].y<<'\n';
		if(p[i].y<=h/2){
			pre=i-1;
			while(topa&&a[topa].y<p[i].y){
				ql=a[topa].x;qr=pre;pre=a[topa].x-1;
				change(1,n,1,a[topa].y-p[i].y);topa--;
			}
			if(pre!=(i-1)) a[++topa]=node(pre+1,p[i].y);
		}
		else{
			pre=i-1;
			while(topb&&b[topb].y>p[i].y){
				ql=b[topb].x;qr=pre;pre=b[topb].x-1;
				change(1,n,1,p[i].y-b[topb].y);topb--;
			}
			if(pre!=(i-1)) b[++topb]=node(pre+1,p[i].y);
		}
		a[++topa]=node(i,0);b[++topb]=node(i,h);
		ql=qr=i;change(1,n,1,h-p[i].x);
		ans=max(ans,seg[1]+p[i+1].x);
	}
}
int main(){
	w=read();h=read();n=read();int i;
	for(i=1;i<=n;i++) p[i].x=read(),p[i].y=read();
	p[++n]=node(0,0);p[++n]=node(w,h);
	solve();
	for(i=1;i<=n;i++) swap(p[i].x,p[i].y);
	swap(w,h);
	solve();
	printf("%d",ans*2);
}
