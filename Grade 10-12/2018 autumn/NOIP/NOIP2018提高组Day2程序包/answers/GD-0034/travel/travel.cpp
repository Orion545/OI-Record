#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
inline int readin()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
const int maxn=300005;
int n,m;
vector<int> g[maxn];
void dfs2(int u,int fa)
{
	printf("%d ",u);
	for(int i=0;i<g[u].size();i++)
		if(g[u][i]!=fa)
			dfs2(g[u][i],u);
	//cout<<u<<" "<<f[u][0]<<" "<<f[u][1]<<" "<<f[u][2]<<endl;*
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=readin(),m=readin();
	int x,y;
	for(int i=1;i<n;i++) x=readin(),y=readin(),g[x].push_back(y),g[y].push_back(x);
	for(int i=1;i<=n;i++)
		sort(g[i].begin(),g[i].end());
	if(m==n-1) dfs2(1,0);
	else ;
}
