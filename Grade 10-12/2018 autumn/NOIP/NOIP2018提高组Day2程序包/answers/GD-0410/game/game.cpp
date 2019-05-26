#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int N=1e5+5,mo=1e9+7;
int n,m,ans,b[N],c[N],a[50][50],cnt,i;
int read(){
	int sum=0;
	char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') {
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
void make(int x,int y,int z,int t){
	if (x==n&&y==m){
		b[++cnt]=z;
		c[cnt]=t;
		return;
	}
	//if (y>m) dfs(x+1,1);
	if (y<m) make(x,y+1,z*10+1,t*10+a[x][y+1]);
	if (x<n) make(x+1,y,z*10,t*10+a[x+1][y]);
}
bool check(){
	int i,j;
	cnt=0;
	make(1,1,0,0);
	fo(i,1,cnt-1)
	  fo(j,i+1,cnt)  {
	  	  if (b[i]<=b[j]) continue;
	  	  if (c[i]>c[j]) return 0;
	  } 
	return 1;
}
void dfs(int x){
	//if (y>m) dfs(x+1,1);
	if (x==n*m+1){
		if (check()) ++ans;
		return;
	}
	a[(x-1)/m+1][(x-1)%m+1]=1;
	dfs(x+1);
	a[(x-1)/m+1][(x-1)%m+1]=0;
	dfs(x+1);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read();
	if (n==2){
		long long k=4;
		fo(i,1,m-1) k=k*3%mo;
		printf("%d\n",k);
		return 0;
	}
	if (n<=5&&m<=5){
		dfs(1);
		printf("%d\n",ans);
		return 0;
	}
}
