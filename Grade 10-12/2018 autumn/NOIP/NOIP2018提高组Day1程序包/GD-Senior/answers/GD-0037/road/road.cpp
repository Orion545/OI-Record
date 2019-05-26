#include <stdio.h>
#include <cstring>
#include <cstdlib>
using namespace std;

int a[100002],b[10002],h[100002],sum[10002],d[100002];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,i,tot=0,ans=0,p=0;
	scanf("%d",&n);
	for (i=1; i<=n; i++){
	    scanf("%d",&a[i]);
	    if (p<a[i]) p=a[i];
	}
	for (i=1; i<=n; i++)
	    if (a[i]!=a[i-1]){
	    	tot++;
	    	h[tot]=a[i];
	    }
	for (i=1; i<=tot; i++)
		b[h[i]]++;
	for (i=1; i<=tot; i++){
		if (h[i]<h[i-1]) b[h[i-1]]--;
		if (h[i]<h[i+1]) b[h[i+1]]--;
	}
	for (i=1; i<=10000; i++)
		sum[i]=sum[i-1]+b[i];
	for (i=1; i<=p; i++){
	    ans+=sum[i-1]+1;
	    if (i>h[1]) ans--;
	    if (i>h[tot]) ans--;
	}
	printf("%d\n",ans);
/*	for (i=0; i<=n; i++){
		printf("%d ",b[i]);
	}
	for (i=0; i<=n; i++){
		printf("   %d",sum[i]);
	}*/
	return 0;
}

















