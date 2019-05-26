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

const int N=110,M=25010;

int n,ans,a[N];
bool f[M];

void work()
{
    n=get(),ans=0;
    rep(i,1,n)
        a[i]=get();
    sort(a+1,a+1+n);
    memset(f,0,sizeof(f)),f[0]=1;
    rep(i,1,n)
    {
        if (f[a[i]])
            continue;
        ++ans;
        rep(j,a[i],a[n])
            f[j]|=f[j-a[i]];
    }
    printf("%d\n",ans);
}

int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    for (int tc=get(); tc--; work());
    return 0;
}
