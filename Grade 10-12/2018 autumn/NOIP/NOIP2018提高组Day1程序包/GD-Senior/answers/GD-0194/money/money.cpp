#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=25010;
int T,n,a[maxn],ans;
bool tf[maxn];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);ans=0;
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		memset(tf,false,sizeof tf);tf[0]=true;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)if(!tf[a[i]])
		{
			ans++;
			for(int j=0;j<maxn-a[i];j++)tf[j+a[i]]|=tf[j];
		}
		printf("%d\n",ans);
	}
	return 0;
}
