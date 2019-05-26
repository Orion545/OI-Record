#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

namespace mine
{
	const int MAX_N=110;
	int a[MAX_N];
	const int MAX_NUM=31000;
	bool f[MAX_NUM];
	void main()
	{
		freopen("money.in","r",stdin);
		freopen("money.out","w",stdout);
		
		int T;scanf("%d",&T);
		while(T--)
		{
			int n;scanf("%d",&n);
			for(int i=1;i<=n;i++) scanf("%d",&a[i]);
			sort(a+1,a+n+1);
			
			memset(f,0,sizeof f);
			f[0]=1;
			int tot=0;
			for(int i=1;i<=n;i++)
			{
				int now=a[i];
				if(f[now]==0)
				{
					tot++;
					for(int s=now;s<MAX_NUM;s++) f[s]|=f[s-now];
				}
			}
			printf("%d\n",tot);
		}
	}
}
/*
因为非负整数加法，从小到大考虑
动态维护好背包
如果当前能被以前的直接表示，显然没用
否则，显然当前这个数，新被表示出来
用更小而且没出现的数，去取代当前的数，会导致多出那个数，所以也不行 

只需对 值域 内进行背包即可，很小 
*/
int main()
{
	srand(time(0));
	mine::main();
}
