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
struct node{
	double x,y;
	node(){};
	node(double xx,double yy){x=xx;y=yy;}
	void read(){scanf("%lf%lf",&x,&y);}
}a,b,c,d,l1,r1,l2,r2;
node merge(node l,node r,double a,double b){
	return node((l.x*b+r.x*a)/(a+b),(l.y*b+r.y*a)/(a+b));
}
double dis(node l,node r){
	return sqrt((r.x-l.x)*(r.x-l.x)+(r.y-l.y)*(r.y-l.y));
}
double vab,vcd,vef;
double check(node e){
	double re=dis(a,e)/vab;
	l2=c;r2=d;node t1,t2;
	double dis1,dis2;
	while(dis(l2,r2)>=1e-6){
		t1=merge(l2,r2,1,2);t2=merge(l2,r2,2,1);
		dis1=dis(e,t1)/vef+dis(t1,d)/vcd;
		dis2=dis(e,t2)/vef+dis(t2,d)/vcd;
		if(dis1>dis2) l2=t1;
		else r2=t2;
	}
	return re+dis(e,l2)/vef+dis(l2,d)/vcd;
}
int main(){
	a.read();b.read();c.read();d.read();
	vab=read();vcd=read();vef=read();
	//first layer;
	l1=a;r1=b;node t1,t2;
	while(dis(l1,r1)>=1e-6){
		t1=merge(l1,r1,1,2);t2=merge(l1,r1,2,1);
		if(check(t1)>check(t2)) l1=t1;
		else r1=t2;
	}
	printf("%.2lf\n",check(l1));
}
