#include<cstdio>
#include<algorithm>
using namespace std;
int a[200000];
int f[200000][3];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	char s[10];
	scanf("%d%d%s",&n,&m,s);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1,x,y;i<=n-1;++i) scanf("%d%d",&x,&y);
	for(int i=1,x1,y1,x2,y2;i<=m;++i)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if((x1+1==x2||x1-1==x2)&&y1==y2&&y1==0) printf("-1\n");
		else
		for(int j=1;j<=n;++j)
		{
				f[j][1]=f[j-1][2]+a[j];
				f[j][2]=f[j-1][1];
				if(j==x1) 
				{
					if(y1==0) f[j][1]=f[j][1]-a[j]+a[j-1];
					else  f[j][2]=f[j][2]+a[j];
				}
				if(j==x2)
				{
					if(y2==0) f[j][1]=f[j][1]-a[j]+a[j-1];
					else f[j][2]=f[j][2]+a[j];
				}
		}
		int ans=min(f[n][1],f[n][2]);
		printf("%d\n",ans);
	}
	return 0;
}
