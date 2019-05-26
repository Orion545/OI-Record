#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int t,n,ans;
int a[105];
bool f[10000003];
int c[105],cnt;

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for (int i=1;i<=t;i++){
		scanf("%d",&n);
		if (n==1) {scanf("%d",&ans);printf("1\n");}else
		if (n==2){
			int b,c;
			scanf("%d%d",&b,&c);
			if (b==1||c==1) printf("1\n"); else
			if (b==c) printf("1\n");else
			if (b%c==0&&c%b==0) printf("1\n");else
			printf("2\n");
		} else{
			ans=n;
			for (int j=1;j<=n;j++)
				scanf("%d",&a[j]);
			sort(a+1,a+1+n);
			int k=2,j=n;
			while (a[k]%a[1]==0) ans--,k++;
			for (;j>=k+1;j--)
				if (a[j]<a[1]*a[k]-a[1]-a[k]) break; else ans--;
		    memset(f,0,1000002*sizeof(bool));
			f[a[1]]=1;f[a[k]]=1;
			c[1]=a[1];c[2]=a[k];
			for (int l=a[1]+1;l<a[1]*a[k]-a[1]-a[k];l++)
				for (int j=1;j<=2;j++)
				f[l]|=f[l-c[j]];
			for (int l=k+1;l<=j;l++) {
			    if (f[a[l]]) {ans--;continue;}
			    f[a[l]]=1;
			    for (int g=a[1]+1;g<a[1]*a[k]-a[1]-a[k];g++)
			    	f[g]|=f[g-a[l]];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
