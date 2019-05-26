#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
bool vst[1000]={};
int a[1000],n,t,ans;
int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int find2(int a,int b)
{
	if(b%a==0)
		return 1;
	else
		return 2;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int ans=0;
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j]);
		if(n==2)
		{
			ans=find2(a[1],a[2]);
			printf("%d",ans);
			cout<<endl;
		}	
		if(n==3)
		{
			sort(a,a+n);
			ans=find2(a[1],a[2]);
			if(ans==1)
				if(gcd(a[1],a[3])==1)
					ans++;
			else
				{
					int f1=gcd(a[1],a[2]);
					int tmp1=a[1]/f1,tmp2=a[2]/f1,tmp3=a[3]%f1;
					if(tmp3==0)
					{
						if(a[3]/f1<=tmp1*tmp2-tmp1-tmp2)
							ans++;
					}
				}
				cout<<ans<<endl;
		}
		if(n>3)
			cout<<n<<endl;
	}
	return 0;
}
