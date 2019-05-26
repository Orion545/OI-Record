#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int a[102];
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int main()
{
	freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
	int t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int l=1;l<=n;l++)
				{if(l==i||l==j)continue;
				for(int k=0;k<=100;k++)
				{
					for(int h=0;h<=100;h++)
					{
						if(k*a[i]+h*a[j]==a[l])
						{
							a[l]=a[n];
							n--;
							h=101;
							k=101;
						}
					}
				}
			    }
			}
		}
		printf("%d\n",n);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
