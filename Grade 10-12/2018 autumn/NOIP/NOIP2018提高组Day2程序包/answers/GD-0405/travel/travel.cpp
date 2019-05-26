#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
int n,m,u,v,map[5005][5005];
int vis[5005]={0};
void ans(int s)
{   
    cout<<s<<" ";
	for(int i=1;i<=n;i++)
	{  
		
	   if(map[s][i]&&!vis[i])
	{  
	   	map[s][i]=0;
	    map[i][s]=0;
	   	vis[i]=1;
	   	ans(i);
	   }
	   
	}
	return;
}
int main()
{
    freopne("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	map[i][j]=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		map[u][v]=1;
		map[v][u]=1;
	}
	vis[1]=1;
    ans(1);
    fclose(stdin);
    fclose(stdout);
	
	return 0;
}
