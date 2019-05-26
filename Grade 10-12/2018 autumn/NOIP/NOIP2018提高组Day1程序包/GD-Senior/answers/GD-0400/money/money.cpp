#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=110;
int t,n,a[maxn];
int sum[10010],cnt;
int sign=1;

int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

void clear()
{
	memset(a,0,sizeof(a));
	sign=1;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	while(t--)
	{
		clear();
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		sort(a+1,a+n+1);
		if(n==2)
		{
			int flag=0;
			for(int i=1;(i*a[1]<=a[2]);i++)
			{
				int op=i*a[1];
				if(op==a[2])
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				n--;
				printf("%d\n",n);
			}
			else
			{
				printf("%d\n",n);
			}
		}
		else if(n==3)
		{
			int flag=0;
			int as1=0,as2=0;
			while(as1*a[1]<a[2])
			{
				as1++;
			}
			for(int i=1;i<=as1;i++)
			{
				if(i*a[1]==a[2])
				{
					n--;
					break;
				}
			}
			as1=0;
			while(as1*a[1]<=a[3])
			{
				as1++;
			}
			while(as2*a[2]<=a[3])
			{
				as2++;
			}
			for(int i=0;i<=as1;i++)
			{
				for(int j=0;j<=as2;j++)
				{
					int qwe=i*a[1]+j*a[2];
					if(qwe==a[3])
					{
						flag=1;
						break;
					}
				}
				if(flag==1)
				{
					break;
				}
			}
			if(flag==1)
			{
				n--;
				printf("%d\n",n);
			}
			else
			{
				printf("%d\n",n);
			}
		}
		else if(n==4)
		{
			int flag=0;
			int as1=0,as2=0,as3=0;
			while(as1*a[1]<=a[4])
			{
				as1++;
			}
			while(as2*a[2]<=a[4])
			{
				as2++;
			}
			while(as3*a[3]<=a[4])
			{
				as3++;
			}
			for(int i=1;i<=as1;i++)
			{
				if(i*a[1]>a[2])
					break;
				if(i*a[1]==a[2])
				{
					n--;
					break;
				}
			}
			for(int i=0;i<=as1;i++)
			{
				for(int j=0;j<=as2;j++)
				{
					int qwe=i*a[1]+j*a[2];
					if(qwe>a[3])
						break;
					if(qwe==a[3])
					{
						flag=1;
						n--;
						break;
					}
				}
				if(flag==1)
				{
					break;
				}
			}
			for(int i=0;i<=as1;i++)
			{
				for(int j=0;j<=as2;j++)
				{
					for(int k=0;k<=as3;k++)
					{
						int qwe=i*a[1]+j*a[2]+k*a[3];
						if(qwe>a[4])
							break;
						if(qwe==a[4])
						{
							n--;
							flag=1;
						}
					}
					if(flag==1)
						break;
				}
				if(flag==1)
					break;
			}
			printf("%d\n",n);
		}
		else if(n==5)
		{
			int flag=0;
			int as1=0,as2=0,as3=0,as4=0;
			while(as1*a[1]<=a[5])
			{
				as1++;
			}
			while(as2*a[2]<=a[5])
			{
				as2++;
			}
			while(as3*a[3]<=a[5])
			{
				as3++;
			}
			while(as4*a[4]<=a[5])
			{
				as4++;
			}
			for(int i=1;i<=as1;i++)
			{
				if(i*a[1]>a[2])
					break;
				if(i*a[1]==a[2])
				{
					n--;
					break;
				}
			}
			for(int i=0;i<=as1;i++)
			{
				for(int j=0;j<=as2;j++)
				{
					int qwe=i*a[1]+j*a[2];
					if(qwe>a[3])
						break;
					if(qwe==a[3])
					{
						flag=1;
						n--;
						break;
					}
				}
				if(flag==1)
				{
					break;
				}
			}
			for(int i=0;i<=as1;i++)
			{
				for(int j=0;j<=as2;j++)
				{
					for(int k=0;k<=as3;k++)
					{
						int qwe=i*a[1]+j*a[2]+k*a[3];
						if(qwe>a[4])
							break;
						if(qwe==a[4])
						{
							n--;
							flag=1;
						}
					}
					if(flag==1)
						break;
				}
				if(flag==1)
					break;
			}
			for(int i=0;i<=as1;i++)
			{
				for(int j=0;j<=as2;j++)
				{
					for(int k=0;k<=as3;k++)
					{
						for(int h=0;h<=as4;h++)
						{
							int qwe=i*a[1]+j*a[2]+k*a[3]+h*a[4];
							if(qwe>a[5])
								break;
							if(qwe==a[5])
							{
								n--;
								flag=1;
							}
						}
						if(flag==1)
							break;
					}
					if(flag==1)
						break;
				}
				if(flag==1)
					break;
			}
			printf("%d\n",n);
		}
		else
			printf("%d\n",n);
	}
	return 0;
}
