#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;

const int maxnode=5011;
int node,line,totloop;
bool inloop[maxnode];
struct edge_inf
{
	int nxt,to;
}edge[maxnode*2];
int head[maxnode],cnt;
int dfn[maxnode],low[maxnode],timetick;
int ans[maxnode],totans;
bool endtarjan=false;

inline void add(int x,int y){
	++cnt;
	edge[cnt].to=y;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}

stack<int> sta;
void tarjan(int father,int now)
{
	low[now]=dfn[now]=++timetick;
	sta.push(now);
	int v;
	for(int i=head[now];i;i=edge[i].nxt)
	{
		v=edge[i].to;
		if(v==father) continue;
		if(dfn[v])
		{
			low[now]=min(low[now],dfn[v]);
		}
		else
		{
			tarjan(now,v);
			low[now]=min(low[now],low[v]);
		}
	}
	int siz=0;
	if(low[now]==dfn[now])
	{
		while(sta.top()!=now)
		{
			++siz;
			inloop[sta.top()]=1;
			sta.pop();
		}
		if(siz>1)
		{
			++totloop;
			inloop[sta.top()]=endtarjan=true;
		}
		sta.pop();
		return;
	}
}

void tanxin(int father,int now)
{
	ans[++totans]=now;
	priority_queue<int, vector<int>,greater<int> > team;
	while(team.empty()==false) team.pop();
	for(int i=head[now];i;i=edge[i].nxt)
	{
		if(edge[i].to!=father)team.push(edge[i].to);
	}
	while(team.empty()==false)
	{
		tanxin(now,team.top());
		team.pop();
	}
}

bool vis[maxnode*2],usedloop,doubled;
int lax;
priority_queue<int, vector<int>,greater<int> > dij;
void sp_tan(int now)
{
//	printf("now in %d\n",now);
	int nobian=0;
	int v;
	vis[now]=true;
	ans[++totans]=now;
	priority_queue<int, vector<int>,greater<int> > team;
	while(team.empty()==false) team.pop();
	
	for(int i=head[now];i;i=edge[i].nxt)
	{
		v=edge[i].to;
		if(!vis[v])
		{
			if(usedloop==false&&inloop[now])
			{
				dij.push(v);
			}
			if(!inloop[v])
			{
//				printf("when %d ++\n",v);
				++nobian;
			}
			team.push(v);
		}
	}
	
	while(team.empty()==false)
	{
		if(inloop[now])
		{
			if(team.top()>dij.top()&&usedloop==false&&nobian==0)
			{
				if(vis[dij.top()])
				{
					dij.pop();
					continue;
				}
				else
				{
					usedloop=true;
					lax=now;
					sp_tan(dij.top());
				}
			}
		}
		
		if(vis[team.top()])
		{
			team.pop();
			continue;
		}
		if(inloop[now])
		{
			if(team.top()>lax&&usedloop==true&&doubled==false&&inloop[team.top()]==true&&nobian==0)
			{
				doubled=true;
//				printf("jump to %d when nobian==%d\n",lax,nobian);
				sp_tan(lax);
			}
		}
//		printf("in %d goto %d\n",now,team.top());
		sp_tan(team.top());
		if(!inloop[team.top()])
		{
//			printf("when %d ++\n",team.top());
			--nobian;
		}
		team.pop();
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int x,y;
	scanf("%d%d",&node,&line);
	for(int i=1;i<=line;++i)
	{
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	if(node==line)
	{
		while(sta.empty()==false) sta.pop();
		tarjan(-1,1);
	}
	
//	for(int i=1;i<=node;++i) cout<<inloop[i];
//	cout<<endl;
	
	if(node!=line) tanxin(-1,1);
	else
	{
		while(dij.empty()==false) dij.pop();
		sp_tan(1);
	}
	
	for(int i=1;i<=node;++i) vis[i]=false;
	for(int i=1;i<=totans-1;++i)
	{
		if(vis[ans[i]]==false) printf("%d ",ans[i]);
		vis[ans[i]]=true;
	}
	if(vis[ans[totans]]==false) printf("%d\n",ans[totans]);
	fclose(stdin);fclose(stdout);
	return 0;
}
