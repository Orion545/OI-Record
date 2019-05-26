#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1E2+5,M=25005;
bool suf[N][M],pre[M];
int a[N],n,T,Ans,Max;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		memset(suf,0,sizeof(suf));
		memset(pre,0,sizeof(pre));
		scanf("%d",&n);Max=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			Max=max(Max,a[i]);
		}suf[n+1][0]=1;
		for(int i=n;i>=1;i--){	
			for(int j=0;j<=Max;j++){
				suf[i][j]|=suf[i+1][j];
				if (j+a[i]<=Max)
					suf[i][j+a[i]]|=suf[i][j];
			}
		}pre[0]=1;Ans=n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=a[i];j++){
				if (pre[j]&&suf[i+1][a[i]-j]){
					Ans--;
					break;
				}
			}for(int j=0;j<=Max-a[i];j++)
				pre[j+a[i]]|=pre[j];
		}printf("%d\n",Ans);
	}
	return 0;
}
