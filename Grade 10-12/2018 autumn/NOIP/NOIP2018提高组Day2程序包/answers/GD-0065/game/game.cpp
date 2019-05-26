#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=260;
const ll mo=1e9+7;
ll a[maxn][maxn];
ll n,m,i,t,j,k,l,x,y,z,ans;
void dg(int x,int y){
	if (y==m+1){
		dg(x+1,1);return;
	}
	if (x==n+1){
		ans++;
		return;
	}
	a[x][y]=1;dg(x,y+1);a[x][y]=0;
	if (!a[x-1][y+1]) a[x][y]=0,dg(x,y+1);
}
int main(){
	freopen("game.in","r",stdin);freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	dg(1,1);
	printf("%lld\n",ans);
}
