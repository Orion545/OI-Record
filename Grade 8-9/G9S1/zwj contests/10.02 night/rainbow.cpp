#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
double x0,h;
double l,r,mid;
struct circle{
	double x,r;
}a[10];
struct seg{
	double l,r;
};
bool cmp2(seg xx,seg yy){
	return xx.l<yy.l;
}
bool solve(double k){
	double tx,ty,ans=0;int i,j;
//	cout<<endl<<endl<<"solving "<<k<<endl;
	seg x[10];
	for(i=1;i<=7;i++){
		if(a[i].r+k<h){
			x[i].l=x[i].r=x0;
			continue;
		}
		tx=sqrt((a[i].r+k)*(a[i].r+k)-h*h);
//		cout<<i<<ends<<a[i].r+k<<ends<<a[i].x<<ends<<tx<<endl;
		x[i].l=min(x0,max(0.0,a[i].x-tx));x[i].r=max(0.0,min(x0,a[i].x+tx));
	}
	int vis[10]={0},flag;
	sort(x+1,x+8,cmp2);
	x[8].l=x0;x[8].r=x0;
//	cout<<endl<<endl;
//	for(i=1;i<=8;i++) printf("%d %.6f %.6f\n",i,x[i].l,x[i].r);
	i=1;j=2;
	if(x[1].l>0) return 0;
	while(i!=j&&j<8){
//		cout<<i<<ends<<j<<endl;
		if(x[i].r>=x[j].l&&x[j].r==x0) return 1;
		if(x[j].l<=x[i].r) j++;
		else i++;
	}
//	cout<<i<<ends<<j<<endl;
//	if(j==8) return 1;
	return 0;
}
bool cmp(circle xx,circle yy){
	return xx.x<yy.x;
}
int main(){
	freopen("rainbow.in","r",stdin);
	freopen("rainbow.out","w",stdout);
	int i;
	scanf("%lf%lf",&h,&x0);
	for(i=1;i<=7;i++) scanf("%lf%lf",&a[i].x,&a[i].r);
	sort(a+1,a+8,cmp);
	l=0;r=10000.0;
	while(r-l>=0.001){
		mid=(r+l)/2;
//		cout<<"l && r:"<<l<<ends<<r<<endl;
		if(solve(mid)) r=mid;
		else l=mid;
	}
	printf("%.2f",(l+r)/2+0.0005);
} 
/*
53.82 4869.24
2865.17 920.97
1.32 455.15
198.93 809.26
1387.51 471.69
6931.01 398.96
5897.21 240.07
7781.01 718.24

*/
