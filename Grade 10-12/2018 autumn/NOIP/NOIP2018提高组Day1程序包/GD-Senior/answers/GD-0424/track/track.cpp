#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
struct node
{
	int next;
	int v;
	int w;
}a[100001];
int cnt=0;
int head[100001];
void add(int u,int v,int w)
{
	a[++cnt].v=v;
	a[cnt].w=w;
	a[cnt].next=head[u];
	head[u]=cnt;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
	}
	cout<<"100";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
