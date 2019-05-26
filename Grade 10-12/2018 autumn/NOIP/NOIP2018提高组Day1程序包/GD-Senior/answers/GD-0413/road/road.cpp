#include<set>
#include<cstdio>
#include<algorithm>
using namespace std;
struct R{
	int d,id;
}p[100001];
int ml[100001],mr[100001];
bool cmp (const R &a,const R &b)
{
	return a.d<b.d;
}
set <int> s,ss;
int main()
{
	int n,ans=0,l,r,mx;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i].d),p[i].id=i;
	sort(p+1,p+n+1,cmp);
	s.insert(0); s.insert(n+1);
	ss.insert(0); ss.insert(-n-1);
	for (int i=1;i<=n;i++)
	{
		l=-(*ss.lower_bound(-p[i].id));
		r=*s.lower_bound(p[i].id);	
		mx=max(ml[l],mr[r]);
		ans+=p[i].d-mx;
		ml[l]=mr[r]=p[i].d;
		s.insert(p[i].id);
		ss.insert(-p[i].id);
	}
	printf("%d",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
