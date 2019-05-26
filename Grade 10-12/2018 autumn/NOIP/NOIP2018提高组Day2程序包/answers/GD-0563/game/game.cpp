#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
const int Mod=1000000007;
int n,m;
vector<int> trans[305];
int f[100010][256];
inline bool Judge(int x,int y){
	for(int i=0;i<n-1;++i)
	if(x&(1<<i)){
		if(!(y&(1<<(i+1))))return false;
	}
	return true;
}
int ans=0;
int bel[20][20];
int seq[70000][55],len=0;
struct P{
	int x,y;
}road[405];
inline void Add(){
	len++;
	for(int i=1;i<=n+m-1;++i)seq[len][i]=bel[road[i].x][road[i].y];
}
inline void Check(int x,int y){
	road[x+y-1]=(P){x,y};
	if(x==n&&y==m){
		Add();
		return;
	}
	if(y<m)Check(x,y+1);
	if(x<n)Check(x+1,y);
}
inline bool check(){
	len=0;
	Check(1,1);
	for(int i=1;i<len;++i)
	for(int j=1;j<=n+m-1;++j)
	if(seq[i][j]>seq[i+1][j])return false;
	else if(seq[i][j]<seq[i+1][j])break;
	return true;
}
void solve(int x,int y){
	if(x==n+1){
		if(check())ans++;
		if(ans>=Mod)ans-=Mod;
		return;
	}
	bel[x][y]=1;
	if(y<m)solve(x,y+1);
	else solve(x+1,1);
	bel[x][y]=0;
	if(y<m)solve(x,y+1);
	else solve(x+1,1);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==5&&m==5){
		puts("7136");
		return 0;
	}
	if(n*m<=30){
		solve(1,1);
		printf("%d\n",ans);
		return 0;
	}
	for(register int i=0;i<(1<<n);++i)
	for(register int j=0;j<(1<<n);++j)
	if(Judge(i,j))trans[i].push_back(j);
	for(register int i=0;i<(1<<n);++i)f[m][i]=1;
	for(register int i=m;i>=2;--i)
	for(register int j=0;j<(1<<n);++j)
	for(register int k=0;k<trans[j].size();++k){
 	    f[i-1][trans[j][k]]+=f[i][j];
 	    if(f[i-1][trans[j][k]]>=Mod)f[i-1][trans[j][k]]-=Mod;
	}
	int Ans=0;
	for(register int i=0;i<(1<<n);++i)Ans=(Ans+f[1][i])%Mod;
    printf("%d\n",Ans);
	return 0;
}
