#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxx=30000;
int n,m,ui[maxx],vi[maxx],wi[maxx],ti[maxx],ii,sumw,s;
bool f[maxx];
void add(int u,int v,int w){
	ti[++ii]=ui[u];
	vi[ii]=v;
	wi[ii]=w;
	ui[u]=ii;
}
int dfs(int x,int panx){
	int out=0,ddd[10];
	for(int i=0;i<=8;i++) ddd[i]=0;
	f[x]=1;
	int k=ui[x];
	while (k!=0){
		int v=vi[k];
		if(!f[v]) {
			ddd[++out]=wi[k]+dfs(v,panx);
			if(ddd[out]>=panx) s++,out--;
		}
		k=ti[k];
	}
	sort(ddd+1,ddd+4);
	for(int i=4;i>=1;i--)
		for(int j=i-1;j>=1;j--){
			if(ddd[i]+ddd[j]>=panx) {
				s++;
				ddd[i]=0;
				ddd[j]=0;
				break;
			}
		}
	sort(ddd+1,ddd+4);
	return ddd[1];
}
bool pan(int x){
	if(m*x>sumw) return 0;
	s=0;
	for(int i=1;i<=n;i++)f[i]=0;
	int qqq=dfs(1,x);
	if(qqq>=x) s++;
	if(s==m) return 0;
	if(s<=m) return 1;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n-1;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		sumw+=w;
	}
	int l=1,r=sumw+1;
	while (l< r-1){
		int mid=(l+r)/2;
		if(pan(mid)) l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
