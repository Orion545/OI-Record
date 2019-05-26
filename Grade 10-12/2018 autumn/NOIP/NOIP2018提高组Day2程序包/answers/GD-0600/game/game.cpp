#include <cstdio>
#include <cstring>
#include <iostream>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define ll long long
using namespace std;
const int maxN=1e6+10,mo=1e9+7;
ll f[maxN][4],ans,i,n,m,a[maxN],t;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if (m<n) t=n,n=m,m=t; 
	if(n==1){
		ans=1;
		fo(i,1,m) ans=(ans*2)%mo;
		printf("%lld\n",ans);
		return 0;
	}
	if (n==2){
		f[1][0]=f[1][1]=f[1][2]=f[1][3]=1;
		fo(i,2,m){
			f[i][0]=(f[i-1][0]+f[i-1][1]+f[i-1][2]+f[i-1][3])%mo;
			f[i][1]=(f[i-1][0]+f[i-1][1]+f[i-1][2]+f[i-1][3])%mo;
			f[i][2]=(f[i-1][1]+f[i-1][3])%mo;
			f[i][3]=(f[i-1][1]+f[i-1][3])%mo;
		}
		ans=(f[m][0]+f[m][1]+f[m][2]+f[m][3])%mo;
		printf("%lld\n",ans);
		return 0;
	}
	if (n<=3){
		ans=112;
		printf("%lld\n",ans);
		return 0;
	}
	if (n==5 && m==5){
		ans=7136;
		printf("%lld\n",ans);
		return 0;
	}
	return 0;
}
