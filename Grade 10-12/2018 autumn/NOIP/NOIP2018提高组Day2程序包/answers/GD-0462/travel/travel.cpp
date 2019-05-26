#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define il inline
#define rg register
#define ll long long
#define fn "travel"

il char gtc();
il int read();

struct nd{
	int ord,bn;
};

struct e{
	int to,next;
} edge[10005];
int head[5005];
il void addEdge(int,int);

int N,M,u,v;
int ord[5005];
bool vis[5005];

priority_queue<int,vector<int>,greater<int> > q[5005];

void dfs(int);
void bfsn();
int main(){
	freopen(fn".in","r",stdin),
	freopen(fn".out","w",stdout),
	N=read(),M=read();
	for(rg int i=0;i<M;++i)
		u=read(),v=read(),
		addEdge(u,v);
	if(M==N-1)
		dfs(1);
	else
	{
		bfsn();
		int i=0;
		while(q[i].size()!=0){
			while(!q[i].empty())
				ord[++ord[0]]=q[i].top(),
				q[i].pop();
			++i;
		}
	}
	for(rg int i=1;i<=ord[0];++i)
		printf("%d ",ord[i]);
	return 0;
}

void dfs(int x){
	int tmp;
	priority_queue<int,vector<int>,greater<int> > qu;
	ord[++ord[0]]=x,
	vis[x]=true;
	for(rg int i=head[x];i!=0;i=edge[i].next)
		if(!vis[edge[i].to])
			qu.push(edge[i].to);
	while(!qu.empty())
		tmp=qu.top(),
		qu.pop(),
		dfs(tmp);
}
void bfsn(){
	nd tmp;
	queue<nd> qu;
	qu.push((nd){1,0}),
	vis[1]=true;
	while(!qu.empty()){
		tmp=qu.front(),
		q[tmp.bn].push(tmp.ord),
		qu.pop();
		for(rg int i=head[tmp.ord];i!=0;i=edge[i].next)
			if(!vis[edge[i].to])
				qu.push((nd){edge[i].to,tmp.bn+1}),
				vis[edge[i].to]=true;
	}
}
void addEdge(int x,int y){
	edge[++head[0]]=(e){y,head[x]},
	head[x]=head[0],
	edge[++head[0]]=(e){x,head[y]},
	head[y]=head[0];
}
char gtc(){
	static char buff[0xFFFF],*p1=buff,*p2=buff;
	return ((p1==p2)&&(p2=(p1=buff)+fread(buff,1,0xFFFF,stdin)))?(EOF):(*p1++);
}
int read(){
	int t=0;
	char c=gtc();
	while((c<'0')||(c>'9'))
		c=gtc();
	while((c>='0')&&(c<='9'))
		t=t*10+c-'0',
		c=gtc();
	return t;
}
