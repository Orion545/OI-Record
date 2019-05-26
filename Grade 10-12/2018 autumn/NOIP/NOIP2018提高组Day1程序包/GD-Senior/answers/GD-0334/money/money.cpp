#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<cstring>
#include<string>
#define ll long long int
#define INF 0x3f3f3f3f 
#define MAXN 25005
using namespace std;

ll vis[MAXN];
ll a[MAXN];
ll used[MAXN];
ll ans=0,cnt=0,cur=0,tot=0;

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	ll t;
	scanf("%lld",&t);
	int n,now;
	while(t--){
		ans=0,cnt=0,cur=0,tot=0;
		memset(vis,0,sizeof(vis));
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		 if((a[i]%a[1])==0){
			vis[i]=1;
			cnt++;
		 }
		used[++tot]=a[1];
		ans++;
		if(cnt==n){
			printf("1\n");
			break;
		}
		while(1){
			for(int i=1;i<=n;i++){
			  if(!vis[i]){
			  	cur=i;
			  	break;
			  }
		    }
			used[++tot]=a[cur];
			ans++;
			for(int i=cur;i<=n;i++){
				if(!vis[i]){
					if(a[i]%a[cur]==0){
						vis[i]=1;
						cnt++;
					}
				}
			}
			for(int i=1;i<=tot;i++)
			 for(int j=i+1;j<=tot;j++)
			  for(int k=i;k<=n;k++)
				if(!vis[k]){
					if((a[k]-used[i]-used[j])%used[i]==0||(a[k]-used[i]-used[j])%used[j]==0||a[k]>(used[i]*used[j]-used[i]-used[j])){
				 	 vis[k]=1;
				 	 cnt++;
				}
		}
		if(cnt==n)break;
	}
	printf("%lld\n",ans);
    }
	return 0;
}
