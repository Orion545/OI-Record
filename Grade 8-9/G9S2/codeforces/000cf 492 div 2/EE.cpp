#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cassert>
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
struct vec{
	int x,y;
}a[100010],p[100010],q[100010];
int n,ans[100010],cntp,cntq;
double dis(double xx,double yy){
	xx=abs(xx),yy=abs(yy);
	return sqrt(xx*xx+yy*yy);
}
bool cmp(vec l,vec r){
	return dis(l.x,l.y)<dis(r.x,r.y);
}
int main(){
	n=read();int i,tx=0,ty=0,d1,d2;
	for(i=1;i<=n;i++){
		a[i].x=read(),a[i].y=read();
		d1=dis(tx+a[i].x,ty+a[i].y);
		d2=dis(tx-a[i].x,ty-a[i].y);
		if(d1<d2){
			tx+=a[i].x;ty+=a[i].y;
			ans[i]=1;
		}
		else{
			tx-=a[i].x;ty-=a[i].y;
			ans[i]=-1;
		}
	}
//	for(i=1;i<=n;i++) if(a[i].x<0) a[i].x=-a[i].x,a[i].y=-a[i].y;
	sort(a+1,a+n+1,cmp);
//	cout<<tx<<' '<<ty<<' '<<dis(tx,ty)<<'\n';
	if(dis(tx,ty)<=1500000) goto out;
	for(i=1;i<=n;i++){
		d1=dis(tx+(-ans[i])*2*a[i].x,ty+(-ans[i])*2*a[i].y);
		if(d1<dis(tx,ty)){
			tx+=(-ans[i])*2*a[i].x;
			ty+=(-ans[i])*2*a[i].y;
			ans[i]=-ans[i];
			if(d1<=1500000) goto out;
		}
	}
	out:
	assert(dis(tx,ty)<=1500000);
//	cout<<tx<<' '<<ty<<' '<<dis(tx,ty)<<'\n';
	for(i=1;i<=n;i++) printf("%d ",ans[i]);
}
