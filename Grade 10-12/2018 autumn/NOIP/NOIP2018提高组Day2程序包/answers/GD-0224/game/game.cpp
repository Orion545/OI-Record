#include<iostream>
#include<cstdio>
using namespace std;
int n,m,f[10][1000005][2],sum;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[1][1][0]=f[1][1][1]=1;
	for(int i=1;i<=n;i++)
	{
	
		for(int j=1;j<=m;j++){
			f[i][j][1]=f[i][j][0]=(f[i-1][j][0]*2)/(f[i-1][j-1][0]*2)*(f[i-1][j][0]*2)%1000000007;
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i][0][0]=f[i-1][m][0];
		f[i][0][1]==f[i-1][m][1];
		for(int j=1;j<=m;j++){
				f[i][j][1]=(f[i][j-1][0]+f[i][j-1][1])%1000000007;
			for(int k=i-1;k>0;k--){
				if(j+(i-k)>m) break;
				f[i][j][0]=f[i][j][1]*f[k][j+(i-k)][0]/(f[k][j+(i-k)][0]+f[k][j+(i-k)][1])%1000000007;
			}
		}
	}
	cout<<f[n][m][0]+f[n][m][1];
	return 0;
}
