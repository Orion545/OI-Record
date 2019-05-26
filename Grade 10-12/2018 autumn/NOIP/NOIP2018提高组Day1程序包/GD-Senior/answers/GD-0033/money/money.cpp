#include<cstdio>
#include<algorithm>
using namespace std;

int t,n,m,a[110],b[110];
bool p[110];

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for (int i=1;i<=t;i++){
		m=0;
		scanf("%d",&n);
		for (int j=1;j<=n;j++){
			p[j]=false;
			a[j]=b[j]=0;
		}
		int l=1;
		for (int j=1;j<=n;j++){
			scanf("%d",&a[j]);
		}
		sort(a+1,a+1+n);
		for (int j=1;j<n;j++){
			for (int k=j+1;k<=n;k++){
				if (a[k]%a[j]==0){
					p[k]=true;
				}
			}
		}
		for (int j=1;j<=n;j++){
			if (!p[j]){
				b[l]=a[j];
				l++;
			}
		}
		int x=b[1]*b[2]-b[1]-b[2],y;
		for (y=1;y<l;y++){
			if (b[y]<x){
				m=y;
			}
		}
		if (b[2]>x) m++;
		if (m==0) printf("1\n");
		else printf("%d\n",m);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
