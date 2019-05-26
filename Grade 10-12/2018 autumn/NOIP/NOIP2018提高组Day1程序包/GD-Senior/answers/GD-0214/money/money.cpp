#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char ch;
void read(int&n)
{
	for(ch=getchar();ch<'0' || ch>'9';ch=getchar());
	for(n=0;'0'<=ch && ch<='9';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
}
const int N=103;
int n,a[N],T,ans,t,m;
bool bz[N*250];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	for(read(T);T;T--)
	{
		read(n);ans=0;
		for(int i=1;i<=n;i++)read(a[i]);
		sort(a+1,a+1+n);m=a[n]+1;
		memset(bz,0,sizeof(bz));
		bz[0]=1;
		for(int i=1;i<=n;i++)
			if(!bz[a[i]])
			{
				ans++;t=a[i];
				for(int j=t;j<m;j++)bz[j]=bz[j]|bz[j-t];
			}
		printf("%d\n",ans);
	}
	return 0;
}
