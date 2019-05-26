#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int map[5001][5001];

int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}

bool cmp(int l,int r){
	return l<r;
}

int n,m;
int vis[5001];
int mark[5001],ans[5001];
int now;

void exchange(int be,int en){
	while(be<en){
		swap(ans[be],ans[en]);
		be++;
		en--;
	}
	
	
}
void dfs(int u,int f){
	int i,j,v;
	int temp1,temp2;
	ans[now]=u;
	mark[u]=now;
	for(i=1;i<=map[u][0];i++){
		v=map[u][i];
		if(vis[v]&&v!=f){
			temp1=mark[u];
			temp2=mark[v]+1;
			while(temp1>temp2&&ans[temp1]>ans[temp2]){
				temp2++;
			}
			exchange(temp2,temp1);
			continue;
		}		
		if(v!=f&&!vis[v]){
			vis[v]=true;
			now++;
			dfs(v,u);
		}
	}
	if(now==n){
		return ;
	}	
}

int main(){
	int i,j,k;
	int x,y;
	int u;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();
	m=read();
	for(i=1;i<=m;i++){
		x=read();
		y=read();
		map[x][0]++;
		map[x][map[x][0]]=y;
		map[y][0]++;
		map[y][map[y][0]]=x;
	}
	for(i=1;i<=n;i++){
		sort(map[i]+1,map[i]+map[i][0]+1,cmp);
	}
	now=1;
	vis[1]=true;
	dfs(1,0);
	for(i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
	
	
}
