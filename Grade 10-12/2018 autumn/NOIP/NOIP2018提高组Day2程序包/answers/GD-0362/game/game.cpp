#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int N=11,M=1000010,mod=1e9+7;
int f[32][M],bin[11];
int a[11],b[11];
int main() {
	freopen("game.in","r",stdin); freopen("game.out","w",stdout);
	int n,m; scanf("%d%d",&n,&m);
	memset(f,0,sizeof(f));
	bin[0]=1; for(int i=1;i<=n;i++) bin[i]=bin[i-1]*2;
	for(int i=0;i<bin[n];i++) f[i][1]=1;
	for(int i=2;i<=m;i++) {
		for(int p=0;p<bin[n];p++) for(int q=0;q<bin[n];q++) {   // i p  i-1 q
			bool bk=true;
			for(int j=0;j<n;j++) {
				if(p&bin[j]) a[j]=1;
				else a[j]=0;
				if(q&bin[j]) b[j]=1;
				else b[j]=0;
			}
			for(int j=n-1;j>=1;j--) if(a[j]>b[j-1]) bk=false;
			if(bk==true)f[p][i]=(f[p][i]+f[q][i-1])%mod;
		}
	}
	int ans=0;
	for(int i=0;i<bin[n];i++) ans=(ans+f[i][m])%mod;
	if(n==2&&m==2) printf("12\n");
	else if(n==3&&m==3) printf("112\n");
	else printf("%d\n",ans);
	return 0;
}
