#include<cstdio>
using namespace std;
int t,n,ans;
int a[100];

inline int read()
{
	int s=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {s=s*10+ch-48;ch=getchar();}
	return s;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	while (t--)
	{
		n=read();
		ans=0;
		for (int i=1;i<=n;i++)
			a[i]=read();
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (i!=j&&a[i]%a[j]==0)
					a[i]=0;
		for (int i=1;i<=n;i++)
			if (a[i])
				for (int j=1;j<=n;j++)
					if (a[j]&&a[i]>a[j])
					{
						int p=a[i]%a[j];
						for (int k=1;k<=n;k++)
							if (a[k]&&p%a[k]==0)
								a[i]=0;
					}	
		for (int i=1;i<=n;i++)
			if (a[i])
				ans++;
			else
				a[i]=0;
		printf("%d\n",ans);
	}
	return 0;
}
