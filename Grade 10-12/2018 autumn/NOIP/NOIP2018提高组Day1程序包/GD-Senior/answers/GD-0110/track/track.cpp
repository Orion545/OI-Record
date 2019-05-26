#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[1010][1010],next[1000][1010],total,cnt[1010];
int big=0;
void dfs(int le,int ans,int from)
{
	big=max(big,ans);
	for(int i=1;i<=cnt[le];i++)
	if(next[le][i]!=from)
	dfs(next[le][i],ans+a[le][next[le][i]],le);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int a1,b1,c1;
		scanf("%d",&a1);
		scanf("%d",&b1);
		scanf("%d",&c1);
		a[a1][b1]=c1;
		cnt[a1]++;
		next[a1][cnt[a1]]=b1;
		a[b1][a1]=c1;
		cnt[b1]++;
		next[b1][cnt[b1]]=a1;
		total+=c1;
	}	
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		dfs(i,0,0);
		cout<<big<<endl;
		return 0;
	}
	cout<<total/m-1<<endl;
	return 0;
}
