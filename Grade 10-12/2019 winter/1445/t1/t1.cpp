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
struct vec{
	double x,y;
	inline vec operator +(const vec &b){return (vec){x+b.x,y+b.y};}
	inline vec operator -(const vec &b){return (vec){x-b.x,y-b.y};}
	inline vec operator *(const double &b){return (vec){x*b,y*b};}
	friend inline double dot(vec a,vec b){return a.x*b.x+a.y*b.y;}
	friend inline double dis(vec a,vec b){return sqrt(dot(a-b,a-b));}
}p[110],lp;
int n;
double h,a,r;
vec get(vec a,vec b,vec c){
	double k=dot(a-b,c-b)/dot(b-c,b-c);
	return b+(c-b)*k;
}
double tri(vec t1,vec t2){
	double d1=dis(lp,t1),d2=dis(lp,t2),d3=dis(t1,t2);
	if(r<d1) return (double)acos(d1/d2)*r*r/2.0;
	else{
		if(r>d2) return d1*d3/2;
		else return d1*sqrt(r*r-d1*d1)/2+(acos(d1/d2)-atan(sqrt(r*r-d1*d1)/d1))*r*r/2;
	}
}
double calctri(vec t1,vec t2){
	vec p=get(lp,t1,t2);
	if(dot(t1-p,t2-p)>0) return fabs(tri(p,t1)-tri(p,t2));
	else return tri(p,t1)+tri(p,t2);
}
double jifen(double x,double aa){
	double t=sqrt(aa+x*x);
	return (x*t+aa*log(x+t))/2;
}
double calcwall(vec t1,vec t2){
	vec p=get(lp,t1,t2);
	double d2=dot(p-lp,p-lp);
//	cout<<"get "<<d2<<' '<<r<<'\n';
	if(d2>r*r) return 0;
	double x1=dis(p,t1),x2=dis(p,t2);
	double x3=-sqrt(r*r-d2);
	if(dot(t2-t1,t1-lp)<0) x1=-x1;
	if(dot(t1-t2,t2-lp)>0) x2=-x2;
//	cout<<"get "<<x1<<' '<<x2<<' '<<x3<<'\n';
	if(x3>x1) x1=x3;
	if(-x3<x2) x2=-x3;
//	cout<<"get "<<x1<<' '<<x2<<' '<<x3<<'\n';
	if(x1>x2) return 0;
	return (x2-x1)*h-h/r*(jifen(x2,d2)-jifen(x1,d2));
}
double solve1(){
	double re=0;
	for(int i=1;i<=n;i++) re+=calctri(p[i],p[i+1]);
	return re;
}
double solve2(){
	double re=0;
	for(int i=1;i<=n;i++) re+=calcwall(p[i],p[i+1]);
	return re;
}
int main(){
	int T=read(),i;
	while(T--){
		scanf("%lf%lf%lf%lf",&lp.x,&lp.y,&h,&a);
		a*=acos(-1.0)/360.0;
		r=tan(a)*h;
		n=read();
		for(i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
		p[n+1]=p[1];
		printf("%.10lf %.10lf\n",solve2(),solve1());
	}
}
