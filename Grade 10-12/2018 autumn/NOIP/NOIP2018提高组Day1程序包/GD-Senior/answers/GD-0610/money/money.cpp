#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[111],bj[111],ans,now,bb;
void dfs(int k,int top){
	if (k==top){
		if (now==a[top]) bb=1;
		return;
	}
	if (bj[k]) dfs(k+1,top);
	else{
		for (int i=0;i<=a[top]/a[k];++i)
		if (now+i*a[k]<=a[top]){
			now=now+i*a[k];dfs(k+1,top);
			if (bb) break;
			now=now-i*a[k];
		}
	}	
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for (int i=1;i<=t;++i){
		scanf("%d",&n);
		for (int j=1;j<=n;++j){
			scanf("%d",&a[j]);
			bj[j]=0;
		}
		sort(a+1,a+1+n);
		ans=1;
		if (a[2]%a[1]==0) bj[2]=1;else ans=2;
		for (int j=3;j<=n;++j){
			now=0;bb=0;dfs(1,j);if (!bb) ++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
