#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

int n,m;
struct edge{
	int y,next;
}s[10010];
int first[5010],len=1;
int d[5010],t=0,end=0;
bool stack[5010];
int ans[5010],op[5010];
int isn;
bool we,tf;

void ins(int x,int y){
	len++;
	s[len]=(edge){y,first[x]};first[x]=len;
}

void dfs(int x,int fa,int*ans){
	ans[++ans[0]]=x;
	int t=0;
	priority_queue<int , vector<int> , greater<int> > f;
	for(int i=first[x];i!=0;i=s[i].next){
		int y=s[i].y;
		if(i==isn || i==(isn^1)) continue;
		if(y==fa) continue;
		f.push(y);
	}
	while(!f.empty()){
		int y=f.top();f.pop();
		dfs(y,x,ans);
	}
}

void find_loop(int x,int fa){
	stack[x]=true;
	for(int i=first[x];i!=0;i=s[i].next){
		int y=s[i].y;
		if(y==fa) continue;
		if(stack[y]){
			we=tf=true;
			d[++t]=i;end=y;
			break;
		}
		find_loop(y,x);
		if(tf){
			if(we) d[++t]=i;
			if(x==end) we=false;
			break;
		}
	}
	stack[x]=false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		ins(x,y);
		ins(y,x);
	}
	if(m==n-1) dfs(1,0,ans);
	else{
		int now=1;
		find_loop(1,0);
		isn=d[1];
		dfs(1,0,ans);
		for(int i=2;i<=t;i++){
			op[0]=0;
			isn=d[i];
			dfs(1,0,op);
			for(int j=1;j<=n;j++) if(op[j]<ans[j]){
				for(int k=1;k<=n;k++) ans[k]=op[k];
				break;
			}
			else if(op[j]>ans[j]) break;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}
