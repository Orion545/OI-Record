#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

const int MAXN=30001;

int n,ans,t,maxn=0,a[MAXN],vis[MAXN];
bool tf[MAXN],dp[MAXN];

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);ans=n;
		memset(vis,0,sizeof(vis));
		memset(tf,0,sizeof(tf));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){scanf("%d",&a[i]);tf[a[i]]=true;maxn=max(maxn,a[i]);}
		sort(a+1,a+1+n);
		dp[0]=true;
		for(int i=a[1];i<=maxn;i++){
			for(int j=1;j<=vis[0];j++)if(dp[i-vis[j]])dp[i]=true;
			if(dp[i]){
					if(tf[i])ans--;
			}else{
				if(tf[i]){vis[++vis[0]]=i;dp[i]=1;}
			}
		}
		printf("%d\n",ans);
	}
}
/*
4
3 19 10 6
*/
