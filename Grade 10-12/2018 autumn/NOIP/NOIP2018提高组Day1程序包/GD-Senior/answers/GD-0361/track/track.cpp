#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct data
{
	int a,b;
}opens[100005];
vector<int> f[50005],g[50005];
int n,m,mxx,p,x,y,z,visit[50005],a[50005],b[50005],c[50005],s;
void bfs(int start)
{
	int head=1,tail=1,u,v;
	opens[head].a=start;
	opens[head].b=0;
	for (int i=1;i<=n;i++) visit[i]=0;
	visit[start]=1;
	while (head<=tail)
	 {
	 	u=opens[head].a;
	 	for (int i=0;i<f[u].size();i++)
	 	 {
	 	 	v=f[u][i];
	 	 	if (!visit[v])
	 	 	 {
	 	 	 	++tail;
	 	 	 	opens[tail].a=v;
	 	 	 	opens[tail].b=opens[head].b+g[u][i]; 
	 	 	 	visit[v]=1;
	 	 	 	if (opens[tail].b>mxx)
	 	 	 	 { mxx=opens[tail].b; p=opens[tail].a; }
	 	 	 }
	 	 }
	 	head++;
	 }
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[i]=x; b[i]=y; c[i]=z; s=s+z;
		f[x].push_back(y);
		f[y].push_back(x);
		g[x].push_back(z);
		g[y].push_back(z);
	}
	if (m==1)
	 {
	 	mxx=0;
	 	bfs(1);
	 	mxx=0;
	 	bfs(p);
	 	cout<<mxx;
	 }
	else if (m==n-1)
	 {
	 	int mnn=99999999;
	 	for (int i=1;i<n;i++)
	 	 mnn=min(mnn,c[i]);
	 	cout<<mnn;
	 }
	return 0;
}
