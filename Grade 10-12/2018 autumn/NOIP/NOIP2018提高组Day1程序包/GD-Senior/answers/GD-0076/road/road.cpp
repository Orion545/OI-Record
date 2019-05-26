#include<cstdio>
using namespace std;
const int N=100005;
int n,d[N],ans,di,sheng[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%d",&d[i]);
	for(int i=1;i<=n;i++){
		if(d[i]>=d[i-1])continue;
		if(d[i]<d[i-1]&&d[i-1]>=d[i-2]){
			ans+=d[i-1]-di;
			di=d[i];
			continue;
		}
		if(d[i]<d[i-1]&&d[i]<di)	di=d[i];
	}
	if(d[n]>d[n-1]){
		ans+=d[n]-di;
	}
	printf("%d",ans);
	return 0;
}

