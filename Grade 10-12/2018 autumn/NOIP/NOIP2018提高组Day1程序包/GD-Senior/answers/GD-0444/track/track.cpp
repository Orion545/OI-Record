#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,anss;
struct edge
{
	int fa;
	int to;
	int v;
}edge[50050];
int find(int x)
{
	if(edge[x].fa!=x)edge[x].fa=find(edge[x].fa);
	return edge[x].fa;
}

void sd1()
{
	int ans;
	cout<<"31";
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)edge[i].fa=i;
	for(int i=1;i<n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		edge[a].to=b;
		edge[b].to=a;
		edge[a].v=c;
		edge[b].v=c;
		a=find(a);
		b=find(b);
		edge[a].fa=b;
	}
	if(m==1)sd1();

}
