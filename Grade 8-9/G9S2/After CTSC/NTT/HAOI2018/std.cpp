#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define Rep(i,a,b) for(register int i=(a),i##end=(b);i<=i##end;++i)
#define Repe(i,a,b) for(register int i=(a),i##end=(b);i>=i##end;--i)
#define For(i,a,b) for(i=(a),i<=(b);++i)
#define Forward(i,a,b) for(i=(a),i>=(b);--i)
template<typename T>inline void read(T &x)
{
    T f=1;x=0;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+(c^48);
    x*=f;
}
using namespace std;
void file()
{
#ifndef ONLINE_JUDGE
    freopen("color19.in","r",stdin);
    freopen("color.out","w",stdout);
#endif
}

const int MAXN=1e7+7,MAXM=1e6+7,mod=1004535809,g=3;

static int n,m,s,N,w[MAXM];

inline void init()
{
    read(n);read(m);read(s);
    N=min(m,n/s);
    Rep(i,0,m)read(w[i]);
}

static int func[MAXN],inv[MAXN];

#define ll long long

inline int power(int a,int b)
{
    static int sum;
    for(sum=1;b;b>>=1,a=(ll)a*a%mod)if(b&1)
        sum=(ll)sum*a%mod;
    return sum;
}

static int len,rev[MAXM<<2],a[MAXM<<2],b[MAXM<<2],invN,invS;
inline void NTT(int *X,int typ)
{
    Rep(i,1,len-1)if(i<rev[i])swap(X[i],X[rev[i]]);
    static int i,j,k,kk,w,wn,t;
    for(k=2,kk=1;k<=len;k<<=1,kk<<=1)
    {
        wn=power(g,(mod-1)/k);
        for(i=0;i<len;i+=k)
            for(w=1,j=0;j<kk;++j,w=(ll)w*wn%mod)
            {
                t=(ll)w*X[i+j+kk]%mod;
                X[i+j+kk]=(X[i+j]-t+mod)%mod;
                X[i+j]=(X[i+j]+t)%mod;
            }
    }
    if(typ<0)
    {
        reverse(X+1,X+len);
        static int invN=power(len,mod-2);
        Rep(i,0,len-1)X[i]=(ll)X[i]*invN%mod;
    }
}

inline void solve()
{
    func[0]=1;
    Rep(i,1,max(max(n,s),m))func[i]=(ll)func[i-1]*i%mod;
    inv[max(max(n,s),m)]=power(func[max(n,max(s,m))],mod-2);
    Repe(i,max(max(n,m),s),1)inv[i-1]=(ll)inv[i]*i%mod;
    invS=inv[s];
    for(len=2;len<=2*N;len<<=1);
    Rep(i,1,len-1)rev[i]=(rev[i>>1]>>1)|((i&1)*(len>>1));
    Rep(i,0,N)
    {
        a[i]=(ll)inv[i]*w[i]%mod;
        b[i]=(i&1?(ll)mod-1:1)*inv[i]%mod;
        cout<<i<<' '<<a[i]<<' '<<b[i]<<'\n';
    }
    NTT(a,1);NTT(b,1);
    Rep(i,0,len)a[i]=(ll)a[i]*b[i]%mod;
    NTT(a,-1);
    static int ans=0;
    Rep(i,0,N)
        ans=(ans+(ll)inv[m-i]*inv[n-i*s]%mod*power(invS,i)%mod*power(m-i,n-i*s)%mod*a[i]%mod)%mod;
    printf("%lld\n",(ll)ans*func[n]%mod*func[m]%mod);
}

int main()
{
    file();
    init();
    solve();
    return 0;
}
