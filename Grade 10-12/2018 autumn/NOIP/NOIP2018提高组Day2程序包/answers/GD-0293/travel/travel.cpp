#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

struct data{
	int a[5001],siz;
	friend bool operator<(const data &dt1,const data &dt2){
		if(dt1.siz<dt2.siz)return false;
		for(int i=1;i<=dt1.siz;++i)if(dt1.a[i]!=dt2.a[i])return dt1.a[i]<dt2.a[i];
		return false;
	}
	inline void clear(){siz=0;memset(a,0,sizeof(a));}
};

bool vis[5001];
vector<int> point[5001];
int n,m,x[5001],y[5001],px,py,final;
data res,minn;

void dfs1(int u,int f){
	printf("%d ",u);
	for(int i=0;i<point[u].size();++i){
		int v=point[u][i];
		if(v!=f)dfs1(v,u);
	}
}

void tree(){dfs1(1,0);}

void dfs3(int u){
	res.a[++res.siz]=u,vis[u]=true;
	for(int i=0;i<point[u].size();++i){
		int v=point[u][i];
		if(!vis[v]&&(u!=px||v!=py)&&(u!=py||v!=px))dfs3(v);
	}
}

void c_tree(){
	for(int i=1;i<=m;++i){
		memset(vis,false,sizeof(vis));
		px=x[i],py=y[i];
		dfs3(1);
		if(res.siz==n&&(res<minn||minn.siz==0))minn=res;
		res.clear();
	}
	for(int i=1;i<=minn.siz;++i)printf("%d ",minn.a[i]);
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d%d",x+i,y+i),point[x[i]].push_back(y[i]),point[y[i]].push_back(x[i]);
	for(int i=1;i<=n;++i)sort(point[i].begin(),point[i].end());
	if(m==n-1)tree();else c_tree();
}
/*
6 5
1 3
2 3
2 5
3 4
4 6

6 6
1 3
2 3
2 5
3 4
4 5
4 6
*/
