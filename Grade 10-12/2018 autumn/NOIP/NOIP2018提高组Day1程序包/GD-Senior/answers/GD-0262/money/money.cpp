#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
#define LL long long

const int maxn=25007;

using namespace std;

int T,n,m,ans;
int a[maxn];
int f[maxn];

struct rec{
	int num,x;
};

bool operator <(rec a,rec b)
{
	return a.x>b.x;
}

priority_queue <rec> q;

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		m=a[1];
		for (int i=0;i<m;i++) f[i]=maxn;
		f[0]=0;
		ans=n;
		for (int i=2;i<=n;i++)
		{
			if (f[a[i]%m]<=a[i]) ans--;
			else
			{
				for (int j=0;j<m;j++)
				{
					if (f[j]+a[i]<maxn) q.push((rec){j,f[j]});
				} 
				while (!q.empty())
				{
					rec d=q.top();
					q.pop();
					int x=d.num,y=(d.num+a[i])%m;
					if (f[x]+a[i]<f[y])
					{
						f[y]=f[x]+a[i];
						if (f[y]+a[i]<maxn) q.push((rec){y,f[y]});
					}
				}
			}
		}
		printf("%d\n",ans);
    }
}
