#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
int f[10][1000010][2],m,n;
const int M=1e9+7;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	f[1][1][0]=f[1][1][1]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++){
		if (i==1&&j==1) continue;
		if (j+1<=m&&i-1>=1){
			f[i][j][0]=f[i-1][j+1][0];
			f[i][j][1]=f[i-1][j+1][0]+f[i-1][j+1][1];
		}else{
			f[i][j][1]=f[i][j][0]=(f[i][j-1][0]+f[i][j-1][1]);
		}
	//	printf("f[%d][%d][0]=%d [1]=%d\n",i,j,f[i][j][0],f[i][j][1]);
	}
	printf("%d",f[n][m][0]+f[n][m][1]);
	return 0;
}
