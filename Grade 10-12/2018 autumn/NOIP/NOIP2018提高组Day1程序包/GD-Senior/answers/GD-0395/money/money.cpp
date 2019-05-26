#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105;
int t,n,a[maxn],ans,mx;
int gcd(int a,int b)
{
	if(a<b)swap(a,b);
	if(b==0)return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("money,in","r",stdin);
	freopen("money,out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));ans=0;mx=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		ans=max(ans,gcd(a[i],a[j]));
		ans--;
		if(ans!=0&&ans<n)printf("%d\n",ans);
		else if(ans==0||ans>n)printf("%d\n",n);
	}
	return 0;
}
