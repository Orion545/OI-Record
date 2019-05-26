#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define eps 1e-8
#define MN 100000
#define INF 2000000000
using namespace std;
inline int read()
{
    int x = 0 , f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}

struct P{
    double a,b,x,y,r,slop;int id;
    bool operator<(const P&b)const{return slop>b.slop;}
}p[MN+5],t[MN+5];
double f[MN+5];
int n,q[MN+5];

double getslop(int x,int y)
{
    if(!y)return -INF;
    if(fabs(p[x].x-p[y].x)<eps)return INF;
    return (p[y].y-p[x].y)/(p[y].x-p[x].x);
}

void solve(int l,int r)
{
    if(l==r)
    {
        f[l]=max(f[l-1],f[l]);
		cout<<"get "<<l<<' '<<f[l]<<'\n';
        p[l].y=f[l]/(p[l].a*p[l].r+p[l].b);
        p[l].x=p[l].y*p[l].r;
        return;
    }
    int mid=l+r>>1,cnt1=l,cnt2=mid+1,top=0,j=1;
    for(int i=l;i<=r;i++)
        t[p[i].id<=mid?cnt1++:cnt2++]=p[i];
    for(int i=l;i<=r;i++)p[i]=t[i];
    solve(l,mid);
    for(int i=l;i<=mid;i++)
    {
        while(top>1&&getslop(q[top-1],q[top])<getslop(q[top],i)+eps) --top;
        q[++top]=i;
    }
    for(int i=mid+1;i<=r;i++)
    {
        while(j<top&&getslop(q[j],q[j+1])+eps>p[i].slop) ++j;
        f[p[i].id]=max(f[p[i].id],p[q[j]].x*p[i].a+p[q[j]].y*p[i].b);
    }
    solve(mid+1,r);cnt1=l,cnt2=mid+1;
    for(int i=l;i<=r;i++)
        if(cnt2>r||(cnt1<=mid&&(p[cnt1].x<p[cnt2].x+eps||(fabs(p[cnt1].x-p[cnt2].x)<eps&&p[cnt1].y<p[cnt2].y+eps))))  t[i]=p[cnt1++];
        else t[i]=p[cnt2++];
    for(int i=l;i<=r;i++)p[i]=t[i];
}

int main()
{
    n=read();scanf("%lf",&f[0]);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf%lf",&p[i].a,&p[i].b,&p[i].r);
        p[i].slop=(-p[i].a/p[i].b);p[i].id=i;
    }
    sort(p+1,p+n+1);
    solve(1,n);
    printf("%.3lf\n",f[n]);
    return 0;
}
