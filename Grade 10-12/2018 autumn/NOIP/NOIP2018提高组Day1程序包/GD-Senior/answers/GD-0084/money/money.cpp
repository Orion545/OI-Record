#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define X (110)
#define mes(a,b) memset(a,b,sizeof a)
#define mec(a,b) memcpy(a,b,sizeof a)
using namespace std;
inline void read(int &x)
{
	char ch=getchar();x=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
}
int bz,T,n,m,a[X],b[X];
void dg(int x,int p)
{
	if (x>m)
		return;
	if (!(p%b[x]))
	{
		bz=1;
		return;
	}
	int mx=p/b[x];
	for (int j=0;j<=mx;j++)
	{
		dg(x+1,p-j*b[x]);
		if (bz) return;
	}
		
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	read(T);
	while (T--)
	{
		read(n);
		m=0;
//		mes(b,0);
		register int i;
		for (i=1;i<=n;i++)
			read(a[i]);
		sort(a+1,a+n+1);
		for (i=1;i<=n;i++)
		{
			bz=0;
			dg(1,a[i]);
			if (!bz)
				b[++m]=a[i];
			//+
		}
		printf("%d\n",m);
	}
	
	return 0;
}











