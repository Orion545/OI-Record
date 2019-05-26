#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m;
string type;
int p[maxn];
int mark1[maxn];
int mark2[maxn];
long long dp[maxn][2];
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int u,v;
	int a,b,x,y;
	scanf("%d %d",&n,&m);
	cin>>type;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&u,&v);	
	}
	if(type=="A3"){ 
		for(int i=1;i<=m;i++){
			memset(dp,0x3f,sizeof(dp));
			dp[0][0]=dp[0][1]=0;
			scanf("%d %d %d %d",&a,&x,&b,&y);
			if(a>b){
				swap(a,b);
				swap(x,y);
			}
			for(int i=1;i<=n;i++){
				if(i==a||i==b){
					if(i==a){
						if(x==1) dp[i][1]=min(dp[i-1][0],dp[i-1][1])+p[i];
						else dp[i][0]=dp[i-1][1];
					}else if(i==b){
						if(y==1) dp[i][1]=min(dp[i-1][0],dp[i-1][1])+p[i];
						else dp[i][0]=dp[i-1][1];
					} 
				}else{
					dp[i][0]=dp[i-1][1];
					dp[i][1]=min(dp[i-1][0],dp[i-1][1])+p[i];
				}
			}
			long long ans=0;
			if(b==n){
				if(y==1) ans=dp[n][1];
				else ans=dp[n][0];
				if(ans>=INF) ans=-1;
				printf("%lld\n",ans);
			}else{
				ans=min(dp[n][0],dp[n][1]);
				if(ans>=INF) ans=-1;
				printf("%lld\n",ans);
			}
		}
	}else if(type=="A2"){
		long long sum1=0;
		long long sum2=0;
		long long ans=0;
		for(int i=1;i<=n;i+=2){
			sum1+=p[i];
			mark1[i]=1;
		}
		for(int i=2;i<=n;i+=2){
			sum2+=p[i];
			mark2[i]=1;
		} 
		for(int i=1;i<=m;i++){
			scanf("%d %d %d %d",&a,&x,&b,&y);
			ans=INF;
			if(x==0&&y==0)	ans=-1;
			else if(x==1&&y==0){
				if(a%2) ans=sum1;
				else ans=sum2;
			}else if(x==0&&y==1){
				if(b%2) ans=sum1;
				else ans=sum2;
			}else{
				if(a%2){
					ans=min(ans,sum1+p[b]);
					ans=min(ans,sum2+p[a]);
				}else{
					ans=min(ans,sum1+p[a]);
					ans=min(ans,sum2+p[b]);
				}
			}
			printf("%lld\n",ans);
		}
	} 
}
