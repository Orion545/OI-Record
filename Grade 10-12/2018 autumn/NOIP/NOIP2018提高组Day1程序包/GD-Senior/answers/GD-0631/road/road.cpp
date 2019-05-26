#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;


int main()
{
	int i,x,n;
	int a[100000+5];
	int ans=0;
	stack <int> s;
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	s.push(a[1]);
	for (i=2;i<=n;i++)
	{
		if (a[i]<s.top())
		{
			x=s.top();	s.pop();
			ans+=x-a[i];
//			if (s.empty())
//				break;
		}
		s.push(a[i]);
	}
	if (!s.empty())
	{
		ans+=s.top();
	}
	printf("%d\n",ans);
	
	
	return 0;
}
