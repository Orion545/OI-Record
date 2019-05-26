#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int t,n,a[10001];
bool is[70000];
bool gg[500];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		scanf("%d",a+i);
		sort(a+1,a+n+1);
		memset(gg,0,sizeof(gg));
		memset(is,0,sizeof(is));
		is[0]=1;
		for(int i=1;i<=n;i++)
		{
			if(is[a[i]]==1) {
				gg[i]=1;continue;
			}
			for(int j=0;j<=25000;j++)
			{
				if(is[j])
				is[j+a[i]]=1;
			}
		}
		int ans=n;
		for(int i=1;i<=n;i++)
		if(gg[i])ans--;
		cout<<ans<<endl;
	}return 0;
}
