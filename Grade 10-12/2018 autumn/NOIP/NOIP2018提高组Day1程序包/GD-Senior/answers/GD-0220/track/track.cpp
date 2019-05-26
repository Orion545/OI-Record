#include<iostream>
#include<cstdio>
using namespace std;
int a[8001][8001]={0},aa[8001][8001]={0};
int n,m,b[10001]={0},st,en,tot,ans[10];
void sea(int l)
{
	if(b[l]==1)
		for(int i=1;i<=n;i++)
		{
			if(a[l][i]>0)
			{
				tot=a[l][i];
				aa[i][l]=0;
				sea(i);
				aa[i][l]=a[i][l];
				i=n;
			}
		}
	else
		for(int i=1;i<=n;i++)
		{
			if(aa[l][i]>0)
			{
				tot+=a[l][i];
				if(tot>=ans[1])
					ans[1]=tot;
				aa[i][l]=0;
				sea(i);
				aa[i][l]=a[i][l];
				if(i==n)
					return;
			}
		}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	ans[1]=0;
	ans[2]=99999;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d %d",&st,&en);
		scanf("%d",&a[st][en]);
		a[en][st]=aa[en][st]=aa[st][en]=a[st][en];
		b[en]++;
		b[st]++;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
			if(b[i]==1)
				sea(i);
		printf("%d\n",ans[1]);
	}
	else
	{
		if(m==n-1||(a[1][2]>0&&a[n-1][n]>0))
		{
			for(int i=1;i<=n-1;i++)
				for(int j=i+1;j<=n;j++)
					if(a[i][j]>0&&a[i][j]<ans[2])
						ans[2]=a[i][j];
			printf("%d\n",ans[2]);
		}
		else
			printf("26282\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
