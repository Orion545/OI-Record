#include<cstdio>
#include<cstring>
int h[5000],des[10000],nxt[10000];
int in_circle[5000],visited[5000],position;
void dfs(int p,int f)
{
	printf("%d ",p+1);
	for(int i=h[p];i!=-1;i=nxt[i])
		if(des[i]!=f)
			dfs(des[i],p);
}
int find_circle(int p,int f)
{
	visited[p]=1;
	for(int i=h[p];i!=-1;i=nxt[i])
		if(des[i]!=f)
		{
			if(visited[des[i]])
			{
				in_circle[p]=1;
				position=p;
				return des[i];
			}
			int ans=find_circle(des[i],p);
			in_circle[p]=(ans!=-1)?1:0;
			if(in_circle[p])
				return (ans!=p)?ans:-1;
		}
	return -1;
}
void travel(int p)
{
	if(p==position)
		position=65535;
	visited[p]=1;
	printf("%d ",p+1);
	for(int i=h[p];i!=-1;i=nxt[i])
		if(!visited[des[i]])
		{
			if(in_circle[des[i]])
				if(des[i]<=position)
					travel(des[i]);
				else
					position=65535;
			else
				dfs(des[i],p);
		}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(h,-1,sizeof(h));
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0,u,v,p;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		u--;
		v--;
		des[2*i]=v;
		if((h[u]==-1)||(des[h[u]]>v))
		{
			nxt[2*i]=h[u];
			h[u]=2*i;
		}
		else
		{
			for(p=h[u];(nxt[p]!=-1)&&(des[nxt[p]]<v);p=nxt[p]);
			nxt[2*i]=nxt[p];
			nxt[p]=2*i;
		}
		des[2*i+1]=u;
		if((h[v]==-1)||(des[h[v]]>u))
		{
			nxt[2*i+1]=h[v];
			h[v]=2*i+1;
		}
		else
		{
			for(p=h[v];(nxt[p]!=-1)&&(des[nxt[p]]<u);p=nxt[p]);
			nxt[2*i+1]=nxt[p];
			nxt[p]=2*i+1;
		}
	}
	if(m==n-1)
		dfs(0,-1);
	else
	{
		memset(in_circle,0,sizeof(in_circle));
		memset(visited,0,sizeof(visited));
		find_circle(0,-1);
		memset(visited,0,sizeof(visited));
		travel(0);
	}
	return 0;
}
