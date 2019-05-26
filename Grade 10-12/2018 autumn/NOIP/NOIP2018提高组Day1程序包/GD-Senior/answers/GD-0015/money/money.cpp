#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T;
int num[105];
int use[105];
bool vis[105];
bool die[105];
int n;
inline int gcd(int a,int b)
{
	return a%b==0?b:gcd(b,a%b);
}
bool find(int tmp,int m)
{
	register int a,b,c,d;
	for(a=1;a<=m;a++)
	if(tmp%use[a]==0) return true;
	for(a=1;a<=m;a++)
	{
		for(b=1;b*use[a]<=tmp;b++)
		{
			if(find(tmp-b*use[a],m))
			return true;
		}
	}
	return false;
}
bool jiancha(int m)
{
	int least=1e9;
	for(int a=1;a<=n;a++)
	{
		if(die[a]||num[a]>least||find(num[a],m)) continue;
		else
		return false;
	}
	return true;
}
inline bool dfs(int k,int limit)
{
	if(k>limit)
	{
		if(jiancha(limit)) 
		return true;
		else 
		return false;
	}
	else
	{
		register int a,b,c,d;
		for(a=1;a<=n;a++)
		{
			if(vis[a]||die[a]) continue;
			use[k]=num[a];
			vis[a]=1;
			if(dfs(k+1,limit))
			return true;
			vis[a]=false;
		}
	}
	return false;
}
inline bool check(int a)
{
	if(dfs(1,a)) return true;
	return false;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(use,0,sizeof use);
		memset(vis,0,sizeof vis);
		memset(die,0,sizeof die);
		scanf("%d",&n);
		int a,b,c,d;
		for(a=1;a<=n;a++)
		scanf("%d",&num[a]);
		sort(num+1,num+1+n);
		for(a=1;a<=n;a++)
		{
			for(b=a+1;b<=n;b++)
			{
				if(num[b]%num[a]==0&&a!=b)
				die[b]=true;
			}
		}
		for(a=1;a<n;a++)
		{
			if(check(a)) break;
		}
		printf("%d\n",a);
	}
	return 0;
}
