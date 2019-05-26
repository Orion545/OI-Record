#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define X (100001)
#define mes(x,y) memset(x,y,sizeof x)
#define mcp(x,y) memcpy(x,y,sizeof x)
using namespace std;
inline void read(int &x)
{
	char ch=getchar();x=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
}
char T1,T2;
int n,m,a[X],f1[X],f2[X];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	read(n),read(m);
	scanf("%c%c\n",&T1,&T2);
	
	if (T1=='A')
	{
		register int i;
		for (i=1;i<=n;i++)
		{
			read(a[i]);
			if (i&1)
				f1[i]=f1[i-1]+a[i],f2[i]=f2[i-1];
			else
				f2[i]=f2[i-1]+a[i],f1[i]=f1[i-1];
		}
		int x,l=n*2-2;
		for (i=1;i<=l;i++)
			read(x);
		for (i=1;i<=m;i++)
		{
			int x1,y1,x2,y2,s1=1,e1,s2,e2,s3,e3=n,ans=0;
			read(x1),read(y1),read(x2),read(y2);
			if (x2<x1)
				swap(x1,x2),swap(y1,y2);
			if (y1)
				ans+=a[x1],e1=x1-1,s2=x1+1;
			else
				ans+=a[x1-1]+a[x1+1],e1=x1-2,s2=x1+2;
			if (y2)
				ans+=a[x2],e2=x2-1,s3=x2+1;
			else
				ans+=a[x2-1]+a[x2+1],e2=x2-2,s3=x2+2;
			if (x1+2==x2)
				ans-=a[x1+1];
			ans+=(s1<=e1?min(f1[e1]-f1[s1-1],f2[e1]-f2[s1-1]):0)+
				 (s2<=e2?min(f1[e2]-f1[s2-1],f2[e2]-f2[s2-1]):0)+
				 (s3<=e3?min(f1[e3]-f1[s3-1],f2[e3]-f2[s3-1]):0);
			if (x1+1==x2 && y1==0 && y2==0)
				ans=-1;
			printf("%d\n",ans);
		}
	}
	
	return 0;
}


















