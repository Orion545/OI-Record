#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int dx[5]={0,-1,0,1,0},dy[5]={0,0,-1,0,1};
int r,c;
struct node{
	int tx[5],ty[5],fx,fy,x,cnt,belong;
	node(){
		cnt=0;fx=fy=0;
		memset(tx,0,sizeof(tx));
		memset(ty,0,sizeof(ty));
	}
}a[51][51];
struct e{
	int tx,ty,next;
}edge[10010];
bool vis[51][51],exe[51][51];
int isx[20],isy[20],n=0,first[2500];
pair<int,int> find(int x,int y){
	pair<int,int>re;
	if(a[x][y].fx==x&&a[x][y].fy==y){
		re.first=x;re.second=y;return re;
	}
	else return find(a[x][y].fx,a[x][y].fy);
}
void bfs(){
	queue<pair<int,int> >q;queue<int>qq;
	pair<int,int>tmp(1,1),top;q.push(tmp);
	qq.push(0);vis[1][1]=1;
	int x,y,tx,ty,i,tt,newnode;
	while(!q.empty()){
		top=q.front();q.pop();
		tt=qq.front();qq.pop();
		x=top.first;y=top.second;newnode=0;
//		cout<<x<<ends<<y<<endl;
		exe[x][y]=1;
		for(i=1;i<=4;i++){
			tx=x+dx[i];ty=y+dy[i];
//			cout<<"	to "<<tx<<ends<<ty<<ends<<a[tx][ty].x<<endl;
			if(tx>0&&tx<=r&&ty>0&&ty<=c&&!exe[tx][ty]){
//				cout<<"		suc"<<endl;
//				vis[tx][ty]=1;
				if(!a[x][y].x){
//					cout<<"			t0"<<endl;
					if(!vis[tx][ty]){
						tmp.first=tx;tmp.second=ty;
						q.push(tmp);qq.push(0);vis[tx][ty]=1;
					}
				}
				else{
					++a[x][y].cnt;
					a[x][y].tx[a[x][y].cnt]=tx;a[x][y].ty[a[x][y].cnt]=ty;
					if(a[x][y].x==1){
//						cout<<"			t1"<<endl;
						if(!vis[tx][ty]){
							tmp.first=tx;tmp.second=ty;
							q.push(tmp);
							vis[tx][ty]=1;
							if(a[tx][ty].x!=2) qq.push(0);
							else qq.push(1);
						}
					}
					if(a[x][y].x==2){
//						cout<<"			t2"<<endl;
						if(!vis[tx][ty]){
							tmp.first=tx;tmp.second=ty;
							q.push(tmp);
							vis[tx][ty]=1;
							if(a[tx][ty].x!=2) qq.push(0);
							else{
								qq.push(tt+1);a[tx][ty].fx=x;a[tx][ty].fy=y;
							}
						}
						if(a[tx][ty].x==2) newnode++;
					}
				}
			}
			if(a[x][y].x==2&&i==4&&newnode==0){
				cout<<x<<ends<<y<<ends<<a[x][y].fx<<ends<<a[x][y].fy<<" new island"<<endl;
				tmp=find(x,y);
				isx[++n]=tmp.first;isy[n]=tmp.second;
				a[tmp.first][tmp.second].belong=n;
			}
		}
	}
}
int m=0;
int main(){
	int i,j,t,tmp,ul;pair<int,int>ttt;char str[50];
	memset(first,-1,sizeof(first));
	scanf("%d%d",&r,&c);
	for(i=1;i<=r;i++){
		scanf("%s",str);
		for(j=0;j<c;j++){
			if(str[j]=='.') a[i][j+1].x=0;
			if(str[j]=='S') a[i][j+1].x=1;
			if(str[j]=='X'){
				cout<<i<<ends<<j<<endl;
				a[i][j+1].x=2;a[i][j+1].fx=i;a[i][j+1].fy=j+1;
			} 
		}
	}
	bfs();
//	cout<<n<<endl;
//	for(i=1;i<=n;i++) cout<<isx[i]<<ends<<isy[i]<<endl;
	for(i=1;i<=r;i++){
		for(j=1;j<=c;j++){
			if(a[i][j].x==2){
				ttt=find(i,j);
				int t_t=a[ttt.first][ttt.second].belong;
				for(tmp=1;tmp<=4;tmp++){
					if(a[i][j].tx[tmp]==0&&a[i][j].ty[tmp]==0) break;
					for(t=first[t_t];~t;t=edge[t].next){
						if(edge[t].tx==a[i][j].tx[tmp]&&edge[t].ty==a[i][j].ty[tmp]) goto jump;
					}
					m++;edge[m].tx=a[i][j].tx[tmp];edge[m].ty=a[i][j].ty[tmp];edge[m].next=first[t_t];first[t_t]=m;
					m++;edge[m].tx=i;edge[m].ty=j;
					edge[m].next=first[((a[i][j].tx[tmp]-1)*c+a[i][j].ty[tmp])];
					first[((a[i][j].tx[tmp]-1)*c+a[i][j].ty[tmp])]=m;
					jump:ul++,ul--;
				}
			}
		}
	}
}
