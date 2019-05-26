#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100010
using namespace std;

int n,m,i,j,k,a[maxn],d[maxn],t,mi[maxn],ans;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	d[t=1]=0;
	for(i=1;i<=n;i++){
		while(t&&d[t]>=a[i]) t--;
		mi[i]=d[t];
		d[++t]=a[i];
	}
	d[t=1]=0;
	for(i=n;i>=1;i--){
		while(t&&d[t]>a[i]) t--;
		mi[i]=max(mi[i],d[t]);
		d[++t]=a[i];	
	}
	ans=0;
	for(i=1;i<=n;i++) ans+=a[i]-mi[i];
	printf("%d",ans);
}
