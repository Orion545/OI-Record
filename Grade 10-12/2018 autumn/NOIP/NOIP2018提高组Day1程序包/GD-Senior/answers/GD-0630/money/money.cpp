#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
int shu[200];
bool f[30000];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int zs;scanf("%d",&zs);
	int n,ans;
	while(zs--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&shu[i]);
		sort(shu+1,shu+n+1);
		memset(f,0,sizeof(f));f[0]=true;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(f[shu[i]])continue;
			ans++;
			for(int j=shu[i];j<=25000;j++)f[j]|=f[j-shu[i]];
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
