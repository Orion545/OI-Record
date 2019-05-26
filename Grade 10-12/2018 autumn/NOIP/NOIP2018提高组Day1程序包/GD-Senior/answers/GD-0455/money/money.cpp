#include<iostream>
#include<cstdio>
using namespace std;
int a[100+5],n,t,i,j,l,m,mx,an;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(i=0;i<t;i++){
		an=0;mx=0;
		int dp[25000+5]={1};
		scanf("%d",&n);
		for(j=0;j<n;j++){scanf("%d",&a[j]);if(a[j]>mx)mx=a[j];}
		for(j=0;j<n;j++){
			l=1;
			while(l*a[j]<=mx){
				for(m=mx-l*a[j];m>=0;m--)if(dp[m]!=0)dp[m+l*a[j]]++;
				l=l*2;
			}
		}
		for(j=0;j<n;j++)if(dp[a[j]]==1)an++;
		printf("%d\n",an);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
