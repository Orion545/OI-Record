//raod.in
//road.out
//暴力？ 
//回头再写 
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100001;
int a[maxn];
int n,ans=0;
void jian(int l,int r,int k)
{
	for(int i=l;i<=r;i++)
	 a[i]-=k;
	return;
}
bool pan()
{
	for(int i=1;i<=n;i++)
	 if(a[i]!=0)
	  return 1;
	return 0;
}
void bfs(int l,int r)
{
	int ls=1,rs,minn;
	while(a[ls]==0&&ls<=n)
	 ls++;
	minn=a[ls];
	rs=ls;
	while(a[rs+1]!=0&&rs+1<=n)
	{
		rs++;
		minn=min(minn,a[rs]);
	}
	ans+=minn;
	jian(ls,rs,minn);
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	while(pan())
	 bfs(1,n);
	cout<<ans;
	return 0;
}
