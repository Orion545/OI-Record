#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
inline ll lread()
{
	ll x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
const int N=1e2+10;
int n;
int a[N];
bool v[N];
int now=0;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	for(int ti=1;ti<=T;ti++)
	{
		n=read(); 
		if(n==2)
		{
			for(int i=1;i<=n;i++) a[i]=read();
			sort(a+1,a+n+1);
			memset(v,false,sizeof(v));
			int ans=n;
			if(a[1]!=1)
			{
				for(int i=2;i<=a[1];i++)
				{
					if(a[1]%i==0 && a[2]%i==0)
					{
						ans=1;
					}
				}
				printf("%d\n",ans);
			}
			else printf("1\n");
		}
		
	}
	return 0;	
}
