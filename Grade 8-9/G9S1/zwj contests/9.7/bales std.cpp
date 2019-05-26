#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m;
int f[1000010];
struct QUERY
{
    int qa,qb,qv;
}q[25010],p[25010];
int find(int x)
{
    return (f[x]==x)?x:(f[x]=find(f[x]));
}
bool cmp(QUERY a,QUERY b)
{
    return a.qv>b.qv;
}
bool solve(int sta)
{
    int i,j,l1,l2,r1,r2;
    for(i=1;i<=n+1;i++)    f[i]=i;
    for(i=1;i<=sta;i++)    q[i].qa=p[i].qa,q[i].qb=p[i].qb,q[i].qv=p[i].qv;
    sort(q+1,q+sta+1,cmp);
    l1=l2=q[1].qa,r1=r2=q[1].qb;
    for(i=2;i<=sta;i++)
    {
        if(q[i].qv<q[i-1].qv)
        {
            if(find(l1)>r1)    return false;
            for(j=f[l2];j<=r2;j=f[j])
            {
                find(j);
                f[j]=find(j+1);
            }
            l1=l2=q[i].qa,r1=r2=q[i].qb;
        }
        else
        {
            l1=max(l1,q[i].qa),l2=min(l2,q[i].qa),r1=min(r1,q[i].qb),r2=max(r2,q[i].qb);
            if(r1<l1)    return false;
        }
    }
    if(find(l1)>r1)    return false;
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)    scanf("%d%d%d",&p[i].qa,&p[i].qb,&p[i].qv);
    int l=1,r=m+1,mid;
    while(l<r)
    {
        mid=l+r>>1;
        if(solve(mid))    l=mid+1;
        else    r=mid;
    }
    printf("%d",l>n?0:l);
    return 0;
}
