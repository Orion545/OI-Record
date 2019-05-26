#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cassert>
#define N 100010
using namespace std;
struct node{long double x,y;}b[N];
node O;
long double R;
long double sqr(long double x){return x*x;}
long double dis(node x,node y)
{
    return sqrt(sqr(x.x-y.x)+sqr(x.y-y.y));
}
bool incircle(node x)
{
//	cout<<"inc "<<dis(O,x)<<' '<<R<<'\n';
    if(dis(O,x)<=R) return true;
    return false;
}
node solve(long double a,long double b,long double c,long double d,long double e,long double f)
{
    long double y=(f*a-c*d)/(b*d-e*a);
    long double x=(f*b-c*e)/(a*e-b*d);
    return (node){x,y};
}
int main()
{
    int n;double t1,t2;
    scanf("%d",&n);
    int i,j,k,flag0=0,flag1=0;
    for(i=1;i<=n;i++){
    	scanf("%lf%lf",&t1,&t2);
    	b[i].x=t1;b[i].y=t2;
    	if(b[i].y>0) flag1=1;
    	else flag0=1;
	}
	if(flag0==1&&flag1==1){
		puts("-1");return 0;
	}
    random_shuffle(b+1,b+n+1);
    R=0;
    for(i=1;i<=n;i++)
    if(!incircle(b[i]))
    {
        O.x=b[i].x;O.y=b[i].y;R=0;
        for(j=1;j<i;j++)
        if(!incircle(b[j]))
        {
            O.x=(b[i].x+b[j].x)/2;
            O.y=(b[i].y+b[j].y)/2;
            R=dis(O,b[i]);
            for(k=1;k<j;k++)
            if(!incircle(b[k]))
            {
                O=solve(
                b[i].x-b[j].x,b[i].y-b[j].y,(sqr(b[j].x)+sqr(b[j].y)-sqr(b[i].x)-sqr(b[i].y))/2,
                b[i].x-b[k].x,b[i].y-b[k].y,(sqr(b[k].x)+sqr(b[k].y)-sqr(b[i].x)-sqr(b[i].y))/2 
                );
                R=dis(b[i],O);
            }
        }
    }
    // printf("%.10lf\n%.10lf %.10lf\n",R,O.x,O.y);
	b[n+1]=(node){O.x,0};i=n+1;
        O.x=b[i].x;O.y=b[i].y;R=0;
        for(j=1;j<i;j++)
        if(!incircle(b[j]))
        {
            O.x=(b[i].x+b[j].x)/2;
            O.y=(b[i].y+b[j].y)/2;
            R=dis(O,b[i]);
            for(k=1;k<j;k++)
            if(!incircle(b[k]))
            {
                O=solve(
                b[i].x-b[j].x,b[i].y-b[j].y,(sqr(b[j].x)+sqr(b[j].y)-sqr(b[i].x)-sqr(b[i].y))/2.0,
                b[i].x-b[k].x,b[i].y-b[k].y,(sqr(b[k].x)+sqr(b[k].y)-sqr(b[i].x)-sqr(b[i].y))/2.0 
                );
                R=dis(b[i],O);
            }
        }
    // printf("%.10lf\n%.10lf %.10lf\n",R,O.x,O.y);
    t1=R;
	printf("%.10lf\n",t1);
}
