#include<cstdio>
#include<cstring>
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	long long x,tmp=0,ans=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&x);
		if (x>tmp) ans+=(x-tmp); 
		tmp=x;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
