#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

#define maxn 105
#define maxa 25005

using namespace std;

int T;

int n,len;
int a[maxn];

bool flag[maxa];

int ans;

void solve()
{
	int i,j;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	
	memset(flag,false,sizeof(flag));
	flag[0]=true;
	len=a[n];
	ans=n;
	for(i=1;i<=n;i++)
	{
		if (flag[a[i]])
		{
			ans--;
			continue;
		}
		for(j=0;j+a[i]<=len;j++)
			flag[j+a[i]]|=flag[j];
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	scanf("%d",&T);
	for(;T;T--)
		solve();
		
	return 0;
}
