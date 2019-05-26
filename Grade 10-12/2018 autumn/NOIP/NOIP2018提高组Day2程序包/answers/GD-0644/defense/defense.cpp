#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("defense.in");
ofstream fout("defense.out");
long long a,ua,b,ub,x,y,z,n,m,d[2][100001],hf[100001],tot,head[100001],to[200001],nex[200001],pdd[100001];
bool us[100001],fl1;
long long MIN(long long a,long long b){
	if(a<b) return a;
	return b;
}
void build(long long x,long long y){
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
string pd;
void dfs(int now){
	long long y;
	d[1][now]=hf[now];d[0][now]=0;
	for(int i=head[now];i;i=nex[i]){
		y=to[i];
		if(us[y]) continue;
		us[y]=1;
		dfs(y);
		if(pdd[y]==1){
			d[0][now]+=d[1][y];
			d[1][now]+=d[1][y];
			continue;
		}
		if(pdd[y]==2){
			d[1][now]+=d[0][y];
			pdd[now]=1;
			continue;
		}
		d[0][now]+=d[1][y];
		d[1][now]+=MIN(d[0][y],d[1][y]);
	}
	return;
}
int main(){
	fin>>n>>m>>pd;
	for(int i=1;i<=n;i++) fin>>hf[i];
	for(int i=1;i<n;i++){
		fin>>x>>y;
		build(x,y);
		build(y,x);
	}
	for(int i=1;i<=m;i++){
		fl1=0;
		for(int i1=1;i1<=n;i1++) us[i1]=0,pdd[i1]=0;
		fin>>a>>ua>>b>>ub;
		if(ua==1) pdd[a]=1;
		else pdd[a]=2;
		if(ub==1) pdd[b]=1;
		else pdd[b]=2;
		us[a]=1;
		if(ua==0&&ub==0){
			for(long long i1=head[a];i1;i1=nex[i1]){
				if(to[i1]==b){
					fl1=1;break;
				}
			}
			if(fl1){
				fout<<-1<<endl;
				continue;
			}
		}
		dfs(a);
		if(ua==1) fout<<d[1][a]<<endl;
		else fout<<d[0][a]<<endl;
	}
	return 0;
}
