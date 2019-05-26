/**************************************************************
    Problem: 2982
    User: ez_zjt
    Language: C++
    Result: Accepted
    Time:93 ms
    Memory:2144 kb
****************************************************************/
 
 
#include <bits/stdc++.h>
#define MAXN 110
 
const double eps=1e-8;
 
struct vec{
    double x,y;
    friend vec operator+(vec x,vec y){ return (vec){x.x+y.x,x.y+y.y}; }
    friend vec operator-(vec x,vec y){ return (vec){x.x-y.x,x.y-y.y}; }
    friend vec operator*(vec x,double y){ return (vec){x.x*y,x.y*y}; }
    friend double dot(vec x,vec y){ return x.x*y.x+x.y*y.y; }
    friend double dis(vec x,vec y){ return sqrt(dot(x-y,x-y)); }
}p[MAXN],lp;
 
int n;
double h,a,r;
 
vec getp(vec a,vec b,vec c){
    double k=dot(c-b,a-b)/dot(b-c,b-c);
    return b+(c-b)*k;
}
 
double calc0(vec t1,vec t2){
    double d1=dis(lp,t1),d2=dis(lp,t2),d3=dis(t1,t2);
    if(r<d1){
        double a=acos(d1/d2);
        return a*r*r/2;
    }else if(r>d2){
        return d1*d3/2;
    }else{
        double k=sqrt(r*r-d1*d1);
        double a=acos(d1/d2)-atan(k/d1);
        return d1*k/2+a*r*r/2;
    }
}
 
double calc1(vec t1,vec t2){
    vec p=getp(lp,t1,t2);
    if(dot(t1-p,t2-p)>0) return fabs(calc0(p,t1)-calc0(p,t2));
    else return calc0(p,t1)+calc0(p,t2);
}
 
double getint(double x,double a2){
    double t=sqrt(a2+x*x);
    return (x*t+a2*log(x+t))/2;
}
 
double calc2(vec t1,vec t2){
    vec p=getp(lp,t1,t2);
    double d2=dot(p-lp,p-lp);
    if(d2>r*r) return 0;
    double x1=dis(p,t1),x2=dis(p,t2);
    double x3=-sqrt(r*r-d2),x4=-x3;
    if(dot(t2-t1,t1-lp)<0) x1=-x1;
    if(dot(t1-t2,t2-lp)>0) x2=-x2;
    if(x3>x1) x1=x3;
    if(x4<x2) x2=x4;
	printf("%.5lf %.5lf %.5lf\n",x1,x2,x3);
    if(x1>x2) return 0;
    return (x2-x1)*h-h/r*(getint(x2,d2)-getint(x1,d2));
}
 
double solve1(){
    double res=0;
    for(int i=1;i<=n;i++)
        res+=calc1(p[i],p[i+1]);
    return res;
}
 
double solve2(){
    double res=0;
    for(int i=1;i<=n;i++)
        res+=calc2(p[i],p[i+1]);
    return res;
}
 
void solve(){
    scanf("%lf%lf%lf%lf",&lp.x,&lp.y,&h,&a);
    a*=M_PI/360.0;
    r=tan(a)*h;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
    p[n+1]=p[1];
    double res=solve1(),res2=solve2();
    printf("%.10f %.10f\n",res2,res);
}
 
int main(){
#ifdef DEBUG
    freopen("A.in","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--) solve();
}
