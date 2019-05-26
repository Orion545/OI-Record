#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define il inline
#define rg register
#define ll long long
#define fn "defense"

il char gtc();
il int read();

struct nd{
	int ord;
	bool isa;
};

struct e{
	int to,next;
} edge[200005];
int head[100005];
il void addEdge(int,int);

int N,M,u,v,a,x,b,y;
ll ans;
int P[100005];
bool vis[100005];

bool bfs();
int main(){
	freopen(fn".in","r",stdin),
	freopen(fn".out","w",stdout),
	N=read(),M=read(),read();
	for(rg int i=1;i<=N;++i)
		P[i]=read();
	for(rg int i=1;i<N;++i)
		u=read(),v=read(),
		addEdge(u,v);
	for(rg int i=0;i<M;++i)
		a=read(),x=read(),b=read(),y=read(),
		ans=(x==1)?((ll)P[a]):(0LL),
		(bfs())?(printf("%d\n",ans)):(printf("-1\n"));
	return 0;
}

bool bfs(){
	queue<nd> qu;
	nd tmp;
	memset(vis,false,sizeof vis),
	qu.push((nd){a,x}),
	vis[a]=true;
	while(!qu.empty()){
		tmp=qu.front(),
		qu.pop();
		for(rg int i=head[tmp.ord];i!=0;i=edge[i].next)
			if(!vis[edge[i].to]){
				ans+=(tmp.isa)?(0LL):((ll)P[edge[i].to]),
				qu.push((nd){edge[i].to,(tmp.isa)?(false):(true)}),
				vis[edge[i].to]=true;
				if(edge[i].to==b)
					if(y!=(tmp.isa)?(0):(1))
						return false;
			}
	}
	return true;
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
