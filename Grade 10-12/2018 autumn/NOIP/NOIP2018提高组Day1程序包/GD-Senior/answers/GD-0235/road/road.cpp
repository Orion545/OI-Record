#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,ma,mi,s,ans,a[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);mi=100010;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i>1&&a[i]>a[i-1]){
			ans+=ma-s;
			s=mi;
			ma=0;
			mi=100010;
		}
		if(ma<a[i]) ma=a[i];
		if(mi>a[i]) mi=a[i];
	}
	printf("%d",ans+ma-s);
	return 0;
}
