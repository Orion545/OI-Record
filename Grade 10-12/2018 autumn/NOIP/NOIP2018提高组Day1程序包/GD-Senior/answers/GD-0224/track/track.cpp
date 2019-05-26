#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a,b,c,num[50005],T[50005],vis[50005],dep[50005],DEP,deepest;
vector<int>edge[50005],lon[50005];
bool cmp(int a,int b){
	return a>b;
}
void lie1(){
	int sz=edge[1].size();
	for(int i=0;i<sz;i++){
		num[i]=lon[1][i];
	}
	sort(num,num+sz,cmp);
	int ans=2147483647;
	for(int i=0;i<m;i++)
		ans=min(ans,num[i]+num[m*2-i-1]);
	printf("%d",ans);
}
void lie2(){
	int l=0,r=20040901,mid;
	while(l+1<r){
		mid=(l+r)/2;
		memset(vis,0,sizeof(vis));
		int sum=0,p=1,ss=0;
		vis[1]=1;
		for(int i=0;i<edge[p].size();i++){
			if(!vis[edge[p][i]]){
				sum+=lon[p][i];
				if(sum>=mid) sum=0,ss++;
				vis[edge[p][i]]=1;
				p=edge[p][i];i=-1;
			}
		}
		if(ss>=m) l=mid;
			else r=mid;
	}
	printf("%d",l);
}
void dfs(int o){
	int sz=edge[o].size();
	for(int i=0;i<sz;i++){
		if(!dep[edge[o][i]]){
			dep[edge[o][i]]=dep[o]+lon[o][i];
			if(dep[edge[o][i]]>DEP){
				DEP=dep[edge[o][i]];
				deepest=edge[o][i];
			}
			dfs(edge[o][i]);
		}
	}
}
void lie3(){
	dep[1]=1;
	dfs(1);
	memset(dep,0,sizeof(dep));
	dep[deepest]=1;DEP=0;
	dfs(deepest);
	printf("%d",DEP-1);
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int bol=0;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(b!=a+1) bol=1;
		edge[a].push_back(b);
		edge[b].push_back(a);
		lon[a].push_back(c);
		lon[b].push_back(c);
		T[a]++;
	}
	if(T[1]==n-1) {
		lie1();
		return 0;
	}
	if(!bol){
		lie2();
		return 0;
	}
	if(m==1){
		lie3();
		return 0;
	}
	return 0;
}
