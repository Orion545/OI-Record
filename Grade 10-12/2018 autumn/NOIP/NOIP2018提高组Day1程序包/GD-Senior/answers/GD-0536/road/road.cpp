#include<iostream>
#include<sstream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,num[200001],ans;
struct st
{
	int s[800001],tag[800001];
	inline void js(int l,int r,int p)
	{
		if(l==r)
		{
			s[p]=num[l];
			return;
		}
		js(l,(l+r)>>1,p<<1);
		js(((l+r)>>1)+1,r,p<<1|1);
		s[p]=min(s[p<<1],s[p<<1|1]);
		return;
	}
	inline void k(int l,int r,int p,int now)
	{//cout<<l<<" "<<r<<" "<<s[p]-now<<endl;
		if(s[p]-now)
			ans+=s[p]-now;//cout<<ans<<endl;
		if(l==r)
		    return;
		k(l,(l+r)>>1,p<<1,s[p]);
		k(((l+r)>>1)+1,r,p<<1|1,s[p]);
		return;
	}
}t;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int x=1;x<=n;++x)
	    scanf("%d",num+x);
	t.js(1,n,1);
	t.k(1,n,1,0);
	printf("%d",ans);
	return 0;
}
