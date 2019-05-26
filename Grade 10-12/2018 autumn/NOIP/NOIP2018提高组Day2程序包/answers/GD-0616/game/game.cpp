#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int n,m,i,j,res,ans,f[257][1000001],pd;
bool check(int s1,int s2){
	pd=1;
	if((s1&(1<<(n-1)))==0) pd=0;
	for(int u=n-2;u>=0;u--){
		if(pd==0&&(s2&(1<<u))>0) return 1;
		if((s1&(1<<u))==0) pd=0;
	}
	pd=1;
	if((s2&(1<<(n-1)))==0) pd=0;
	for(int u=n-2;u>=0;u--){
		if(pd==0&&((s2&(1<<u))>0)) return 1;
		if((s2&(1<<u))==0) pd=0;
	}
	return 0;
}
bool check1(int s1,int s2){
	pd=1;bool pd1=1;
	if((s1&(1<<(n-1)))==0) pd=0;
	if((s2&(1<<(n-1)))==0) pd1=0;
	for(int u=n-2;u>=0;u--){
		if(pd==0&&pd1==0&&((s2&(1<<u))>0)) return 1;
		if((s1&(1<<u))==0) pd=0;
	    if((s2&(1<<u))==0) pd1=0;
	}
	return 0;
}
int dfs(int situ,int o){
	int res=0;
	if(f[situ][o]>0) return f[situ][o];
	for(int i=0;i<=(1<<n)-1;i++)
	if(o+1<m){
	  if(check(situ,i)==0) 
	    res+=dfs(i,o+1),res=res%MOD;
	}else{
		if(check1(situ,i)==0)
		  res+=dfs(i,o+1),res=res%MOD;
	}
	f[situ][o]=res;
	return res;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=0;i<=(1<<n)-1;i++){
		res=2;pd=1;
		if((i&(1<<(n-1)))==0) pd=0;
		for(j=n-1;j>=1;j--){
			if(pd>0){
				res*=2;res=res%MOD;
			}
			if((i&(1<<(j-1)))==0) pd=0;
		}
		f[i][m]=res%MOD;
	}
	ans=dfs((1<<n)-1,1);
	printf("%d\n",ans);
}
