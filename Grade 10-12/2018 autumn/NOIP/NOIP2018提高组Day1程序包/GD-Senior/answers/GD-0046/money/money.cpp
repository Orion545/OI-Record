#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int dpmaxx=30000,nmaxx=200;
int T,n,a[nmaxx],maxai,s;
bool dp[dpmaxx];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for(int asd=1;asd<=T;asd++){
		scanf("%d",&n);
		maxai=0,s=0;
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			if(a[i]==0) i--,n--;
			maxai=max(maxai,a[i]);
		}
		for(int i=0;i<=maxai;i++) dp[i]=0;
		sort(a+1,a+1+n);
		dp[0]=1;
		for(int i=1;i<=n;i++){
			if(!dp[a[i]]){
				s++;
				for(int j=0;j<=maxai;j++){
					if(j+a[i]>maxai) break;
					if(dp[j]) dp[j+a[i]]=1;
				}
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
