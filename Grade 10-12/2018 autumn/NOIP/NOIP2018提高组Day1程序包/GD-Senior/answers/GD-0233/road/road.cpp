#include<bits/stdc++.h>
using namespace std;
#define N 110000
typedef long long ll;
	int n,a[N],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[n+1]=0;
	for(int i=2;i<=n+1;i++)if(a[i]<a[i-1])ans+=a[i-1]-a[i];
	printf("%d\n",ans);
}
