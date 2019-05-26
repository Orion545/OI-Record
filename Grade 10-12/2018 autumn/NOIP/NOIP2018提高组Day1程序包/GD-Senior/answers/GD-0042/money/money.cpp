#include<cstdio>
#include<cstring>
using namespace std;
int T,i,j,n;
int a[110],f[30000];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	for(scanf("%d",&T);T;--T)
	{
		memset(f,0,sizeof(f)),f[0]=1;
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			if(!f[a[i]]) f[a[i]]=2;
			for(j=a[i]+1;j<30000;++j)
				if(f[j-a[i]]) f[j]=1;
		}
		for(i=1,j=n;i<=n;++i)
			if(f[a[i]]^2) --j;
		printf("%d\n",j);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
