#include<set>
#include<list>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
set<int>s1;
set<int>s2;
int a[100005];
int b[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)q.push(make_pair(a[i],i));
	s1.insert(0);s1.insert(n+1);
	s2.insert(0);s2.insert((n+1)*-1);	
	while(!q.empty())
	{
		int tmp=0;
		pair<int,int> u=q.top();
		q.pop();
		for(int i=u.second;i;i-=i&-i)tmp+=b[i];
		ans+=u.first-tmp;
		set<int>::iterator it1=s1.upper_bound(u.second),it2=s2.upper_bound(u.second*-1);
		int l=*it2*-1+1,r=*it1;
		for(int i=l;i<=n;i+=i&-i)b[i]+=u.first-tmp;
		for(int i=r;i<=n;i+=i&-i)b[i]-=u.first-tmp;
		s1.insert(u.second);
		s2.insert(u.second*-1);
	}
	printf("%d",ans);
	return 0;
}
