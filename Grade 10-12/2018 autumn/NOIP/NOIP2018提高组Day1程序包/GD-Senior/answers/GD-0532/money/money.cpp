#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
	int f[27010],Tm,a[111],t[27010];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&Tm);
		while(Tm--)
			{
				int i,j,mx=0,mn=299999,n;
				memset(f,0,sizeof(f));
				memset(t,0,sizeof(t));
				scanf("%d",&n);
				int ans=n;
					for(i=1;i<=n;++i)
						{
							scanf("%d",&a[i]);
								mn=min(a[i],mn);
								mx=max(a[i],mx);
							t[a[i]]=1;
						}
					f[0]=1;
					for(i=mn;i<=mx;++i)
						for(j=1;j<=n;++j)
							{
								if(a[j]>i) continue;
									f[i]=f[i] || f[i-a[j]];
									if((f[i-a[j]]!=0) && (i!=a[j]) && (t[i]!=0))
										{
											--ans;
											break;
										}
							}
					printf("%d\n",ans);
			}
		return 0;
}
