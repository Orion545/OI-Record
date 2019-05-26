#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf (1ll<<60ll)
using namespace std;
inline ll read(){
    ll re=0,flag=1;char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') flag=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
    return re*flag;
}
ll n,m,a[1010],sum[1010],sqr[1010],s[1010][1010],dp[1010][1010];
ll w(ll l,ll r){
    return ((sum[r]-sum[l-1])*(sum[r]-sum[l-1])-(sqr[r]-sqr[l-1]))/2ll;
}
int main(){
    freopen("hdu2829.in","r",stdin);
    ll i,j,k,tmp;
    while((n=read())&&(m=read())){
        m++;
        for(i=1;i<=n;i++)
            a[i]=read(),sum[i]=sum[i-1]+a[i],sqr[i]=sqr[i-1]+a[i]*a[i];
        //for(i=1;i<=n;i++) cout<<sum[i]<<" ";cout<<'\n';
        //for(i=1;i<=n;i++) cout<<sqr[i]<<" ";cout<<'\n';
        for(i=1;i<=n;i++) dp[1][i]=w(1,i),s[1][i]=1;
        for(i=2;i<=m;i++){
            s[i][n+1]=n;
            for(j=n;j>i;j--){
                dp[i][j]=inf;
                for(k=s[i-1][j];k<=s[i][j+1];k++){
                    if((tmp=dp[i-1][k-1]+w(k,j))<dp[i][j]){
                        dp[i][j]=tmp;s[i][j]=k;
                    }
                }
                cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
            }
        }
        printf("%lld\n",dp[m][n]);
    }
}
