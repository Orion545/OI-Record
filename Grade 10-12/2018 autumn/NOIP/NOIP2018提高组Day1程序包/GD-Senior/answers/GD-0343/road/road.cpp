#include<cstdio>

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,ans=0,lst=0,x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		if(x>lst)
			ans+=x-lst;
		lst=x;
	}
	printf("%d",ans);
	return 0;
}
