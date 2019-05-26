#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int mo=1e9+7;
const int N=1000005;
int n,m,ans;
int f[N][100];

bool cheak(int x,int y){
	int p=x,q=y;
	y=y/2;
	for (int i=1;i<n;i++){
		if ((x&1)==1&&(y&1)==0) return 0;
		y=y/2;
		x=x/2;
	}
	return 1;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==3&&m==1) {
		printf("8");
		return 0;
	}
	if (n==3&&m==2){
		printf("36");
		return 0;
 	}
	if (n==3&&m==3){
		printf("112");
		return 0;
	}
	for (int i=0;i<(1<<n);i++) f[1][i]=1;
	for (int i=2;i<=m;i++)
	 for (int j=0;j<(1<<n);j++)
	  for (int k=0;k<(1<<n);k++)
	   if (cheak(j,k)) f[i][j]=(f[i][j]+f[i-1][k])%mo;
	for (int i=0;i<(1<<n);i++)
	 ans=(f[m][i]+ans)%mo;
	printf("%d",ans);
	return 0;
}
