#include<bits/stdc++.h>
using namespace std;
int ans,n,a[100001],i;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&a[1]);ans=a[1];
	for(i=2;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
	}
	printf("%d\n",ans);
}
