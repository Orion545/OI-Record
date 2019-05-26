#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e6+10,MOD=1e9+7;
struct Data{
	int a[10],len;
	friend bool operator < (Data x,Data y){
		for (int i=1;i<=x.len;++i)
			if (x.a[i]==y.a[i]) continue;
			else return x.a[i]<y.a[i];
		return false;
	}
}nowmx,tmprec;
int rec[10][10];
int n,m,cnt;
int plu(int x,int y){return (1LL*x+y)%MOD;}
int mul(int x,int y){return 1LL*x*y%MOD;}
bool check(int x,int y,int step){
	tmprec.a[step]=rec[x][y];
	if (x==n&&y==m){
		tmprec.len=step;
		if (nowmx.len==0){nowmx=tmprec; return true;}
		if (tmprec<nowmx) 
			return false;
		nowmx=tmprec;
		return true;
	}
	bool flag=true;
	if (x<n)
		if (!check(x+1,y,step+1)) flag=false;
	if (y<m&&flag)
		if (!check(x,y+1,step+1)) flag=false;
	return flag;
}
void dfs(int x,int y){
	if (x==n+1){
		tmprec.len=0; nowmx.len=0;
		if (check(1,1,1)){
			++cnt;
			/*for (int i=1;i<=n;++i){
				for (int j=1;j<=m;++j)
					printf("%d ",rec[i][j]);
				printf("\n");
			}
			printf("\n");*/
		}
		return;
	}
	rec[x][y]=1;
	if (y+1>m) dfs(x+1,1);
	else dfs(x,y+1);
	rec[x][y]=0;
	if (y+1>m) dfs(x+1,1);
	else dfs(x,y+1);
}
int ksm(int x,int y){
	int ret=1,base=x;
	for (;y;y>>=1,base=mul(base,base))
		if (y&1) ret=mul(ret,base);
	return ret;
}
void solve1(int n){
	printf("%d\n",ksm(2,n));
}
void solve2(int n){
	printf("%d\n",mul(4,ksm(3,n-1)));
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	scanf("%d%d",&n,&m);
	if (n<=4&&m<=4){
		cnt=0;
		dfs(1,1);
		printf("%d\n",cnt);
	}
	else{
		if (n==1){
			solve1(m);
		}
		else{
			solve2(m);
		}
	}
}
