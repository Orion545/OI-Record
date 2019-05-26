#include <cstdio>
#include <algorithm>
using namespace std;
const int N=105;
const int M=25005;
int t;
int n,ans;
int a[N],mv;
int d[M],dv,dx,dj,nx;
int gcd(int a,int b)
{
	if (a%b==0)
		return b;
	return gcd(b,a%b);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		mv=M;
		ans=1;
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		mv=a[1];
		for (int i=1;i<mv;i++)
			d[i]=-1;
		d[0]=0;
		for (int i=2;i<=n;i++)
		{
			dv=a[i]/mv;
			dx=a[i]%mv;
			if (dv>=d[dx]&&d[dx]!=-1)
				continue;
			ans++;
			if (dx==0)
				dj=mv;
			else
				dj=gcd(dx,mv);
			for (int j=0;j<dj;j++)
			{
				int k=j;
				do
				{
					nx=(k+dx)%mv;
					if (d[k]!=-1)
						if (d[nx]==-1||d[k]+dv+(k+dx>=mv)<d[nx])
							d[nx]=d[k]+dv+(k+dx>=mv);
					k=nx;
				}
				while (k!=j);
				do
				{
					nx=(k+dx)%mv;
					if (d[k]!=-1)
						if (d[nx]==-1||d[k]+dv+(k+dx>=mv)<d[nx])
							d[nx]=d[k]+dv+(k+dx>=mv);
					k=nx;
				}
				while (k!=j);
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
