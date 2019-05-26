#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<cctype>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
const int N=100005;
int n,minn,res,a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>minn){
			res+=a[i]-minn;
			minn=a[i];
		}else{
			minn=min(minn,a[i]);
		}
	}
	printf("%d\n",res);
	return 0;
}
