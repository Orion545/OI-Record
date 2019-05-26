#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

#include<cstdlib>

using namespace std;
struct ci{
	int index, p;
	bool army;
}city[200];
int main()
{
	int n,m;
	bool map[200][200];
	string type;
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>type;
	for(int i=1;i<=n;i++)
	{
		cin>>city[i].p;
		city[i].index=i;
	}
		
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		map[u][v]=true;
		map[v][u]=true;
	}
	for(int i=1;i<=m;i++)
	{
		int a,x,b,y;
		cin>>a>>x>>b>>y;
		if((!x)&&(!y))
			if(map[a][b])
				cout<<-1<<endl;
			else
			{
				cout<<rand()<<endl;
			}
	}
	return 0;
}
