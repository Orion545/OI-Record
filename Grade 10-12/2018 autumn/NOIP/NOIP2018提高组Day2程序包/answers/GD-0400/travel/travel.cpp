#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=5001;
int n,m;
int a[maxn][maxn],f[maxn],ans[maxn],sum,fa[maxn];
int x,y;

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

void shuchu()
{
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	return;
}

int find(int num)
{
	int qq1=9999;
	for(int i=1;i<=a[num][0];i++)
	{
		if(f[a[num][i]]==0)
		{
			qq1=min(qq1,a[num][i]);
		}
	}
	return qq1;
}

void chuli(int num,int fath)
{
	if(sum==n)
	{
		shuchu();
		return;
	}
	if(a[num][0]==0)
	{
		//cout<<"YES";
		chuli(fath,fa[fath]);
	}
	int xiao;
	for(int i=1;i<=a[ans[sum]][0];i++)
	{
		xiao=find(ans[sum]);
	}
//	cout<<xiao<<endl;
	ans[++sum]=xiao;
	fa[xiao]=num;
	a[xiao][0]--;
	f[xiao]=1;
//	cout<<a[xiao][0]<<endl;
/*	for(int i=1;i<=n;i++)
		cout<<fa[i]<<" ";*/
//	cout<<xiao<<" "<<num<<endl;
 	chuli(xiao,fa[xiao]);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	if(n==m+1)
	{
		for(int i=1;i<=m;i++)
		{
			x=read();y=read();
			if(y!=1)
			{
				a[x][0]++;
				a[x][a[x][0]]=y;
			}
			if(x!=1)
			{	
				a[y][0]++;
				a[y][a[y][0]]=x;
			}
		}
		sum=1;
		ans[sum]=1;
		f[1]=1;
		fa[1]=0;
		while(a[ans[sum]][0]==1)
		{
			if(f[a[ans[sum]][1]]==0)
			{
				fa[a[ans[sum]][1]]=ans[sum];
				//cout<<a[ans[sum]][1]<<endl;
				sum++;
				ans[sum]=a[ans[sum-1]][1];
				f[a[ans[sum-1]][1]]=1;
				if(fa[ans[sum]]!=1)
				{
					a[sum][0]--;
				}
				//cout<<ans[1]<<" "<<ans[2]<<" "<<sum<<endl;
			}
			else
			{
				break;
			}
		}
	/*	for(int i=1;i<=n;i++)
			cout<<fa[i]<<" "<<endl;*/
		//cout<<ans[sum]<<" "<<fa[ans[sum]]<<endl;
		chuli(ans[sum],fa[ans[sum]]);
//		shuchu();
	}
	return 0;
}
