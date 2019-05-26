#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
int n,ans,a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n+1;i++)
	 if (a[i]<a[i-1]) ans+=a[i-1]-a[i];
	printf("%d\n",ans);
	return 0;
}

