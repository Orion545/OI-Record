#include<cstdio>
#include<vector>
#include<iostream>
#include<string.h>
using namespace std;
vector<int> map[100010];
long long f[10010][2];
int n,m,di[10010],lx,ly,lx1,ly1;
string sss;
bool p[10010];
void dp(int x)
{
	p[x]=1;
	int pp=0;
	for (int i=0;i<map[x].size();i++)
	{
		int t=map[x][i];
		if (!p[t]) 
		{
			dp(t);
			pp=1;
		}
	}
	f[x][1]=di[x];
	f[x][0]=0;
	p[x]=0;
	if (!pp) 
	{
		if (lx==x) f[x][!ly]=100000000000;
		if (lx1==x) f[x][!ly1]=100000000000;
		return;
	}
	int s[100010],now;
	long long Min=10000000000000;
	s[0]=min(f[map[x][0]][0],f[map[x][0]][1]);
	for (int i=0;i<map[x].size()-1;i++) s[i+1]=s[i]+min(f[map[x][i+1]][0],f[map[x][i+1]][1]);
	for (int i=0;i<map[x].size();i++)
	{
		if (p[map[x][i]]) continue;
		int t=map[x][i];
		if (s[map[x].size()-1]-s[i]+s[i-1]+f[t][1]<Min) Min=s[map[x].size()-1]-s[i]+s[i-1]+f[t][1];
	}
	f[x][0]=Min;
	f[x][1]+=s[map[x].size()-1];
	if (lx==x) f[x][!ly]=100000000000;
	if (lx1==x) f[x][!ly1]=100000000000;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>sss;
	for (int i=1;i<=n;i++) scanf("%d",&di[i]);
	for (int i=1;i<n;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		map[x].push_back(y);
		map[y].push_back(x);
	}
	for (int i=0;i<m;i++)
	{
		scanf("%d%d%d%d",&lx,&ly,&lx1,&ly1);
		memset(f,0,sizeof(f));
		dp(1);
		if (min(f[1][0],f[1][1])>10000000000) printf("-1\n");else printf("%lld\n",min(f[1][0],f[1][1]));
	}
	fclose(stdin);
	fclose(stdout);
}
