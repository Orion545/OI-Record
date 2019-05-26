using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100000
int n;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	int ans=0;
	for (int i=1,lst=0;i<=n;++i){
		int x;
		scanf("%d",&x);
		ans+=max(x-lst,0);
		lst=x;
	}
	printf("%d\n",ans);
	return 0;
}
