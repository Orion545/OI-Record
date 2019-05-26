#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,m,opx,opy,liml,limr,a[2010][2010],qx[8000010],qy[8000010],head=4000000,tail=4000000;
bool vis[2010][2010];int ul[2010][2010],ur[2010][2010];
char s[2010];int ans=0;
void bfs(){
	int i,j,x,y,tx,ty;
	tail++;
	qx[head]=opx;qy[head]=opy;
	ul[opx][opy]=ur[opx][opy]=0;
	while(head<tail){
		x=qx[head];y=qy[head];ans++;head++;
//		cout<<"bfs "<<x<<' '<<y<<' '<<vis[x][y]<<' '<<ul[x][y]<<' '<<ur[x][y]<<'\n';
		vis[x][y]=1;
		i=x+1;
		while(a[i][y]){
//			cout<<"	uuuu "<<i<<' '<<y<<' '<<vis[i][y]<<'\n';
			if(vis[i][y]) break;
			head--;qx[head]=i;qy[head]=y;
//			qx[tail]=i;qy[tail]=y;tail++;
			ul[i][y]=ul[x][y];ur[i][y]=ur[x][y];
			vis[i][y]=1;
			i++;
		}
		i=x-1;
		while(a[i][y]){
//			cout<<"	ddd "<<i<<' '<<y<<' '<<vis[i][y]<<'\n';
			if(vis[i][y]) break;
			head--;qx[head]=i;qy[head]=y;
//			qx[tail]=i;qy[tail]=y;tail++;
			ul[i][y]=ul[x][y];ur[i][y]=ur[x][y];
			vis[i][y]=1;
			i--;
		}
		if(ul[x][y]<liml){
//			cout<<"ll\n";
			if(!(vis[x][y-1]||(a[x][y-1]==0))){
			qx[tail]=x;qy[tail]=y-1;tail++;
			ul[x][y-1]=ul[x][y]+1;
			ur[x][y-1]=ur[x][y];
			vis[x][y-1]=1;
//			cout<<"ll\n";
			} 
		}
		if(ur[x][y]<limr){
//			cout<<"rr\n";
			if(!(vis[x][y+1]||(a[x][y+1]==0))){
				
//			cout<<"rr\n";
			qx[tail]=x;qy[tail]=y+1;tail++;
			ur[x][y+1]=ur[x][y]+1;
			ul[x][y+1]=ul[x][y];
			vis[x][y+1]=1;
		}
		}
//		cout<<head<<' '<<tail<<'\n';
	}
}
int main(){
	n=read();m=read();int i,j;
	opx=read();opy=read();
//	cout<<"finish read\n";
	liml=read();limr=read();
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=0;j<m;j++){
			a[i][j+1]=(s[j]=='.');
		}
	}
//	cout<<"finish read\n";
	bfs();
	cout<<ans<<'\n';
}
/*

20 11
3 10
5 2
..........*
.********.*
.****...*.*
....*.*.*.*
**.**.*.*.*
**.**.*.*.*
**.**.*.*.*
**.**.*.*.*
**.**.*.*.*
**.**.*.*.*
**.**.*.*.*
**.**.*.*.*
**.**.*.*.*
**.**.*.*.*
**.**.*.*.*
**.**.*.*.*
**.**.*.*.*
**.**.*.*.*
**....*...*
*********.*

*/

