#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;
struct data
{
	int num,len;
}opens[1000000];
int x,y,n,m,ans,visit[100000],s,t[10000],b,p,mn,mx;
struct data1
{
	int y,len;
};
vector <data1> f[100000];
void bfs(int k)
{
	int head=1,tail=1;
	opens[1].num=k;
	opens[1].len=0;
	for (int i=1;i<=n;i++)
	 visit[i]=0;
	while (head<=tail)
	{
		int q=opens[head].num;
		int len=opens[head].len;
		for (int i=0;i<f[q].size();i++)
		{
			if (visit[f[q][i].y]==1) continue;
			ans=max(ans,f[q][i].len+len);
			tail++;
			opens[tail].num=f[q][i].y;
			opens[tail].len=f[q][i].len+len;
			visit[f[q][i].y]=1;
		}
		head++;
	}
}
void add(int x,int y,int len)
{
	data1 q;
	q.y=y;q.len=len;
	f[x].push_back(q);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	s=100000;mn=100000;
	for (int i=1;i<n;i++)
	{
	 scanf("%d%d%d",&x,&y,&b);
	 add(x,y,b);
	 add(y,x,b);
	 if (b<s){p=i;s=b;}
	 mx=max(b,mx);
	 t[i]=b;
	}
	if (m==1)
	{
	for (int i=1;i<=n;i++)
	 bfs(i);
	cout<<ans;	
	return 0;
	}
	for (int i=1;i<n;i++)
	 if (i!=p) mn=min(mn,t[i]);
	if (m==n-1) cout<<s;

	return 0;
}
