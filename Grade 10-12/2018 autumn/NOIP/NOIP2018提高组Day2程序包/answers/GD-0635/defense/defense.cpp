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
const int N=1010;
const int M=1010;
struct edge
{
	int x,y,next;
}a[M*2]; int len,last[N];
int f[N][2];
int p[N];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
	}
	for(int ti=1;ti<=m;ti++)
	{
		int a=read(),x=read(),b=read(),y=read();
		memset(f,0x3f,sizeof(f)); f[0][1]=f[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			f[i][0]=f[i-1][1];
			f[i][1]=min(f[i-1][0],f[i-1][1])+p[i];
		}
		printf("%d\n",min(f[n][0],f[n][1]));
	}
	return 0;
}

