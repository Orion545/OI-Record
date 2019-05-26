#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fod(i,a,b) for(i=a;i>=b;i--)
using namespace std;
const int maxn=107,mxx=25007;
int i,j,k,l,t,n,m,ans,a[maxn],T,da;
bool bz[mxx],az[mxx];
int main(){
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    scanf("%d",&T);
    while(T--){
	    scanf("%d",&n);
	    memset(bz,0,sizeof(bz));
	    memset(az,1,sizeof(az));da=0;
	    fo(i,1,n)scanf("%d",&a[i]),da=max(da,a[i]);
	    sort(a+1,a+1+n);ans=1;bz[0]=1;
	    fo(i,1,da/a[1])bz[a[1]*i]=1;
	    fo(i,2,n){
			if(bz[a[i]])az[i]=0;else{
				fo(j,a[i],da)if(!bz[j]&&bz[j-a[i]])bz[j]=1;
			    ans++;
			}
	    }
		printf("%d\n",ans);
    }
}
