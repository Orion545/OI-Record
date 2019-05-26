#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,tot,v[5005],minn[5005],father[5005];
int edge[5005][5005],ans;
int sk[5005],ski;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-48;
		ch=getchar();
	}
	return s*w;
}
int dfs_go(int from,int wanto)
{
	for(int i=1;i<=edge[from][0];i++)
		if(!v[edge[from][i]]&&wanto>edge[from][i])
			return edge[from][i];
	return wanto;
}
int dfs_back(int xx,int wanto)
{
	if(xx==9999) return wanto;
	ans=min(ans,wanto);
	for(int i=1;i<=edge[xx][0];i++)
	{
		if(v[edge[xx][i]])
		ans=min(ans,dfs_go(edge[xx][i],wanto));
	}
	ans=min(ans,dfs_back(father[xx],wanto));
	return ans;
}
void dfs(int x,int from)
{
	v[x]=1;
	cout<<x<<" ";
	father[x]=from;
	for(int i=1;i<=edge[x][0];i++)
	{
		if(!v[edge[x][i]])
		{    
			ans=9999;
			int next=dfs_back(father[x],edge[x][i]);
			if(next=edge[x][i])
			dfs(next,x);
			else
			dfs(next,father[next]);
		}
	}

}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	int a,b;
	for(int i=1;i<=m;i++)
	{
		a=read();b=read();
		edge[a][0]++;
		edge[a][edge[a][0]]=b;
		edge[b][0]++;
		edge[b][edge[b][0]]=a;				
	}
	for(int i=1;i<=n;i++)
		sort(edge[i]+1,edge[i]+1+edge[i][0]);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<i<<": ";
//		for(int j=1;j<=edge[i][0];j++)
//			cout<<edge[i][j]<<" ";
//		cout<<endl;
//	}
	dfs(1,9999);
	return 0;
}
