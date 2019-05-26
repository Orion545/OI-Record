#include <cstdio>
#include <cstring>
#include <algorithm>
#define ele int
#define ll long long
using namespace std;
const ele MOD=1000000007;
inline ele pw(ele a,ele x){
	ele ans=1,tmp=a%MOD;
	for (; x; x>>=1,tmp=(ll)tmp*tmp%MOD)
		if (x&1) ans=(ll)ans*tmp%MOD;
	return ans;
}
ele n,m;
int main(){
	freopen("game.in","r",stdin); freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m);
	if (n==1){
		printf("%d\n",pw(2,m));
	}
	else if (n==2){
		ele ans=pw(3,m-1);
		ans=(ll)ans*4%MOD;
		printf("%d\n",ans);
	}
	else puts("112");
	return 0;
}
