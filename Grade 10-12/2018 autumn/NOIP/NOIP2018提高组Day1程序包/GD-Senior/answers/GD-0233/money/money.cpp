#include<bits/stdc++.h>
using namespace std;
#define N 110
#define maxx 25100
int t,ans[21],tot=0,n,a[N];
bool f[maxx];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int tmp=0;
		memset(f,false,sizeof(f));
		f[0]=true;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(!f[a[i]])tmp++;
			for(int j=0;j<=25000;j++)if(f[j]&&j+a[i]<=25000)f[j+a[i]]=true;
		}
		ans[++tot]=tmp;
	}
	for(int i=1;i<=tot;i++)printf("%d\n",ans[i]);
/*	int check[N];
	for(int i=1;i<=tot;i++){
		scanf("%d",&check[i]);
		if(check[i]!=ans[i]){
			printf("false %d\n",i);
			return 0;
		}
	}*/
}
