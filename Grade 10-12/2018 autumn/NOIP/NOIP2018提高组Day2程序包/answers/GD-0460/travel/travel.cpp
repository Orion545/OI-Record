#include<bits/stdc++.h>
using namespace std;
int r[5000][5000]={{32768}};bool c[5000]={false}; int d[50000]={0},k,n;
void find(int a)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(r[a][i]==1&&c[i]==false)
		{
			c[i]=true;
			d[k]=i;
			k++;
			find(a+1);
		}
		if(i==n)
		{
			a=d[k-1];
			a=d[k];
			k++;
		}
	}
	if(i==n) return;
}
int main()
{
	freopen("travel.in","r",stdin); freopen("travel.out","r",stdout);
	int m; cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		r[u][v]=1;
		r[v][u]=1;
	}
	c[1]=true;
	k=1;
	find(1);
	for(int i=1;i<=k;i++) cout<<d[k]; return 0;
	fclose(stdin); fclose(stdout);
	return 0;
}
