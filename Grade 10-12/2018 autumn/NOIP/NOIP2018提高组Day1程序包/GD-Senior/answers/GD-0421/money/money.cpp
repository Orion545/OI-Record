#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int T;
int n,a[105];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		if(n==2 || n==4)
		{
			puts("2");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			a[i] = read();
			if(a[i] == 1)
				puts("2");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
