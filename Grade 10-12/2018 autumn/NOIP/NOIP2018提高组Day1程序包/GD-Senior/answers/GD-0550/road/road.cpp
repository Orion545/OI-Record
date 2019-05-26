#include<bits/stdc++.h>
using namespace std;

#define Re return
#define In inline
#define St static
#define Rg register
#define Op operator
#define Ct continue
#define inc(l, i, r) for(Rg int i=l; i<r; ++i)
#define dec(l, i, r) for(Rg int i=r; i>l; --i)

typedef long long ll;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    St int n;
    scanf("%d", &n);
    St int a[1<<17];
    Rg ll cnt=0, ans=0;
    inc(1, i, n+1)
    {
        scanf("%d", a+i);
        if(a[i]>a[i-1])
            cnt+=a[i]-a[i-1], ans+=a[i]-a[i-1];
        else
            cnt+=a[i]-a[i-1];
    }
    cout<<ans;
    Re 0;
}
