#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define ll long long
#define il inline
#define rg register
#define fileName "track"

il char gtc();
il int read();
il int max(int,int);
il int min(int,int);

struct e{
	int to,val,next;
} edge[100005];
int head[50005];
il void addEdge(int,int,int);

int N,M,a,b,l,ans;
int iin[50005],oin[50005];

void dfs(int,int,int,int&,int&);
int main(){
	freopen(fileName".in","r",stdin),
	freopen(fileName".out","w",stdout),
	N=read(),M=read();
	for(rg int i=1;i<N;++i)
		a=read(),b=read(),l=read(),
		++iin[a],++iin[b],
		addEdge(a,b,l);
	for(rg int i=1;i<=N;++i)
		(iin[i]==1)?(oin[++oin[0]]=i):(0);
	int mx=M,minl=0x7FFFFFFF;
	for(rg int i=head[oin[1]];i!=0;i=edge[i].next)
		dfs(edge[i].to,oin[1],edge[i].val,mx,minl);
	printf("%d\n",ans);
	return 0;
}

void dfs(int x,int fa,int len,int& mx,int& minl){
	if(iin[x]==1){
		--mx;
		if(mx>0)
			minl=min(minl,len);
		else
			++mx,
			ans=max(ans,min(minl,len));
		return;
	}
	for(rg int i=head[x];i!=0;i=edge[i].next)
		if(edge[i].to!=fa)
			dfs(edge[i].to,x,len+edge[i].val,mx,minl);
}
void addEdge(int x,int y,int z){
	edge[++head[0]]=(e){y,z,head[x]},
	head[x]=head[0],
	edge[++head[0]]=(e){x,z,head[y]},
	head[y]=head[0];
}
int max(int a,int b){
	return (a>b)?(a):(b);
}
int min(int a,int b){
	return (a<b)?(a):(b);
}
char gtc(){
	static char buff[0xFFFF],*p1=buff,*p2=buff;
	return ((p1==p2)&&(p2=(p1=buff)+fread(buff,1,0xFFFF,stdin),p1==p2))?(EOF):(*p1++);
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
