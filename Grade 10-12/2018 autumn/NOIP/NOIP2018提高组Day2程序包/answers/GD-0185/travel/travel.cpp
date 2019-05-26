#include<iostream>
#include<cstdio>
using namespace std;
int n,m,map[5001][5001],v[5001]={0},d[5001],a[5001],b[5001],z[5001];
void dfs(int x,int y)
{
	if(y==n)
	{
		int o=1;
		if(b[o]==0)
		{
			for(o=1;o<=n;o++)
				b[o]=a[o];
		}
		else
		{
			while(a[o]==b[o])
				o++;
			if(a[o]<b[o])
			{
				for(o=1;o<=n;o++)
				b[o]=a[o];
			}
		}
		
	}
	else
	{
		if(d[x]!=0&&d[x]!=x)
			dfs(d[x],y);
		for(int o=1;o<=n;o++)
		{
			if(map[x][o]!=0&&v[o]==0)
			{
				v[o]=1;d[o]=x;a[y+1]=z[o];
				dfs(o,y+1);
				v[o]=0;d[o]=0;
			}
		}
	}
	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i,j,x,y,k,l,p;
	cin>>n>>m;
	j=2;
	cin>>z[1]>>z[2];
	map[1][2]=1;
	map[2][1]=1;
	for(i=2;i<=m;i++)
	{
		cin>>x>>y;
		p=1;
		while(z[p]!=x&&p<=j)
			p++;
		if(z[p]!=x)
		{
			z[p]=x;
			j++;
		}
		k=p;p=1;
		while(z[p]!=y&&p<=j)
			p++;
		if(z[p]!=y)
		{
			z[p]=y;
			j++;
		}
		l=p;
		map[k][l]=1;
		map[l][k]=1;
	}
	for(i=1;i<=n;i++)
	{
		v[i]=1;d[i]=i;a[1]=z[i];
		dfs(i,1);
		v[i]=0;d[i]=0;
	}
	
	for(i=1;i<=n;i++)
	cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}
