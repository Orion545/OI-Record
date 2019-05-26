#include <cstdio>
#include <iostream>

using namespace std;
int map[100][100], f[100][100];
int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		map[a][b]=map[b][a]=w;
	}
	int ans=0;
	for(int k=1;k<n;k++)
		for(int i=1;i<n;i++)
			for(int j=1;j<n;j++)
				{
					f[i][j]=max(map[i][j],map[i][k]+map[k][j]);
					ans=max(f[i][j],ans);
				}
	
	cout<<ans<<endl;
	return 0;
}
