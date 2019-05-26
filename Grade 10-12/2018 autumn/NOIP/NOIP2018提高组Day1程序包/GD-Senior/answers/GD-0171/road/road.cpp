#include<stdio.h>

using namespace std;

int n;
int d[100010]={0};
int peak[100010]={0},valley[100010]={0};
int ans=0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++){
		scanf("%d",&d[i]);
	}
	int pe=1,va=1;
	for(i=1;i<=n;i++){
		if(d[i]>d[i-1]){
			if(d[i]>=d[i+1]){
				peak[pe]=d[i];
				pe++;
			} 
		}
		if(d[i]<d[i-1]){
			if(d[i]<=d[i+1]){
				valley[va]=d[i];
				//printf("**%d\n",i);//###############
				va++;	
			}
		}
	}
	/*for(i=1;i<pe;i++){//##########################
		printf("%d ",peak[i]);
	}
	printf("\n");//###########################
	for(i=1;i<va;i++){//#############################
		printf("%d ",valley[i]);
	}
	printf("\n");//###########################*/
	
	ans=peak[1];
	for(i=2;i<pe;i++){
		ans+=peak[i]-valley[i-1];
	}
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
