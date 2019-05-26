#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,a[105],f[500000];
void work()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if (n==2)
	{
		if (a[2]%a[1]==0) cout<<1<<endl;else cout<<2<<endl;
		return ;
	}
	int sum=1;
	memset(f,0,sizeof(f));
	f[a[1]]=1;
	for (int i=a[1];i<=a[n];i++)
	 if (f[i])
	 {
	 	for (int j=1;j<=n;j++)
	 	if (i+a[j]<=a[n]) f[i+a[j]]=1;else break;	
	 }
	for (int i=2;i<=n;i++) if (!f[a[i]]) sum++;
	cout<<sum<<endl;
	return ;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	cin>>T;
	for (;T>0;T--) work();
	return 0;
}

