#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>

#define hash DDF
#define MAXN 200
#define MOD 65521

using namespace std;

typedef long long int LL;

int tot=0; //状态总数
int sizeoftree[]={1,1,1,3,16,125}; //sizeoftree[i]=点的个数为i的完全图的生成树个数
int K;
LL n; //!!!!!

struct Matrix
{
    LL num[MAXN][MAXN]; //!!!!!!
    int n,m;
    Matrix()
    {
        n=m=0;
        memset(num,0,sizeof(num));
    }
}one,mp,A;

Matrix operator*(Matrix a,Matrix b)
{
    Matrix c;
    c.n=a.n,c.m=b.m;
    for(int k=1;k<=a.m;k++)
        for(int i=1;i<=c.n;i++)
            for(int j=1;j<=c.m;j++)
                c.num[i][j]=(c.num[i][j]+a.num[i][k]*b.num[k][j]%MOD)%MOD;
    return c;
}

Matrix fastPow(Matrix base,LL pow)
{
    Matrix ans=one;
    while(pow)
    {
        if(pow&1) ans=ans*base;
        base=base*base;
        pow>>=1;
    }
    return ans;
}

int num[MAXN],status[600],hash[1<<16]; //hash[S]=状态S的编号

void DFS(int pos,int sta) //当前要加入第pos个点的联通状态，当前的状态为sta
{
    if(pos==K+1)
    {
        memset(num,0,sizeof(num)); //num[i]=最小表示法里第i个联通块的大小
        A.num[1][++tot]=1;
        for(int i=1;i<=K;i++)
            num[sta>>((i-1)*3)&7]++;
        for(int i=0;i<K;i++)
            A.num[1][tot]*=sizeoftree[num[i]];
        status[tot]=sta;
        hash[sta]=tot;
        return;
    }
    int tmp=-1; //联通块的最大编号,联通块编号的区间是[0,K-1]
    for(int i=1;i<pos;i++) //!!!当前的sta里只保存了1~pos-1这些点的连通性
        tmp=max(tmp,sta>>((i-1)*3)&7);
    for(int i=0;i<=tmp+1&&i<K;i++)
        DFS(pos+1,sta<<3|i);
}

int f[MAXN];

int findSet(int x)
{
    if(f[x]==x) return x;
    return f[x]=findSet(f[x]);
}

int getstatus() //用当前的并查集来求出新的点2到点k+1的最小表示
{
    int sta=0,tot=0;
    bool vis[MAXN];
    memset(vis,false,sizeof(vis));
    for(int i=K+1;i>=2;i--)
    {
        if(!vis[i])
        {
            vis[i]=true;
            sta|=tot<<((i-2)*3);
            for(int j=i-1;j>=2;j--)
            {
                if(findSet(i)==findSet(j)) //i和j在同一联通块
                {
                    vis[j]=true;
                    sta|=tot<<((j-2)*3); //!!!!!
                }
            }
            tot++;
        }
    }
    return hash[sta];
}

void calc(int sta,int addsta) //用加边状态addsta去更新最小表示法sta,addsta里的第i位为1表示第k+1个点要和点i+1连新边
{
    for(int i=0;i<=K+1;i++) f[i]=i;
    for(int i=1;i<=K;i++) //枚举点对(i,j)是否在最小表示法里的同一联通块内，将最小表示法中的连通性用并查集表示
    {
        for(int j=i+1;j<=K;j++)
            if((status[sta]>>((i-1)*3)&7)==(status[sta]>>((j-1)*3)&7))
            {
                int rooti=findSet(i);
                int rootj=findSet(j);
                if(rooti!=rootj)
                    f[rooti]=rootj;
            }
    }
    for(int i=1;i<=K;i++)
        if(addsta&(1<<(i-1)))
        {
            int rooti=findSet(i);
            int rootj=findSet(K+1);
            if(rooti==rootj) return; //加的新边的两端点原来就是联通的，加入新边后会出现环
            f[rooti]=rootj;
        }
    bool flag=false; //flag=true表示有点和点1联通
    for(int i=2;i<=K+1;i++)
        if(findSet(i)==findSet(1))
        {
            flag=true;
            break;
        }
    if(!flag) return; //点1不链接后面的点，那么这个生成树不联通
	cout<<"trans "<<sta<<' '<<addsta<<' '<<getstatus()<<'\n'; 
    mp.num[sta][getstatus()]++;
}

int main()
{
    scanf("%d%lld",&K,&n);
    DFS(1,0);
    A.n=1;
    A.m=mp.n=mp.m=one.n=one.m=tot;
    for(int i=1;i<=tot;i++) one.num[i][i]=1;
    for(int i=1;i<=tot;i++)
        for(int addsta=0;addsta<(1<<K);addsta++)
            calc(i,addsta);
	int i,j;
	for(i=1;i<=tot;i++) cout<<A.num[1][i]<<' ';
	cout<<'\n';
	for(i=1;i<=tot;i++){
		for(j=1;j<=tot;j++) cout<<mp.num[1][i]<<' ';
		cout<<'\n';
	}

    A=A*fastPow(mp,n-K);
    printf("%lld\n",A.num[1][1]);
    return 0;
}
