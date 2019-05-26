#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[128];
bool can[30203];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(can,0,sizeof(can));
		int n,ans=0;
		can[0]=1;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for (int i=1;i<=n;i++){
			if (can[a[i]]) continue;
			ans++;
			for (int j=a[i];j<=25005;j++)
			if (can[j-a[i]]) can[j]=1;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
