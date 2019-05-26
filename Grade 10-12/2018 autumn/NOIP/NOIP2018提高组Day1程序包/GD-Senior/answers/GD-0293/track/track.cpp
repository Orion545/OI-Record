#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct edge{
	int v,w;
	edge():v(0),w(0){}
	edge(int y,int z):v(y),w(z){}
};

bool cklist=true,ckflower=true;
int n,m,x,y,w,maxd[50001],maxn1,maxn2,lista[50001],flowera[50001];
vector<edge> point[50001];

void dfs(int u,int f){
	for(int i=0;i<point[u].size();++i){
		int v=point[u][i].v,w=point[u][i].w;
		if(v!=f)dfs(v,u),maxd[u]=max(maxd[u],maxd[v]+w);
	}
}

void mequal1(){
	dfs(1,0);
	for(int i=0;i<point[1].size();++i){
		int k=maxd[point[1][i].v]+point[1][i].w;
		if(k>maxn1)maxn2=maxn1,maxn1=k;else if(k>maxn2)maxn2=k;
	}
	printf("%d",maxn1+maxn2);
}

bool check(int x){
	int length=0,cnt=0;
	for(int i=1;i<n;++i){
		length+=lista[i];
		if(length>=x)length=0,++cnt;
	}
	return cnt>=m;
}

void list_(){
	int l=1,r=500000000,M,ans=l;
	while(l<=r)if(check(M=l+r>>1))l=(ans=M)+1;else r=M-1;
	printf("%d",ans);
}

void flower(){
	sort(flowera+1,flowera+n);
	int ans=2147483647;
	while(m*2>=n)ans=min(ans,flowera[n-1]),--n,--m;
	int l=n-(m<<1);
	ans=min(ans,flowera[n-1]+flowera[l]);
	for(int j=2;j<=m;++j)ans=min(ans,flowera[n-j]+flowera[l+j-1]);
	printf("%d",ans);
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i){
		scanf("%d%d%d",&x,&y,&w),point[x].push_back(edge(y,lista[x]=w)),point[y].push_back(edge(x,flowera[y-1]=w));
		if(y!=x+1)cklist=false;if(x!=1)ckflower=false;
	}if(cklist)list_();else if(ckflower)flower();else mequal1(); 
}
/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7

8 3
1 2 4
2 3 6
3 4 5
4 5 7
5 6 9
6 7 10
7 8 1
*/
