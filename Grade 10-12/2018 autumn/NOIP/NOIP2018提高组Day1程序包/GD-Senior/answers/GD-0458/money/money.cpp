#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define mmst(a, b) memset(a,b,sizeof(a))
#define mmcp(a, b) memcpy(a,b,sizeof(a))

typedef long long LL;

const int N=25050;

int T,n,a[N],ans;
bool b[N];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		mmst(b,0);
		b[0]=1;
		ans=0;
		
		cin>>n;
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		if(!b[a[i]])
		{
			ans++;
			for(int j=a[i];j<=25000;j++)
			if(b[j-a[i]])
			b[j]=1;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}

