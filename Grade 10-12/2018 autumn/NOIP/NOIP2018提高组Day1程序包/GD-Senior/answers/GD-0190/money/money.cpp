#include <stdio.h>
#include <algorithm>
using namespace std;
int T,n,m,i,j,k,x,a[105];
int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	//printf("%d",gcd(8,42));
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		if(n==1)printf("1\n");
		if(n==2){
			scanf("%d%d", &a[1], &a[2]);
			sort(a+1,a+3);
			if(a[1]==1 || (a[2]%a[1]==0)){
				printf("1\n");
			}
			else printf("2\n");
		}
		if(n==3){
			scanf("%d%d%d", &a[1], &a[2], &a[3]);
			sort(a+1,a+4);
			if(a[1]==1)printf("1\n");
			else if(a[2]%a[1]==0 &&a[3]%a[1]==0)printf("1\n");
			else if(a[1]+a[2]==a[3])printf("2\n");
			else if(a[2]%a[1]==0||a[3]%a[1]==0||a[3]%a[2]==0)printf("2\n");
			else printf("3\n");
		}
		if(n==4){
			m=n;
			for(i=1;i<=n;i++)scanf("%d", &a[i]);
			sort(a+1,a+i);
			if(a[1]==1)printf("1\n");
			else {
				for(i=1;i<=n;i++)if(a[i]==a[i+1])a[i]=0,m--;
				if(a[3]&&a[1]+a[2]==a[3])a[3]=0,m--;
				if(a[4]&&a[1]+a[2]==a[4])a[4]=0,m--;
				if(a[4]&&a[2]+a[3]==a[4])a[4]=0,m--;
				if(a[4]&&a[1]+a[3]==a[4])a[4]=0,m--;
				if(a[4]&&a[1]+a[2]+a[3]==a[4])a[4]=0,m--;
				if(a[1]){
					for(i=2;i<=4;i++){
						if(a[i]&&a[i]%a[1]==0)a[i]=0,m--;
					}
				}
				if(a[2]){
					for(i=3;i<=4;i++){
						if(a[i]&&a[i]%a[2]==0)a[i]=0,m--;
					}
				}
				if(a[3]&&a[4]&&a[4]%a[3]==0)m--;
				if(a[1]){
					x=a[3]-a[2];
					if(x&&x%a[1]==0)a[3]=0,m--;
					x=a[4]-a[2];
					if(x&&x%a[1]==0)a[4]=0,m--;
					x=a[4]-a[3];
					if(x&&x%a[1]==0)a[4]=0,m--;
					x=a[4]-a[3]-a[2];
					if(x&&x%a[1]==0)a[4]=0,m--;
				}
				if(a[2]){
					x=a[4]-a[3];
					if(x&&x%a[2]==0)a[4]=0,m--;
				}
				printf("%d\n",m?m:1);
			}
		}
	} 
	return 0;
}
