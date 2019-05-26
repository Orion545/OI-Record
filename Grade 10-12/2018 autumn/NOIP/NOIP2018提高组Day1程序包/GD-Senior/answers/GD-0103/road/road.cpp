#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for (int(i)=(a);(i)<=(b);(i)++)
using namespace std;
const int N=1e+5+255;
int a[N],n,ans,cnt,mx;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
	int i=1;
	while (i<=n){
		while (a[i]){
			int j=i,mx=2147483647;
			while (a[j]!=0){
				if (mx>a[j]) mx=a[j];
				j++;
			}
			j--;
			ans=ans+mx;
			fo(k,i,j) {
				a[k]-=mx;
			}
		}
		i++;
	}
	printf("%d",ans);
	return 0;
}

