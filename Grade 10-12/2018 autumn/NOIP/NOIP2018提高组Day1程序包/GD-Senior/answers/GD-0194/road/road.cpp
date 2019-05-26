#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
typedef long long ll;
ll n,d[maxn],maxd,ans,cnt;
struct node
{
	ll d,id;
	bool operator<(node x)const{return d>x.d;}
}s[maxn];
bool tf[maxn];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",d+i),maxd=max(maxd,d[i]);
	for(int i=1;i<=n;i++)s[i].d=d[i],s[i].id=i;
	sort(s+1,s+n+1);
	int j=1;
	for(int i=maxd;i>=1;i--)
	{
		for(;j<=n;j++)
		{
			if(s[j].d<i)break;
			if(tf[s[j].id-1]&&tf[s[j].id+1])cnt--,tf[s[j].id]=true;
			else if(tf[s[j].id-1]||tf[s[j].id+1])tf[s[j].id]=true;
			else cnt++,tf[s[j].id]=true;
		}
		//for(int j=1;j<=n;j++)if(tf[j])printf("%d ",j);
		//printf("\n%lld\n",cnt);
		ans+=cnt;
	}
	printf("%lld\n",ans);
	return 0;
}
