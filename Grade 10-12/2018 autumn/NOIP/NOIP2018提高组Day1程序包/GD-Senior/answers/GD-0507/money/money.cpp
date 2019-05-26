#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
const int N=110,M=25010;
int a[N],f[M];
int T,n;
inline int read()
{
	char ch=getchar();int x=0,f=0;
	for(; ch<'0'||ch>'9' ;ch=getchar())	if(ch=='-')	f=1;
	for(;'0'<=ch&&ch<='9';ch=getchar())	x=(x<<3)+(x<<1)+(ch^48);
	return f?-x:x;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while(T--)
	{
		memset(f,0,sizeof f);
		n=read();
		for(int i=1;i<=n;i++)	a[i]=read();
		sort(a+1,a+n+1);
		int cnt=0; f[0]=1;
		for(int i=1;i<=n;i++)
		{
			if(!f[a[i]])
			{
				cnt++;
				for(int j=0;j+a[i]<=a[n];j++)
					if(f[j])	f[j+a[i]]=1;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
