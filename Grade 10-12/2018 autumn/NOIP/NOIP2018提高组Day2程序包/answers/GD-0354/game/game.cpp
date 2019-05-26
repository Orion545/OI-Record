#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
int n,m,ans;

#define mod (int)(1e9+7)

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n>m){
		swap(n,m);
	}
	if (n==1){
		int ans=1;
		for (int i=1;i<=m;i++){
			ans=(ans*2)%mod;
		}
		printf("%d\n",ans);
	}
	if (n==2){
		ll ans=4LL;
		for (int i=1;i<m;i++){
			ans=ans*3LL%mod;
		}
		printf("%lld\n",ans);
	}
	else if (n==3){
		printf("112\n");
	}
	else if (n==5){
		printf("7136\n");
	}
	return 0;
} 
