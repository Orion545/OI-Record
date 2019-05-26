#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define X (100010)
#define mes(a,b) memset(a,b,sizeof a)
#define mec(a,b) memcpy(a,b,sizeof a)
using namespace std;
inline void read(int &x)
{
	char ch=getchar();x=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
}
int n,z[X],k=0,ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	mes(z,0);
	for (register int i=1;i<=n;i++)
	{
		int a;
		read(a);
		if (a<z[k])
		{
			ans+=z[k]-a;
			while (a<z[k]) k--;
		}
		z[++k]=a;
	}
	printf("%d\n",ans+z[k]);
	return 0;
}
















