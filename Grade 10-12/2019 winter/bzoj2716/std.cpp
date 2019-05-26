#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define eps 1e-8
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
using namespace std;
typedef long long ll;
inline int rd()
{
    int x=0,f=1;
    char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
    return x*f;
}
const int N=500010,Inf=1000000000;
struct tree{
    int x,y,mn[2],mx[2],ch[2];
}tr[1000010];
int n,m,cnt,ans,rt;
bool flag;
inline bool operator <(tree a,tree b){return !flag?a.x<b.x:a.y<b.y;}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
inline int fabs(int a){return a<0?-a:a;}
 
namespace KD{
inline void pushup(int o)
{
    int l=tr[o].ch[0],r=tr[o].ch[1];
    tr[o].mn[0]=tr[o].mx[0]=tr[o].x;
    tr[o].mn[1]=tr[o].mx[1]=tr[o].y;
    if(l){
        tr[o].mn[0]=min(tr[o].mn[0],tr[l].mn[0]);
        tr[o].mn[1]=min(tr[o].mn[1],tr[l].mn[1]);
        tr[o].mx[0]=max(tr[o].mx[0],tr[l].mx[0]);
        tr[o].mx[1]=max(tr[o].mx[1],tr[l].mx[1]);
    }
    if(r){
        tr[o].mn[0]=min(tr[o].mn[0],tr[r].mn[0]);
        tr[o].mn[1]=min(tr[o].mn[1],tr[r].mn[1]);
        tr[o].mx[0]=max(tr[o].mx[0],tr[r].mx[0]);
        tr[o].mx[1]=max(tr[o].mx[1],tr[r].mx[1]);
    }
}
inline int build(int l,int r,int ty)
{
    if(l>r)return 0;
    flag=ty;int mid=(l+r)>>1;
    nth_element(tr+l,tr+mid,tr+r+1);
    tr[mid].ch[0]=build(l,mid-1,ty^1);
    tr[mid].ch[1]=build(mid+1,r,ty^1);
    pushup(mid);
    return mid;
}
int sta[1000010],tp;
inline void insert(int p)
{
    flag=0;int o=rt;tp=0;
    while(1){
        sta[++tp]=o;
        if(tr[o]<tr[p]){
            if(tr[o].ch[0])o=tr[o].ch[0];
            else{tr[o].ch[0]=p;break;}
        }
        else{
            if(tr[o].ch[1])o=tr[o].ch[1];
            else{tr[o].ch[1]=p;break;}
        }
        flag^=1;
    }
    while(tp)pushup(sta[tp--]);
}
inline int calc(int o,int x,int y)
{
    if(!o)return Inf;
    int res=0;
    if(x>tr[o].mx[0])res+=x-tr[o].mx[0];
    if(x<tr[o].mn[0])res+=tr[o].mn[0]-x;
    if(y>tr[o].mx[1])res+=y-tr[o].mx[1];
    if(y<tr[o].mn[1])res+=tr[o].mn[1]-y;
    return res;
}
inline void query(int o,int x,int y)
{
    ans=min(ans,fabs(tr[o].x-x)+fabs(tr[o].y-y));
    int dl=calc(tr[o].ch[0],x,y),dr=calc(tr[o].ch[1],x,y);
    if(dl<dr){
        if(dl<ans)query(tr[o].ch[0],x,y);
        if(dr<ans)query(tr[o].ch[1],x,y);
    }
    else{
        if(dr<ans)query(tr[o].ch[1],x,y);
        if(dl<ans)query(tr[o].ch[0],x,y);
    }
}
 
}
 
int main()
{
    n=rd();m=rd();int t1,t2;
    fo(i,1,n){
    	scanf("%d%d",&t1,&t2);
        tr[i].mn[0]=tr[i].mx[0]=tr[i].x=t1;
        tr[i].mn[1]=tr[i].mx[1]=tr[i].y=t2;
    }
    rt=KD::build(1,n,0);
    cnt=n;
    while(m--){
    	int ty,x,y;
        scanf("%d%d%d",&ty,&x,&y);
        if(ty==1){
            cnt++;
            tr[cnt].x=tr[cnt].mn[0]=tr[cnt].mx[0]=x;
            tr[cnt].y=tr[cnt].mn[1]=tr[cnt].mx[1]=y;
            KD::insert(cnt);
        }
        else{
            ans=Inf;KD::query(rt,x,y);
            printf("%d\n",ans);
        }
    }
    return 0;
}
