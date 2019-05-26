#include<iostream>
#include<algorithm>
#include<fstream>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
priority_queue<int,vector<int>,greater<int> > que;
/*typedef pair<int,int>P;
map<P,int> mp;
vector<int> l[50005];*/
struct E{
	int a,b,v,nex;
}e[100005];
bool ed[50005];
int n,m,p[50005],l[50005];
int du()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if (c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
void dfs(int x,int s)
{
	que.push(s);
	ed[x]=1;
	while (que.size()>m) que.pop();
	for (int i=p[x];i!=-1;i=e[i].nex)
	{
		if (!ed[e[i].b])
		dfs(e[i].b,s+e[i].v);
	}
	return ;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=du();m=du();
	for (int i=0;i<=n;i++) p[i]=-1;
	for (int i=0;i<n-1;i++)
	{
		e[i].a=du();e[i].b=du();e[i].v=du();
		e[i+n-1].a=e[i].b;e[i+n-1].b=e[i].a;e[i+n-1].v=e[i].v;
		e[i].nex=p[e[i].a];e[i+n-1].nex=p[e[i].b];
		p[e[i].a]=i;p[e[i].b]=i+n-1;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) ed[j]=0;
		dfs(i,0);
	}
	while(que.size()>1) que.pop();
	cout<<que.top();
	return 0;
}
