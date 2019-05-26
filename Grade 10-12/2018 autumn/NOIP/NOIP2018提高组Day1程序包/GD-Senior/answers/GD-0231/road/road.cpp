#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int d[111100],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&d[i]);
	}
	ans=0;d[0]=0;
	for (int i=1;i<=n;i++){
		if (d[i]>d[i-1])ans+=d[i]-d[i-1];
	}
	printf("%d\n",ans);
	return 0;
}

