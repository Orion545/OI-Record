#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1E5+5;
int a[N],n,Ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]<=a[i-1])
			continue;
		Ans=Ans+a[i]-a[i-1];
	}printf("%d\n",Ans);
	return 0;
}
