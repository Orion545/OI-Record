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
const int N=105,M=25005;
int t,n,ans,a[N];
bool f[M];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		memset(f,0,sizeof(f));
		f[0]=1;
		sort(a+1,a+n+1);
		ans=n;
		for(int i=1;i<=n;i++){
			if(f[a[i]]){
				ans--;
				continue;
			}
			for(int j=0,up=25000-a[i];j<=up;j++){
				f[j+a[i]]|=f[j];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
