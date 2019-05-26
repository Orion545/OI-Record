#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#define mp make_pair
#define N 300010
vector<int>G[N];
int n,m,low[N],dfn[N];
bool is_cut[N];
int father[N];
int tim=0;
void input()
{
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);/*邻接表储存无向边*/
        G[b].push_back(a);
    }
}
void Tarjan(int i,int Father)
{
    father[i]=Father;/*记录每一个点的父亲*/
    dfn[i]=low[i]=tim++;
    for(int j=0;j<G[i].size();++j)
    {
        int k=G[i][j];
        if(dfn[k]==-1)
        {
            Tarjan(k,i);
            low[i]=min(low[i],low[k]);
        }
        else if(Father!=k)/*假如k是i的父亲的话，那么这就是无向边中的重边，有重边那么一定不是桥*/
            low[i]=min(low[i],dfn[k]);//dfn[k]可能！=low[k]，所以不能用low[k]代替dfn[k],否则会上翻过头了。
    }
}
map<pair<int,int>,int>mm;
void count()
{
    int rootson=0;
    Tarjan(1,0);
    for(int i=2;i<=n;++i)
    {
        int v=father[i];
        if(v==1)
        rootson++;/*统计根节点子树的个数，根节点的子树个数>=2,就是割点*/
        else{
            if(low[i]>=dfn[v])/*割点的条件*/
            is_cut[v]=true;
        }
    }
    if(rootson>1)
    is_cut[1]=true;
//    for(int i=1;i<=n;++i)
//    if(is_cut[i])
//    printf("%d\n",i);
    for(int i=1;i<=n;++i)
    {
        int v=father[i];
        if(v>0&&low[i]>dfn[v]){
			mm[mp(v,i)]=1;
//        	printf("%d,%d\n",v,i);
		}/*桥的条件*/
    }
    
}

int fi[N],belong[N],cnt;
int find(int x){
	return ((fi[x]<0)?x:(fi[x]=find(fi[x])));
}
void join(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	fi[fy]+=fi[fx];fi[fx]=fy;
}
vector<int>g[N];
int q[N],head,tail,dep[N];
void bfs(int op){
	memset(dep,-1,sizeof(dep));
	int i,j;head=0,tail=1;dep[op]=0;
	q[0]=op;
	while(head<tail){
		i=q[head++];
		for(j=0;j<g[i].size();j++){
			if(~dep[g[i][j]]) continue;
			dep[g[i][j]]=dep[i]+1;
			q[tail++]=g[i][j];
		}
	}
}
int main()
{
    input();
    memset(dfn,-1,sizeof(dfn));
    memset(father,0,sizeof(father));
    memset(low,-1,sizeof(low));
    memset(is_cut,false,sizeof(is_cut));
    count();
    int i,j;
    for(i=1;i<=n;i++) fi[i]=-1;
    for(i=1;i<=n;i++){
    	for(j=0;j<G[i].size();j++){
    		if(mm[mp(i,G[i][j])]||mm[mp(G[i][j],i)]) continue;
//    		cout<<"get non cut "<<i<<' '<<G[i][j]<<'\n';
    		join(i,G[i][j]);
		}
	}
    for(i=1;i<=n;i++){
    	if(fi[i]<0) belong[i]=++cnt;
	}
    for(i=1;i<=n;i++){
    	for(j=0;j<G[i].size();j++){
    		if(mm[mp(i,G[i][j])]||mm[mp(G[i][j],i)]){
    			int ff1=find(i),ff2=find(G[i][j]);
    			g[belong[ff1]].push_back(belong[ff2]);
    			g[belong[ff2]].push_back(belong[ff1]);
			}
		}
	}
	bfs(1);
	int dd=0,tmp;
	for(i=1;i<=cnt;i++){
		if(dd<dep[i]) dd=dep[i],tmp=i;
	}
	bfs(tmp);dd=0;
	for(i=1;i<=cnt;i++) dd=max(dd,dep[i]);
	cout<<dd;
    return 0;
}
