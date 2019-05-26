#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool book[25001];
int t,n,a[101],ans;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		memset(book,false,sizeof(book));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			if(book[a[i]]) continue;
			ans++;
			book[a[i]]=true;
			for(int j=a[i];j<=a[n];j++)
				book[j]|=book[j-a[i]];
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
