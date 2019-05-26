#include<bits/stdc++.h>
using namespace std;
int cc,to[300300],net[300300],fr[300300],f[300300][3],fa[300300];
int p[300300],n,m,u,v,a,b;string type;
void addedge(int u,int v)
{
	cc++;
	to[cc]=v;net[cc]=fr[u];fr[u]=cc;
}
bool dfs(int x)
{
	if (f[x][0]>0) f[x][0]=0;
	if (f[x][1]>0) f[x][1]=0;bool flag=true;
	for (int i=fr[x];i;i=net[i])
	{
		int y=to[i];
		if (y==fa[x]) continue;
		fa[y]=x;
		if (dfs(y)) flag=true;else flag=false;
		if (f[x][0]!=-1)
		{
			if (f[y][1]==-1) f[x][0]=-1;
		    else f[x][0]+=f[y][1];
	    }
	    if (f[x][1]!=-1)
	    {
	    	if (f[y][0]==-1) f[x][1]+=f[y][1];else
	    	if (f[y][1]==-1) f[x][1]+=f[y][0];else
	    	  f[x][1]+=min(f[y][0],f[y][1]);
	    	//if (f[y][0]==-1) f[x][1]=-1;
	    	//else f[x][1]+=f[y][1];
	    }
	} 
	if (f[x][0]==-1&&f[x][1]==-1) return false;
	if (f[x][1]!=-1) f[x][1]+=p[x];
//	cout<<fa[x]<<" "<<x<<" "<<f[x][0]<<" "<<f[x][1]<<" "<<flag<<endl;
	return flag;
} 
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>type;
	for (int i=1;i<=n;i++) cin>>p[i];
	for (int i=1;i<n;i++)
	{
		cin>>u>>v;
		addedge(u,v);addedge(v,u);
	}
	for (int i=1;i<=m;i++)
	{
	   cin>>u>>a>>v>>b;
	   for (int j=1;j<=n;j++)
	     for (int k=0;k<=1;k++)
	       f[j][k]=0;
	   f[u][a^1]=-1;f[v][b^1]=-1;
	   if (!dfs(1)) {cout<<"-1\n";continue;}
	   if (f[1][0]==-1) cout<<f[1][1]<<endl;else
	   if (f[1][1]==-1) cout<<f[1][0]<<endl;else
	    cout<<min(f[1][0],f[1][1])<<endl;
	   
    }
	return 0;
}
