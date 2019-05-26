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
int n,x[100010],y[100010],ans[100010];
double dis(double xx,double yy){
	xx=abs(xx),yy=abs(yy);
	return sqrt(xx*xx+yy*yy);
}
int main(){
	n=read();int i,tx=0,ty=0,d1,d2;
	for(i=1;i<=n;i++){
		x[i]=read(),y[i]=read();
		d1=dis(tx+x[i],ty+y[i]);
		d2=dis(tx-x[i],ty-y[i]);
//		assert(min(d1,d2)<=1500000);
		if(d1<d2){
			tx+=x[i];ty+=y[i];
			ans[i]=1;
		}
		else{
			tx-=x[i];ty-=y[i];
			ans[i]=-1;
		}
	}
	for(i=1;i<=n;i++) printf("%d ",ans[i]);
	
}
