#include<bits/stdc++.h>
using namespace std;
bool r[1001][1001]; bool l[2500][2500]={{false}},x[100000],y[100000];int p[100000],a[100000],b[100000];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m; cin>>n>>m; char c[3]; cin>>c[0]>>c[1];
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=m;i++) cin>>a[i]>>x[i]>>b[i]>>y[i];
	if(c[0]=='A')
	{
		int u,v;
		for(int i=1;i<=n;i++)
		{
			cin>>u>>v;
			l[u][v]=true; l[v][u]=true;
			l[i][i+1]=true; l[i+1][i]=true;
		}
		for(int i=1;i<=m;i++)
		{
			if(x[i]==0&&y[i]==0&&r[a[i]][b[i]]==false) cout<<"-1";
			else cout<<rand;
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
