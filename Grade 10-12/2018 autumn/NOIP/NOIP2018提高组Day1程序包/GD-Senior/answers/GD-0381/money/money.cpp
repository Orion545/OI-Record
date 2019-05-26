#include <bits/stdc++.h>
using namespace std;

int rea()
{
	int x=0, f=1;
	char ch=getchar();
	while (!(isdigit(ch) || ch=='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=x * 10 + ch - 48, ch=getchar();
	return x * f;
}

bool cmp(int x, int y)
{
	return x<y;
}

int T,n,a[200];
bool f[3000000];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=rea();
	while (T--)
	{
		n=rea();
		for (int i=1; i<=n; i++) a[i]=rea();
		if (n==1) {printf("1\n"); continue;}
		if (n==2)
		{
			if (a[1] % a[2] == 0 || a[2] % a[1] == 0) printf("1\n");
			else printf("2\n");
			continue;
		}
		sort(a+1,a+1+n,cmp);
		if (a[1]==1)
		{
			printf("1\n"); continue;
		}
		memset(f,0,sizeof(f)); f[0]=1;
		int sum=n;
		for (int i=1; i<=n; i++)
		{
			if (f[a[i]]) {sum--;continue;}
			else
			{
				for (int j=a[i]; j<=a[n]; j++)
				if (f[j-a[i]]) f[j]=1;
			}
		}
		printf("%d\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
