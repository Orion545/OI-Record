#include<cstdio>
#define fo(i,x,y) for(int i=x;i<=y;i++)
#define ll long long
using namespace std;
const int N=1e5+5;
int n,m,a[N];
ll ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n) {
		scanf("%d",&a[i]);
		if (i>1 && a[i]<a[i-1]) ans+=a[i-1]-a[i]; 
	}
	ans+=a[n];
	printf("%lld\n",ans);
}
