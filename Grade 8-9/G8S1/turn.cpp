#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int dx[5]={0,-1,0,1,0};
const int dy[5]={0,0,-1,0,1};
int n,m;
bool a[101][101];
bool c[101][101]={0};
int b[101][101];
bool vis[101][101]={0};
int x1,x2,y1,y2;
struct node{
	int x,y,turn,way;
}link[1000001];
void bfs(){
	int head=0,tail=1;
	link[1].x=x1;link[1].y=y1;link[1].turn=0;link[1].way=0;
	vis[x1][y1]=1;
	while(head<tail){
		head++;
		for(int i=1;i<=4;i++){
			int tx=link[head].x+dx[i],ty=link[head].y+dy[i];
			if(tx>0&&tx<=n&&ty>0&&ty<=m&&!a[tx][ty]){
				do{
					if(!vis[tx][ty]){
						vis[tx][ty]=1;
						b[tx][ty]=link[head].turn+((link[head].way!=0&&link[head].way!=i)?1:0);
						if(c[tx][ty]){
							tail++;
							link[tail].x=tx;
							link[tail].y=ty;
							link[tail].turn=link[head].turn+((link[head].way!=0&&link[head].way!=i)?1:0);
							link[tail].way=i;
						}
					}
				}while((tx+=dx[i])&&(ty+=dy[i])&&!a[tx][ty]&&tx>0&&tx<=n&&ty>0&&ty<=m);
			}
		}
	}
}
int main(){
	cin>>n>>m;
	memset(a,1,sizeof(a));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<=n+1;i++) a[i][m+1]=1;
	/*
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++){
			cout<<a[i][j]<<ends;
		}
		cout<<endl;
	}
	*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!a[i][j]&&(!a[i+1][j]||!a[i-1][j])&&(!a[i][j+1]||!a[i][j-1])) c[i][j]=1;
			//cout<<c[i][j]<<ends;
		}
		//cout<<endl;
	}
	cin>>x1>>y1>>x2>>y2;
	bfs();
	cout<<b[x2][y2];
} 
/*
5 7
1 0 0 0 0 1 0
0 0 1 0 1 0 0
0 0 0 0 1 0 1
0 1 1 0 0 0 0
0 0 0 0 1 1 0
1 3 1 7

5 7
1 0 0 0 0 1 0
1 0 1 0 0 0 0
1 0 1 0 1 0 0
1 0 1 1 1 1 0
1 0 0 0 0 0 0
1 2 1 7
*/
