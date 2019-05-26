#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define next zry

using namespace std;

int map[5001][5001],n,a[5001],b[5001],dfn[5001],cnt=0,t=0,son[5001],_t=0,minx=0;
bool check[5001],p=false;


void dfs(int x){
	for(int i=1;i<=n;i++){
		if(map[x][i] && !check[i]){
			printf("%d ",i);
			check[i]=true;
			dfs(i);
		}
	}
}

void _dfs(int x){
	if(t)return;
	dfn[x]=++cnt;
	for(int i=1;i<=n;i++)if(map[x][i] && !check[i])son[x]++;
	for(int i=1;i<=n;i++){
		if(map[x][i] && check[i]){
			if(dfn[i]<dfn[x]-1){
				t=i;
				check[x]=false;
				for(int j=1;j<=n;j++){
					if(map[i][j] && !check[j]){
						minx=j;
						break;
					}
				}
				if(t){
					if(x==t){
						p=true;
						return;
					}
					if(_t && i>minx)map[x][i]=0,map[i][x]=0,p=true;
					if(son[x]>0 && !_t)_t=x;
					return;
				}
				return;
			}
		}
		if(map[x][i] && !check[i]){
			check[i]=true;
			_dfs(i);
			if(p)return;
			if(t){
				if(x==t){
					p=true;
					return;
				}
				if(_t && i>minx)map[x][i]=0,map[i][x]=0,p=true;
				if(son[x]>1 && !_t)_t=x;
				return;
			}
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,xx,y;
	memset(map,0,sizeof(map));
	memset(check,false,sizeof(check));
	memset(son,0,sizeof(son));
	//check[0]=true;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&xx,&y);
		a[i]=xx; b[i]=y;
		map[xx][y]=1;
		map[y][xx]=1;
	}
	if(m==n-1){
		check[1]=true;
		printf("1 ");
		dfs(1);
		return 0;
	}
	else{
		check[1]=true;
		_dfs(1);
		printf("1 ");
		memset(check,false,sizeof(check));
		check[1]=true;
		dfs(1);
		return 0;
	}
	return 0;
}
