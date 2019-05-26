#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char s=getchar();
	while(s>'9'||s<'0')
	{
		if(s=='-') f=-1;
		s=getchar();
	}
	while(s<='9'&&s>='0') x=x*10+s-48,s=getchar();
	return x*f;
}
int a[110],ff[110];
bool f[55001];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t=read();
	while(t--)
	{
		int n=read(),maxx=0;
		for(int i=1;i<=n;i++) a[i]=read(),maxx=max(maxx,a[i]);
		sort(a+1,a+n+1);
		int ans=1;ff[1]=a[1];
		memset(f,0,sizeof(f));f[0]=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=ff[ans];j<=maxx;j++) {if(f[j-ff[ans]]) f[j]=1;}
			if(!f[a[i]]) ff[++ans]=a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
