#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200,M=3e4;

int gti(void)
{
    char c=getchar();
    int ret=0,st=1;
    for (;!isdigit(c);c=getchar()) if (c=='-') st=-1;
    for (;isdigit(c);c=getchar()) ret=ret*10+c-'0';
    return ret*st;
}

bool vis[M];
int a[N];
int main(void)
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    for (int t=gti();t>=1;t--)
    {
        memset(vis,0,sizeof(vis));
        int n=gti(),ans=0,mx=0;
        for (int i=1;i<=n;i++)
            a[i]=gti(),mx=max(mx,a[i]);
        sort(a+1,a+1+n);
        vis[0]=true;
        for (int i=1;i<=n;i++)
            if (!vis[a[i]])
            {
                ++ans;
                for (int j=0;j+a[i]<=mx;j++)
                    vis[j+a[i]]|=vis[j];
            }
        printf("%d\n",ans);
    }
    return 0;
}
