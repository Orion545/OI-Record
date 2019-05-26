#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define id(i,j) ((i-1)*5+j)
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
const int dx[8]={3,0,-3,0,2,-2,-2,2},dy[8]={0,3,0,-3,2,2,-2,-2};
int ok[50][50],vis[6][6],opx,opy,edx,edy;
int dfs(int x,int y,int z){
//	cout<<"dfs "<<x<<' '<<y<<' '<<z<<'\n';
	if(x==edx&&y==edy){
		if(z==25){
			vis[edx][edy]=25;
//			cout<<"find "<<opx<<' '<<opy<<' '<<edx<<' '<<edy<<'\n';
			cout<<'{'<<'\n';
			for(int i=1;i<=5;i++){
				cout<<'{';
				for(int j=1;j<=5;j++){
					cout<<vis[i][j];
					if(j!=5) cout<<',';
				}
				cout<<'}';
				if(i!=5) cout<<',';
				cout<<'\n';
			}
			cout<<'}'<<','<<'\n';
			return 1;
		}
		else return 0;
	}
	int i,j,k;vis[x][y]=z;
	for(k=0;k<8;k++){
		i=x+dx[k];
		j=y+dy[k];
		if(i<1||i>5||j<1||j>5||vis[i][j]) continue;
		if(dfs(i,j,z+1)) return 1;
	}
	vis[x][y]=0;
	return 0;
}
int main(){
	for(opx=1;opx<=5;opx+=4){
	for(opy=1;opy<=5;opy+=4){
			cout<<'{'<<'\n';
	for(edx=1;edx<=5;edx+=4){
	for(edy=1;edy<=5;edy+=4){
	if(opx==edx&&opy==edy){
			cout<<'{'<<'\n';
			for(int i=1;i<=5;i++){
				cout<<'{';
				for(int j=1;j<=5;j++){
					cout<<0;
					if(j!=5) cout<<',';
				}
				cout<<'}';
				if(i!=5) cout<<',';
				cout<<'\n';
			}
			cout<<'}'<<','<<'\n';
		continue;
	}
//	cout<<"try "<<opx<<' '<<opy<<' '<<edx<<' '<<edy<<'\n';
	dfs(opx,opy,1);
	memset(vis,0,sizeof(vis));
	}}
			cout<<'}'<<','<<'\n';
	}}
}
