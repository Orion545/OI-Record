#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define pii pair<int,int>
  
int sum[20000010],num[20000010],ls[20000010],rs[20000010],size[20000010],rt[20000010],n,m,tt,tot;
bool rev[20000010];
  
inline int rd()
{
    int x=0;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar());
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x;
}
  
inline int copy(int x)
{
    int hh=++tot;
    sum[hh]=sum[x];num[hh]=num[x];ls[hh]=ls[x];rs[hh]=rs[x];size[hh]=size[x];rev[hh]=rev[x];
    return hh;
}
  
inline void reverse(int x) { rev[x]^=1;swap(ls[x],rs[x]); }
  
inline void pushup(int x)
{
    sum[x]=sum[ls[x]]+sum[rs[x]]+num[x];
    size[x]=size[ls[x]]+size[rs[x]]+1;
}
  
inline void pushdown(int x)
{
    if (!rev[x]) return;
    if (ls[x]) ls[x]=copy(ls[x]),reverse(ls[x]);
    if (rs[x]) rs[x]=copy(rs[x]),reverse(rs[x]);
    rev[x]=false;
}
  
inline int build(int l,int r)
{
    int mid=(l+r)>>1;
    if (l<mid) ls[mid]=build(l,mid-1);
    if (r>mid) rs[mid]=build(mid+1,r);
    pushup(mid);
    return mid;
}
  
inline pii split(int x,int k)
{
    if (!x) return pii(0,0);
    int now=copy(x);
    pushdown(now);
    if (size[ls[now]]>=k)
    {
        pii hh=split(ls[now],k);
        ls[now]=hh.second;hh.second=now;
        pushup(now);
        return hh;
    }
    pii hh=split(rs[now],k-size[ls[now]]-1);
    rs[now]=hh.first;hh.first=now;
    pushup(now);
    return hh;
}
  
inline int merge(int x,int y)
{
    if (!x||!y) return x+y;
    if (rand()%(size[x]+size[y])<size[x])
    {
        pushdown(x);
        rs[x]=merge(rs[x],y);
        pushup(x);
        return x;
    }
    pushdown(y);
    ls[y]=merge(x,ls[y]);
    pushup(y);
    return y;
}
  
int main()
{
    srand(19260817);
    n=rd();m=rd();tt=0;tot=n;
    for (int i=1;i<=n;i++) num[i]=rd();
    rt[0]=build(1,n);
    int now=0;
    while (m--)
    {
        int p=rd();
        if (p==1)
        {
            int l=rd()-1,r=rd();
            pii h1=split(rt[now],l),h2=split(h1.second,r-l);
            reverse(h2.first);
            rt[now=++tt]=merge(h1.first,merge(h2.first,h2.second));
        }
        else if (p==2)
        {
            int l=rd()-1,r=rd();
            int hhh=tot;
            pii h1=split(rt[now],l),h2=split(h1.second,r-l);
            printf("%d\n",sum[h2.first]);
            tot=hhh;
        }
        else now=rd();
    }
    return 0;
}
