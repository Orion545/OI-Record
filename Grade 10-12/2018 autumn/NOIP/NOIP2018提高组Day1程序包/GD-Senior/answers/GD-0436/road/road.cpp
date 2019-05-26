#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
const int maxn=100000+10;
int a[maxn],num[maxn];
int i,j,k,l,t,n,m,mi,ans;
int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
	num[n+1]=1000000000;
	fd(i,n,1){
		num[i]=min(num[i+1],a[i]);
		a[i]-=a[i-1];
	}
	fo(i,1,n)
		if (a[i]>0) ans+=a[i];
	/*i=2;
	while (i<=n&&a[i]>=0) i++;
	j=n;mi=1000000000;
	while (j&&a[j]<=0){
		mi=min(mi,num[j]);
		j--;
	}
	while (a[1]>0&&i<j&&mi>0){
		k=min(a[1],min(-a[i],min(mi,num[j])));
		ans-=k;
		a[1]-=k;
		a[i]+=k;
		a[j]-=k;
		mi=min(mi-k,num[j]-k);
		while (i<=n&&a[i]>=0) i++;
		while (j&&a[j]<=0){
			mi=min(mi,num[j]);
			j--;
		}
	}*/
	printf("%d\n",ans);
	return 0;
}
