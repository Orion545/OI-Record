#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
const int maxN=110;
struct bian{
	int po,next;
}edge[maxN*2];
int n,m;
char s1,s2;
int p[maxN];
int head[maxN],tot;
int sol[maxN],pre[maxN];
int ans,nans;
bool book[maxN];

void insert(int x,int y)
{
	edge[++tot].po=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

void init()
{
	memset(book,false,sizeof(book));
	memset(sol,-1,sizeof(sol));
	memset(pre,0,sizeof(pre));
	ans=-1;
}

inline void operate(int x,int y)
{
	book[x]=y;
	int t=head[x];
	while(t!=0){
		int k=edge[t].po;
		book[k]=y;
		sol[k]=y;
		t=edge[t].next;
	}
}

inline bool judge()
{
	for(int i=1;i<=n;++i)
		if(book[i]==false)
			return false;
	return true;
}

inline void dfs(int x)
{
	if(judge()){
		if((ans==-1)||(ans>nans))
			ans=nans;
		return;
	}
	if(x==(pre[0]+1))
		return;
	int t=head[pre[x]];
	while(t!=0){
		int y=edge[t].po;
		if(sol[y]==-1&&book[y]==false){
			sol[y]=1;
			nans+=p[y];
			dfs(x+1);
			nans-=p[y];
		}
		book[y]=true;
		t=edge[t].next;
	}
}

void work(int a,int x,int b,int y)
{
	if(x==1)
		operate(a,1);
	else
		operate(a,0);
	if(y==1)
		operate(b,1);
	else
		operate(b,0);
	for(int i=1;i<=n;++i){
		if(sol[i]==-1)
			pre[++pre[0]]=i;
	}
	dfs(1);
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s1>>s2;
	for(int i=1;i<=n;++i)
		cin>>p[i];
	for(int i=1;i<=n-1;++i){
		int u,v;
		cin>>u>>v;
		insert(u,v);
		insert(v,u);
	}
	if(n<=100){
		for(int i=1;i<=m;++i){
			init();
			int a,x,b,y;
			cin>>a>>x>>b>>y;
			work(a,x,b,y);
			cout<<ans<<endl;
		}
	}
}
