#include<bits/stdc++.h>
#define N 100050
using namespace std;
typedef long long ll;
ll ans=0;
int n,a[N],now;
int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[n+1]=0;
	now=a[1];
	for (int i=2;i<=n+1;i++) if (a[i]<now) ans+=now-a[i],now=a[i];else now=a[i];
	printf("%lld\n",ans);
}
