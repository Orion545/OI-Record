#include<bits/stdc++.h>
using namespace std;

#define Re return
#define In inline
#define Op operator
#define St static
#define Rg register
#define Ct continue
#define mP make_pair
#define lB lower_bound
#define inc(l, i, r) for(Rg int i=l; i<r; ++i)
#define dec(l, i, r) for(Rg int i=r; i>l; --i)

typedef long long ll;
typedef double db;
typedef pair<int, int> pInt;

const int p=1e9+7;

In ll dP(ll a, int b)
{
    if(b<0) Re 0;
    Rg ll r=1;
    for(; b; a=a*a%p, b>>=1)
        if(b&1) r=r*a%p;
    Re r;
}

int n, m;

In ll f(int i)
{
//    Rg ll r=0;
    if(i<n) Re dP(4, n-i)*dP(3, m-n)%p*dP(2, n-1)%p;
    else if(i<m) Re dP(3, m-i)*dP(2, n-1)%p;
    else Re dP(2, m+n-1-i)%p;
//    Re i-2<n? 4*r%p: 3*r%p;
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%d", &n, &m);
    if(m<n) swap(n, m);
    if(n==2)
    {
        cout<<dP(3, m-1)*4%p<<"\n";
        Re 0;
    }
    Rg ll ans=dP(4, n-2)*dP(3, m-n+1)%p*dP(2, n)%p;
    if(n>=3 && m>=3)
    {
        ans=(ans+8*f(4))%p;
        inc(3, i, n)
            ans=(ans+20*f(i+2))%p;
        inc(n, i, m)
            ans=(ans+8*f(i+2))%p;
    }
    cout<<(ans+p)%p<<"\n";
    Re 0;
}
