#include <cmath>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
//Constant
const int N=3;
const int M=1000000;
const int T=1000000;
const int FULL=(1<<N+1)-1;
const int MOD=1000000007;
//Quick Read
int Read(){
	int x=0;
	bool neg=false;
	char c=getchar();
	while(isdigit(c)==false)neg^=c=='-',c=getchar();
	while(isdigit(c)==true)x=x*10+c-'0',c=getchar();
	return neg==true?-x:x;
}
inline void Read(int &x){x=Read();}
//DFS
int n,m,ans;
int cnt,temp[T+1];
int map[N+1][M+1];
void Check(int x,int y,int s){
	if(x==n&&y==m){
		temp[++cnt]=s*2+map[x][y];
		return;
	}
	if(x<n)Check(x+1,y,s*2+map[x][y]);
	if(y<m)Check(x,y+1,s*2+map[x][y]);
}
void DFS(int x,int y){
	if(y>m)++x,y=1;
	if(x>n){
		bool ok=true;
		cnt=0,Check(1,1,0);
		for(int i=2;i<=cnt;++i)
			if(temp[i]>temp[i-1])ok=false;
		if(ok==true)++ans;
		return;
	}
	map[x][y]=0,DFS(x,y+1);
	map[x][y]=1,DFS(x,y+1);
}
//Main
int f[M+1][FULL],tot[FULL+1],from[FULL+1][FULL+1];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	Read(n),Read(m);
	if(n==2){
		int full=(1<<n)-1;
		for(int i=0;i<=full;++i)
			for(int j=0;j<=full;++j){
				bool ok=true;
				for(int k=0;k<n-1;++k){
					int b2=1<<k+1;
					for(int p=0;p<=k;++p){
						int b1=1<<p;
						if((j&b2)<(i&b1))ok=false;
					}
				}
				if(ok==true)from[i][++tot[i]]=j;
			}
		for(int i=0;i<=full;++i)f[1][i]=1;
		for(int i=2;i<=m;++i)
			for(int j=0;j<=full;++j)
				for(int k=1;k<=tot[j];++k){
					f[i][j]+=f[i-1][from[j][k]];
					if(f[i][j]>=MOD)f[i][j]-=MOD;
			}
		for(int i=0;i<=full;++i)ans+=f[m][i];
		printf("%d\n",ans);
	}
	else{
		DFS(1,1);
		printf("%d\n",ans);
	}
	return 0;
}

