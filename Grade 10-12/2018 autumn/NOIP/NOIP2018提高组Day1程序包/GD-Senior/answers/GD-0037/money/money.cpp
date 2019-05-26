#include <stdio.h>
#include <cstring>
#include <cstdlib>
using namespace std;

int a[102],b[25002];

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n,i,j,p,m;
	scanf("%d",&t);
	while (t--){
		memset(b,0,sizeof(b));
		m=0; b[0]=1;
		scanf("%d",&n);
		for (i=1; i<=n; i++)
		    scanf("%d",&a[i]);
		for (i=1; i<=n; i++)
			for (j=i+1; j<=n; j++)
			    if (a[i]>a[j]){
			    	p=a[i];
			    	a[i]=a[j];
			    	a[j]=p;
			    }
		for (i=1; i<=n; i++){
		    if (!b[a[i]]){
		    	m++;
		    	for (j=a[i]; j<=25000; j++)
		    	    if (b[j-a[i]]) b[j]=1;
		    }
		}
		printf("%d\n",m);
	}
	return 0;
}






