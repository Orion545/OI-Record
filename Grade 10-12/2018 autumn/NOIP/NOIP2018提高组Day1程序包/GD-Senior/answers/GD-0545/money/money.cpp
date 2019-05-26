#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=105;

int T,n;
int a[MAXN];

inline bool DFS(int pst,int end,int val)
{
	if(pst==end+1)
	{
		if(val==a[end+1])
			return true;
		else
			return false;
	}
	
	for(int i=0;val+i*a[pst]<=a[end+1];i++)
		if(DFS(pst+1,end,val+i*a[pst]))
			return true;
	
	return false;
}

signed main(void)
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		
		sort(a+1,a+n+1);
		
		int ans=0;
		for(int i=n;i>=2;i--)
		{
			if(DFS(1,i-1,0))
				ans++;
		}
		
		printf("%d\n",n-ans);
	}
	
	return 0;
}
