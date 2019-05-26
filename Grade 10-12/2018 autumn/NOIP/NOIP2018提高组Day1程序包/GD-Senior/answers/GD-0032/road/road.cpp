#include<cstdio>
#define ll long long
#define maxn 100050
using namespace std;
ll a[maxn],s[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n; ll ans=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=a[i]-a[i-1];
		if (s[i]>0) ans+=s[i];
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
