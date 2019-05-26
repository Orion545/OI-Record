#include<bits/stdc++.h>
using namespace std;

typedef vector<int> ve;
vector <ve> vec(5050);
bool vis[5050];
int a[5050],b[5050];
int n,m;

inline int rea()
{
	int x=0, f=1;
	char ch=getchar();
	while (!(isdigit(ch) || ch=='-')) ch=getchar();
	if (ch=='-') f=-1, ch=getchar();
	while (isdigit(ch)) x=x * 10 + ch - 48 , ch=getchar();
	return x * f;
}

inline void addedge(int x, int y)
{
	vec[x].push_back(y);
	vec[y].push_back(x);
}

void f(int x)
{
	printf("%d ",x);
	vis[x]=1;
	int si=vec[x].size();
	for (int i=0; i<si; i++)
	{
		int v=vec[x][i];
		if (!vis[v]) f(v);
	}
	vis[x]=0;
}

void chec()
{
	for (int i=1; i<=n; i++)
	{
		if (a[i]<b[i]) return;
		if (a[i]>b[i]) break;
	}
	for (int i=1; i<=n; i++) a[i]=b[i];
}

void ff(int x, int t)
{
	b[++b[0]]=x;
	if (t==n) chec();
	vis[x]=1;
	int si=vec[x].size();
	for (int i=0; i<si; i++)
	{
		int v=vec[x][i];
		if (!vis[v]) ff(v,t+1);
	}
	b[0]--;
	vis[x]=0;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=rea(), m=rea();
	for (int i=1; i<=m; i++)
	{
		int x=rea(), y=rea();
		addedge(x,y);
	}
	for (int i=1; i<=m; i++) sort(vec[i].begin(),vec[i].end());
	for (int i=1; i<=n; i++) a[i]=9999999;
	if (m==n-1) f(1);
	else
	{
		ff(1,1);
		for (int i=1; i<=n; i++) printf("%d ",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
