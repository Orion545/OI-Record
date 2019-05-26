#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAXN = 109,
		  MAXV = 25000;

int v,n,ans;
bool f[MAXV+9];
int a[MAXN];

bool _cmp(int a,int b) {return a<b;}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=0;
	scanf("%d",&T);
	for (int cn=1;cn<=T;cn++)
	{
		scanf("%d",&n);
		ans=n;
		memset(f,0,sizeof f);
		f[0]=1;
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n,_cmp);
		for (int i=0;i<n;i++)
		{
			v=a[i];
			if (f[v])
			{
				ans--;
				continue;
			}
			for (int i=0;i+v<=MAXV;i++)
				if (f[i])
					f[i+v]=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
