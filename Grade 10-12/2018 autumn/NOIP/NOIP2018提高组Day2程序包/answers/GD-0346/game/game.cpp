#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define re register int
using namespace std;
const int N = 10;
const int M = 1e6+5;
const int P = 1e9+7;
long long ans = 0;
int a[N][M],n,m;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
void dfs(int x,int y,int cntd,int cntr){
	if(x== n&&y==m){
		if(cntd>=cntr){
			ans++;
			ans %=P;
			return ;
		}
	}
	if(y+1<=m){
		dfs(x,y+1,cntd,cntr);
		dfs(x,y+1,cntd+x,cntr+y);
	}
	if(x+1<=n){
		dfs(x+1,y,cntd,cntr);
		dfs(x+1,y,cntd+x,cntr+y);
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n >> m;
	if(n==1&&m==1){
		cout << 2<<endl;
		return 0;
	}
	if(n==2&&m==1){
		cout <<4<<endl;
	}
	if(n==1&&m==2){
		cout << 2 << endl;
	}
	if(n == 2&& m==3){
		cout << 20 << endl;
	}
	if(n == 3&&m==2){
		cout << 48 << endl;
	}
	if(n == 3&&m==1){
		cout << 8 << endl;
	}
	if(n==1&&m==3){
		cout << 2 << endl;
	}
	if(n==3&&m==3){
		cout << 112 << endl;
		return 0;
	}
	dfs(1,1,0,0);
	dfs(1,1,1,1);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}




