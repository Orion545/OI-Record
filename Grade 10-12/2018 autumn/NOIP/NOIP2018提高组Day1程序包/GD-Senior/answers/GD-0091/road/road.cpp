#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;
int n;
long long ans;
int a[100005];
long long dfs(int l,int r,int x)
{
	if(l==r) return a[l]-x;
	int mina=10005,tmp;
	for(int i=l;i<=r;i++)
	{
		a[i]-=x;
		if(a[i]<mina)
		{
			mina=a[i];
			tmp=i;
		}
	}
	long long ret=mina;
	if(l<tmp) ret+=dfs(l,tmp-1,mina);
	if(r>tmp) ret+=dfs(tmp+1,r,mina);
	return ret;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=dfs(1,n,0);
	cout<<ans;
	return 0;
}
