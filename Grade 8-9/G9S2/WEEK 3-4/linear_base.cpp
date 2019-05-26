#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
ll n,a[100],b[100],i,j;
int main(){
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        for(j=50ll;j>=0ll;j--){
            if(a[i]&(1ll<<j)){
                if(!b[j]){
                    b[j]=a[i];break;
                }
                else a[i]=a[i]^b[j];
            }
            if(!a[i]) break;
        }
    }
    ll ans=0;
    for(i=50ll;i>=0ll;i--){
        if((ans^b[i])>ans) ans^=b[i];
    }
    printf("%lld",ans);
}
