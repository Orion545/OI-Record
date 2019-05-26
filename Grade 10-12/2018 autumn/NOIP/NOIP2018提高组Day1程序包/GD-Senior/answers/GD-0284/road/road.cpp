#include<algorithm>
#include<cstdio>

using namespace std;

const int MAXN=100001;

int n,ans,a[MAXN];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[0]=0;
	for(int i=1;i<=n;i++)if(a[i]>a[i-1])ans=ans+(a[i]-a[i-1]);
	printf("%d",ans);
}
/*
6
4 3 2 5 3 5
*/
