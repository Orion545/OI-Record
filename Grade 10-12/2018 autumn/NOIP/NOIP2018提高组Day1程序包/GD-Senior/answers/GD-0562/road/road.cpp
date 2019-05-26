#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long a[200000],n,ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%ld",&n);
	a[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%ld",&a[i]);
		if(a[i]>a[i-1])ans+=a[i]-a[i-1];
	}
	printf("%ld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
