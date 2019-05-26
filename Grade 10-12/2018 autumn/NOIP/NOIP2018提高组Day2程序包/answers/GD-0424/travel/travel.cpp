#include<iostream>
#include<cstdio>
using namespace std;
int fa[100001];
int a[5002][5002]={0};
int cnt=0;
int b[100001];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		fa[y]=x;
		a[x][y]=1;
		a[y][x]=1;
	}
	int k=1;
	if(n!=m)
	{
		while(cnt<=n)
	{
		int flag=0;
		for(int i=k;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==1)
			{
				a[i][j]=0;
				a[j][i]=0;
				k=j;
				b[++cnt]=i;
				flag=1;
				break;
			}
		}
		if(flag==1) continue;
		else 
		{
			while(a[fa[k]][k]==0) k=fa[k];
		}
	}
	}
	else 
	{
		int cnt=1;
		b[1]=1;
		for(int i=1;i<=n;i++)
	      for(int j=1;j<=n;j++)
	      {
	      	if(i<=j)
	      	{
	      		if(a[i][j]==1) b[++cnt]=j;
	      	}
	      }
	}
	for(int i=1;i<=n;i++)
	cout<<b[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
