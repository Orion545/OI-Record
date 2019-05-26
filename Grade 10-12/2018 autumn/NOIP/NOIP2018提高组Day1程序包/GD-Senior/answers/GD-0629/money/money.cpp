#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int mx=105;
const int mxa=300000;
int n;
int a[mx];
bool f[mxa];

void solve()
{
	memset(f,0,sizeof f);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	
	int ans=0,Max=a[n];
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(f[a[i]]) continue;
		ans++;
		for(int j=0;j+a[i]<=Max;j++)
			if(f[j]) f[j+a[i]]=1;
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		solve();
	}
	
	
	return 0;
}
