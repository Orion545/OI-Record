#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int t,n,m,i,j,a[101],v[25001],ans;

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		
		scanf("%d",&n);
		m=n;
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=2;i<=25000;i++)
		{
			if(v[i]==2)continue;
			for(j=1;j<=n;j++)
			{
				if(a[j]%i==0&&v[a[j]]==0)
				{
					v[a[j]]=2;
					v[i]=1;
					m--;
				}
			}
			if(v[i]==1) ans++;
			if(m==0) break;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
