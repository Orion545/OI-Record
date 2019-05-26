#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int num[110],t,n,mx;
bool bo[25010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=rd();
	while (t--)
	{
		n=rd();mx=0;
		for (int i=1;i<=n;i++) num[i]=rd();
		for (int i=1;i<=n;i++) mx=max(mx,num[i]);
		sort(num+1,num+n+1);
		memset(bo,false,sizeof(bo));
		bo[0]=true;
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			if (bo[num[i]]) continue;
			ans++;
			for (int j=num[i];j<=mx;j++) if (bo[j-num[i]]) bo[j]=true;
		}
		printf("%d\n",ans);
	}
	return 0;
}
