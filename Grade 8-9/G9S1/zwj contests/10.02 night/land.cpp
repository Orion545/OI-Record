#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
struct P{
	double x,y,slop;
	P(){}
	P(double a,double b){x=a;y=b;}
	friend P operator -(P a,P b){
		return P(a.x-b.x,a.y-b.y);
	}
	friend double operator *(P a,P b){
		return a.x*b.y-a.y*b.x;
	}
}a[1005],b[1005];
int n;
double ans=1e9;
bool cmp(P a,P b){
	return a.slop<b.slop;
}
double sum(P a,P b,P c){
	return fabs((a-b)*(a-c)/2);
}
int main(){
	freopen("land.in","r",stdin);
	freopen("land.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++){
		for(int p=1,o=0;p<=n;p++){
			if(i==p) continue;
			b[++o]=a[p];
			b[o].slop=atan2(b[o].y-a[i].y,b[o].x-a[i].x);
		}
		sort(b+1,b+n,cmp);
		for(int p=1,nxt;p<n;p++){
			nxt=p+1;
			if(nxt==n) nxt=1;
			ans=min(ans,sum(a[i],b[p],b[nxt]));
		}
	}
	printf("%.2lf",ans);
	return 0;
}
