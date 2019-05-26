#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("track1.in");
ofstream fout("track.out");
long long x,y,z,n,m,tot,ans,head[400001],to[400001],edge[400001],nex[400001],d[400001];
bool us[400001];
void build(long long x,long long y,long long z){
	to[++tot]=y;
	edge[tot]=z;
	nex[tot]=head[x];
	head[x]=tot;
}
void dfs(long long now){
	for(long long i=head[now];i;i=nex[i]){
		long long y=to[i];
		if(us[y]) continue;
		us[y]=1;
		long long z=edge[i];
		dfs(y);
		ans=max(ans,d[now]+d[y]+z);
		if(d[now]<d[y]+z) d[now]=d[y]+z;
	}
	return;
}
int main(){
	fin>>n>>m;
	for(int i=1;i<n;i++){
		fin>>x>>y>>z;
		build(x,y,z);
		build(y,x,z);
	}
	us[1]=1;
	dfs(1);
	fout<<ans<<endl;
	return 0;
}
