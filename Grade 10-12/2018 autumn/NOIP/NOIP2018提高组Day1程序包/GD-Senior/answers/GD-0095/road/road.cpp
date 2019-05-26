#include<cstdio>
#include<cstring>
using namespace std;
int n,d[100000+10],maxx,ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	maxx=d[1];
	d[n+1]=0;
	for(int i=2;i<=n+1;i++){
		if(maxx>d[i])
			ans+=maxx-d[i];
		maxx=d[i];
	}
	printf("%d",ans);
	return 0;
}

