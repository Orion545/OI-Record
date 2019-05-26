#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=5e3+5,MAXM=MAXN<<1;

int head[MAXM],nxt[MAXM],v[MAXM],w[MAXM],cnt;

int n,m;

inline void Addline(int x,int y)
{
	v[cnt]=y;
	nxt[cnt]=head[x],head[x]=cnt++;
	
	return;
}

inline void DFS1(int x,int from)
{
	printf("%d ",x);
	
	int que[MAXN],tail=0;
	
	for(int i=head[x];~i;i=nxt[i])
		if(v[i]!=from)
			que[++tail]=v[i];
	
	sort(que+1,que+tail+1);
	
	for(int i=1;i<=tail;i++)
		DFS1(que[i],x);
	
	return;
}

inline void SubWork1(void)
{
	DFS1(1,0);
	
	return;
}

int ans[MAXN];
int temp[MAXN],dad[MAXN],tag[MAXN];

inline void DEBUG(void)
{
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	putchar('\n');
}

bool c[MAXN];

inline void DFS2(int x,int from,int step)
{
	if(!tag[x])
		dad[x]=from,temp[step]=x;
	tag[x]++;
	
	if(step==n)
	{
		bool flag=false;
		
		for(int i=1;i<=n;i++)
		{
			if(temp[i]<ans[i])
			{
				flag=true;
				break;
			}
			
			if(temp[i]>ans[i])
			{
				flag=false;
				break;
			}
		}
			
		if(flag||ans[1]==0)
		{
			for(int i=1;i<=n;i++)
				ans[i]=temp[i];
		}
		
		tag[x]--;
		return;
	}
	
	//DEBUG();
	
	for(int i=head[x];~i;i=nxt[i])
		if(!tag[v[i]])
			DFS2(v[i],x,step+1);
		
	if(from&&c[x])
		DFS2(from,dad[from],step);
	
	tag[x]--;
	return;
}

int stack[MAXN],top;
bool vis[MAXN];
inline void DFS3(int x,int from)
{
	vis[x]=true;
	stack[++top]=x;
	for(int i=head[x];~i;i=nxt[i])
		if(v[i]!=from)
		{
			if(vis[v[i]])
			{
				while(stack[top]!=v[i])
					c[stack[top--]]=true;
				c[stack[top--]]=true;
				return;	
			}
		}
	
	--top;
	vis[x]=false;
	
	return;
}

inline void SubWork2(void)
{
	DFS2(1,0,1);
	
	DFS3(1,0);
	
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	
	return;
}

signed main(void)
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(head,-1,sizeof head);
	
	cin>>n>>m;
	
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		Addline(x,y),Addline(y,x);
	}
	
	if(m==n-1)
		SubWork1();
	else
		SubWork2();
	
	return 0;
}
