#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int a[150];
bool vis[150];
bool viss[25500];
int cnt[150];
int cntt[150];
int tott;
int tot;
int ans;
int main(){
	int T;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		memset(cntt,0,sizeof(cnt));
		memset(viss,0,sizeof(viss));
		tott=0;
		tot=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		if(a[1]==1||n==1){
			printf("1\n");
			continue;
		}
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				if(!vis[j]&&!vis[i]&&a[j]%a[i]==0){
					vis[j]=true;
				}
			}
		}
		for(int i=1;i<=n;++i)
			if(!vis[i]) cnt[++tot]=a[i];
		ans=0;
		long long tmp=0x7fffffffffffffff;
		for(int i=1;i<tot;++i){
			for(int j=i+1;j<=tot;++j){
				int xxx=cnt[j]-cnt[i];
				for(int k=1;k<=n;++k){
					if(xxx%cnt[k]==0){
						viss[j]=true;
						break;
					}
					if(cnt[k]>xxx) break;
				}
			}
		}
		for(int i=1;i<=tot;++i){
			if(!viss[i]) cntt[++tott]=cnt[i];
		}
		for(int i=1;i<tott;++i){
			for(int j=i+1;j<=tott;++j){
				if(gcd(cntt[i],cntt[j])==1){
					if(tmp>cntt[i]*cntt[j]-cntt[i]-cntt[j])
					tmp=1ll*cntt[i]*cntt[j]-cntt[i]-cntt[j];
				}
			}
		}
		for(int i=1;i<=tott;++i){
			if(tmp<=cntt[i]) break;
			++ans;
		}
		if(tmp!=0x7fffffff&&ans<2) ans=2;
		printf("%d\n",ans);
	}
	return 0;
}
