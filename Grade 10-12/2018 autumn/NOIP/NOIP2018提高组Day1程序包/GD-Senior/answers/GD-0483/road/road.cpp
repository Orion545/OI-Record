#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 100010
using namespace std;
int n,d[N],f[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	f[1]=d[1];
	for (int i=2;i<=n;i++){
		if (d[i]>=d[i-1]) f[i]=f[i-1]+d[i]-d[i-1];
		else f[i]=f[i-1];
	}
	printf("%d",f[n]);
	return 0;
}

