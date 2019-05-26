#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
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
double v,a;
int main(){
	scanf("%lf%lf",&v,&a);
	double v0=v*cos(a),g=10.0;
	double y0=0.5*v0*v0/g;
	double v1=v*sin(a);double x0=v1*v0/g;
	printf("%.10lf %.10lf",x0,y0);
}
