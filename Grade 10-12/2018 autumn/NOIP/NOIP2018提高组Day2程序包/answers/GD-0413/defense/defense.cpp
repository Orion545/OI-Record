#include<cstdio>
#include<algorithm>
using namespace std;
long long p[100001],f[100001];
int Head[100001],Next[200001],To[200001],t;
void add(int a,int b)
{
	Next[++t]=Head[a];
	Head[a]=t;
	To[t]=b;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,a,b,x,y;
	char q;
	scanf("%d %d %c %d",&n,&m,&q,&y);
	for (int i=1;i<=n;i++) scanf("%lld",&p[i]);
	for (int i=1;i<n;i++)
	{
		scanf(" %d %d",&a,&b);
		add(a,b); add(b,a);
	}
	if (q=='A')
		while (m--)
		{
			scanf("%d %d %d %d",&a,&x,&b,&y);
			if (!x && !y && (a==b+1 || b==a+1)) printf("-1\n");
			else
			{
				if ((a==1 && !x) || (b==1 && !y)) f[1]=2e10;
				else f[1]=p[1];
				for (int i=2;i<=n;i++)
				{
					if (i==a+1 && x) f[i]=f[i-1]+p[i];
					else if (i==a && !x) f[i]=2e10;
					else if (i==b+1 && y) f[i]=f[i-1]+p[i];
					else if (i==b && !y) f[i]=2e10;
					else f[i]=min(f[i-1],f[i-2])+p[i];
				}
				if ((a==n && x) || (b==n && y))printf("%lld\n",f[n]);
				else printf("%lld\n",min(f[n],f[n-1]));
			}
		}
	fclose(stdin); fclose(stdout);
	return 0;
}
