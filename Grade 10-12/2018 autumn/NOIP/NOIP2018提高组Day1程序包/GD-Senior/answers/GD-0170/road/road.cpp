#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#define M 100005
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
int n;
int f[M][21];
int maxn;
long long ans;
void work(int x,int y,int res)
{
	for (int i=x;i<=x+(1<<y)-1;i++)
		f[i][0]-=res;
	for (int j=1;j<=maxn;j++)
		for (int i=1;i<=n;i++)
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	int m=0,pos;
	for (int i=1;i<=n;i++)
	{
		read(f[i][0]);
		if (f[i][0]>m)
		{
			pos=i;
			m=f[i][0];
		}
	}
	maxn=floor(log(n)/log(2));
	for (int j=1;j<=maxn;j++)
		for (int i=1;i<=n;i++)
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	while (f[pos][0])
	{
		bool flag=0;
		for (int j=maxn;j>=0;j--)
		{
			for (int i=1;i+(1<<j)-1<=n;i++)
			{
				if (f[i][j]>0)
				{
					ans+=f[i][j];			
					work(i,j,f[i][j]);
					flag=1;
					break;
				}
			}
			if (flag==1)
				break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

