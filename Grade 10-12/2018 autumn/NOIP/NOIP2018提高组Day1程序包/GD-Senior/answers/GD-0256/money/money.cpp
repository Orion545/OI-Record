#include<cstdio>
#include<algorithm>
using namespace std;
const int N=110;
int a[N];
int b[N],tot=1;
int dfs(int,int);
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		b[1]=a[1];
		tot=1;
		for(int i=2;i<=n;i++)
		{
			int temp=dfs(a[i],tot);
			if(temp==0)
			{
				b[++tot]=a[i];
			}
		}
		printf("%d\n",tot);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
int dfs(int sum,int start)
{
	for(int i=start;i>=1;i--)
	{
		if(sum-b[i]<0) continue;
		if(sum-b[i]==0) return 1;
		int temp=dfs(sum-b[i],i);
		if(temp==1) return 1;
	}
	return 0;
}
