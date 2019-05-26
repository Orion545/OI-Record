#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#define inf 0x7fffffff
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct node{
	int add,num,in;
}a[50][50];
const int dx[9]={0,1,1,-1,-1,2,2,-2,-2},dy[9]={0,2,-2,2,-2,1,-1,1,-1};
int n,m,opx,opy,edx,edy;
bool vis[50][50];
void bfs(){
	queue<pair<int,int> >q;vis[opx][opy]=1;
	pair<int,int>t;
	t.first=opx;t.second=opy;
	q.push(t);
	int x,y,tx,ty,i,tmp;
	while(!q.empty()){
		t=q.front();q.pop();
		x=t.first;y=t.second;vis[x][y]=0;
//		cout<<"bfs in "<<x<<ends<<y<<endl;
		for(i=1;i<=8;i++){
			tx=x+dx[i];ty=y+dy[i];
			if(tx>0&&tx<=n&&ty>0&&ty<=m&&a[tx][ty].in!=2){
				tmp=(a[tx][ty].in==0);
				t.first=tx;t.second=ty;
				if(a[x][y].add+tmp<a[tx][ty].add){
//					cout<<"	type 1: going to "<<tx<<ends<<ty<<endl;
					a[tx][ty].add=a[x][y].add+tmp;
					a[tx][ty].num=a[x][y].num;
					if(!vis[tx][ty]){
						q.push(t);vis[tx][ty]=1;
					}
					continue;
				}
				if(a[x][y].add+tmp==a[tx][ty].add){
//					cout<<"	type 2: going to "<<tx<<ends<<ty<<endl;
					a[tx][ty].num+=a[x][y].num;
					if(!vis[tx][ty]){
						q.push(t);vis[tx][ty]=1;
					}
					continue;
				}
			}
		}
	}
}
int main(){
	int i,j;
	n=read();m=read();
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			a[i][j].in=read();
			a[i][j].add=inf;
			if(a[i][j].in==3){
				opx=i;opy=j;
				a[i][j].add=0;a[i][j].num=1;
			}
			if(a[i][j].in==4){
				edx=i;edy=j;
			}
		}
	}
	bfs();
	if(a[edx][edy].add==inf) printf("-1");
	else printf("%d\n%d",a[edx][edy].add,a[edx][edy].num);
}
/*

4 5
1 0 0 0 0
3 0 0 0 0
0 0 2 0 0
0 0 0 4 0

*/
