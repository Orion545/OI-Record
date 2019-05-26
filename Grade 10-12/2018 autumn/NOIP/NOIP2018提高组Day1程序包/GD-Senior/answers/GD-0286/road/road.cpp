#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100010;
int d[maxn];
void cut(int i,int j,int val)
{
	for (int k=i;k<=j;++k) d[k]-=val;
	return;
}
inline int read()
{
	int flag=1,f=0;
	char c=getchar();
	while (c<'0'||c>'9') 
	{
		if (c=='-') flag=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9') 
	{
		f=f*10+c-'0';
		c=getchar();
	}
	return flag*f;
}
int main()
{
	int n,m;
	long long ans=0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for (int i=1;i<=n;++i) d[i]=read();
	bool v=0;
	while (!v)
	{
		m=0x7fffffff;
		int i=1,cnt=0;
		v=1;
		while (i<=n)
		{
			if (d[i]!=0)
			{
				++cnt; 
				m=min(d[i],m);
			}
			else 
			if (cnt!=0) v=0,ans+=m,cut(i-cnt,i-1,m),cnt=0,m=0x7fffffff;
			++i;
		} 
		if (cnt!=0) v=0,ans+=m,cut(i-cnt,i-1,m),cnt=0,m=0x7fffffff;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
