#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
ifstream fin("travel.in");
ofstream fout("travel.out");
long long n,m,x,y,a[5001],nua=1,tot,nex[100001],to[100001],head[5001],st=100001;
bool us[5001];
void build(long long x,long long y){
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
long long MIN(long long a,long long b){
	if(a<b) return a;
	return b;
}
void dfs(long long now){
	int y,p[5001],nup=0;
	for(long long i=head[now];i;i=nex[i]){
		y=to[i];
		if(us[y]) continue;
		us[y]=1;
		p[nup]=y;nup++;
	}
	sort(p,p+nup);
	for(int i=0;i<nup;i++){
		a[nua]=p[i];nua++;
		dfs(p[i]);
	}
	return;
}
int main(){
	fin>>n>>m;
	for(long long i=1;i<=m;i++){
		fin>>x>>y;
		st=MIN(MIN(x,y),st);
		build(x,y);
		build(y,x);
	}
	a[0]=st;us[st]=1;
	dfs(st);
	for(long long i=0;i<nua;i++){
		fout<<a[i]<<" ";
	}
	return 0;
}
