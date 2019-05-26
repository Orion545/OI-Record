#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
void read(int &x)
{
	x=0;
	char ch=getchar();
	while (ch<'0'||ch>'9')
		ch=getchar();
	while (ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
}
void exgcd(int a,int b,int &x,int &y)
{
	if (b==0)
	{
		x=1;
		y=0;
		return;
	}
	int x2,y2;
	exgcd(b,a%b,x2,y2);
	x=y2;
	y=x2-(a/b)*y2;
}
int a[105],b[105];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		if (n==1)
		{
			printf("1\n");
			continue;
		}
		for (int i=1;i<=n;i++)
			read(a[i]);
		sort(a+1,a+n+1);
		if (a[1]==1)
		{
			printf("1\n");
			continue;
		}
		int top=0;
		for (int i=1;i<=n;i++)
		{
			if (!a[i])
				continue;
			for (int j=i+1;j<=n;j++)
			{
				if (a[j]%a[i]==0)
					a[j]=0;
			}
			if (a[i])
				b[++top]=a[i];
		}
		int ans=top;
		for (int i=1;i<=top;i++)
		{
			if (!b[i])
				continue;
			for (int j=i+1;j<=top;j++)
			{
				if (!b[j])
					continue;
				for (int k=j+1;k<=top;k++)
				{
					if (b[k]<b[i]+b[j])
						continue;
					if (b[k]==b[i]+b[j])
					{
						b[k]=0;
						--ans;
						continue;
					}
					int x,y;
					exgcd(b[j],b[i],x,y);
					x=x*b[k],y=y*b[k];
					while (y-b[j]>0)
					{
						x=x+b[i];
						y=y-b[j];
					}
					while (x-b[i]>0)
					{
						x=x-b[i];
						y=y+b[j];
					}
					if (x>0&&y>0)
					{
						b[k]=0;
						--ans;
					}	
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

