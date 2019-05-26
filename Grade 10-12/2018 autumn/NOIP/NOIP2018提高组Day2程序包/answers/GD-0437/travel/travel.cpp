#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
bool map[5001][5001];
int n, m, du[5001][5001];
vector <int> route;
vector <int> ::iterator it;
bool visited[5001];

void srch(int k)
{
	if(du[k][0]==1 && k>1)
	{
		return;
	}
	for(int i=1;i<=du[k][0];i++)
		if(!visited[du[k][i]])
		{
			visited[du[k][i]]=true;
			route.push_back(du[k][i]);
			srch(du[k][i]);
		}
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		scanf("%d%d",&u,&v);
		map[u][v]=true;
		du[u][0]++;
		du[u][du[u][0]]=v;
		du[v][0]++;
		du[v][du[v][0]]=u;
	}
	for(int i=1;i<=n;i++)
		sort(du[i]+1, du[i]+du[i][0]+1);
	visited[1]=true;
	route.push_back(1);
	srch(1);
	for(it=route.begin();it!=route.end();it++)
		printf("%d ", *it);
	return 0;
}
