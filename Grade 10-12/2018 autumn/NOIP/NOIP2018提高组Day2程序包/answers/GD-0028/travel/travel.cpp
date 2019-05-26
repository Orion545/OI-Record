#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
int banx=-1,bany=-1,n,m,ans[5001],ans1[5001],top_ans=0,top_round=0,round[5001];
vector<int> map[5001];
bool p[5001];
bool check(int x,int y)
{
	if ((x==banx&&y==bany)||(x==bany&&y==banx)) return 0; else return 1;
}
void dfs(int x)
{
	p[x]=1;
	ans[top_ans++]=x;
	for (int i=0;i<map[x].size();i++)
	{
		int t=map[x][i];
		if (!p[t]&&check(x,t)) dfs(t);
	}
	p[x]=0;
}
bool find(int x,int la)
{
	p[x]=1;
	for (int i=0;i<map[x].size();i++)
	{
		int t=map[x][i];
		if (!p[t]) 
		{
			bool f=find(t,x);
			if (f)
			{
				round[top_round++]=x;
				return 1;
			}
		}
		if (p[t]&&la!=t) 
		{
			round[top_round++]=t;
			round[top_round++]=x;
			return 1;
		}
	}
	p[x]=0;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		map[x].push_back(y);
		map[y].push_back(x);
	}
	for (int i=1;i<n;i++) sort(map[i].begin(),map[i].end());
	if (m==n-1) 
	{
		dfs(1);
		for (int i=0;i<top_ans;i++) printf("%d ",ans[i]);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	find(1,0);
	memset(p,0,sizeof(p));
	memset(ans1,127,sizeof(ans1));
	for (int i=0;(round[i]!=round[0]||i==0)&&i<top_round;i++)
	{		
		top_ans=0;
		memset(ans,0,sizeof(ans));
		banx=round[i];
		bany=round[i+1];
		dfs(1);
		int f=0;
		for (int j=0;j<top_ans;j++)
			if (ans1[j]>ans[j])
			{
				f=1;
				break;
			} else if (ans1[j]<ans[j]) break;
		if (f)
			for (int j=0;j<top_ans;j++)
				ans1[j]=ans[j];
	}
	for (int i=0;i<top_ans;i++)	printf("%d ",ans1[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
