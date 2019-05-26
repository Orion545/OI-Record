#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int mo=1e9+7;
int f[105][1050],n,m,ans;
int s[105][105],d[105][105];
int cnt[100];
int check(){
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++){
		if (i>1&&j>1)s[i][j]=s[i-1][j]|s[i][j-1]|(f[i-1][j]==f[i][j-1]);
	}
	for (int i=n;i>=1;i--)
	for (int j=m;j>=1;j--){
		if (i<n&&j<m)d[i][j]=d[i+1][j]|d[i][j+1]|(f[i+1][j]!=f[i][j+1]);
		if (s[i][j]&&d[i][j])
		return 0;
	}
	return 1;
	
}
void dfs(int x,int y){
	if (y>m){
		y=1;
		x++;
	}
	if (x>n){
		ans+=check();
		return;
	}
	f[x][y]=0;
	if (f[x-1][y+1]==0)dfs(x,y+1);
	f[x][y]=1;dfs(x,y+1);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if (n==2){
		int fi=0;
		for (int i=0;i<1<<n;i++)f[fi][i]=1;
		for (int u=2;u<=m;u++){
			fi^=1;memset(f[fi],0,sizeof f[fi]);
			for (int i=0;i<1<<n-1;i++)
			f[fi][i+(1<<n-1)]=(f[fi^1][i*2]+f[fi^1][i*2+1])%mo;
			for (int j=0;j<n;j++)
			for (int i=0;i<1<<n;i++)
				if (i&(1<<j))(f[fi][i^(1<<j)]+=f[fi][i])%=mo;
		}
		int ans=0;
		for (int i=0;i<1<<n;i++)ans=(ans+f[fi][i])%mo;
		cout<<ans<<endl;
		return 0;
	}
	ans=0;
	dfs(1,1);
	cout<<ans<<endl;
}
