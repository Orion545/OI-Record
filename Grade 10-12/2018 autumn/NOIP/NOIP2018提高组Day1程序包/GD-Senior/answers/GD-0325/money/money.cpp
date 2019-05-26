#include<iostream>
#include<cstdio>
#include<fstream>
	using namespace std;
	int a[105],f[30005],s[30005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=0;
	scanf("%d",&T);
	for(int G=1;G<=T;G++)
	{
		int n=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=0;i<=30000;i++) f[i]=s[i]=0;
		f[0]=1;
		for(int i=1;i<=n;i++)
			for(int j=a[i];j<=30000;j++)
				if(f[j-a[i]])
				{
					f[j]=1;
					if(j!=a[i]) s[j]=1;
				}
		int ans=n;
		for(int i=1;i<=n;i++)
			if(s[a[i]]) ans--;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
