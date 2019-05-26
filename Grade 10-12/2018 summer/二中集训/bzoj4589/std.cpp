#include<bits/stdc++.h>
#define M 131072
#define L long long
#define MOD 1000000007
using namespace std;
int b[M]={0},pri[M]={0},use=0;
void init(){
    for(int i=2;i<M;i++){
        if(!b[i]) pri[++use]=i;
        for(int j=1;j<=use&&i*pri[j]<M;j++){
            b[i*pri[j]]=1;
            if(i%pri[j]==0) break;
        }
    }
}
L pow_mod(L x,int k){
    L ans=1;
    while(k){
        if(k&1) ans=ans*x%MOD;
        x=x*x%MOD; k>>=1;
    }
    return ans;
}
void FWT(L a[],int n,int on){
    for(int i=1;i<n;i<<=1)
    for(int j=0;j<n;j++)
    if(i&j){
        L w=a[i^j];
        a[i^j]=(w+a[j])%MOD;
        a[j]=(w-a[j]+MOD)%MOD;
    }
    if(on==-1){
        L inv=pow_mod(n,MOD-2);
        for(int i=0;i<n;i++) a[i]=a[i]*inv%MOD;
    }
}
 
L g[M]={0},ans[M]={0};
int main(){
	freopen("in.in","r",stdin);
	freopen("std.out","w",stdout);
    init();
    int t,n;int c1,c2,c3,c4;
    while(cin>>t>>n){
    	c1=clock();
        int len=1; while(len<=n) len<<=1;
        for(int i=2;i<=n;i++) if(b[i]==0) g[i]=1;
        FWT(g,len,1); memcpy(ans,g,M<<3); t--;
        c2=clock();
        while(t){
            if(t&1) for(int i=0;i<len;i++) ans[i]=ans[i]*g[i]%MOD;
            t>>=1; for(int i=0;i<len;i++) g[i]=g[i]*g[i]%MOD;
        }
        c3=clock();
        FWT(ans,len,-1);
        printf("%lld\n",ans[0]);
        memset(g,0,len<<3); memset(ans,0,len<<3);
        c4=clock();
        cout<<len<<' '<<c2-c1<<' '<<c3-c2<<' '<<c4-c3<<'\n';
    }
}
    
