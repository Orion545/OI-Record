#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
long long n,m,maxn;
bool ai1=true;
int a[1010][1010],book[1010][1010],w[50010];
void dfs(int x,int len){
	if(len>maxn){
		maxn=len;
	}
	for(int i=1;i<=n;++i){
		if(!book[x][i]&&a[x][i]){
			book[x][i]=1;
			book[i][x]=1;
			dfs(i,len+a[x][i]);
			book[x][i]=0;
			book[i][x]=0;
		}
	}
	return;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n-1;++i){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
		w[i]=z;
		if(x!=1) ai1=false;
	}
	if(ai1){
		sort(w+1,w+n,greater<int>());
		cout<<w[m];
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;++i)
			dfs(i,0);
		cout<<maxn;
		return 0;
	}
	return 0;
}
