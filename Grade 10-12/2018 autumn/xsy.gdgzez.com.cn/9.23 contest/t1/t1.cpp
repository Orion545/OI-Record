#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n,a[200010];long long ans;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	scanf("%d",&n);int i;
	for(i=1;i<=n;i++) scanf("%d",&a[i]),ans+=a[i];
	for(i=1;i<=n;i++){q.push(a[i]);if(q.size()>(i>>1)){ans-=q.top()*2,q.pop();}}
	printf("%lld\n",ans);
}
