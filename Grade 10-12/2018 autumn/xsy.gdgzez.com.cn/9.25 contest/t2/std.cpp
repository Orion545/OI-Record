#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 100010
#define gc getchar()
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define lint long long
#define mod 1000000007
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
using namespace std;
inline int inn()
{
    int x,ch;while((ch=gc)<'0'||ch>'9');
    x=ch^'0';while((ch=gc)>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^'0');return x;
}
int fac[N],facinv[N],f[N],onc[N],sz[N],p[N],cnt[N];
int cyc_cnt,vis[N],l[N],pre[N],jhs[N],in[N],mi[N],it[N];
inline int fast_pow(int x,int k,int ans=1)
{   for(;k;k>>=1,x=(lint)x*x%mod) (k&1)?ans=(lint)ans*x%mod:0;return ans; }
inline int prelude(int n)
{
    rep(i,fac[0]=1,n) fac[i]=(lint)fac[i-1]*i%mod;
    facinv[n]=fast_pow(fac[n],mod-2);
    for(int i=n-1;i>=0;i--) facinv[i]=facinv[i+1]*(i+1ll)%mod;
    rep(i,mi[0]=1,n) mi[i]=mi[i-1]*2,(mi[i]>=mod?mi[i]-=mod:0);
    rep(i,f[0]=1,n/2) f[i]=f[i-1]*(2*i-1ll)%mod;return 0;
}
inline int C(int n,int m)
{
    if(n<0||m<0||n<m) return 0;
    return (lint)fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
int main()
{
    int n=inn();rep(i,1,n) in[p[i]=inn()]++;
    //unsigned int QwQ=1,t=1;rep(i,1,n) QwQ+=p[i]*t,t*=998244353;cout<<QwQ<<endl;
    for(int i=1,x;i<=n;i++)
    {
        for(x=i;!vis[x];x=p[x]) vis[x]=i;
        if(vis[x]^i) continue;
		cout<<"getnew "<<i<<' '<<x<<'\n';
        for(cyc_cnt++;!onc[x];x=p[x])
            onc[x]=cyc_cnt,sz[cyc_cnt]++;
    }
//  debug(cyc_cnt)ln;
//  rep(i,1,cyc_cnt) debug(i)sp,debug(sz[i])ln;
//  rep(i,1,n) debug(i)sp,debug(onc[i])sp,debug(in[i])ln;cerr ln;
    memset(vis,0,sizeof(int)*(n+1));
    for(int i=1,x,c;i<=n;i++) if(!in[i])
    {
        for(x=i,c=0;!onc[x];vis[x]=1,x=p[x],c++)
            if(vis[x]) return !printf("0\n");
        if(vis[x]) return !printf("0\n");vis[x]=1,l[x]=c;
		cout<<"cnt "<<i<<' '<<c<<'\n';
    }
    rep(i,1,n) if(onc[i]&&l[i]) jhs[onc[i]]=1;
    rep(i,1,cyc_cnt) if(!jhs[i]) cnt[sz[i]]++;
//  rep(i,1,cyc_cnt) debug(i)sp,debug(jhs[i])sp,debug(sz[i])ln;
//  rep(i,1,n) debug(i)sp,debug(l[i])sp,debug(cnt[i])ln;cerr ln;
    prelude(n);int ans=1;
    for(int i=1,k,t,s,v;i<=n;i++) if(cnt[i])
    {
        rep(j,it[0]=1,cnt[i]/2) it[j]=(lint)it[j-1]*i%mod;
        for(k=cnt[i],t=0,s=0;t<=cnt[i]/2;t++)
            v=(lint)C(k,2*t)*f[t]%mod*it[t]%mod,
            (((i&1)&&i>1)?v=(lint)v*mi[k-2*t]%mod:0),
            s+=v,(s>=mod?s-=mod:0);
        ans=(lint)ans*s%mod;
    }
    for(int i=1,x,c;i<=n;i++) if(onc[i]&&l[i])
    {   for(x=i,c=1;!l[p[x]];x=p[x],c++);pre[p[x]]=c;   }
//  rep(i,1,n) debug(i)sp,debug(pre[i])ln;
    rep(i,1,n) if(onc[i]&&l[i])
    {
        if(l[i]>pre[i]) return !printf("0\n");
        else if(l[i]<pre[i]) ans=ans*2,(ans>=mod?ans-=mod:0);
    }
    return !printf("%d\n",ans);
}
