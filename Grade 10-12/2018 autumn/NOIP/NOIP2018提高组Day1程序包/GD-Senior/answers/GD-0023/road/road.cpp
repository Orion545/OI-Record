#include<cstdio>
using namespace std;
int n,a[200000],s[200000];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	s[1]=a[1];
	for (int i=2;i<=n;i++)
		if (a[i]<=a[i-1])
			s[i]=s[i-1];
		else s[i]=s[i-1]+a[i]-a[i-1];
	printf("%d\n",s[n]);
	fclose(stdin);fclose(stdout);
}
