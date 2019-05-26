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
int n,m,x[510][510],ans[60010];
namespace BIT{
	int a[510][510];
	void init(){memset(a,0,sizeof(a));}
	void add(int x,int y,int val){
//		cout<<"add "<<x<<' '<<y<<' '<<val<<'\n';
		for(;x<=n;x+=(x&(-x)))
			for(int i=y;i<=n;i+=(i&(-i)))
				a[x][i]+=val;
	}
	int sum(int x,int y){
		int re=0;
//		cout<<"sum "<<x<<' '<<y<<' ';
		for(;x;x^=(x&(-x)))
			for(int i=y;i;i^=(i&(-i)))
				re+=a[x][i];
//		cout<<"get "<<re<<'\n';
		return re;
	}
}
struct node{
	int val,x,y;
}a[250010];
bool cmp(node l,node r){
	return l.val<r.val;
}
struct query{
	int lx,rx,ly,ry,lim,id;
}q[60010],stl[60010],str[60010];
void solve(int l,int r,int ql,int qr){
	int i,cntl=0,cntr=0,cur,mid=(l+r)>>1;
	if(ql>qr) return;
//	cout<<"***********solve "<<l<<' '<<r<<' '<<ql<<' '<<qr<<'\n';
	if(l==r){
		for(i=ql;i<=qr;i++) ans[q[i].id]=a[l].val;
		return;
	}

	for(i=l;i<=mid;i++) BIT::add(a[i].x,a[i].y,1);
	for(i=ql;i<=qr;i++){
		cur=0;
		cur+=BIT::sum(q[i].lx-1,q[i].ly-1);
		cur-=BIT::sum(q[i].lx-1,q[i].ry);
		cur-=BIT::sum(q[i].rx,q[i].ly-1);
		cur+=BIT::sum(q[i].rx,q[i].ry);
		if(cur>=q[i].lim) stl[++cntl]=q[i];
		else q[i].lim-=cur,str[++cntr]=q[i];
	}
	for(i=l;i<=mid;i++) BIT::add(a[i].x,a[i].y,-1);
	
	for(i=ql;i<=ql+cntl-1;i++) q[i]=stl[i-ql+1];
	for(i=ql+cntl;i<=qr;i++) q[i]=str[i-ql-cntl+1];
	solve(l,mid,ql,ql+cntl-1);
	solve(mid+1,r,ql+cntl,qr);
}
int main(){
	n=read();m=read();int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++){
			a[n*(i-1)+j].val=read(),
			a[n*(i-1)+j].x=i;
			a[n*(i-1)+j].y=j;
//			cout<<"mat get "<<(i-1)*n+j<<'\n';
		}
	}
	sort(a+1,a+n*n+1,cmp);
//	for(i=1;i<=n*n;i++) cout<<i<<' '<<a[i].x<<' '<<a[i].y<<' '<<a[i].val<<'\n';
	for(i=1;i<=m;i++){
		q[i].lx=read();q[i].ly=read();
		q[i].rx=read();q[i].ry=read();
		q[i].lim=read();q[i].id=i;
	}
	solve(1,n*n,1,m);
	for(i=1;i<=m;i++) printf("%d\n",ans[i]);
}
