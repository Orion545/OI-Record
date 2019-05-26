#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t,s,i,j,n,a[105],f[2500005];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>a[0])a[0]=a[i];
		}
		sort(a+1,a+n+1);
		f[0]=1,s=0;
		for(i=1;i<=n;i++){
			if(f[a[i]])continue;
			s++;
			for(j=0;j<=a[0]*n;j++){
				if(f[j]&&(j+a[i])<=a[0]*n)f[j+a[i]]=1;
				if((j+a[i])>a[0]*n)break;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
