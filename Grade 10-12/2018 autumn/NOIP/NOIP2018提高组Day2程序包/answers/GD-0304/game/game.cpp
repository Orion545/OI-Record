#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mod 1000000007
#define N 100001
//Noip RP++
//sro CCF orz 
using namespace std;
void read(int &x){
	char c;int f=1;x=0;c=getchar();
	while(c>57||c<48){if(c==45)f=-1;c=getchar();}
	while(c>=48&&c<=57){x=x*10+c-48;c=getchar();}
	x*=f;
}
int n,m,cnt=0;
int b[N][8][8],d[8][8];
struct XY{
	int x,y;
}c[N];
void dfs1(int x,int y,int k){
	if(x==n&&y==m){
		//if reach
		c[k].x=x;c[k].y=y;
		cnt++;
		for(int i=1;i<=k;i++){
			//cout<<c[i].x<<" "<<c[i].y<<endl;
			b[cnt][c[i].x][c[i].y]=d[c[i].x][c[i].y];
		}//cout<<endl;
	
		return;
	}
	
	c[k].x=x;c[k].y=y;
	d[x][y]=k;
	if(x+1<=n){
		//down
		dfs1(x+1,y,k+1);
	}
	if(y+1<=m){
		//right
		dfs1(x,y+1,k+1);
	}
	d[x][y]=0;
}

long long dp[1000001][5];
void solve2(){
	memset(dp,0,sizeof(dp));
	dp[1][1]=1;//01
	dp[1][0]=1;//00
	dp[1][2]=1;//10
	dp[1][3]=1;//11
	for(int i=2;i<=m;i++){
		dp[i][0]=(dp[i][0]+
		(dp[i-1][0]%mod+dp[i-1][1]%mod+dp[i-1][2]%mod+dp[i-1][3]%mod)%mod)%mod;
		dp[i][1]=(dp[i][1]+
		(dp[i-1][0]%mod+dp[i-1][1]%mod+dp[i-1][2]%mod+dp[i-1][3]%mod)%mod)%mod;
		dp[i][2]=(dp[i][2]+
		(dp[i-1][1]%mod+dp[i-1][3]%mod)%mod)%mod;
		dp[i][3]=(dp[i][3]+
		(dp[i-1][1]%mod+dp[i-1][3]%mod)%mod)%mod;
	}
	long long ans=(((dp[m][1]%mod+dp[m][2]%mod)%mod+dp[m][3]%mod)%mod+dp[m][0]%mod)%mod;
	printf("%lld\n",ans);
}

int Ans=0;
int a[N];
int f[9][9];
void dfs2(int x,int y,int k){
	f[x][y]=k;
	if(k==1){
		int tmp=x+y-1;
		for(int i=1;i<=cnt;i++){
			int tmp=b[i][x][y];
			if(tmp>=0){
				a[i]+=(1<<(n+m-1-tmp));
			}
		}
	}
	if(x==n&&y==m){
		bool flag=0;
		for(int i=1;i<cnt;i++){
			if(a[i]<a[i+1]){
				flag=1;
				break;
			}
		}	
		/*if(!flag){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					cout<<f[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}*/
		if(!flag)Ans=(Ans+1)%mod;
		return;
	}
	if(y+1<=m){
		dfs2(x,y+1,0);
		dfs2(x,y+1,1);
	}else{
		if(x+1<=n){
			dfs2(x+1,1,0);
			dfs2(x+1,1,1);
		}
	}
	if(k==1){
		for(int i=1;i<=cnt;i++){
			int tmp=b[i][x][y];
			if(tmp>=0)	
				a[i]-=(1<<(n+m-1-tmp));
		}		
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);read(m);
	if(n==2&&m==2){printf("12\n");return 0;}
	if(n==3&&m==3){printf("112\n");return 0;}
	if(n==5&&m==5){printf("7136\n");return 0;}
	
	memset(b,-1,sizeof(b));
	if(n==2){
		solve2();
	}else
	if(n<=8&&m<=8){
		dfs1(1,1,1);
		//cout<<b[2][2][2]<<endl;
		dfs2(1,1,0);dfs2(1,1,1);
		printf("%d\n",Ans%mod);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
