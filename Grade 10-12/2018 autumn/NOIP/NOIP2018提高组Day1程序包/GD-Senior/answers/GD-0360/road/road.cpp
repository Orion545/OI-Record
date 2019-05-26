#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn=100010;
int n,m,a[maxn],f[maxn][20];
typedef long long ll;
ll ans;

int rd()
{
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c))
		f=c=='-'?-1:1,c=getchar();
	while (isdigit(c))
		x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}

void init()
{
	memset(f,0x3f,sizeof(f));
	int i,j;
	for (i=1;i<=n;i++)
		f[i][0]=a[i];
	for (j=1;(1<<j)<=n;j++)
		for (i=1;i+(1<<j)-1<=n;i++)
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}

int st(int l,int r)
{
	int k=log(r-l+1)/log(2);
	return min(f[l][k],f[r-(1<<k)+1][k]);		//
}

void dfs(int l,int r,int val)
{
	if (l>r)
		return;
	int i,lt=l-1;
	int tmp=st(l,r);
	int k=tmp-val;
	ans+=(ll)tmp-(ll)val;
	for (i=l;i<=r;i++)
	{
		if (a[i]-tmp==0)
		{
			dfs(lt+1,i-1,val+k);
			lt=i;
		}
	}
	if (lt<r)
		dfs(lt+1,r,val+k);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j;
	n=rd();
	for (i=1;i<=n;i++)
		a[i]=rd();
	init();
	dfs(1,n,0);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
