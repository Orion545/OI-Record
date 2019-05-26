
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

struct node{int to,next;}e[10020];
bool vis[10020];
bool vis2[10020];
int left_next=0,right_next=0,all2=0,have2[10020];
int n,m,u,v,head[10020],cnt,all=0,have[10020];
inline void print(){
	for(int i=1;i<=all;i++){
		printf("%d ",have[i]);
	}
}
inline void print2(){
	for(int i=1;i<=all2;i++){
		printf("%d ",have2[i]);
	}
}
inline void dfs(int rt){
	if(all==n){
		return ;
	}
	while(true){
		int minn=10000000;
		for(int i=head[rt];i;i=e[i].next){
			if(e[i].to<minn&&!vis[e[i].to]){
				minn=e[i].to;
			}
		}
		if(minn==10000000) break;
		vis[minn]=true;all++;have[all]=minn;dfs(minn);		
	}
	return ;
}
inline void sos(int rt){
	if(all2==n){
		return ;
	}
	
	if(right_next>left_next){
		all2++;have2[all2]=left_next;vis2[left_next]=true;//cout << have2[all2] << endl;
		for(int i=head[left_next];i;i=e[i].next){
			if(!vis2[e[i].to]){
				left_next=e[i].to;
			}
		}
		sos(left_next);
	}
	else{
		all2++;have2[all2]=right_next;vis2[right_next]=true;//cout << have2[all2] << endl;
		for(int i=head[right_next];i;i=e[i].next){
			if(!vis2[e[i].to]){
				//cout << e[i].to << " " << vis2[e[i].to] << endl;
				right_next=e[i].to;
			}
		}		
		sos(right_next);
	}
	return ;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&n);scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&u);scanf("%d",&v);
		e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;
		e[++cnt].to=u;e[cnt].next=head[v];head[v]=cnt;
	}
	if(m==(n-1)) {vis[1]=true;have[++all]=1;dfs(1);print();}
	if(m==n){
//		if(n==1000){
			vis2[1]=true;have2[++all2]=1;
			int cnt=1;
			for(int i=head[1];i;i=e[i].next,cnt++){
				if(cnt==1) left_next=e[i].to;
				else right_next=e[i].to;
			}
			sos(1);print2();
//		}
//		else{
			
			
//		}
	}
	
	
	
	fclose(stdin);fclose(stdout);
	return 0;
}












