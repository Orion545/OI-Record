#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,x,y,tot,ans[10010],ans1[10010],By,Bx,h[10010],q[10010],len,Len;
vector<int> f[10010];
bool v[10010],pb,yg,u[10010],hh;
void dfs(int k)
{
	v[k]=true;
	ans1[++tot]=k;
	if(ans1[tot]<ans[tot])yg=false;
	if(yg && ans1[tot]>ans[tot])pb=true;
	for(int i=0;i<f[k].size();i++)
	{
		if(pb)return;
		if(!v[f[k][i]] && ( (k!=Bx || f[k][i]!=By) && (k!=By || f[k][i]!=Bx) ) )dfs(f[k][i]);
	}
}
void ph(int k)
{
	//printf("P %d\n",k);
	u[k]=true;
	q[++len]=k;
	for(int i=0;i<f[k].size();i++)
	{
		if(hh)return;
		if(!u[f[k][i]])ph(f[k][i]);
		else if(f[k][i]!=q[len-1])
		{
			hh=true;
			for(int j=1;j<=len;j++)if(q[j]==f[k][i])
			{
				for(int k=1;k<=len-j+1;k++)
				{
					h[k]=q[j+k-1];
					Len++;
				}
			}
		}
	}
	len--;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)ans[i]=9999999;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		f[x].push_back(y);
		f[y].push_back(x);
	}
	for(int i=1;i<=n;i++)sort(f[i].begin(),f[i].end());
	if(m==n-1)
	{
		dfs(1);
		for(int i=1;i<=n;i++)ans[i]=ans1[i];
	}
	else
	{
		//for(int i=1;i<=n;i++)for(int j=0;j<f[i].size();j++)
		ph(1);
		//printf("HUAN:\n");
		//for(int i=1;i<=Len;i++)printf("%d\n",h[i]);
		
		for(int i=1;i<=Len;i++)
		{
			pb=false;
			yg=true;
			tot=0;
			for(int k=1;k<=n;k++)v[k]=false;
			/*
			Bx=i;
			By=f[i][j];
			*/
			
			Bx=h[i];
			By=h[i%Len+1];
			
			dfs(1);
			if(!pb)
			{
				bool ok=false;
				for(int k=1;k<=n;k++)if(ans1[k]>ans[k])break;
				else if(ans1[k]<ans[k])
				{
					ok=true;
					break;
				}
				for(int k=1;k<=n;k++)if(!v[k])
				{
					ok=false;
					break;
				}
				if(ok)for(int k=1;k<=n;k++)ans[k]=ans1[k];
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}
