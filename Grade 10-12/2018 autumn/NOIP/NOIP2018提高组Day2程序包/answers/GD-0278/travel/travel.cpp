#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct node{int to,next;}edge[15050];
int n,m,head[5050],cnt=0,cnta=0,ans[5050],v[5050];
void addedge(int x,int y)
{
	cnt++;
	edge[cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
void find(int k)
{
	priority_queue<int,vector<int>,greater<int> > q; 
	v[k]=1;
	ans[++cnta]=k;
	for (int i=head[k];i;i=edge[i].next)
	 if (!v[edge[i].to]) q.push(edge[i].to);
	for (;q.size();)
	 {
	 	int x=q.top();
	 	q.pop();
	 	find(x);
	 }
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	 {
	 	int x,y;
	 	scanf("%d%d",&x,&y);
	 	addedge(x,y);
	 	addedge(y,x);
	 }
	

	memset(v,0,sizeof v);
	
	find(1);
	

	
	for (int i=1;i<=cnta;i++)
	 printf("%d ",ans[i]);
	
	return 0;
}

