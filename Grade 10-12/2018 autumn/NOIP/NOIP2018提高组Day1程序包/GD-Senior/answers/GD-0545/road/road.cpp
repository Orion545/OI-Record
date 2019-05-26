#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=1e5+5,MAXD=1e4+5;

int a[MAXN];
vector<int> V[MAXD];

int n;
int ans;

#define mid ((x+y)>>1)
#define lson (pst<<1)
#define rson (pst<<1|1)

struct SegmentTree
{
	int s[MAXN<<2];
	
	inline void PushUp(int pst)
	{
		s[pst]=min(s[lson],s[rson]);
		
		return;
	}
	
	inline void Build(int x,int y,int pst)
	{
		if(x==y)
			s[pst]=a[x];
		else
		{
			Build(x,mid,lson),Build(mid+1,y,rson);
			PushUp(pst);
		}
		
		return;
	}
	
	inline int Query(int x,int y,int pst,int l,int r)
	{
		if(y<l||x>r)
			return MAXD;
		
		if(l<=x&&y<=r)
			return s[pst];
			
		return min(Query(x,mid,lson,l,r),Query(mid+1,y,rson,l,r));
	}
}ST;

inline void PreWork(void)
{
	ST.Build(1,n,1);
	
	for(int i=1;i<=n;i++)
		V[a[i]].push_back(i);
	
	return;
}

inline void Half(int l,int r,int last)
{
	if(l>r)
		return;
	
	int mi=ST.Query(1,n,1,l,r);
	
	int delta=mi-last;
	ans+=delta;
	
	int sz=V[mi].size();
	
	int x=0,y=sz-1,pst=r+1;
	while(x<=y)
	{
		if(V[mi][mid]>=l)
			pst=mid,y=mid-1;
		else
			x=mid+1;
	}
	
	int head=l;
	for(int i=pst;i<sz&&V[mi][i]<=r;i++)
		Half(head,V[mi][i]-1,mi),head=V[mi][i]+1;
	if(head<=r)
		Half(head,r,mi);
	
	return;
}

signed main(void)
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	
	PreWork();
	
	Half(1,n,0);
	
	cout<<ans<<endl;
	
	return 0;
}
