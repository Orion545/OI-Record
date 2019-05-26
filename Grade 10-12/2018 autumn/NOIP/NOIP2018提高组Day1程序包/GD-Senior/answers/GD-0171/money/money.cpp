#include<stdio.h>
#include<cstring>
#include<algorithm>

using namespace std;

int T,n;
int a[110]={0};
int b[110]={0};
int ans=0;
int biao[1000000];

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	scanf("%d",&T);
	int i,j,k,p,q;
	int temp;
	//printf("%d",T);
	while(T>0){
		//printf("%d**",T);
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		ans=0;
		for(i=0;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		if(n==2){
			if(a[2]%a[1]==0) printf("1\n");
			else printf("2\n");
			continue;
		}
		b[1]=a[1];
		k=2;
		while(a[k]%a[1]==0 && k<n) k++;
		if(k==n){
			printf("1\n");
			continue;
		}
		b[2]=a[k];
		temp=b[1]*b[2]-b[1]-b[2];
		ans=2;
		memset(biao,0,sizeof(biao));
		for(i=0;i<b[2];i++){
			for(j=0;j<b[1];j++){
				biao[i*b[1]+j*b[2]]=1;
			}
		}
		for(i=k+1;i<=n;i++){
			if(a[i]>temp) break;
			/*for(j=1;j<=ans;j++){
				if(a[i]%b[j]==0) continue;
			}*/
			if(biao[a[i]]==1) continue;
			else{
				ans++;
				b[ans]=a[i];
				for(j=temp;j<b[1];j++){
					if(biao[j]==0){
						p=1;
						while(biao[j]-p*a[i]>0){
							if(biao[biao[j]-p*a[i]]!=1){
								p++;
							}
							else{
								for(p;p>0;p--){
									biao[biao[j]-p*a[i]]=1;
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans);
		T--;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
