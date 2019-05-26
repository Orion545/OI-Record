#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n,m,tot,ans;
int p[100010],f[100010][2];
int map[2010][2010];
int const INF=1<<29;
int read()
{
	char C;int ret=1;
	C=getchar();
	while(C<'0'||C>'9')
	{
		if(C=='-') ret=-1;
		C=getchar();
	}
	int num=0;
	while(C>='0'&&C<='9') num=num*10+C-48,C=getchar();
	return num*ret;
}
vector<int> edge[100010];
void dp(int from,int u,int a,int x,int b,int y)
{
	if(u==a&&x||u==b&&y) f[u][1]=min(f[from][0],f[from][1])+p[u];
	else if(u==a&&!x||u==b&&!y) f[u][0]=f[from][1];
	else 
	{
		f[u][1]=min(f[from][0],f[from][1])+p[u];
		f[u][0]=f[from][1];
	}
	for(int i=0; i<edge[u].size(); i++)
	{
		int to=edge[u][i];
		if(to==from) continue;
		dp(u,to,a,x,b,y);
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();m=read();string s;
	cin>>s;
	for(int i=1; i<=n; i++) p[i]=read();
	if(s[0]=='A')
	{
		for(int i=1; i<n; i++)
		 int a=read(),b=read();
		for(int i=1; i<=m; i++)
		{
			int a=read(),x=read(),b=read(),y=read();
			if(a+1==b&&!x&&!y) {printf("-1\n");continue;}
			f[0][0]=0;f[0][1]=0;
			for(int i=1; i<=n; i++) f[i][0]=INF,f[i][1]=INF;
			for(int i=1; i<=n; i++)
			{
				if(i==a&&x||i==b&&y) {f[i][1]=min(f[i-1][0],f[i-1][1])+p[i];continue;}
				if(i==a&&!x||i==b&&!y) {f[i][0]=f[i-1][1];continue;}
				f[i][1]=min(f[i-1][0],f[i-1][1])+p[i];
				f[i][0]=f[i-1][1];
			}
			printf("%d\n",min(f[n][0],f[n][1]));
		}
	}
	/*if(s[0]=='C')
	{
		for(int i=1; i<n; i++)
		{
			int a=read(),b=read();
			edge[a].push_back(b);
			edge[b].push_back(a);
			map[a][b]=1;map[b][a]=1;
		}
		for(int i=1; i<=m; i++)
		{
			int a=read(),x=read(),b=read(),y=read();
			if(map[a][b]&&!x&&!y) {printf("-1\n");continue;}
			f[0][0]=0;f[0][1]=0;tot=0;
			for(int i=1; i<=n; i++) f[i][0]=INF,f[i][1]=INF;
			dp(0,1,a,x,b,y);
			for(int i=2; i<=n; i++)
			 if(edge[i].size)
			printf("%d\n",ans);
		}
	}*/
	return 0;
}

