#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=105,M=25010;

typedef long long LL;

int T,n,a[N],f[M],ans;

char c;

int read()
{
	int x=0,sig=1;
	for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') sig=-1;
	for (;c>='0' && c<='9';c=getchar()) x=x*10+c-48;
	return x*sig;
}

void work()
{
	n=read();
	ans=0;
	memset(f,0,sizeof(f));
	for (int i=0;i<n;i++)
	{
		a[i]=read(); f[a[i]]=1;
	}
	for (int i=0;i<n;i++)
	{
		for (int j=a[i];j<M;j++) if (f[j-a[i]]) f[j]=max(f[j],f[j-a[i]]+1);
	}
	for (int i=1;i<M;i++) if (f[i]==1) ans++;
	printf("%d\n",ans);
}

int main()
{
	freopen("money.in","r",stdin); freopen("money.out","w",stdout);
	for (T=read();T--;work());
	return 0;
}
