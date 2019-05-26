#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,i,j,k,a[10005],ans[10005],r[10005],minn,anss,now;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int exgcd(int a,int b,int &x,int &y)
{
	if (!b)
	{
		x=1,y=0;
		return a;
	}
	int ans=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return ans;
}
bool check(int x)
{
	for (int i=1;i<k;i++)
	for (int j=i+1;j<=k;j++)
	{
		int X=0,Y=0;
		int Gcd=exgcd(ans[i],ans[j],X,Y);
		if (x%Gcd==0&&((X*x/Gcd)%(ans[j]/Gcd)+ans[j])%(ans[j]/Gcd)*ans[i]<=x)
		return false;
	}
	return true;
}
bool check2(int x)
{
	for (int j=1;j<=n;j++)
	if (x%a[j]==0)
	return false;
	return true;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		minn=2e9,anss=k=2;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		scanf("%d",&r[i]);
		sort(r+1,r+n+1);
		now=n,n=0;
		for (i=1;i<=now;i++)
		{
			if (check2(r[i]))
			n++,a[n]=r[i];
		}
		if (n==1)
		{
			printf("1\n");
			continue;
		}
		if (n==2)
		{
			if (gcd(a[1],a[2])==a[1]||gcd(a[1],a[2])==a[2])
			printf("1\n");
			else
			printf("2\n");
			continue;
		}
		ans[1]=a[1],ans[2]=a[2];
		for (i=1;i<n;i++)
		for (j=i+1;j<=n;j++)
		if (gcd(a[i],a[j])==1&&minn>a[i]*a[j]-a[i]-a[j])
		minn=a[i]*a[j]-a[i]-a[j],ans[1]=a[i],ans[2]=a[j];
		for (i=1;i<=n;i++)
		if (a[i]<=minn&&check(a[i]))
		{
			now=k,anss++,k++,ans[k]=a[i];
			for (j=1;j<=now;j++)
			k++,ans[k]=ans[j]+a[i];
		}
		printf("%d\n",anss);
	}
	return 0;
}
