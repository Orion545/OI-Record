#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,_n,a[110];
int f[25010];
int del[110];
int main(void){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--&&~scanf("%d",&_n)){
		memset(del,0,sizeof del);
		memset(f,0,sizeof f);
		for(int i=1;i<=_n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+_n);
		int n=(unique(a+1,a+1+_n)-a-1);
		f[0]=1;
		for(int i=1;i<=n;i++){
			if(f[a[i]]!=0) {
				del[i]=1;
				continue;
			}
			for(int j=0;j<=25000;j++)
				if(f[j]!=0&&a[i]+j<=25000)
					f[a[i]+j]=1;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(del[i]==0)
				++cnt;
		printf("%d\n",cnt);
	}
	return 0;
}
