#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[107],tmp[107],cnt,f[25007];

inline bool cmp(const int& a,const int& b)
{
	return a<b;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(f,0,sizeof(f));
		scanf("%d",&n); cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
		    int fg=0;
			for(int j=1;j<i;j++) if(a[i]%a[j]==0) fg=1;
			if(fg) continue;
			for(int w=1;w<=a[i-1];w++)
			{
				for(int k=0;k*tmp[cnt]<=w && !f[w];k++) f[w]|=f[w-k*tmp[cnt]];
			}
			for(int w=a[i-1];w<=a[i];w++)
			{
				for(int j=1;j<=cnt && !f[w];j++)
				{
					for(int k=0;k*tmp[j]<=w && !f[w];k++)
					{
						f[w]|=f[w-k*tmp[j]];
					}
				}
			}
			if(f[a[i]]) continue;
			tmp[++cnt]=a[i]; f[a[i]]=1;
		}
		printf("%d\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
