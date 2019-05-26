#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int y,z;
};
vector<node> map[110001];
int n,m,s[110010];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int p=0,sumz=0,p1=0;
	for (int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (x!=y-1&&y!=x-1) p=1;
		if (x!=1) p1=1;
		sumz+=z;
		node hehe={y,z},hehe1={y,z};

		map[x].push_back(hehe);
		map[y].push_back(hehe1);
	}
	if (p==0)
	{
		int l=0,r=sumz,ans=0;
		for (int i=2;i<=n;i++) s[i]+=s[i-1]+((map[i-1][0].y==i)?map[i-1][0].z:map[i-1][1].z);
		while (l<=r)
		{
			int mid=(l+r)/2,cnt=0,now=1,last=1;
			while (cnt<m&&now<=n)
			{
				for (;s[now]-s[last]<mid&&now<=n;now++);
				last=now;
				if (now<=n) cnt++;
			}
			if (cnt>=m)
			{
				ans=mid;
				l=mid+1;
			} else r=mid-1;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
