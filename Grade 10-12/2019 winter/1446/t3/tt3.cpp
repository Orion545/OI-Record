#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,ch[1010][2],cnt,ans=0,tmp;
inline void check(int u,int dep){
//  cout<<"check "<<u<<' '<<dep<<'\n';
	if(u>=n){tmp=max(tmp,dep);return;}
	if(ch[u][0]) check(ch[u][0],dep+1);
	if(ch[u][1]) check(ch[u][1],dep);
}
int dep[110];
void dfs(int u,int maxd){
	int i;
//  cout<<"dfs "<<u<<'\n';
	if(u==n){
		cnt=n-1;
		for(i=1;i<n;i++){
			if(ch[i][0]==0) ch[i][0]=++cnt;
			if(ch[i][1]==0) ch[i][1]=++cnt;
		}
		tmp=0;
		check(1,0);
		ans+=(tmp<m-1);
		for(i=1;i<n;i++){
			if(ch[i][0]>=n) ch[i][0]=0;
			if(ch[i][1]>=n) ch[i][1]=0;
		}
		return;
	}
	ch[u][0]=ch[u][1]=0;
	dep[1]=1;
	if(u==1) dfs(u+1,1);
	else{
		for(i=1;i<u;i++){
//		  cout<<"   choose "<<i<<' '<<u<<' '<<ch[i][1]<<' '<<ch[i][0]<<'\n';
			if(!ch[i][1]&&dep[i]>=maxd-1){
				ch[i][1]=u;
				dep[u]=dep[i]+1;
				dfs(u+1,max(maxd,dep[u]));
				ch[i][1]=0;
				dep[u]=0;
			}
//		  cout<<"   choose "<<i<<' '<<u<<' '<<ch[i][1]<<' '<<ch[i][0]<<'\n';
			if(!ch[i][0]&&!ch[i][1]&&dep[i]>=maxd-1){
				ch[i][0]=u;
				dep[u]=dep[i]+1;
				dfs(u+1,max(maxd,dep[u]));
				ch[i][0]=0;
				dep[u]=0;
			}
		}
	}
}
int main(){
	n=read();m=read();
	memset(ch,0,sizeof(ch));
	dfs(1,0);
	cout<<ans<<'\n';
}
