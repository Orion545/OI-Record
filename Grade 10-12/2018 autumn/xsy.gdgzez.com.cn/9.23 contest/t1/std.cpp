#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
priority_queue<int,vector<int>,greater<int> > q;
int n,x;LL ans;
int main()
{
	scanf("%d%d",&n,&x);ans-=x;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		if(i&1)
		if(x>q.top())
		ans+=(x-q.top()*2),q.pop(),q.push(x);
		else ans-=x;
		else ans+=x,q.push(x);
	}
	printf("%lld\n",ans);
	return 0;
}
