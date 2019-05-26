#include<iostream>//针对A型 
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#define MAXN 100000+10
using namespace std;
int a[MAXN],n,m,r[MAXN],x,xx,y,yy,u,v;
int sum[2]={0},q[2]={0};
string s;
int main()
{
	freopen("defence.in","r",stdin);
	freopen("defence.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<n;++i)
		scanf("%d%d",&u,&v);
	for(int i=1;i<=n;i+=2)
		sum[0]+=a[i];//奇数位置的代价和 
	for(int i=2;i<=n;i+=2)
		sum[1]+=a[i];//偶数位置 
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d%d",&x,&xx,&y,&yy);
		if(xx==0&&yy==0)
		{
			if(abs(x-y)%2==1)
			{
				cout<<-1<<endl;
				continue;
			}
			else
			if(x%2==0)
			{
				cout<<sum[0]<<endl;
				continue;
			}
		}
		if(xx==1&&yy==1)
		{
			if(abs(x-y)%2==0)
			{
				if(x%2==0)
				{
					cout<<sum[1]<<endl;
					continue;
				}
				else
				{
					cout<<sum[0]<<endl;
					continue;
				}
			}
			else
			{
				if(x>y)//x是小的数 
				{
					int tump=x;
					x=y;
					y=tump;
				}
				int total=0;
				for(int j=x;j>=1;j-=2)
					total+=a[j];
				for(int j=y;j<=n;j+=2)
					total+=a[j];
				cout<<total<<endl;
				continue;
			}
		}
		if(xx==1&&yy==0)
		{
			if(abs(x-y)%2==1)
			{
				if(x%2==1)
				{
					cout<<sum[0]<<endl;
					continue;
				}
				else
				{
					cout<<sum[1]<<endl;
					continue;
				}
			}
			else
			{
				if(x%2==1)
				{
					int total=sum[0]-a[y]+min(a[y-1],a[y]+1);
					cout<<total<<endl;
					continue;
				}
				else
				{
					int total=sum[1]-a[y]+min(a[y-1],a[y]+1);
					cout<<total<<endl;
					continue;
				}
			}
		}
		if(xx==0&&yy==1)
		{
			if(abs(x-y)%2==1)
			{
				if(x%2==1)
				{
					cout<<sum[1]<<endl;
					continue;
				}
				else
				{
					cout<<sum[0]<<endl;
					continue;
				}
			}
			else
			{
				if(x%2==1)
				{
					int total=sum[1]-a[x]+min(a[x-1],a[x+1]);
					cout<<total<<endl;
					continue;
				}
				else
				{
					int total=sum[0]-a[x]+min(a[x-1],a[x+1]);
					cout<<total<<endl;
					continue;
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
