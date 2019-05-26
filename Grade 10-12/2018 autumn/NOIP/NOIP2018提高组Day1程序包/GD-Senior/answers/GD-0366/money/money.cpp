#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int t,n,num,ma,ans;
int a[105],f[100005];

int main()
{freopen("money.in","r",stdin);
freopen("money.out","w",stdout);
	cin>>t;
	while (t--)
	 {
	 	cin>>n;ma=0;
	 	memset(a,0,sizeof(a));
	 	for (int i=1;i<=n;i++)
	 	 {scanf("%d",&a[i]);ma=max(ma,a[i]);}
	 	sort(a+1,a+1+n);
	 	if (a[1]==1) {printf("1\n");continue;}
	 	num=n;
	 	for (int i=2;i<=n;i++)
	 	 {
	 	 	for (int j=1;j<i;j++)
	 	 	 if (a[i]%a[j]==0) {num--;a[i]=10000009;break;}
		 }
		sort(a+1,a+1+n);
		memset(f,0,sizeof(f));
		f[0]=1;ans=num;
		for (int i=1;i<=num;i++)
		 {
		 	if (f[a[i]]==1) {ans--;continue;}
		 	for (int j=a[i];j<=ma;j++)
		 	 {
		 	 	if (f[j-a[i]]) f[j]=1;
			 }
		 }
		cout<<ans<<endl;
	 }
	return 0;
}
