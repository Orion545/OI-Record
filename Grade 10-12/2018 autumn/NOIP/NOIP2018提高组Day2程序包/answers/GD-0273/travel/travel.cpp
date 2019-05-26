#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
const int N=5005;
using namespace std;
int read(){
	int ans=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-48;c=getchar();}
	return ans*f;
}
inline int Min(int x,int y){return x>y?y:x;}
int n,m,ne[N*2],fi[N],to[N*2],tot=0;
int tt=0;
void ins(int x,int y){
	ne[++tot]=fi[x];to[tot]=y;fi[x]=tot;
}
bool ye[N];
void so1(int fa,int x){
	printf("%d ",x);ye[x]=1;
	priority_queue<int>q;
	for(int i=fi[x];i;i=ne[i]){
		if(ye[to[i]])continue;
		q.push(-to[i]);
	}
	while(!(q.empty())){
		int p=-q.top();
		q.pop();
		so1(x,p);
	}
}
/************************************************/
int dfn[N],st[N],pp=0,low[N];
int co[N],ss=0,num=0;
bool vis[N],at[N];
void tarjan(int fa,int x){
	dfn[x]=low[x]=++tt;
	st[++pp]=x;vis[x]=1;
	for(int i=fi[x];i;i=ne[i]){
		if(to[i]==fa)continue;
		if(vis[to[i]])low[x]=Min(low[x],dfn[to[i]]);
		else{
			tarjan(x,to[i]);
			low[x]=Min(low[x],low[to[i]]);
		}
	}
	ss=0;
	if(dfn[x]==low[x]){
		
		while(st[pp]!=x){
			co[++ss]=st[pp];
			pp--;
		}
		co[++ss]=st[pp];pp--;
	}
	if(ss>1){
		for(int i=1;i<=ss;i++)at[co[i]]=1;
	}
}
int left=0,first=0;
bool fl=0,xx=0;
void DFS(int fa,int x){
	printf("%d ",x);ye[x]=1;
	priority_queue<int>q;
	if(!at[x]){
		for(int i=fi[x];i;i=ne[i]){
			if(to[i]==fa)continue;
			q.push(-to[i]);
		}
		while(!q.empty()){
			int p=-q.top();q.pop();
			DFS(x,p);
		}
	}
	else{
		if(!left&&!xx){
			first=x;
			for(int i=fi[x];i;i=ne[i]){
				if(to[i]==fa)continue;
				q.push(-to[i]);
			}
			while(!(q.empty())){
				int p=-q.top();q.pop();
				if(left||!at[p])continue;
				if(fl)left=p;
				else fl=1;
			}
		}
		if(!xx){
			for(int i=fi[x];i;i=ne[i]){
				if(to[i]==fa)continue;
				q.push(-to[i]);
			}
			while(!(q.empty())){
				int p=-q.top();q.pop();
				if(!at[p])so1(x,p);
				else{
					if(p<left)DFS(x,p);
					else xx=1;
				}
			}
		}
		if(xx&&x==first)so1(x,left);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	for(int i=1,a,b;i<=m;i++){
		a=read();b=read();
		ins(a,b);ins(b,a);
	}
	if(n==m+1){so1(0,1);return 0;}
	tarjan(0,1);
	for(int i=1;i<=n;i++)vis[i]=0;
	DFS(0,1);
	fclose(stdin);fclose(stdout);
	return 0;
}
