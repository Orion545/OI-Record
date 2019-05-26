#include<cstdio>
#define int long long
const int N=100005;
int n,k,cnt,head,tail,a[N],sum[N],q[N],f[N],g[N];
int getx(int k,int j){
    return g[k]-g[j]+sum[j]*sum[j]-sum[k]*sum[k];
}
int gety(int k,int j){
    return sum[j]-sum[k];
}
void dp(int k){
    q[head=tail=1]=k;
    for(int i=k+1;i<=n;i++){
        while(head<tail&&getx(q[head],q[head+1])<sum[i]*gety(q[head],q[head+1])){
            head++;
        }
        f[i]=g[q[head]]+sum[q[head]]*(sum[i]-sum[q[head]]);
        while(head<tail&&getx(q[tail],i)*gety(q[tail-1],q[tail])<getx(q[tail-1],q[tail])*gety(q[tail],i)){
            tail--;
        }
        q[++tail]=i;
    }
    for(int i=k+1;i<=n;i++){
        g[i]=f[i];
    }
}
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]){
            a[++cnt]=a[i];
        }
    }
    n=cnt;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=k;i++){
        dp(i);
    }
    printf("%lld\n",f[n]);
    return 0;
}
