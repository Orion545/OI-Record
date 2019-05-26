#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int dx[5]={0,-1,0,1,0};
const int dy[5]={0,0,-1,0,1};
int n,m,a[300][300];
int link[100000][2];
int sheep=0,wolf=0;
void bfs(int x,int y){
	int head=0,tail=1,ts=0,tw=0;
	memset(link,0,sizeof(link));
	link[1][0]=x;link[1][1]=y;
	if(a[x][y]==2) ts++;
	if(a[x][y]==3) tw++;
	a[x][y]=1;
	while(head<tail){
		head++;
		for(int i=1;i<=4;i++){
			int tx=link[head][0]+dx[i],ty=link[head][1]+dy[i];
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]!=1){
				tail++;
				link[tail][0]=tx;link[tail][1]=ty;
				if(a[tx][ty]==2) ts++;
				if(a[tx][ty]==3) tw++;
				a[tx][ty]=1;
			}
		}
	}
	if(ts>tw) sheep+=ts;
	else wolf+=tw;
}
int main(){
	for(int i=0;i<=300;i++) for(int j=0;j<=300;j++) a[i][j]=1;
	cin>>n>>m;
	string ssr;
	for(int i=1;i<=n;i++){
		cin>>ssr;
		for(int j=0;j<m;j++){
			switch(ssr[j]){
				case '.':a[i][j+1]=0;break;
				case '#':a[i][j+1]=1;break;
				case 'o':a[i][j+1]=2;break;
				case 'v':a[i][j+1]=3;break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int j=1;
		while(a[i][j]==0){
			a[i][j]=1;j++;
			if(a[i][j]==1) break;
		}
		j=m;
		while(a[i][j]==0){
			a[i][j]=1;j--;
			if(a[i][j]==1) break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==0&&a[i][j+1]==1&&a[i][j-1]==1&&a[i+1][j]==1&&a[i-1][j]==1) a[i][j]=1;
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]) bfs(i,j);
		}
	}
	cout<<sheep<<" "<<wolf;
} 
