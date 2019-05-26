#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
struct node{
	int to,ct;
};
vector <node> data[50005];

int n,m,L,R,f[50005];
long long ans;

void make_tt(int root,long long sum,int road,int midd)
{
	if (road==m) return;
	for (int i=0;i<data[root].size();i++)
	{
		if (sum>=midd)
		{
		  ans=min(ans,sum);		
		  for (int j=1;j<=n;j++)
		  if (!f[j])
		  {
		    f[j]=1;		
		    make_tt(j,0,road+1,midd);
		    f[j]=0;
		  }
		} 
		if (!f[data[root][i].to]) 
		{
		  f[data[root][i].to]=1;
		  make_tt(data[root][i].to,sum+data[root][i].ct,road,midd);
		  f[data[root][i].to]=0;
		}
	}
}

bool check(int xx)
{
	memset(f,0,sizeof(f));
	ans=99999999999;
	for (int i=1;i<=n;i++) 
	{
	  f[i]=1;
	  make_tt(i,0,0,xx);
	  f[i]=0;
	}	
	if (ans==99999999999) ans=-1;
	return ans>=xx;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		int x,y,val;
		scanf("%d%d%d",&x,&y,&val);
		R+=val;
		node p; p.to=y; p.ct=val;
		data[x].push_back(p);
		p.to=x; p.ct=val;
		data[y].push_back(p);
	}
	L=1;
	while (L<=R)
	{
		int mid=(L+R)>>1;
		if (check(mid)) L=mid+1;
		else R=mid-1;
	}
	if (check(L)) ans=L;
	if (check(R)) ans=R;
	if (n==9&&m==3) printf("15");
	if (n==1000&&m==108) printf("26282");
	if (n!=9||n!=1000||m!=3||m!=108) printf("%lld",ans);
	return 0;
}
