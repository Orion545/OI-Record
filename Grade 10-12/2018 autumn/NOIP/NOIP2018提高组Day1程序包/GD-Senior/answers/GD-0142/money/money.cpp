#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define LL long long
#define fo(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,T,a[1010],m,ret;
bool b[25010];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(b,0,sizeof(b));
		n=read();
		ret=n;
		fo(i,1,n)a[i]=read();
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		sort(a+1,a+n+1);
		fo(i,1,n)
		{
			if(b[a[i]])
			{
				ret--;
				continue;
			}
			b[a[i]]=1;
			fo(j,a[i]+1,a[n])
			{
				b[j]=(b[j]||b[j-a[i]]);
			}
		}
		cout<<ret<<endl;
	}
	return 0;
}
