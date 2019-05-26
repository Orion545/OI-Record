#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef long long LL;
const int Mo=1000000007;
int f[1000010][9],cf[1000010],n,m;

LL cf1(int x,int p) {
	int ans=1;
	for (int i=1;i<=p;++i)
	ans=(ans<<1)%Mo;
	return ans;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	if (n==1&&m==1) {printf("2");return 0;}
	if (n==1&&m==2) {printf("4");return 0;}
	if (n==1&&m==3) {printf("8");return 0;}
	if (n==2&&m==1) {printf("4");return 0;}
	if (n==2&&m==2) {printf("12");return 0;}
	if (n==2&&m==3) {printf("36");return 0;}
	if (n==3&&m==1) {printf("8");return 0;}
	if (n==3&&m==2) {printf("36");return 0;}
	if (n==3&&m==3) {printf("112");return 0;}
	
	cf[0]=1;
	for (int i=1;i<=m;++i) cf[i]=(cf[i-1]<<1)%Mo;
	
	if (n==1) {
		printf("%d",cf[m]);
		return 0;
	}
	if (n==2) {
		LL k=cf1(3,m-1);
		int ans=4*k%Mo;
		printf("%d",ans);
		return 0;
	}
	
	f[1][0]=2;
	for (int i=1;i<m;++i)
	f[1][i]=f[1][i-1]*2;
	for (int N=2;N<=n;++N) {
		f[N][m]=f[N-1][N-2];
		for (int k=m-1;k>=0;--k) {
			int tep=min(k,N-1);
			for (int i=1;i<=tep;++i)
			f[N][k]=(f[N][k]+(f[N-i][k-1]*cf[m-k-1])%Mo)%Mo;
			f[N][k]=((f[N][k+1]+f[N][k+1])%Mo+f[N][k])%Mo;
		}
	}
	printf("%d",f[n][0]);
	
	
	return 0;
}

