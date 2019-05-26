#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

const int maxn=2000;
const int INF=200000;

int a[maxn];
int b[maxn];

int v[INF];

int n,m;
int bb;

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		m=0;
		memset(b,0,sizeof(b));
		memset(v,0,sizeof(v));
		v[0]=1;
		for (int i=1;i<=n;i++)
		{
			int f=1;
			for (int j=1;j<=n;j++)
			{
				if (i==j) continue;
				if (a[i]%a[j]==0)
				{
					f=0;
					break;
				}
			}
			if (f) b[++m]=a[i];
		}
		sort(b+1,b+m+1);
		bb=b[m];
		for (int i=1;i<=m;i++)
		{
			for (int j=b[i];j<=bb;j+=b[i])
				v[j]=1;
			v[b[i]]=2;
		}
		for (int i=1;i<=bb;i++)
		{
			for (int j=1;j<i;j++)
				if ((v[j])&&(v[i-j]))
				{
					v[i]=1;
					break;
				}
		}
		int ans=0;
		for (int i=1;i<=m;i++)
		{
			if (v[b[i]]==1) ans++;
		}
		printf("%d\n",m-ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
