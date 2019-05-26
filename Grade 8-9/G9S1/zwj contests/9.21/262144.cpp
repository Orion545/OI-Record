#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,ans,a;
int f[100][300000];
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		ans=max(ans,a);
		f[a][i]=1;
	} 
	for(i=1;i<=58;i++){
		for(j=1;j<=n;j++){
			if(f[i][j]){
				k=f[i][j]+j;
				if(!f[i][k]) continue;
				f[i+1][j]=f[i][k]+f[i][j];
				ans=max(ans,i+1);
			}
		}
	}
	printf("%d",ans);
} 
