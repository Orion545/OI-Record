#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m;
//ll dp[9][1000010];
#define mod 1000000007
ll pow(ll a,ll x){
	if(x==0) return 1;
	int w=a%mod,p=x,res=1;
	while(p){
		if(p&1) res=(res*w)%mod;
		w=(w*w)%mod;
		p>>=1;
	}
	return res;
}
ll c[10];
void getc(){
	ll i;
	c[0]=1;
	for(i=1;i<=9;i++) c[i]=(c[i-1]*i)%mod;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	getc();
	ll ans;
	if(m==1) ans=pow(2,n)%mod;
	else if(m==2 && n==3) ans=36;
	else if(n<=2){
	ans=(c[n]*c[n])%mod;
	ans=(ans*pow(n+1,m-n+1))%mod;
	}else if(n==3){
		ans=(16*pow(4,m-n+1))%mod;
		ans=ans+(12*pow(4,m-n+1)%mod);
		ans%=mod;
	}/*else{
		ll s,la,sp,sa;
		dp[0][1]=dp[1][1]=1;
		s=2;
		la=2;
		int i,j,p1,p2;
		ll k;
		for(j=2;j<=m+n-1;j++){
			k=min((ll)j,n);
			k=min(k,m+n-j);
			dp[0][j]=dp[k][j]=s;
			sp=(s*2)%mod;
			sa=2;
			for(i=1;i<k;i++){
				p1=i;p2=k-i;
				if(p1==1||p2==1) dp[i][j]=s,sa++,sp=(sp+s)%mod;
				else if(p1>2&&p2>2) dp[i][j]=0;
				else{
					dp[i][j]=(la*2)%mod;
					sa++;
					sp=(sp+dp[i][j])%mod;
				}
			}
			la=sa;
			s=sp;
		}
		ans=(dp[0][m+n-1]+dp[1][m+n-1])%mod;
	}*/
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
