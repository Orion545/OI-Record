#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define rep(i,x,y) for (int i=x; i<=(y); ++i)

using namespace std;

int get()
{
    char c;
    while (!isdigit(c=getchar()) && c!='-');
    int s=c=='-'? -1:1,k=~s? c-'0':0;
    for (; isdigit(c=getchar()); k=k*10+c-'0');
    return s*k;
}

const int N=1e5+10;

int n,ans,a[N];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=get();
    rep(i,1,n)
    {
        a[i]=get();
        ans+=max(0,a[i]-a[i-1]);
    }
    printf("%d",ans);
    return 0;
}
