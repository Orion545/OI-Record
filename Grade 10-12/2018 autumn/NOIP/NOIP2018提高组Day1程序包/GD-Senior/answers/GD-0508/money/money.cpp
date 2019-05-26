#include<cstdio>
#include<algorithm>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e5+5;
int n,m;
int a[N],bz[N],tong[N];
bool cmp(int a,int b)
{
	return a<b;
}
int main() 
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int mx=0;
		fo(i,1,n)
		{
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		fo(i,1,mx)tong[i]=0;
		fo(i,1,n)tong[a[i]]=1;
		fo(i,1,mx)
		{
			fo(j,1,n)
			{
				if (tong[i]!=0&&i+a[j]<=mx)
				{
					if (tong[i+a[j]]!=2)tong[i+a[j]]=2;//1:存在 2:可被分解 0:不存在 
				}
			}
		}
		int ans=0;
		fo(i,1,n)if (tong[a[i]]!=2)++ans;
		printf("%d\n",ans);
	}
	return 0;
}
