#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int sum[50005];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y,L;
		scanf("%d%d%d",&x,&y,&L);
		sum[i]=sum[i-1]+L;
	}
	int l=0,r=sum[n-1]/m+1;
	while(l+1<r)
	{
		int mid=l+r>>1;
		int k=0,s=0;
		for(int i=1;i<n;i++)
			if(sum[i]-sum[s]>=mid) 
			{
				k++;
				s=i;
				if(k==m) break;
			}
		if(k<m) r=mid; else l=mid;
	}
	cout<<l;
	return 0;
}
