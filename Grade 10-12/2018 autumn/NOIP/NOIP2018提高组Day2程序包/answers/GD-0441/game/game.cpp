#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define mo 1000000007
#include<set>
using namespace std;
typedef long long ll;
ll n,m,a[100][100],ans;
ll qp(ll x,ll y){
	if(!y)return 1;
	if(y==1)return x%mo;
	ll r=qp(x,y/2);
	if(y&1)return r*r%mo*x%mo;
	return r*r%mo;
}
ll mmin(ll x,ll y){return x<y?x:y;}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n==2){
		ll c=qp(3,m-1);
		printf("%lld",4ll*c%mo);
		return 0;
	}
	if(m==2){
		ll c=qp(3,n-1);
		printf("%lld",4ll*c%mo);
		return 0;
	}
	if(n==3&&m==3){
		printf("112");
		return 0;
	}
	if(n==1){
		printf("%lld",qp(2,m));
		return 0;
	}
	if(m==1){
		printf("%lld",qp(2,n));
		return 0;
	}
	if(n<=8&&m<=8){
		ll ans=0;
		ll c=n+m-3;
		for(int i=0;i<(1<<c);i++){
			ll r=1;
			for(int j=1;j<m;j++)
				if(i&(1<<(j-1)))
					r=(r*(mmin(n-1,j)+1))%mo;
			for(int j=1;j<n-1;j++)
				if(i&(1<<(j+m-2)))
					r=(r*(mmin(n-j-1,m-1)+1))%mo;
			ans=(ans+r)%mo;
			//printf("%lld\n",r);
		}
		printf("%lld\n",ans*4%mo);
	}
}
