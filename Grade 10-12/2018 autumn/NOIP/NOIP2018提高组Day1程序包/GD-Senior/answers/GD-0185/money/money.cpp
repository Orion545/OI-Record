#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[101];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>n;
	int i,j=0;
	for(i=1;i<=n;i++)
	{
		cin>a[i];
		if(a[i]==1)
		j=1;
	}
	if(j==1) cout<<1<<endl; 
	else
	cout<<n<<endl;
	return 0;
}
