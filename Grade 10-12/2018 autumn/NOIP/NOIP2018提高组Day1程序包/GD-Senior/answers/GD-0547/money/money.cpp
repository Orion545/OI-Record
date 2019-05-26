#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int t;
int n,ans;
int a[200];

int exgcd(int a,int b,int &x,int &y)
{
	if(b==0){x=1;y=0;return 1;}
	int g=exgcd(b,a%b,y,x);y=y-a/b*x;return g;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int i,j;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
//		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
		sort(a+1,a+n+1);
		if(n==2)
		{
			if(a[2]%a[1]==0)printf("1\n");
			else printf("2\n");
			continue;
		}
		if(n==3)
		{
			bool flag=0;
			if(a[2]%a[1]==0)
			{
				n--;
				if(a[3]%a[1]==0)
				{
					printf("1\n");
					continue;
				}
				else
				{
					printf("2\n");
					continue;	
				}
			}
			else
			if(a[3]%a[1]==0 || a[3]%a[2]==0)
			{
				printf("2\n");
				continue;
			}
//			cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
			for(i=1;i<=a[3]/a[1];i++)
				for(j=1;j<=a[3]/a[2];j++)
				{
					if(i*a[1]+j*a[2]==a[3])flag=1;
//					cout<<i*a[i]+j*a[2]<<endl;
				}
			if(flag)printf("2\n");	
			else printf("3\n");
		}
		if(n==4)
		{
			bool flag=1;
			int ans=4;
			for(i=0;i<=a[2]/a[1];i++)
				{
					if(i*a[1]==a[2] &&flag)ans--,flag=0;
				}
			flag=1;
			for(i=0;i<=a[3]/a[1];i++)
				for(j=0;j<=a[3]/a[2];j++)
				{
					if(i*a[1]+j*a[2]==a[3] && flag)ans--;
				}
			flag=1;
			for(i=0;i<=a[4]/a[1];i++)
				for(j=0;j<=a[4]/a[2];j++)
					for(int k=0;k<=a[4]/a[3];k++)
					{
						if(i*a[1]+j*a[2]+k*a[3]==a[4] && flag)ans--,flag=0;
					}
			 printf("%d\n",ans);
		}
		if(n==4)
		{
			bool flag=1;
			int ans=5;
			for(i=0;i<=a[2]/a[1];i++)
				{
					if(i*a[1]==a[2] &&flag)ans--,flag=0;
				}
			flag=1;
			for(i=0;i<=a[3]/a[1];i++)
				for(j=0;j<=a[3]/a[2];j++)
				{
					if(i*a[1]+j*a[2]==a[3] && flag)ans--;
				}
			flag=1;
			for(i=0;i<=a[4]/a[1];i++)
				for(j=0;j<=a[4]/a[2];j++)
					for(int k=0;k<=a[4]/a[3];k++)
					{
						if(i*a[1]+j*a[2]+k*a[3]==a[4] && flag)ans--,flag=0;
					}
					flag=1;
			for(i=0;i<=a[5]/a[1];i++)
				for(j=0;j<=a[5]/a[2];j++)
					for(int k=0;k<=a[5]/a[3];k++)
					for(int l=0;l<=a[5]/a[4];l++)
					{
						if(i*a[1]+j*a[2]+k*a[3]+l*a[4]==a[5] && flag)ans--,flag=0;
					}
			 printf("%d\n",ans);
		}
	}
}
