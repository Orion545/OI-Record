#include<cstdio>
const int maxp=256*256-250;
using namespace std;
int x[110]={0},t,n;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&x[i]);
		}
		bool fv[maxp+1000]={0};
		fv[0]=1;
		for (int i=0;i<=maxp;i++)
		{
			if (fv[i])
			{
				for (int j=1;j<=n;j++)
					fv[i+x[j]]=true;
			}
		}
		int ans=n;	
		for (int w=1;w<(1<<n)-1;w++)
		{
			int nowans=0;
			for (int i=1;i<=n;i++)
				if ((1<<(i-1))&w) 
					nowans++;
			if (nowans>=ans) continue;
			bool fn[maxp+1000]={0},ck=true;fn[0]=1;
			for (int i=0;i<=maxp;i++)
			{
				if (fn[i])
				{
					for (int j=1;j<=n;j++)
					{ 
						if ((1<<(j-1))&w)
							fn[i+x[j]]=true;
					}
				}
			}
			for (int i=0;i<=maxp;i++) if (fn[i]!=fv[i]) 
			{
				ck=false;
				break;
			}
			if (ck) ans=nowans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
