#include<algorithm>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
#define fo(i,a,b) for(i=a;i<=b;i++)
int read(){
	char c=getchar();int x=0;
	for(;'0'>c||'9'<c;c=getchar());
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
const int N=256;
int n,m,f[2][N+5],map[N],ans,dx,la;
bool P;
void doit(int x,int y,int z){
	z=z*2+(map[x]&(1<<(y-1)));
	if(x==n&&y==m){
		if(la>z){P=0;return;}
		la=z;return;
	}
	if(y<m) doit(x,y+1,z);
	if(!P) return;
	if(x<n) doit(x+1,y,z);
	if(!P) return;
}
void dfs(int x){
	int i;
	if(x==n+1){
		P=1;la=0;
		doit(1,1,0);
		if(P)ans++;
		return;
	}
	fo(i,0,(1<<m)-1){
		map[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	n=read(),m=read();
	dfs(1);
	printf("%d\n",ans);
}
