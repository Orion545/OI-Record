//20
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,head[50050],next[500000],num[500000],to[500000],tot[50050],f[500000],nt,ans;
bool been[50050];
void bfs(int sa)
{
	memset(f,0,sizeof(f));
	memset(been,0,sizeof(been));
	int fs = 1,ft = 1;
	f[1] = sa;tot[1] = 0;
	while (fs <= ft)
	{
		for (int p = head[f[fs]];to[p] != 0;p = next[p])
			if (!been[to[p]])
			{
				ft++;
				f[ft] = to[p];tot[to[p]] = tot[f[fs]] + num[p];
				been[to[p]] = true;
			}
		fs++;
	}
	for (int i = 1;i <= n;i++) ans = ans > tot[i] ? ans :tot[i];
}	
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	nt = 0;
	if (m == 1) 
	{
		ans = 0;
		for (int i = 1;i < n;i++) 
		{
			int a,b,t;
			scanf("%d%d%d",&a,&b,&t);
			nt++;
			to[nt] = b;
			num[nt] = t;
			next[nt] = head[a];
			head[a] = nt;
			nt++;
			to[nt] = a;
			num[nt] = t;
			next[nt] = head[b];
			head[b] = nt;
		}
		for (int i = 1;i <= n;i++)
		{
			memset(tot,0,sizeof(tot));
			bfs(i);
		}
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
