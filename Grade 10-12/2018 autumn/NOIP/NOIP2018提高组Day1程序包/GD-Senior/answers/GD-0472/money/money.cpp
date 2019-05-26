#include<cstdio>
#include<cstring>
#include<algorithm>
#define DEBUG true
using namespace std;

int a[101],n,T;

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	int m,ans;
	for(int cs=0;cs<T;cs++){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);	//for(int ii=1;ii<=n;ii++) printf("%d ",a[ii]); printf("\n");
		for(int i=n;i>=2;i--){
			for(int j=i-1;j>=1;j--){
				if (a[i]!=-1 && a[j]!=-1){
					m = a[i]-a[j];
					for(int k=1;k<=j;k++){
						if (a[k]>m) break;
						if (m % a[k] == 0){
							a[i] = -1;break;
						}
					}
				}
				if (a[i] == -1) break;
			}
		}
		ans = 0;
		for(int i=1;i<=n;i++){
			if (a[i] != -1) ans++;	//if(a[i]==-1) printf("a[%d] is deleted\n",i);
		}
		printf("%d\n",ans);
	}
	fclose(stdout);
	return 0;
}

