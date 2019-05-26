#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=140,M=1e9+7;
int n,m;

namespace force2
{
    struct Matrix
    {
        int a[N][N],n;
        void init(int len,int val)
        {
            memset(a,0,sizeof(a)),n=len;
            if (val==1)
                for (int i=0;i<len;i++)
                    a[i][i]=1;
        }
        Matrix operator*(const Matrix &b)const
        {
            static Matrix c;
            c.init(n,0);
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    for (int k=0;k<n;k++)
                        (c.a[i][j]+=a[i][k]*1ll*b.a[k][j]%M)%=M;
            return c;
        }
        void operator=(const Matrix &b)
        {
            this->init(b.n,0);
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    a[i][j]=b.a[i][j];
        }
        Matrix operator^(int b)const
        {
            static Matrix c,d;
            c.init(n,1),d=*this;
            for (;b;b>>=1,d=d*d)
                if (b&1)
                    c=c*d;
            return c;
        }
    }f,g;
    int main(void)
    {
        int s=1<<(n-1);
        g.init(s,0),f.init(s,0);
        for (int j=0;j<s;j++)
            for (int k=0;k<s;k++)
            {
                bool tag=true;
                for (int l=s;l;l>>=1)
                    if ((j&l)>(k&l)) tag=false;
                if (tag)
                    ++f.a[j][(k<<1)&(s-1)],++f.a[j][(k<<1|1)&(s-1)];
            }
        for (int j=0;j<s;j++)
            g.a[0][j]=2;
        g=g*(f^(m-1));
        int ans=0;
        for (int j=0;j<s;j++)
            (ans+=g.a[0][j])%=M;
        printf("%d\n",ans);
        return 0;
    }
}
namespace force1
{
    int ans=0,a[1000],mx=0;
    bool solve(int x,int y,int c=0)
    {
        if (x>n||y>m) return true;
        c=c<<1|(a[x]>>(m-y)&1);
        if (x==n&&y==m)
        {
            if (c>=mx)
            {
                mx=c;
                return true;
            }
            else return false;
        }
        bool ret=true;
        ret&=solve(x,y+1,c);
        ret&=solve(x+1,y,c);
        return ret;
    }
    bool check(void)
    {
        mx=0;
        return solve(1,1);
    }
    void dfs(int d)
    {
        if (d>m)
        {
            if (check()) ++ans;
            return;
        }
        for (int i=0;i<1<<n;i++)
            a[d]=i,dfs(d+1);
    }

    int main(void)
    {
        dfs(1);
        printf("%d\n",ans);
        return 0;
    }
}
int main(void)
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d%d",&n,&m);
    if (m<=3)
        force1::main();
    else force2::main();
    return 0;
}
