#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int T,n,a[105],E,hb[105],hbcnt,Ans,maxhb;
int dp[105][105];
int bitc(int num){
	int Ret=0;
	while(num){
		if(num&1) Ret++;
		num>>=1;
	}
	return Ret;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++){
		scanf("%d",&n);
		Ans=n; maxhb=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			maxhb=max(maxhb,a[i]);
		}
		E=(1<<n)-1;
		for(int i=1;i<=E;i++){
			if(bitc(i)>=Ans) continue;
			hbcnt=0;
			int tmp=i,Cnt=1;
			while(tmp>0){
				if(tmp&1) hb[++hbcnt]=a[Cnt];
				Cnt++;
				tmp>>=1;
			}
			for(int j=1;j<=hbcnt;j++)
			for(int k=0;k<=maxhb;k++)
				dp[j][k]=0;
			dp[0][0]=1;
			for(int j=1;j<=hbcnt;j++){
				for(int k=0;k<=maxhb;k++)
				if(dp[j-1][k]){
					for(int l=0;hb[j]*l+k<=maxhb;l++)
						dp[j][hb[j]*l+k]=1;
				}
			}
			bool flag=true;
			for(int j=1;j<=n;j++)
				if(!dp[hbcnt][a[j]]) {
					flag=false;
					break;
				}
			if(flag) Ans=bitc(i);
		}
		printf("%d\n",Ans);
	}
	return 0;
}
