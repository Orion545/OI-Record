#include<iostream>
#include<cstring>
#include<cstdio>
#define inf 0x7fffffff
using namespace std;
int n,mp[310][310];
bool mark[310][310];
const int xx[4]={0,0,1,-1};
const int yy[4]={1,-1,0,0};
struct data{
	int x,y,t;
}q[90001];
void bfs(){
	int t=0,w=1;
	mark[0][0]=1;
	if(mp[0][0]==inf){printf("0");return;}
	while(t<w){
		int x=q[t].x,y=q[t].y,time=q[t].t;
		t++;
		for(int i=0;i<4;i++){
			int nowx=x+xx[i],nowy=y+yy[i];
			if(mark[nowx][nowy]||nowx<0||nowy<0||time+1>=mp[nowx][nowy]) continue;
            if(mp[nowx][nowy]==inf){
				printf("%d",time+1);return;
			}
			q[w].x=nowx;q[w].y=nowy;q[w++].t=time+1;
			mark[nowx][nowy]=1;
		}
	}
	printf("-1");
}
int main()
{
	for(int i=0;i<=305;i++)
	   for(int j=0;j<=305;j++)
	      mp[i][j]=inf;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		mp[x][y]=min(mp[x][y],t);
		for(int j=0;j<4;j++)
		{
			int nowx=x+xx[j],nowy=y+yy[j];
			if(nowx<0||nowy<0)continue;
			mp[nowx][nowy]=min(mp[nowx][nowy],t);
		}
	}
	bfs();
	return 0; 
}
