#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<iomanip>
using namespace std;

#define maxn 150
#define maxv 25050
#define inf 0x7f7f7f7f
int t,n,a[maxn],maxa,ans;
bool flag,visit[maxv],exist[maxv];
vector<int> can;

inline void input()
{
	memset(exist,false,sizeof(exist));
	maxa = -inf;
	flag = false;
	scanf("%d",&n);
	ans = n;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		exist[a[i]] = true;
		maxa = ((a[i]>maxa)?a[i]:maxa);
		flag = (flag || a[i]==1);
	}
	return;
}

inline void calc()
{
	memset(visit,false,sizeof(visit));
	can.clear();
	can.push_back(0);
	visit[0] = true;//可以被表示 
	sort(a+1,a+1+n);
	int i,j,k,limit,t;
//	for(t=0;t<=maxa;++t)
//		cout<<visit[t]<<' ';
//	cout<<endl;
	for(i=1;i<=n;++i)//all the sort of money
	{
		if(!exist[a[i]])
		{
			--ans;
			continue;
		}
		for(j=0,limit=can.size();j<limit;++j)
		{
			for(k=1;can[j]+a[i]*k<=maxa;++k)//a[i]*k
			{
//				cout<<exist[can[j]+a[i]*k]<<' '<<can[j]<<' '<<can[j]+a[i]*k<<endl;
				if(!visit[can[j]+a[i]*k])//可以被表示 
				{
					visit[can[j]+a[i]*k] = true;
					can.push_back(can[j]+a[i]*k);
				}
				if(exist[can[j]+a[i]*k])//可以被表示 
					exist[can[j]+a[i]*k] = false;
			}
		}
//		for(t=0;t<=maxa;++t)
//			cout<<visit[t]<<' ';
//		cout<<endl;
	}
	return;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		input();
		if(flag || n == 1)
		{
			printf("1\n");
			continue;
		}
		calc();
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
