#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
int n,a[500000],ans;
bool f[5000000];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	 {
	 	scanf("%d",&n);
	 	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	 	sort(a+1,a+n+1);
		if (a[1]==1){cout<<"1"<<endl;continue;}
	 	memset(f,false,sizeof(f));
	 	ans=1;
	 	for (int i=a[1];i<=a[n];i+=a[1]) f[i]=true;
	 	f[0]=true;
	 	for (int i=2;i<=n;i++)
	 	 if (!f[a[i]])
	 	  {
	 	  	ans++;
	 	  	for (int j=a[i];j<=a[n];++j)
	 	  	 if (f[j-a[i]]) f[j]=true;
	 	  }
	 	cout<<ans<<endl;
	 }
	 return 0;
}
