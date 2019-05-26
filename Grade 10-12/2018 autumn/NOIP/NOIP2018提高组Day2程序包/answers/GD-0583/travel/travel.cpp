#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int n,m,h[10001],tot=0,head[10001],vi[100001],c=0;
struct stu{
	int to,nxt;
}edg[10001];
bool cmp(stu a,stu b){
	return a.to<b.to;
}
void add(int x,int y){
	edg[++tot].nxt=head[x];
	head[x]=tot;
	edg[tot].to=y;
}
void dfs(int st){
	cout<<st<<" ";
		if(c==n)return ;
	
	for(int i=head[st];i;i=edg[i].nxt){
		int v=edg[i].to;
		if(!vi[v]){
			dfs(v);
			vi[st]=1;
			h[++c]=v;
		
		}
		
	}
	return ;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	sort(edg+1,edg+1+m*2,cmp);
	dfs(1);
	cout<<endl;
	for(int i=1;i<=c;i++){
		cout<<h[i]<<" ";
	}
	return 0;
}
