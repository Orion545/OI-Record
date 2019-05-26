#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,visnum=0,ans[5000];
bool vis[5000]={false};
struct nodes{
	int tonum;
	int to[1000];
}node[5000];

void addedge(int x,int y)
{
	node[x].tonum++; node[y].tonum++;
	node[x].to[node[x].tonum]=y; node[y].to[node[y].tonum]=x;
}

int goback(int pos)
{
	int minto;
	sort(node[pos].to+1,node[pos].to+node[pos].tonum+1);
	for (int i=1;i<=node[pos].tonum;i++)
		if (!vis[node[pos].to[i]]){
			minto=node[pos].to[i];
			break;
		}
	return minto;
}

void dfs(int pos,int lnode)//lnode:上一个节点 
{
	int minto=9999,smin;
	visnum++;
	ans[visnum]=pos;
	vis[pos]=true;
	if (visnum==n) 
		return;
	sort(node[pos].to+1,node[pos].to+node[pos].tonum+1);
	for (int i=1;i<=node[pos].tonum;i++){
		if (!vis[node[pos].to[i]]){
			minto=node[pos].to[i];
			break;
		} 
		if (i==node[pos].tonum && minto==9999)
			return;
	}
	if (node[minto].tonum==1)
		dfs(minto,pos);
	else{
		smin=goback(lnode);
		if (smin<minto){
			dfs(smin,lnode);
		}else{
			dfs(minto,pos);
		}
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		addedge(x,y);
	}
	int strt=9999;
	for (int i=1;i<=node[1].tonum;i++)
		if (node[1].to[i]<strt) 
			strt=node[1].to[i];
	vis[1]=true; visnum++; ans[1]=1; ans[n]=n;
	dfs(strt,1);
	for (int i=1;i<=n;i++) 
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
