#include<cstdio>
int n,i,j,k,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&j);
		if (j>k)
		ans+=j-k;
		k=j;
	}
	printf("%d\n",ans);
	return 0;
}
