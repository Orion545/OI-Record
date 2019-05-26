#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int num[100010],n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	int ans=0;
	for (int i=1;i<=n;i++) if (num[i]>num[i-1]) ans+=num[i]-num[i-1];
	printf("%d\n",ans);
	return 0;
}
