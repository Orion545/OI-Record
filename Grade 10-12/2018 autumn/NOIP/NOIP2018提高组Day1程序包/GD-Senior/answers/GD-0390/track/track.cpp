#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct hehe{
	int to,l;
};
vector<hehe> map[50001];
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
int n,m;
long long dis[50001];
int junjie[50001],top;
int dd[50001][20],depth[50001];

bool cmp(int l,int r){
	return dis[l]>dis[r];
}

void dfs(int u,int f){
	int i,v;
	depth[u]=depth[f]+1;
	for(i=0;i<19;i++){
		dd[u][i+1]=dd[dd[u][i]][i];
	}
	
	for(i=0;i<map[u].size();i++){
		v=map[u][i].to;
		if(v!=f){
			dis[v]+=dis[u]+map[u][i].l;
			dd[v][0]=u;
			dfs(v,u);
		}
	}
	if(map[u].size()==1&&v==f){
		junjie[++top]=u;
	}	
} 

int lca(int x,int y){
	int i;
	if(depth[x]<depth[y]){
		swap(x,y);
	}
	for(i=19;i>=0;i--){
		if(depth[dd[x][i]]>=depth[y]){
			x=dd[x][i];
		}
		if(x==y){
			return x;
		}
	}
	for(i=19;i>=0;i--){
		if(dd[x][i]!=dd[y][i]){
			x=dd[x][i];
			y=dd[y][i];
		}
	}
	return dd[x][0];
}
long long ans;

int main(){
	int i,j;
	int x,y,z;
	int be;
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();
	m=read();
	for(i=1;i<n;i++){
		x=read();
		y=read();
		z=read();
		map[x].push_back(hehe{y,z});
		map[y].push_back(hehe{x,z});
	}	
	dfs(1,0);
	if(m==1){
		for(i=1;i<=top;i++){
			for(j=1;j<i;j++){
				ans=max(ans,dis[junjie[i]]+dis[junjie[j]]-2*dis[lca(junjie[i],junjie[j])]);
	//			cout<<junjie[i]<<" "<<junjie[j]<<" "<<lca(junjie[i],junjie[j])<<" "<<dis[junjie[i]]<<" "<<dis[junjie[j]]<<" "<<2*dis[lca(junjie[i],junjie[j])]<<endl;
			}
			
		}		
	}
	else{
		sort(junjie+1,junjie+1+top,cmp);	
		ans=0x3f3f3f;
		be=1;
		while(top-be+1<2*m){
			ans=min(dis[junjie[be]],ans);	
			be++;
			m--;
		}
		for(i=be;i<=be+m;i++){
			ans=min(ans,dis[junjie[i]]+dis[junjie[2*m+2*be-i-1]]);
		}
	}

	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
	
	
	
	
	
}
