#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=100010,M=19;

typedef long long LL;

int n,a[N],mi[M][N],D[N][3],tot,L[N],ans;

char c;

int read()
{
	int x=0,sig=1;
	for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') sig=-1;
	for (;c>='0' && c<='9';c=getchar()) x=x*10+c-48;
	return x*sig;
}

int Getmin(int l,int r)
{
	int k=L[r-l+1];
	return (a[mi[k][l]]<a[mi[k][r-(1<<k)+1]])?mi[k][l]:mi[k][r-(1<<k)+1];
}

int main()
{
	freopen("road.in","r",stdin); freopen("road.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) mi[0][i]=i,a[i]=read();
	for (int i=2,j=1;i<N;j++,i<<=1) L[i]=j;
	for (int i=3;i<N;i++) if (!L[i]) L[i]=L[i-1];
	for (int j=1;j<M;j++)
		for (int i=1;i<=n-(1<<j)+1;i++)
			mi[j][i]=(a[mi[j-1][i]]<a[mi[j-1][i+(1<<j-1)]])?mi[j-1][i]:mi[j-1][i+(1<<j-1)];
	D[tot=1][0]=1; D[1][1]=n; D[1][2]=0;
	for (int i=1,l,r,la,x;i<=tot;i++)
	{
		l=D[i][0]; r=D[i][1]; la=D[i][2];
		x=Getmin(l,r);
		//if (a[x]<la) printf("%d %d %d %d\n",l,r,a[x],la);
		ans+=a[x]-la;
		if (l<x)
		{
			D[++tot][0]=l; D[tot][1]=x-1; D[tot][2]=a[x];
		}
		if (x<r)
		{
			D[++tot][0]=x+1; D[tot][1]=r; D[tot][2]=a[x];
		}
	}
	printf("%d\n",ans);
	return 0;
}
