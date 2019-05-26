#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 120
using namespace std;
int tot,n,T;
int b[N],a[N];
bool fla;
bool cmp(int x,int y)
{
	return x<y;
}
void ck(int k,int dep)
{
	if (dep==tot)
	{
		if ((k%b[dep])==0) fla=1;
		return;
	}
	for (int i=k/b[dep];i>=0;i--)	ck(k-i*b[dep],dep+1);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T)
	{
		T--;		//tot=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)	scanf("%d",&a[i]);
		sort(a+1,a+n+1,cmp);
		b[1]=a[1];	tot=1;
		for (int i=2;i<=n;i++)
		{
			bool fl=0;	fla=0;
			for (int j=1;j<=tot;j++)	if ((a[i]%b[j])==0)	fl=1;
			if (fl)	continue;
			ck(a[i],1);	if (fla==0)	b[++tot]=a[i];
		}
		printf("%d\n",tot);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
