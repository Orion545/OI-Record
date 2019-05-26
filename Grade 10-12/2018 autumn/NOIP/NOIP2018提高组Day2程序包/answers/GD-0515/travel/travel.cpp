#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define N 12000
using namespace std;
int p[N/2];
int n,m;
vector<int>a[5200];
int dfs(int x,int fa){
	printf("%d ",x);
	int tot=0;
	sort(a[x].begin(),a[x].end());
	for(int i=0;i<a[x].size();i++){
		if(a[x][i]==fa)continue;
		dfs(a[x][i],x);
	}
}
int solve1(){
	dfs(1,0);
}
namespace huan{
	int tot=0,cnt=0;
	int stk[N],h[N];
	int ans[5200][5200];
	int px,py;
	int dfs(int x,int fa){
		stk[++tot]=x;
		p[x]=1;
		for(int i=0;i<a[x].size();i++){
			if(a[x][i]==fa)continue;
			if(p[a[x][i]]==1){
				while(stk[tot]!=p[a[x][i]]){
					h[++cnt]=stk[tot];
					tot--;
				}
				return 1;
			}
			if(dfs(a[x][i],x))return 1;
		}
		p[x]=0;
		stk[tot--]=0;
		return 0;
	}
	int dfs(int x,int fa,int o){
		++ans[o][0];
		ans[o][ans[o][0]]=x;
		for(int i=0;i<a[x].size();i++){
			if(a[x][i]==fa)continue;
			if(a[x][i]==px&&x==py)continue;
			if(a[x][i]==py&&x==px)continue;
			dfs(a[x][i],x,o);
		}
	}
	int solve(){
		dfs(1,0);
		for(int i=1;i<=n;i++)sort(a[i].begin(),a[i].end());
		for(int i=1;i<cnt;i++){
			px=h[i];
			py=h[i+1];
			dfs(1,0,i);
		}
		px=h[1];
		py=h[cnt];
		dfs(1,0,cnt);
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++){
			int x=0x7fffffff;
			for(int j=1;j<=cnt;j++)if(p[j]==0)x=min(x,ans[j][i]);
			for(int j=1;j<=cnt;j++)if(ans[j][i]!=x)p[j]=1;
			printf("%d ",x);
		}
	}
}
int solve2(){
	huan::solve();
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	if(m==n-1)solve1();
	else solve2();
}
