#include<stdio.h>
using namespace std;
int i,n,s,a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[i-1])s+=a[i]-a[i-1];
	}
	printf("%d",s);
	return 0;
}
