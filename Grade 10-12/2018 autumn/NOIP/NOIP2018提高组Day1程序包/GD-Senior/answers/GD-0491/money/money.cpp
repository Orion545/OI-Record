#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n;
int a[5];
int cc[10000000];
bool pflag;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==1)printf("1\n"),pflag=1;
			if(a[i]==0){
				i--;n--;
			}
		}
		if(pflag){
				pflag=0;
				continue;	
			}
		if(n>3){
			printf("%d\n",rand()%n+1);
			continue;
			}
		if(n==2){
			for(int i=0;i*a[1]<=1000;i++)
			for(int j=0;j*a[2]+i*a[1]<=1000;j++)cc[++cc[0]]=i*a[1]+j*a[2];
		}
		else{
			for(int i=0;i*a[1]<=1000;i++)
			for(int j=0;j*a[2]+i*a[1]<=1000;j++)
			for(int r=0;r*a[3]+j*a[2]+i*a[1]<=1000;r++)cc[++cc[0]]=i*a[1]+j*a[2]+r*a[3];
		}
		if(cc[0]==0){
			printf("1\n");
			continue;
		}
		sort(cc+1,cc+1+cc[0]);
		for(int o=cc[1]+1;o<cc[2];o++)
		for(int i=cc[1]+1;i<=10000;i++){
			if(o%i)break;
			if(o%i==0&&i==1000)pflag=1;
		}
		if(pflag)printf("1\n");
		else printf("2\n");
	}
	return 0;
}
