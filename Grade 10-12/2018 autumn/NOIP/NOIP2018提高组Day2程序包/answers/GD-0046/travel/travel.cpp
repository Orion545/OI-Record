#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<fstream>
#include<stack>
using namespace std;
const int maxx=5007;
int n,m,ui[maxx],vi[maxx],ti[maxx],ii,tim;
bool f1[maxx],f2[maxx],f3[maxx];
struct st{
	int zi,t;
}dp[maxx];
void add(int u,int v){
	ti[++ii]=ui[u];
	vi[ii]=v;
	ui[u]=ii;
}
bool cmb(int x,int y){
	return x<y;
}
void dfs(int x){
	//cout<<tim<<' ';
	dp[x].t=++tim;
	int lin[maxx],vv=0;
	int k=ui[x];
	while(k!=0){
		lin[++vv]=vi[k];
		k=ti[k];
	}
	sort(lin+1,lin+1+vv,cmb);
	for(int i=1;i<=vv;i++){
		if(!f1[lin[i]]){
			f1[lin[i]]=1;
			if(dp[lin[i]].t==0||x<lin[i]){
				dfs(lin[i]);
			}
			f1[lin[i]]=0;
		}
	}
}
bool abc(st x,st y){
	return x.t<y.t;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++) dp[i].zi=i;
	f1[1]=1;
	dfs(1);
	sort(dp+1,dp+1+n,abc);
	for(int i=1;i<=n;i++){
		printf("%d ",dp[i].zi);
	}
	return 0;
}
