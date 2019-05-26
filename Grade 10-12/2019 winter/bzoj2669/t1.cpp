#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 12345678
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
const int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
int ans=0;
int n,m,dp[30][1010],pos[1010],a[10][10],cnt=0;
int calc(){
	int i,j,k,p;cnt=0;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(a[i][j]) a[i][j]=++cnt;
	/*
	cout<<"begin calc "<<cnt<<'\n';
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	*/
	memset(pos,0,sizeof(pos));
	memset(dp,0,sizeof(dp));
	for(p=0;p<(1<<cnt);p++){
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(a[i][j]<=0||((1<<(a[i][j]-1))&p)) continue;
				pos[p]--;
				for(k=0;k<8;k++){
					if(i+dx[k]<1||i+dx[k]>n||j+dy[k]<1||j+dy[k]>m) continue;
					a[i+dx[k]][j+dy[k]]=-1;
				}
			}
		}
		pos[p]+=n*m;
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(a[i][j]==-1){pos[p]--;a[i][j]=0;}
//		cout<<"pos "<<p<<' '<<pos[p]<<'\n';
	}
	/*
	cout<<"begin calc\n";
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	*/
	dp[0][0]=1;
	for(i=1;i<=n*m;i++){
		for(j=0;j<(1<<cnt);j++){
			dp[i][j]=1ll*dp[i-1][j]*(pos[j]-i+1)%MOD;
			for(k=0;k<cnt;k++){
				if((1<<k)&j) dp[i][j]+=dp[i-1][j^(1<<k)];
			}
			dp[i][j]%=MOD;
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
	}
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(a[i][j]) a[i][j]=1;
	/*
	cout<<"finish calc "<<cnt<<'\n';
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	*/
	return dp[n*m][(1<<cnt)-1];
}
void dfs(int x,int y,int num){
//	cout<<"dfs "<<x<<' '<<y<<' '<<num<<'\n';
	if(y==m+1){dfs(x+1,1,num);return;}
	if(x==n+1){ans=(ans+calc()*((num&1)?-1:1)+MOD)%MOD;return;}
	dfs(x,y+1,num);
//	cout<<"try "<<x<<' '<<y<<' '<<a[4][7]<<' '<<a[5][7]<<' '<<a[5][6]<<' '<<a[5][5]<<'\n';
	if(a[x][y]) return;
	for(int i=0;i<8;i++) if(a[x+dx[i]][y+dy[i]]) return;
	a[x][y]=1;
//	cout<<"tagged "<<x<<' '<<y<<'\n';
	dfs(x,y+1,num+1);
	a[x][y]=0;
}
int main(){
	n=read();m=read();int i,j,k;char s[10];
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=1;j<=m;j++){
			if(s[j-1]=='.') continue;
			a[i][j]=1;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]==1){
				for(k=0;k<8;k++)
					if(a[i+dx[k]][j+dy[k]]){puts("0");return 0;}
			}
		}
	}
	dfs(1,1,0);
	cout<<ans<<'\n';
}
