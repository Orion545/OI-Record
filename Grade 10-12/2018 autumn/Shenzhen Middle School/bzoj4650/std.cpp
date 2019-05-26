#include<cstdio>  
#include<iostream>  
#include<algorithm>  
#include<cstdlib>  
#include<cstring>
#include<string>
#include<climits>
#include<vector>
#include<cmath>
#include<map>
#define LL long long
#define rank DDD 
using namespace std;
 
inline char nc(){
  static char buf[100000],*p1=buf,*p2=buf;
  if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
  return *p1++;
}
 
inline void read(int &x){
  char c=nc();int b=1;
  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;
  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
}
 
inline void read(LL &x){
  char c=nc();LL b=1;
  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;
  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
}

inline int read(char *s)
{
    char c=nc();int len=0;
    for(;!(c>='a' && c<='z');c=nc()) if (c==EOF) return 0;
    for(;(c>='a' && c<='z');s[len++]=c,c=nc());
    s[len++]='\0';
    return len;
}

inline void read(char &x){
  for (x=nc();!(x>='A' && x<='Z');x=nc());
}

int wt,ss[19];
inline void print(int x){
    if (x<0) x=-x,putchar('-'); 
    if (!x) putchar(48); else {
    for (wt=0;x;ss[++wt]=x%10,x/=10);
    for (;wt;putchar(ss[wt]+48),wt--);}
}
inline void print(LL x){
    if (x<0) x=-x,putchar('-');
    if (!x) putchar(48); else {for (wt=0;x;ss[++wt]=x%10,x/=10);for (;wt;putchar(ss[wt]+48),wt--);}
}

int n,m,s,b[80010],c[80010],d[80010],f[80010],g[80010];
char sx[80010];
struct data
{
    int len,fa,letter[26],tree[26],id,flag;
}a[80010];
int sa[80010],rank[80010],r1[80010],r2[80010],RANK,f1[80010][20],f2[80010][20];

void Extend(int x,int p)
{
    s++;int q=s;a[q].len=a[p].len+1;
    while (p!=0 && a[p].letter[x]==0)
        a[p].letter[x]=q,p=a[p].fa;
    if (p==0) {a[q].fa=1;return ;}
    int np=a[p].letter[x];
    if (a[np].len==a[p].len+1) a[q].fa=np;
    else
    {
        s++;int nq=s;a[nq].len=a[p].len+1;
        for (int i=0;i<26;i++)
            a[nq].letter[i]=a[np].letter[i];
        a[nq].id=a[np].id;
        a[nq].fa=a[np].fa;a[np].fa=nq;a[q].fa=nq;
        while (p!=0&&a[p].letter[x]==np)
            a[p].letter[x]=nq,p=a[p].fa;
    }
}

void Insert(char x[])
{
    int y=strlen(x);
    s=1;int z=1;
    for (int i=y-1;i>=0;i--)
      Extend(x[i]-'a',z),z=a[z].letter[x[i]-'a'],a[z].id=i+1,d[i+1]=z,a[z].flag=1;
}

void dfs(int x)
{
    if (RANK>=30000)
        print(1);
    if(a[x].id!=0 && a[x].flag) sa[++RANK]=a[x].id,rank[a[x].id]=RANK;
    for (int i=0;i<26;i++)
        if (a[x].tree[i]!=0) dfs(a[x].tree[i]);
}

void build()
{
    for (int i=1;i<=s;i++)
        c[a[i].len]++;
    for (int i=1;i<=s;i++)
        c[i]+=c[i-1];
    for (int i=1;i<=s;i++)
        b[c[a[i].len]--]=i;
    for (int i=s;i>=1;i--)
    {
        int p=b[i];
        a[a[p].fa].tree[sx[a[p].id+a[a[p].fa].len-1]-'a']=p;
    }
    RANK=0;
    dfs(1);
}

LL Query(int x,int y)
{
    if (x==y) return a[x].len;
    if (a[x].len>a[y].len) return Query(a[x].fa,y);
    else return Query(x,a[y].fa);
}

void SWAP(char *s)
{
    int x=strlen(s);
    for (int i=0;i<x/2;i++)
        swap(s[i],s[x-i-1]);
}

void init()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    memset(sa,0,sizeof(sa));
    memset(rank,0,sizeof(rank));
}

int query1(int z,int y)
{
    z=r1[z],y=r1[y];
    if (z>y) swap(z,y);z++;
    int x=(int)(log(y-z+1)/log(2));
    return min(f1[z][x],f1[y-(1<<x)+1][x]);
}

int query2(int z,int y)
{
    z=r2[z],y=r2[y];
    if (z>y) swap(z,y);z++;
    int x=(int)(log(y-z+1)/log(2));
    return min(f2[z][x],f2[y-(1<<x)+1][x]);
}

void sa_init()
{
    n=strlen(sx);
    init();
    Insert(sx);
    build();
    for (int i=2;i<=n;i++)
        f1[i][0]=Query(d[sa[i]],d[sa[i-1]]);
    f1[1][0]=0;
    for (int j=1;1<<j<=n;j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
            f1[i][j]=min(f1[i][j-1],f1[i+(1<<j-1)][j-1]);
    for (int i=1;i<=n;i++)
        r1[i]=rank[i];
    init();
    SWAP(sx);
    Insert(sx);
    build();
    for (int i=2;i<=n;i++)
        f2[i][0]=Query(d[sa[i]],d[sa[i-1]]);
    f2[1][0]=0;
    for (int j=1;1<<j<=n;j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
            f2[i][j]=min(f2[i][j-1],f2[i+(1<<j-1)][j-1]);
    for (int i=1;i<=n;i++)
        r2[n-i+1]=rank[i];
}

int T;

int main()
{
    read(T);
    while (T--)
    {
        read(sx);
        int m=strlen(sx),x,y,s,p;
        sa_init();
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for (int i=1;i<=m;i++)
        {
            x=1,y=x+i;
            while(y<=m)
            { 
                p=min(query1(x,y),i);
                s=min(query2(x,y),i);
                if (p+s>i)
                {
					cout<<"get "<<x<<' '<<y<<' '<<p<<' '<<s<<'\n';
                    f[x-s+1]++;f[x+p-i+1]--;
                    g[y-s+i]++;g[y+p]--;
                }
                x+=i,y+=i;
            }
        }
        int F=0,G=0;
        for (int i=1;i<=m;i++){
            F+=f[i],f[i]=F,G+=g[i],g[i]=G;
            print(i);putchar(' ');
            print(f[i]);putchar(' ');
            print(g[i]);putchar('\n');
           }
        LL ans=0;
        for (int i=1;i<m;i++)
            ans+=(LL)g[i]*f[i+1];
        print(ans),puts("");
    }
    return 0;
}
