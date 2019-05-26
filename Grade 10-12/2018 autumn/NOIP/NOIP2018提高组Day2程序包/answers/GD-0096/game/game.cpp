#include<cstdio>
#include<cstring>
using namespace std;
int ans=0,n=3,m=3,a[10][10];
int t,last;
bool check(int x,int y){
	if(x==n&&y==m){
		if(last>t) return false;
		last=t;
	}
	bool pd=true;
	if(y<m) {t=t*2+a[x][y+1];pd&=check(x,y+1);t/=2;}
	if(x<n) {t=t*2+a[x+1][y];pd&=check(x+1,y);t/=2;}
	return pd;
}
bool check2(){
	for(int i=2;i<=n;i++)
		for(int j=1;j<m;j++)
			if(a[i][j]<a[i-1][j+1]) return false;
	return true;
}
int h[11000];
void dfs(int k){
	if(k>n*m){
		t=a[1][1];last=0;
		if(check(1,1)==true){
			int last=0;
			for(int i=1;i<=m;i++){
				int g=0;
				for(int j=n;j>=1;j--)
					g=g*2+a[j][i];
				if(i==m&&g==0) h[last]++;
				last=g;
			}
			ans++;
		}
		return ;
	}
	int y=(k-1)%m+1,x=(k-1)/m+1;
	a[x][y]=0;dfs(k+1);a[x][y]=1;dfs(k+1);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	memset(h,0,sizeof(h));
	dfs(1);printf("%d\n",ans);
}
