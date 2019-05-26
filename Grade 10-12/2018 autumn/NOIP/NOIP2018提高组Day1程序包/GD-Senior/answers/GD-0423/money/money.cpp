#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
long long f[25005],num[200],ans;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	long long t;
	scanf("%lld",&t);
	while(t--){
		long long n;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++)
			scanf("%lld",&num[i]);
		ans=n;
		sort(num+1,num+1+n);
		for(long long i=1;i<=n;i++){
			memset(f,128,sizeof(f));
		//	printf("\n*****%lld*****\n",f[1]);
			f[0]=0;
			for(long long j=1;j<i;j++)
				for(long long k=num[j];k<=num[i];k++)
					f[k]=max(f[k],f[k-num[j]]+num[j]);
			if(f[num[i]]>0){
				ans--;
			//	printf("\n*****%lld*****\n",num[i]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
