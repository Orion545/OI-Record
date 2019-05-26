#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=105;
const int M=25005;

int n,a[N];
bool f[M];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while (T--)
	{
		n=read();int mx=0;
		for (int i=1;i<=n;i++) a[i]=read(),mx=std::max(mx,a[i]);
		std::sort(a+1,a+n+1);
		for (int i=0;i<=mx;i++) f[i]=0;
		f[0]=1;
		int ans=n;
		for (int i=1;i<=n;i++)
		{
			if (f[a[i]]) {ans--;continue;}
			for (int j=a[i];j<=mx;j++) f[j]|=f[j-a[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
}
