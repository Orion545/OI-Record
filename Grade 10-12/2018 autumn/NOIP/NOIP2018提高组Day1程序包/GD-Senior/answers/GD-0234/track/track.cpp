#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define FOR(A,B,C) for(register int A=B;A<=C;A++)
using namespace std;
void iread(int &cn)
{
    char p='k';cn=0;int k=1;
    while((p<'0')||(p>'9')){if(p=='-')k=-1;p=getchar();}
    while((p>='0')&&(p<='9')){cn=cn*10+p-'0';p=getchar();}
    cn*=k;
}
int n,m,rx,ry,rv;
struct EDGE{int from,to,val,next;}edge[100111];
int ehd[50050],cnt=1;
void addline(int u,int v,int val){++cnt;edge[cnt].next=ehd[u];ehd[u]=cnt;edge[cnt].to=v;edge[cnt].from=u;edge[cnt].val=val;}
struct nbe{int ord,val;}nedge[100111];
bool operator<(nbe a,nbe b){return a.val>b.val;}
bool vis[100111];
int ins[100111],stk[50011][5010],cst,maxlen;
void dfs(int edgeord)
{
	if(cst>m)return;
	if(edgeord>cnt)
	{
		if(cnt==m)
		{
			int ans,minlen=0x7fffffff;
			FOR(i,1,m)
			{
				ans=0;
				FOR(v,1,stk[i][0])ans+=edge[stk[i][v]].val;
				minlen=min(minlen,ans);
			}
			maxlen=max(maxlen,minlen);
		}
		return;
	}
	vis[edgeord]=1;
	int u=edge[nedge[edgeord].ord].from,v=edge[nedge[edgeord].ord].to;
	/*
	cout<<u<<","<<v<<endl;
	FOR(k,1,cst)
	{
		cout<<cst<<":";
		FOR(i,1,stk[k][0])cout<<edge[stk[k][i]].val<<" ";cout<<endl;
	}
	system("pause");
	//*/
	for(int k=ehd[u];k;k=edge[k].next)
	{
		if(vis[k])
		{
			ins[edgeord]=ins[k];
			stk[ins[k]][++stk[ins[k]][0]]=edgeord;
			dfs(edgeord+2);
			--stk[ins[k]][0];
			ins[edgeord]=0;
		}
		if(vis[k^1])
		{
			ins[edgeord]=ins[k^1];
			stk[ins[k^1]][++stk[ins[k^1]][0]]=edgeord;
			dfs(edgeord+2);
			--stk[ins[k^1]][0];
			ins[edgeord]=0;
		}
	}
	for(int k=ehd[v];k;k=edge[k].next)
	{
		if(vis[k])
		{
			ins[edgeord]=ins[k];
			stk[ins[k]][++stk[ins[k]][0]]=edgeord;
			dfs(edgeord+2);
			--stk[ins[k]][0];
			ins[edgeord]=0;
		}
		if(vis[k^1])
		{
			ins[edgeord]=ins[k^1];
			stk[ins[k^1]][++stk[ins[k^1]][0]]=edgeord;
			dfs(edgeord+2);
			--stk[ins[k^1]][0];
			ins[edgeord]=0;
		}
	}
	++cst;
	ins[edgeord]=cst;
	stk[cst][++stk[cst][0]]=edgeord;
	dfs(edgeord+2);
	--stk[cst][0];
	--cst;
	ins[edgeord]=0;
	return;
}
int maxlent[50050];
void dfs1(int st,int fa)
{
	for(int u=ehd[st];u;u=edge[u].next)
	{
		if(edge[u].to==fa)continue;
		dfs1(edge[u].to,st);
		maxlent[st]=max(maxlent[st],maxlent[edge[u].to]+edge[u].val);
	}
	return;
}
void dfs2(int st,int fa)
{
	for(int u=ehd[st];u;u=edge[u].next)
	{
		if(edge[u].to==fa)continue;
		dfs1(edge[u].to,st);
		maxlent[st]=max(maxlent[st],maxlent[edge[u].to]+edge[u].val);
	}
	return;
}
int main()
{
    ///*
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    //*/
    iread(n);iread(m);
    FOR(i,2,n){iread(rx);iread(ry);iread(rv);addline(rx,ry,rv);addline(ry,rx,rv);}
    //FOR(i,2,cnt)cout<<nedge[i].ord<<","<<nedge[i].val<<" ";cout<<endl;
    if(m!=1)
    {
    FOR(i,2,cnt){nedge[i].val=edge[i].val;nedge[i].ord=i;}
    sort(nedge+2,nedge+cnt+1);
    dfs(2);
	dfs(3);
    printf("%d",maxlen);
    }
    else
    {
    	dfs1(1,1);
    	int root=0;
    	FOR(i,1,n)root=(maxlent[root]<maxlent[i]?i:root);
    	memset(maxlent,0,sizeof(maxlent));
    	dfs2(root,root);
    	FOR(i,1,n)root=(maxlent[root]<maxlent[i]?i:root);
    	printf("%d",maxlent[root]);
    }
    return 0;
}
