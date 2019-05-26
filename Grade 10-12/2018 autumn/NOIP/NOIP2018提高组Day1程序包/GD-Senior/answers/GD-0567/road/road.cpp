#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 100010
#define LL long long
using namespace std;
int n,v[N]; LL A=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",v+i);
	for(int i=1;i<=n;++i)
		A+=max(0,v[i]-v[i-1]);
	printf("%lld\n",A);
	return 0;
}
