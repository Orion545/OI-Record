#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
void read(int &x){
	char c;int f=1;x=0;c=getchar();
	while(c>57||c<48){if(c==45)f=-1;c=getchar();}
	while(c>=48&&c<=57){x=x*10+c-48;c=getchar();}
	x*=f;
}
int n,m;
char typ[2];
int p[3001],dp[3001][3001];
void DP(int a,int x,int b,int y){
	memset(dp,0x3f,sizeof(dp));
	dp[0][1]=0;dp[0][0]=0;
	for(int i=1;i<=n;i++){
		if(i!=a&&i!=b){
			dp[i][0]=min(dp[i][0],dp[i-1][1]);
			dp[i][1]=min(dp[i][1],min(dp[i-1][1],dp[i-1][0])+p[i]);
		}else{
			if(i==a){
				if(x==0){
					dp[i][0]=min(dp[i][0],dp[i-1][1]);
				}else{
					dp[i][1]=min(dp[i][1],min(dp[i-1][1],dp[i-1][0])+p[i]);
				}
			}else if(i==b){
				if(y==0){
					dp[i][0]=min(dp[i][0],dp[i-1][1]);
				}else{
					dp[i][1]=min(dp[i][1],min(dp[i-1][1],dp[i-1][0])+p[i]);
				}				
			}
		}
	}
	int ans=min(dp[n][0],dp[n][1]);
	if(ans>=99999999){
		printf("-1\n");
	}else printf("%d\n",ans);
	return;
}
void solve1(){
	for(int i=1;i<=n;i++){
		read(p[i]);
	}
	for(int i=1;i<n;i++){
		int u,v;
		read(u);read(v);
	}
	for(int i=1;i<=m;i++){
		int a,x,b,y;
		read(a);read(x);read(b);read(y);
		DP(a,x,b,y);
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	read(n);read(m);scanf("%s",typ);
	if(typ[0]=='A'){
		solve1();
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*
5 10 A1
6 5 3 7 4
1 2
2 3
3 4
4 5
4 1 2 0
*/
