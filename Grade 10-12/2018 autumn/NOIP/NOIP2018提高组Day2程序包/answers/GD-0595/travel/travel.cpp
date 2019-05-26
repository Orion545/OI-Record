//NOIP2018day2T1	2018.11.11
//两种情况：一：n-1条边直接按最小字典序深搜 
//二：n条边一定有一个环在里面，dfs先把环找出来，在第二次dfs时再进行特殊处理 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,i,j,k,u,a,b,num,way[10010][3],far[5010],que[5010],t[5010][5010];
bool f,ask[5010],have[5010]; 
int read(){
	int ans=0;char c=getchar();
	while(c < '0' || c > '9')	c=getchar();
	while(c >= '0' && c <= '9'){ans=(ans<<1)+(ans<<3)+c-48;c=getchar();}
	return ans;
}
void dfs1(int x){
	if(f)	return;
	int i,j;
	j=far[x];
	while(j > 0 && !f){
		if(ask[way[j][0]] == false){
			que[++que[0]]=way[j][0];
			ask[way[j][0]]=true;
			dfs1(way[j][0]);
			ask[way[j][0]]=false;
			que[0]--;
		}
		else	if(que[que[0]-1] != way[j][0]){//找到环了 
					f=true;
					i=1;
					while(que[i] != way[j][0] && i <= que[0])	i++;
					while(i <= que[0]){have[que[i]]=true;i++;}
				}
		j=way[j][1];
	}
}
int dfs2(int x){
	printf("%d ",x);
	int i,j,k;
	for(i=1;i <= t[x][0];i++)
		if(ask[t[x][i]] == false){
			if(have[t[x][i]] == false || !f){
				ask[t[x][i]]=true;
				dfs2(t[x][i]);
			}
			else	if(t[x][i] < u){
					for(j=i+1;j <= t[x][0];j++)
						if(have[t[x][j]] && ask[t[x][j]] == false)	u=t[x][j];
					ask[t[x][i]]=true;
					dfs2(t[x][i]);
					}
		}
	if(have[x])	f=false;//环上的点返回了说明环已经破了 
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	for(i=1;i <= m;i++){
		a=read();b=read();
		t[a][++t[a][0]]=b;t[b][++t[b][0]]=a;
		way[++num][0]=b;way[num][1]=far[a];far[a]=num;
		way[++num][0]=a;way[num][1]=far[b];far[b]=num;
	}
	for(k=1;k <= n;k++)
		for(i=1;i <= t[k][0]-1;i++)
			for(j=t[k][0];j >= i+1;j--)
				if(t[k][i] > t[k][j])	swap(t[k][i],t[k][j]);
	//dfs1找环 
	que[0]=que[1]=1;ask[1]=true;f=false;
	dfs1(1);
	//dfs2带特殊处理的寻找答案
	//若f=false代表环已经破了或根本就没环
	memset(ask,0,sizeof(ask));
	u=2147483645;ask[1]=true;
	dfs2(1);
	return 0;
}
