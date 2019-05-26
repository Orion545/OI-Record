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
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    St int t;
    scanf("%d", &t);
    for(;t--;)
    {
        St int n;
        scanf("%d", &n);
        St int a[233];
        inc(0, i, n) scanf("%d", a+i);
        sort(a, a+n);
        St bool k[26000];
        memset(k, 0, sizeof k);
        k[0]=1;
        Rg int ans=0;
        inc(0, i, n)
        {
            if(k[a[i]]) Ct;
            ++ans;
            inc(0, j, 25010-a[i])
                k[j+a[i]]|=k[j];
        }
        printf("%d\n", ans);
    }
    
    Re 0;
}
