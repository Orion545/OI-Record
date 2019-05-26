#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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

     struct Point  
    {  
        double x;  
        double y; 
        Point(){
        	x=0;y=0;
		}
        Point(double xx,double yy){
        	x=xx;y=yy;
		}
    }a[4],b[4];
    //判断直线AB是否与线段CD相交  
    bool lineIntersectSide(Point A, Point B, Point C, Point D)  
    {  
        // A(x1, y1), B(x2, y2)的直线方程为：  
        // f(x, y) =  (y - y1) * (x1 - x2) - (x - x1) * (y1 - y2) = 0  
      
        float fC = (C.y - A.y) * (A.x - B.x) - (C.x - A.x) * (A.y - B.y);  
        float fD = (D.y - A.y) * (A.x - B.x) - (D.x - A.x) * (A.y - B.y);  
      
        if(fC * fD > 0)  
            return false;  
      
        return true;  
    }  
    bool judge(Point A, Point B, Point C, Point D)  
    {  
        if(!lineIntersectSide(A, B, C, D))  
            return false;  
        if(!lineIntersectSide(C, D, A, B))  
            return false;  
        return true;  
    }  
/*
struct Point{
       double x,y;
       Point(){}
       Point(int a,int b){
              x=a;
              y=b;
       }
       void input(){
              scanf("%lf%lf",&x,&y);
       }
}a[4],b[4];
struct Line{
       Point a,b;
       Line(){}
       Line(Point x,Point y){
              a=x;
              b=y;
       }
       void input(){
              a.input();
              b.input();
       }
};
bool judge(Point &a,Point &b,Point &c,Point &d)
{
       if(!(min(a.x,b.x)<=max(c.x,d.x) && min(c.y,d.y)<=max(a.y,b.y)&&min(c.x,d.x)<=max(a.x,b.x) && min(a.y,b.y)<=max(c.y,d.y)))
       return false;
    double u,v,w,z;
    u=(c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y);
       v=(d.x-a.x)*(b.y-a.y)-(b.x-a.x)*(d.y-a.y);
       w=(a.x-c.x)*(d.y-c.y)-(d.x-c.x)*(a.y-c.y);
       z=(b.x-c.x)*(d.y-c.y)-(d.x-c.x)*(b.y-c.y);
       return (u*v<=0.00000001 && w*z<=0.00000001);
}
*/ 
double abss(double x){
	return x>0?x:-x;
}
bool check(Point x){
	double S=0;
	S+=0.5*abss(x.x*b[0].y+b[0].x*b[1].y+x.y*b[1].x-b[0].x*x.y-x.x*b[1].y-b[1].x*b[0].y);
	S+=0.5*abss(x.x*b[1].y-b[1].x*x.y+x.y*b[2].x-x.x*b[2].y+b[1].x*b[2].y-b[2].x*b[1].y);
	S+=0.5*abss(x.x*b[2].y-b[2].x*x.y+x.y*b[3].x-x.x*b[3].y+b[2].x*b[3].y-b[3].x*b[2].y);
	S+=0.5*abss(x.x*b[3].y-b[3].x*x.y+x.y*b[0].x-x.x*b[0].y+b[3].x*b[0].y-b[0].x*b[3].y);
//	cout<<"check "<<x.x<<' '<<x.y<<' '<<S<<'\n';
	if(S*2==max(abss(b[0].y-b[2].y),abss(b[0].x-b[2].x))*max(abss(b[0].y-b[2].y),abss(b[0].x-b[2].x))) return 1;
	else return 0;
}
int main(){
	int t1,t2,lx,rx,ly,ry;
	t1=read();t2=read();lx=t1;rx=t1;ly=ry=t2;
	a[0]=Point(t1,t2);
	t1=read();t2=read();lx=min(lx,t1);rx=max(rx,t1);ly=min(t2,ly);ry=max(ry,t2);
	a[1]=Point(t1,t2);
	t1=read();t2=read();lx=min(lx,t1);rx=max(rx,t1);ly=min(t2,ly);ry=max(ry,t2);
	a[2]=Point(t1,t2);
	t1=read();t2=read();lx=min(lx,t1);rx=max(rx,t1);ly=min(t2,ly);ry=max(ry,t2);
	a[3]=Point(t1,t2);
	t1=read();t2=read();
	b[0]=Point(t1,t2);
	t1=read();t2=read();
	b[1]=Point(t1,t2);
	t1=read();t2=read();
	b[2]=Point(t1,t2);
	t1=read();t2=read();
	b[3]=Point(t1,t2);
//	cout<<"check "<<check(a[0]);
	bool flag=0;
	flag=(flag||judge(a[0],a[1],b[0],b[1]));
//	cout<<flag<<'\n';
	flag=(flag||judge(a[1],a[2],b[0],b[1]));
//	cout<<flag<<'\n';
	flag=(flag||judge(a[2],a[3],b[0],b[1]));
//	cout<<flag<<'\n';
	flag=(flag||judge(a[3],a[0],b[0],b[1]));
//	cout<<flag<<'\n';
	flag=(flag||judge(a[0],a[1],b[1],b[2]));
//	cout<<flag<<'\n';
	flag=(flag||judge(a[1],a[2],b[1],b[2]));
//	cout<<flag<<'\n';
	flag=(flag||judge(a[2],a[3],b[1],b[2]));
//	cout<<flag<<'\n';
	flag=(flag||judge(a[3],a[0],b[1],b[2]));
//	cout<<flag<<'\n';
	flag=(flag||judge(a[0],a[1],b[2],b[3]));
//	cout<<flag<<'\n';
	flag=(flag||judge(a[1],a[2],b[2],b[3]));
//	cout<<flag<<'\n';
	flag=(flag||judge(a[2],a[3],b[2],b[3]));
//	cout<<flag<<'\n';
	flag=(flag||judge(a[3],a[0],b[2],b[3]));
//	cout<<flag<<'\n';
	flag=(flag||judge(a[0],a[1],b[3],b[0]));
//	cout<<flag<<'\n';
	flag=(flag||judge(a[1],a[2],b[3],b[0]));
//	cout<<flag<<'\n';
	flag=(flag||judge(a[2],a[3],b[3],b[0]));
//	cout<<flag<<'\n';
	flag=(flag||judge(a[3],a[0],b[3],b[0]));
//	cout<<flag<<'\n';
	if(flag) puts("YES");
	else{
		if(b[0].x>=lx&&b[0].x<=rx&&b[1].x>=lx&&b[1].x<=rx&&b[2].x>=lx&&b[2].x<=rx&&b[3].x>=lx&&b[3].x<=rx&&b[0].y>=ly&&b[0].y<=ry&&b[1].y>=ly&&b[1].y<=ry&&b[2].y>=ly&&b[2].y<=ry&&b[3].y>=ly&&b[3].y<=ry)
			puts("YES");
		else {
			if(check(a[0])&&check(a[1])&&check(a[2])&&check(a[3])) puts("YES");
			else puts("NO");
		}
	}
}
/*
-0 -0 -6 -0 -6 -6 -0 -6
-1 -3 -3 -5 -5 -3 -3 -1

0 0 0 1 1 1 1 0
0 3 3 0 0 -3 -3 0

*/
