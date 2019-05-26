#include<iostream>
#include<cstdio>
using namespace std;
int n,m,minn,l,r,a[5001][5001]={0},b[5001]={0},c[5001];
void search(int pp)
{
	for(int i=1;i<=n;i++)
	{
		if(a[pp][i]==1&&a[i][pp]==1)
		{
			if(c[i]==1)
			{
				printf(" %d",i);
				c[i]=0;
			}
			a[i][pp]=0;
			search(i);
			i=n;
		}
		else
			if(i==n)
				for(int j=1;j<=n;j++)
				{
					if(a[j][pp]==1||a[pp][j]==1)
					{
						a[j][pp]=0;
						a[pp][j]=0;
						search(j);
					}
				}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		c[i]=1;
		scanf("%d %d",&l,&r);
		a[l][r]=1;
		a[r][l]=1;
		b[l]++;
		b[r]++;
	}
	c[n]=1;
	printf("1");
	c[1]=0;
	search(1);
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
