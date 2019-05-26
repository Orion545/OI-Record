#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,num[150],v[150]={0},ans;
bool yy=false;
int cmp(int x,int y)
{
	if(x<y)return 1;
	if(x>y)return 0;
}
void f(int xx,int m,int c)
{
	if(m==0) yy=true;
	if(m>0)
	for(int i=c;i<xx;i++)
	{
		if(v[i]==1)
		{
			int k=num[xx]/num[i];
			for(int j=1;j<=k;j++)
			{
				f(xx,m-num[i]*j,i+1);
				if(yy)break;
			}
		}	
		if(yy)break;
	}
}
void dfs(int x,int y)
{
	if(x==n+1&&y<ans)
	{
		ans=y;
	}
	else if(x<=n)
	{
		yy=false;
		f(x,num[x],1);
		if(yy)dfs(x+1,y);
		else 
		{
			v[x]=1;
			dfs(x+1,y+1);
		}
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		ans=n;
		for(int j=1;j<=n;j++)
			cin>>num[j];
		sort(num+1,num+n+1,cmp);
		v[1]=1;
		dfs(2,1);
		cout<<ans<<'\n';
	}
	return 0;
}
