#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,l,r,deep;
long long ans;
int a[100500];
int main()
{
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	scanf("%d",&n);
	a[0]=0; a[n+1]=0;
	ans=0;
	deep=0;
	l=0; r=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n+1;i++){
		if (a[i-1]==a[i]) continue;
		if (a[i]==0){ans+=deep; l=i; deep=0; continue;}
		if (a[i-1]>a[i]){ans+=deep-a[i]; deep=a[i]; continue;}
		deep=max(deep,a[i]);
	}
	printf("%lld\n",ans);
	fclose(stdin);
    fclose(stdout);
	return 0;
}
