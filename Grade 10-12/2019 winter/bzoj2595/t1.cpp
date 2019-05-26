#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#define mp make_pair
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
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
queue<pair<int,int> >q;
int n,m,cnt,a[11][11],dp[11][11][1100],prex[11][11][1100],prey[11][11][1100],pres[11][11][1100],vis[11][11];
void spfa(int s){
//	cout<<"begin spfa "<<s<<'\n';
	int x,y,tx,ty,i;
	while(!q.empty()){
		x=q.front().first;y=q.front().second;q.pop();
		vis[x][y]=0;
//		cout<<"	do spfa "<<x<<' '<<y<<' '<<dp[x][y][s]<<'\n';
		for(i=0;i<4;i++){
			tx=x+dx[i];ty=y+dy[i];
			if(tx<1||tx>n||ty<1||ty>m) continue;
			if(dp[tx][ty][s]>dp[x][y][s]+a[tx][ty]){
				dp[tx][ty][s]=dp[x][y][s]+a[tx][ty];
				prex[tx][ty][s]=x;
				prey[tx][ty][s]=y;
				pres[tx][ty][s]=s;
				if(!vis[tx][ty]){
					vis[tx][ty]=1;
					q.push(mp(tx,ty));
				}
			}
		}
	}
}
void dfs(int x,int y,int s){
//	cout<<"dfs "<<x<<' '<<y<<' '<<s<<' '<<dp[x][y][s]<<' '<<prex[x][y][s]<<' '<<prey[x][y][s]<<' '<<pres[x][y][s]<<'\n';
	vis[x][y]=1;
	if(prex[x][y][s]==0&&prey[x][y][s]==0) return;
	dfs(prex[x][y][s],prey[x][y][s],pres[x][y][s]);
	if(prex[x][y][s]==x&&prey[x][y][s]==y) dfs(prex[x][y][s],prey[x][y][s],s^pres[x][y][s]);
}
int main(){
	n=read();m=read();int i,s,t,j;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) for(s=0;s<1024;s++) dp[i][j][s]=1e9;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			a[i][j]=read();
			if(!a[i][j]) dp[i][j][1<<(cnt)]=0,cnt++;
		}
	}
	for(s=0;s<(1<<cnt);s++){
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				for(t=s;t;t=(t-1)&s){
					if(dp[i][j][t]+dp[i][j][s^t]-a[i][j]<dp[i][j][s]){
						dp[i][j][s]=dp[i][j][t]+dp[i][j][s^t]-a[i][j];
						prex[i][j][s]=i;
						prey[i][j][s]=j;
						pres[i][j][s]=t;
					}
				}
				if(dp[i][j][s]<1e9) q.push(mp(i,j)),vis[i][j]=1;
			}
		}
		spfa(s);
	}
	int ax,ay,f=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(!a[i][j]){
				ax=i;ay=j;
				f=1;break;
			}
		}
		if(f) break;
	}
	if(!f){puts("0");return 0;}
	printf("%d\n",dp[ax][ay][(1<<cnt)-1]);
	memset(vis,0,sizeof(vis));
	dfs(ax,ay,(1<<cnt)-1);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(!a[i][j]) putchar('x');
			else{
				if(!vis[i][j]) putchar('_');
				else putchar('o');
			}
		}
		putchar('\n');
	}
}
