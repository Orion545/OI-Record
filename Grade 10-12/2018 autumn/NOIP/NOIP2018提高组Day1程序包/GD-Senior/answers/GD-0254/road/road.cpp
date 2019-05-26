# include <bits/stdc++.h>

using namespace std;
const int maxN=100005;
int n,d[maxN],rmq[3*maxN][20];

int cal(int l,int r)
{
	int c=log(r-l+1)/log(2);
	return min(rmq[l][c],rmq[r-(1<<c)+1][c]);
}

int find(int bgn,int l,int r,int k)
{
	l--,r++;
	while (l+1<r)
	{
		int mid=(l+r)/2;
		if (cal(bgn,mid)==k) r=mid; else l=mid;
	}
	return l;
}

int dfs(int l,int r,int s)
{
	if (l>r) return 0;
	if (l==r) return d[l]-s;
	int k=cal(l,r);
	int ret=k-s,p;
	while (l<=r)
	{
		p=find(l,l,r,k);
	    ret+=dfs(l,p,k);
	    l=p+1;
	    while (d[l]==k && l<=r) l++;
	}
	return ret;
}

void make_rmq()
{
	for (int i=1; i<=n; i++) rmq[i][0]=d[i];
	for (int i=1; i<17; i++)
	for (int j=1; j<=n; j++)
	rmq[j][i]=min(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&d[i]);
	make_rmq();
	int ans=dfs(1,n,0);
	printf("%d\n",ans);
	return 0;
}
