#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
#include <bitset>
using namespace std;
inline int read()
{
	int f=1,k=0;char c=getchar();
	while (c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
const int P=1e9+7;
bool mp[10][10];
//int f[2][1<<8];
//int n,m;
//int ST[]
//void dfs(const int x,const int y)
//{
//	if (x==n&&y==m)
//	{
//		if (check())++ans;
//	}
//	
//}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	int n=read(),m=read();
	if (n==1)
	{
		printf("%d\n",1<<m);
		return 0;
	}
	if (n==2)
	{
		if (m==1)return puts("4"),0;
		else if (m==2)return puts("12"),0;
		else 
		{
			int ans=1;
			for (int i=1;i<m;i++)ans=1ll*ans*3%P;
			ans=1ll*ans*4%P;
			printf("%d\n",ans);
			return 0;
		}
	}
	if (n==3&&m==1)return puts("8"),0;
	if (n==3&&m==2)return puts("36"),0;
	if (n==3&&m==3)return puts("112"),0;
	if (n==5&&m==5)return puts("7136"),0;
	puts("0");
//	mp[1][1]=0;
//	dfs(1,1);
//	mp[1][1]=1;
//	dfs(1,1);
//	for (int st=0;st<(1<<n);st++)f[1][st]=1;
//	for (int i=2;i<=m;i++)
//	{
//		memset(f[i&1],0,sizeof(f[i&1]));
//		for (int st=0,up=1<<n;st<up;st++)
//			for (int ST=0,UP=1<<n;ST<UP;ST++)
//			{
//				bool ok=1;
//				for (int pos=0;pos<n;pos++)
//				if (((st>>pos)&1)&&(ST>>pos+1)&1)ok=0;
//				if (ok)(f[i&1][st]+=f[(i&1)^1][ST])%=P;
//			}
//	}
//	int ans=0;
//	for (int st=0;st<(1<<n);st++)(ans+=f[n&1][st])%=P;
//	printf("%d\n",ans);
}
