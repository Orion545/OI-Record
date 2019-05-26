#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
vector <int> lk[5007];
//stack  <int> tar[5007];
int sd[5007],tosu[5007],lj[5007],
tot,tc=999999,zy[5007],low[5007],tot2=1;
bool hh,hhf,cx[5007],b_in[5007],b_out[5007];
int n,m;
void vbf(int x)
{
	int y=lk[x].size();
	y--;
	while(lk[x][y]<lk[x][y-1])
	{
	swap(lk[x][y],lk[x][y-1]);
	y--;
	}
	return;
}
void cs()
{
	for(int a=1;a<=n;a++)
	{	for(int i=1;i<lk[a].size();i++)
			cout<<lk[a][i]<<" ";
		cout<<endl;					
	}
}
void yb(int u)
{
	zy[u]=low[u]=tot2;
	tot2++;
	for(int i=1;i<lk[u].size();i++)
	{
		int v=lk[u][i];
		if(zy[v])
			low[u]=zy[v];	
		else 
		{
			yb(v);
			low[u]=min(low[v],low[u]);
		}
	}
	if(low[u]!=zy[u])
	{
		b_in[u]=true;
		if(tosu[u]<=2)
			b_out[u]=true;
	}
}
void dfs(int u)
{
	lj[tot++]=u;
	cx[u]=true;
	b_in[u]=false;
	if(!hh)
	{
		for(int i=1;i<lk[u].size();i++)
		{
			int v=lk[u][i];	
			if(b_in[v]&& hhf)	{tc=v;hh=true;break;}
			if(b_in[v]&&!hhf)	 hhf=true;
		}
	hhf=false;
	}
	for(int i=1;i<lk[u].size();i++)
	{
		int v=lk[u][i];//cout<<"asdr "<<v;
		if(b_out[u]&&v>tc)	{tc=999999;return;}
		if(!cx[v])dfs(v);
	}
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=n;i++)
	lk[i].push_back(0);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		lk[u].push_back(v);vbf(u);tosu[u]++;
		lk[v].push_back(u);vbf(v);tosu[v]++;
	}
	if(m==n)yb(1);
	else hh=true;
	dfs(1);	
	for(int i=0;i<tot;i++)
	cout<<lj[i]<<" ";
} 

