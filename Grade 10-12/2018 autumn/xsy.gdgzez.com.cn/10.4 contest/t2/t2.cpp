#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<queue>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
struct node{
	int x,y,s;
}; 
const int dx[5]={0,-1,0,1,0},dy[5]={0,0,-1,0,1};
queue<node>q;
int n,m,a[30][30],dp[30][30][300],vis[30][30][300];
int bx[10],by[10],tx[10],ty[10],val[10],pos[10],cntb,cntt;
//b:bomb t:treasure
int main(){
	n=read();m=read();int i,j,stx,sty,x,y,s,xx,yy,ss;char str[30];
	for(i=1;i<=n;i++){
		scanf("%s",str);
		for(j=0;j<m;j++){
			if(isdigit(str[j])){
				cntt++;
				tx[cntt]=i;ty[cntt]=j+1;pos[cntt]=str[j]-'0';
			}
			if(str[j]=='B'){
				cntb++;
				bx[cntb]=i;by[cntb]=j+1;
			}
			if(str[j]=='.'||str[j]=='S') a[i][j+1]=1;
			if(str[j]=='S') stx=i,sty=j+1;
		}
	}
	for(i=1;i<=cntt;i++) val[i]=read();
	
	memset(vis,0,sizeof(vis));memset(dp,0x7f,sizeof(dp));
	dp[stx][sty][0]=0;vis[stx][sty][0]=1;
	q.push((node){stx,sty,0});
	while(!q.empty()){
		x=q.front().x;y=q.front().y;s=q.front().s;vis[x][y][s]=0;
		q.pop();
//		cout<<"bfs "<<x<<' '<<y<<' '<<s<<' '<<dp[x][y][s]<<'\n';
		for(i=1;i<=4;i++){
			xx=x+dx[i];yy=y+dy[i];ss=s;
			if(!a[xx][yy]) continue;
//			cout<<"	to "<<xx<<' '<<yy<<' ';
			if(i==2||i==4){
				for(j=1;j<=cntt;j++)
					if(tx[j]<xx&&max(y,yy)==ty[j]) ss^=(1<<(j-1));
				for(j=1;j<=cntb;j++)
					if(bx[j]<xx&&max(y,yy)==by[j]) ss^=(1<<(j-1+cntt));
			}
//			cout<<ss<<' '<<i<<'\n';
			if(dp[xx][yy][ss]>dp[x][y][s]+1){
				dp[xx][yy][ss]=dp[x][y][s]+1;
				if(!vis[xx][yy][ss]) vis[xx][yy][ss]=1,q.push((node){xx,yy,ss});
			}
		}
	}
	int ans=0;
	for(i=1;i<(1<<cntt);i++){
		if(!dp[stx][sty][i]) continue;
		x=0;
		for(j=0;j<cntt;j++) if(i&(1<<j)) x+=(val[pos[j+1]]);
		ans=max(ans,x-dp[stx][sty][i]);
	}
	cout<<ans;
}
/*
7 7
.......
.1###2.
.#...#.
.#.B.#.
.3...4.
..##...
......S
100
100
100
100

*/
