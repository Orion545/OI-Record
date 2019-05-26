#include<bits/stdc++.h>
using namespace std;
const int N=5010;
bool f[N][N];
bool used[N];
int ans[N<<2];int top=0;
int n,m;
int bian[N];

void dfs(int x)
{
	for(register int i=1;i<=n;i++){
		if(used[i]==0&&f[x][i]==0)
		{
			f[x][i]=f[i][x]=1;
			ans[++top]=i;
			used[i]=1;
			dfs(i);
		}
	}
}
void dfs2(int x)
{
	 bool flag=0;
	 if(!used[x])flag=1,ans[++top]=x,used[x]=1;
     for(register int i=1;i<=n;i++)
     {
     	if(f[x][i]==0)
     	{
     		f[x][i]=1;
     		dfs2(i);
     		f[i][x]=0;
     	}
     }
     if(flag)used[x]=0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			f[i][j]=1;
		}
	}
	for(register int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		f[x][y]=0;f[y][x]=0;
	}
	if(m==n-1){
	ans[1]=1;top=1;used[1]=1;
	dfs(1);
	for(register int i=1;i<=top;i++)
	{
		cout<<ans[i]<<" ";
	}
	}
	else{
	ans[1]=1;top=1;used[1]=1;
	dfs(1);
	for(register int i=1;i<=top;i++)
	{
		cout<<ans[i]<<" ";
	}
	}
	cout<<endl;
	return 0;
}
