#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define rep(i,x,y) for (int i=x; i<=(y); ++i)
#define repd(i,x,y) for (int i=x; i>=(y); --i)

using namespace std;
typedef long long ll;

const int P=1e9+7,N=1e6+10;
int n,m,f[N][3],ans;

int power(int a,int b)
{
    int t=1;
    for (; b; b>>=1,a=1ll*a*a%P)
        b&1? t=1ll*t*a%P:0;
    return t;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d%d",&n,&m);
    if (n==3 && m<n)
        swap(n,m);
    if (n==1)
    {
        printf("%d\n",power(2,m));
        return 0;
    }
    if (n==2)
    {
        printf("%d\n",int(power(3,m-1)*4ll%P));
        return 0;
    }
    if (n==3)
    {
        f[1][0]=1,f[1][1]=8,f[1][2]=3;
        rep(i,2,m-2)
        {
            f[i][0]=f[i-1][0];
            f[i][1]=(f[i-1][2]*4ll+f[i-1][1])%P;
            f[i][2]=f[i-1][0]*3ll%P;
        }
        ans=((f[m-2][0]+f[m-2][2])*3ll+f[m-2][1]*2ll)*4%P;
        printf("%d\n",ans);
        return 0;
    }
/*
    if (m<=8)
    {
        dfs(1,2)
    }
//    f[1][0]=1,f[1][1]=f*/
    return 0;
}
