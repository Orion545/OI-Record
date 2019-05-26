#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 20
#define mo 1000000007
#define ll long long 
using namespace std;

int n,m,i,j,k,cnt,a[maxn][maxn];
int s[1<<maxn],tot[1<<maxn];

ll ksm(ll x,ll y){
	ll s=1;
	for(;y;y>>=1,x=x*x%mo) if (y&1) 
		(s*=x)%=mo;
	return s;
}

int pd(){
	for(int S=0;S<1<<(n+m-2);S++) {
		tot[S]=0;
		for(int T=S;T;T-=T&-T) tot[S]++;
	}
	
	for(int S=0;S<1<<(n+m-2);S++){
		if (tot[S]!=m-1) continue;
		int c=0,x=0,y=0;
 		c=a[x][y];
		for(i=n+m-3;i>=0;i--){
			if ((S>>i)&1) y++; else x++;
			c=c*2+a[x][y];
		}
		s[S]=c;
	}
	for(int S=0;S<1<<(n+m-2);S++) for(int T=0;T<S;T++) {
		if (tot[S]!=m-1||tot[T]!=m-1) continue;
		if (S>T&&s[S]>s[T]) 
			return 0;
	}
	return 1;
}

void dg(int x,int y){
	if (x==n) x=0,y++;
	if (y==m){
		if (pd()==0) return;
		cnt++; 
		if (cnt==mo) cnt=0;
		return;
	} 
	a[x][y]=1,dg(x+1,y);
	a[x][y]=0,dg(x+1,y);
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m);
	if (n==1) printf("%lld",ksm(2,m)); else
	if (n==2) printf("%lld",ksm(3,m-1)*1ll*4%mo); else 
	if (n==3) printf("%lld",ksm(3,m-3)*1ll*112%mo); else{
		cnt=0; dg(0,0); printf("%lld",cnt);
	}
}
