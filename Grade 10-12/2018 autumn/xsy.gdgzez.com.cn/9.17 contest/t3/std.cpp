#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<cstring>
#define LL long long
#define lc(x) x<<1
#define rc(x) x<<1|1
using namespace std;
const int N=3e5+5;
int w,h,n,ans,L,R;
int mx[N*4],tag[N*4];
struct node{int x,y;node(int _x=0,int _y=0):x(_x),y(_y){};}p[N],a[N],b[N]; 
int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
void modify(int x,int l,int r,int v)
{
	cout<<"	change "<<l<<' '<<r<<' '<<L<<' '<<R<<'\n';
    if(L<=l&&r<=R){mx[x]+=v;tag[x]+=v;return;}
    int mid=(l+r)>>1;
    if(L<=mid)modify(lc(x),l,mid,v);
    if(R>mid)modify(rc(x),mid+1,r,v);
    mx[x]=max(mx[lc(x)],mx[rc(x)])+tag[x];
}
bool cmp(node a,node b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
void work()
{
    memset(mx,0,sizeof(mx));
    memset(tag,0,sizeof(tag));
    sort(p+1,p+n+1,cmp);
    int l=0,r=0;
    for(int i=1;i<=n-1;i++)
    {
		cout<<"do "<<i<<' '<<p[i].x<<' '<<p[i].y<<'\n';
        if(p[i].y<=h/2)
        {
            int nxt=i-1;
            while(l&&a[l].y<p[i].y)
            {
                L=a[l].x;R=nxt;nxt=a[l].x-1;
                modify(1,1,n,a[l].y-p[i].y);l--; 
            }
            if(nxt!=i-1)a[++l]=node(nxt+1,p[i].y);
        }
        else
        {
            int nxt=i-1;
            while(r&&b[r].y>p[i].y)
            {
                L=b[r].x;R=nxt;nxt=b[r].x-1;
                modify(1,1,n,p[i].y-b[r].y);r--;
            }
            if(nxt!=i-1)b[++r]=node(nxt+1,p[i].y);
        }
        a[++l]=node(i,0);b[++r]=node(i,h);
        L=i;R=i;modify(1,1,n,h-p[i].x);
        ans=max(ans,mx[1]+p[i+1].x);
    }
}
int main()
{
    w=read();h=read();n=read();
    for(int i=1;i<=n;i++)p[i].x=read(),p[i].y=read();
    p[++n]=node(0,0);p[++n]=node(w,h);work();
    for(int i=1;i<=n;i++)swap(p[i].x,p[i].y);
    swap(w,h);work();
    printf("%d",ans*2);
    return 0;
}
