#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#define N 200005
#define M 2000005
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fod(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int os,n,m,fa[N][20],fs[N],dt[2*N],nt[2*N],dep[N],rt[N],t[M][26],n1,sz[M],vl[M];
char st[N][11],ch[N];
void ins(int ls,int k,char *st)
{
    int le=strlen(st+1);
    sz[k]=sz[ls]+1;
    fo(i,1,le) 
    {
        int c=st[i]-'a';
        fo(j,0,25) 
        {
            if(j==c) t[k][c]=++n1;
            else t[k][j]=t[ls][j];
        }
        ls=t[ls][c],k=t[k][c];
        sz[k]=sz[ls]+1,vl[k]=vl[ls];
    }
    fo(j,0,25) t[k][j]=t[ls][j];
    vl[k]=vl[ls]+1;
}
void dfs(int k)
{
    dep[k]=dep[fa[k][0]]+1;
    ins(rt[fa[k][0]],rt[k]=++n1,st[k]);
    for(int i=fs[k];i;i=nt[i]) dfs(dt[i]);
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    int j=19;
    while(dep[x]>dep[y])
    {
        while(j&&dep[fa[x][j]]<dep[y]) j--;
        x=fa[x][j];
    }
    j=19;
    while(x!=y)
    {
        while(j&&fa[x][j]==fa[y][j]) j--;
        x=fa[x][j],y=fa[y][j];
    }
    return x;
}
void link(int x,int y)
{
    nt[++m]=fs[x];
    dt[fs[x]=m]=y;
}
int main()
{
    cin>>n>>os;
    scanf("\n");
    fo(i,1,n) scanf("%s",st[i]+1);
    fo(i,2,n) scanf("%d",&fa[i][0]),link(fa[i][0],i);
    int q;
    cin>>q;
    dfs(1); 
    fo(i,1,19)
        fo(k,1,n) fa[k][i]=fa[fa[k][i-1]][i-1];
    int lsa=0;
    fo(i,1,q)
    {
        int x,y;
        scanf("%d%d %s",&x,&y,ch+1);
        if(os==1) x^=lsa,y^=lsa;
        int p=fa[lca(x,y)][0],len=strlen(ch+1),ans=0;
        fo(j,1,len)
        {
            int s=0,k=rt[x],q=rt[p];
            sz[0]=0;
            while(s+j<=len&&sz[t[k][ch[s+j]-'a']]-sz[t[q][ch[s+j]-'a']]>0) 
            {
                k=t[k][ch[s+j]-'a'],q=t[q][ch[s+j]-'a'],s++;
                if(vl[k]-vl[q]) ans=max(ans,s); 
            }
        }
        fo(j,1,len)
        {
            int s=0,k=rt[y],q=rt[p];
            sz[0]=0;
            while(s+j<=len&&sz[t[k][ch[s+j]-'a']]-sz[t[q][ch[s+j]-'a']]>0) 
            {
                k=t[k][ch[s+j]-'a'],q=t[q][ch[s+j]-'a'],s++;
                if(vl[k]-vl[q]) ans=max(ans,s); 
            }
        }
        printf("%d\n",ans);
        lsa=ans;
    }
}

