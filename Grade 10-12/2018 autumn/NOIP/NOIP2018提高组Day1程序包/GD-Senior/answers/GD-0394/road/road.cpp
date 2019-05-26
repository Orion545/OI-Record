#include<iostream>
#include<cstdio>
#define INF 2147483647
#define maxn 100005
using namespace std;

int n,d[maxn],k;
long long ans;

inline int read()
{
	char ch=getchar(); 
	while (ch>'9'||ch<'0') ch=getchar();
	int res=ch-48;
	ch=getchar();
	while (ch<='9'&&ch>='0')
	{
		res=res*10+ch-48; ch=getchar();
	}
	return res;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read(); int Min=INF,wz=0; ans=0;
	for (int i=1; i<=n; i++)
	{
		d[i]=read(); 
		if (Min>d[i]&&d[i]!=0) 
		{
			Min=d[i]; wz=i;
		}
	}
	k=0;
	while (k!=n)
	{
		d[wz]-=Min;
		int l=wz-1; int r=wz+1;
		while (l>=1&&d[l]!=0)
		{
			d[l]-=Min; l--;
		}
		while (r<=n&&d[r]!=0)
		{
			d[r]-=Min; r++;
		}
		ans+=Min; k=0; Min=INF;
		for (int i=1; i<=n; i++)
		{
			if (d[i]==0)
			 	k++;
			else	
				if (d[i]<Min&&d[i]!=0) 
				{
					Min=d[i]; wz=i;
				}
		}	
	}
	
	printf("%lld",ans);
	fclose(stdin);fclose(stdout);
	return 0;
} 
