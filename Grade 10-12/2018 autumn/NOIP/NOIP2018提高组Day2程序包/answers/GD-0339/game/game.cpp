#include<cstdio>
#include<algorithm>
#include<set>
#define N 500 
#define mod 1000000007
using namespace std;
int f[N][N];
int n,m,ans,ts,tv;
bool tag[N],co,temp;
struct D{
	int s,v;
};
void DFS(int x,int y,int a,int b,int opt){
	if(x>n||y>m)
		return;
	a=a*2+opt;
	b=b*2+f[x][y];
	if(x==n&&y==m){
		if(a>ts){
			if(b>tv)
				co=false;
		}
		return;
	}
	DFS(x+1,y,a,b,0);
	DFS(x,y+1,a,b,1);
}
void F(int x,int y,int a,int b,int opt){
	if(x>n||y>m)
		return;
	a=a*2+opt;
	b=b*2+f[x][y];
	if(x==n&&y==m){
		ts=a;
		tv=b;
		co=true;
		DFS(1,1,0,0,0);
		if(!co)
			temp=false;
		return;
	}
	F(x+1,y,a,b,0);
	F(x,y+1,a,b,1);
}
void Solve(int x){
	if(x==n){
		for(int i=0;i<(1<<m);i++){
			for(int j=1;j<=m;j++){
				if(i&(1<<(j-1)))
					f[x][j]=1;
				else
					f[x][j]=0;
			}
			temp=true;
			F(1,1,0,0,0);
			if(temp){
				ans++;
			}
		}
		return;
	}
	for(int i=0;i<(1<<m);i++){
		for(int j=1;j<=m;j++){
			if(i&(1<<(j-1)))
				f[x][j]=1;
			else
				f[x][j]=0;
		}
		Solve(x+1);
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	Solve(1);
	printf("%d",ans);
	return 0;
}
