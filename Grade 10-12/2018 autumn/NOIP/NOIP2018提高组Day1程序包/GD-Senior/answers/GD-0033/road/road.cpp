#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[100010],tot;

void road(int x,int y){
	int minx=0x7f,k,l=0,r=0;
	if (x>y||x==0||y==0) return ;
	if (x==y){
		tot+=a[x];
		a[x]=0;
		return ;
	}
	for (int i=x;i<=y;i++){
		if (a[i]<minx&&a[i]!=0){
			minx=a[i];
			k=i;
		}
	}
	for (int i=x;i<=y;i++)
		a[i]-=minx;
	for (int i=x;i<=k;i++){
		if (a[i]){
			l=i;
			break;
		}
	}
	for (int j=y;j>=k;j--){
		if (a[j]){
			r=j;
			break;
		}
			
	}
	tot+=minx;
	road(l,k-1);
	road(k+1,r);
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	road(1,n);
	printf("%d",tot);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
