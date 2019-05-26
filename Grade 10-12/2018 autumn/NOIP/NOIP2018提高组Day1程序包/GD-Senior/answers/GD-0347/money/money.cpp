#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,a[110],vis[110],cnt;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.ans","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		cnt=1;
		for (int i=1;i<=105;++i) a[i]=0;
		for (int i=1;i<=105;++i) vis[i]=0;
		vis[1]=1;
		
		scanf("%d",&n);
		for (int i=1;i<=n;++i) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		if (a[1]==1) printf("1\n");
		else 
		{
			for (int i=2;i<=n;++i)
			{
				int flag=0;
				for (int j=1;j<=n;++j)
				if (vis[j] && a[i]%a[j]==0) flag=1;
				if (cnt==1)
				{
					if (!flag) cnt++,vis[i]=1;
					continue;
				}
				int ff=0;
				for (int j=1;j<=n;++j)
				{
					if (ff) break;
					for (int k=j+1;k<=n;++k) if(vis[j] && vis[k])
					{
						int kk=a[j]*a[k]-a[j]-a[k];
						if (a[i]>kk) {ff=1;break;}
						int tmp=a[i];
						while(tmp>=0)
						{
							if (tmp%a[j] == 0) ff=1;
							tmp-=a[k];
						}
					}
				}
				if (ff) continue;
				if (flag) continue;
				++cnt;
				vis[i]=1;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}
