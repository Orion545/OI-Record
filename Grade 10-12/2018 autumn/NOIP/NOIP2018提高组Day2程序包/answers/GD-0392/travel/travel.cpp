#include <bits/stdc++.h>

using namespace std;
const int maxn=10005;
int dian[5005][5005],n,m,pan[maxn],to[maxn],nextt[maxn],pp[maxn];
int x,y,p,line[maxn],ll[5005][5005];
void dfs(int k)
{
	line[0]++;
	line[line[0]]=k;
	pan[k]=1;
	int pu=pp[k];
	while (pu>0)
	{
		if (pan[to[pu]]==0)
		{
			dian[k][0]++;
			dian[k][dian[k][0]]=to[pu];
		}
		pu=nextt[pu];
	}
	sort(dian[k]+1,dian[k]+1+dian[k][0]);
	for (int i=1;i<=dian[k][0];i++)
	if (pan[dian[k][i]]==0) dfs(dian[k][i]);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		p++;to[p]=y;nextt[p]=pp[x];pp[x]=p;
		p++;to[p]=x;nextt[p]=pp[y];pp[y]=p;
	}
	dfs(1);
	for (int i=1;i<n;i++) printf("%d ",line[i]);
	printf("%d",line[n]);
	return 0;
}
