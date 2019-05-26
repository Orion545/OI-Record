#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 31000;

int n,m;
int v[maxn],del[maxn];
int a[maxn],f[maxn];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int T; scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n); m=0;
		memset(v,0,sizeof v);
		memset(del,0,sizeof del);
		
		for(int i=1;i<=n;i++)
		{
			int x; scanf("%d",&x);
			if(!v[x]) a[++m]=x,v[x]=1;
		} n=m;
		sort(a+1,a+n+1);
		f[0]=1;
		for(int i=1;i<=a[n];i++)
		{
			f[i]=0;
			for(int j=1;j<=n&&a[j]<=i;j++) if(f[i-a[j]])
			{
				if(i!=a[j]) del[i]=1;
				f[i]=1;
				break;
			}
		}
		m=n;
		for(int i=1;i<=n;i++) if(del[a[i]]) m--;
		printf("%d\n",m);
	}
	
	return 0;
}

