#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[102],ans;
bool b[25002];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n;
	cin>>t;
	b[0]=true;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		ans=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=25000;i++)
		b[i]=false;
		for(int i=1;i<=n;i++)
		if(!b[a[i]])
		{
			ans++;
			for(int j=0;j<=25000-a[i];j++)
			if(b[j])
			b[a[i]+j]=true;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
