#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,a[105],f[105][25005],sum,p[25005];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for(int h=1;h<=T;h++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(p,0,sizeof(p));
		f[0][0]=1;
		sum=n;
		for(register int i=1;i<=n;i++)
			for(register int j=0;j<=25000;j++){
				f[i][j]=f[i-1][j];
				if(j>=a[i]&&f[i][j-a[i]]) {
					f[i][j]=1;
					if(j!=a[i]) p[j]=1;
				}
			}
		for(int i=1;i<=n;i++)
			if(p[a[i]]) sum--;
		printf("%d\n",sum);
	}
	return 0;
}
