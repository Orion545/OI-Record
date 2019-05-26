#include<stdio.h>
#include<algorithm>
using namespace std;

int n,m;
int a[50010]={0};
int b[50010]={0};
int l[50010]={0};
int len[50010]={0};

bool panding(int k){
	int i,j=0;
	int temp=0;
	for(i=1;i<=n;i++){
		temp+=len[i];
		if(temp>=k){
			temp=0;
			j++;
			if(j>=m){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	int i,j;
	int flag1=0;
	int flag2=0;
	int sum=0;
	for(i=1;i<n;i++){
		scanf("%d %d %d",&a[i],&b[i],&l[i]);
		if(a[i]!=b[i]-1) flag1=1;
		if(a[i]!=1) flag2=1;
		sum+=l[i];
	}
//	printf("%d\n%d\n",flag1,flag2);//#############
	int left,right,mid;
	if(flag1==0){
		for(i=1;i<=n;i++){
			len[a[i]]=l[i];
		}
	/*	for(i=1;i<=n;i++){//######################
			printf("%d ",len[i]);
		}
		printf("\n");//#####################*/
		left=0,right=sum/m;
		//printf("%d\n",right);//##############
		while(left!=right){
			mid=(left+right)/2+1;
			//int aaa=panding(mid);//#################
			//printf("%d %d\n",mid,aaa);//###########
			if(panding(mid)>0){
				left=mid;
			}
			else{
				right=mid-1;
			}	
		}
		printf("%d",left);		
		fclose(stdin);
		fclose(stdout);
		return 0;	
	}
	if(flag2==0){
		sort(l+1,l+n);
		int min;
		n-=1;
		if(m*2<=n){
			j=n-m;
			min=l[j-m+1]+l[j+m];
			int temp;
			for(i=m-1;i>0;i--){
				temp=l[j-i+1]+l[j+i];
				if(temp<min) min=temp;
			}
		}
		else{
			int n2=2*(n-m);
			j=n-m;
			min=l[n2+1];	
			int temp;
			for(i=n-m;i>0;i--){
				temp=l[j-i+1]+l[j+i];
				if(temp<min) min=temp;
			}
		}
		printf("%d",min);
		fclose(stdin);
		fclose(stdout);
		return 0;	
	}
	else printf("%d",l[n-1]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
