#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;

int gti(void)
{
    char c=getchar();
    int ret=0,st=1;
    for (;!isdigit(c);c=getchar()) if (c=='-') st=-1;
    for (;isdigit(c);c=getchar()) ret=ret*10+c-'0';
    return ret*st;
}

int main(void)
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n=gti(),now=0,lst=0,ans=0;
    for (int i=1;i<=n;i++)
    {
        now=gti();
        if (now>lst)
            ans+=now-lst;
        lst=now;
    }
    printf("%d\n",ans);
    return 0;
}
