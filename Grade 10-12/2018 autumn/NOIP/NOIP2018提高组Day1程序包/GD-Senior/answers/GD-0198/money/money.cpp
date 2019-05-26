#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int t,n,ans,a[1000005],f[1000005];
void begin_clean()
{
	memset(f,0,sizeof(f));
	f[0]=1;ans=0;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(;t>0;t--)
	{
		begin_clean();
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
		{
			if(f[a[i]]>0) continue;
			for(int j=0;j<=25000-a[i];j++) if(f[j]>0) f[j+a[i]]=1;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
