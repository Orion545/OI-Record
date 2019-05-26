#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[105];
bool aa[105];
bool pd(int x,int w){
//	printf("%d %d\n",x,w);
	if(x==0) return true;
	for(int xx=w-1;xx>=0;xx--){
		if(aa[xx]) continue;
		for(int i=1;x-a[xx]*i>=0;i++)
			if(pd(x-a[xx]*i,xx)) return true;
	}
	return false;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int n,t;
	scanf("%d",&t);
	while(t--){
		memset(aa,0,sizeof(aa));
		scanf("%d",&n);
		int ans=0;
		for(int n1=0;n1<n;n1++) scanf("%d",&a[n1]);
		sort(a,a+n);
		for(int n1=0;n1<n;n1++) if(pd(a[n1],n1)) ans++,/*printf("LLL:%d\n",ans),*/aa[n1]=true;
		printf("%d\n",n-ans);
	}
}
