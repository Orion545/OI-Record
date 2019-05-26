#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
int n,a[2010],b[2010],f[2010][2010];
int main(){
	int i,j,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++) f[i][0]=inf;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			f[i][j]=min(f[i][j-1],f[i-1][j]+abs(b[j]-a[i]));
		}
	}
	ans=f[n][n];
	reverse(b+1,b+n+1);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			f[i][j]=min(f[i][j-1],f[i-1][j]+abs(b[j]-a[i]));
		}
	}
	printf("%d",min(ans,f[n][n]));
} 
