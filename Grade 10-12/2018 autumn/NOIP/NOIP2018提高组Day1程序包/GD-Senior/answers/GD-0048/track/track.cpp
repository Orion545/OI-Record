#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 50005
using namespace std;
int Head[N],Next[N*2],Tar[N*2],Len[N*2],Fa[N],cnt,n;
int m,Tempm;
void Add_edge(int u,int v,int len);
void BFS(int root);
int Check(int node,int LEN);
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	cnt=0;
	int Lb=0,Rb=0;
	memset(Next,0,sizeof(Next));
	for(int i=1;i<n;i++)
	{
		int u,v,len;
		scanf("%d%d%d",&u,&v,&len);
		Add_edge(u,v,len);
		Add_edge(v,u,len);
		Rb+=len;
	}
	BFS(1);
	while(Lb+1<Rb)
	{
		int Mid=(Lb+Rb)>>1;
		Tempm=0;
		int Temp=Check(1,Mid);
		if(Tempm>=m)Lb=Mid;else	Rb=Mid;
	}
	printf("%d",Lb);
	return 0;
}
int Check(int node,int LEN)
{
	int edge[N],cur=0,used[N];
	memset(used,0,sizeof(used));
	memset(edge,0,sizeof(edge));
 	for(int i=Head[node];i;i=Next[i])
		if(Tar[i]!=Fa[node])edge[++cur]=Check(Tar[i],LEN)+Len[i];
	sort(edge+1,edge+1+cur);
	for(int i=cur;i>=1;i--)
		if(edge[i]>=LEN)
		{
			used[i]=1;
			Tempm++;
		}
	for(int i=1;i<=cur;i++)
		for(int j=i+1;j<=cur;j++)
			if(edge[i]+edge[j]>=LEN&&!used[i]&&!used[j])
			{
				used[i]=1;
				used[j]=1;
				Tempm++;
			}
	for(int i=cur;i>=1;i--)if(!used[i])return	edge[i];
	return 0;
}
void BFS(int root)
{
	int que[N],Hd,Td;
	memset(que,0,sizeof(que));
	Hd=Td=1;
	que[1]=root;
	Fa[root]=root;
	while(Hd<=Td)
	{
		int node=que[Hd++];
		for(int j=Head[node];j;j=Next[j])
			if(Tar[j]!=Fa[node])
			{
				que[++Td]=Tar[j];
				Fa[Tar[j]]=node;
			}
	}
	return;
}
void Add_edge(int u,int v,int len)
{
	cnt++;
	Next[cnt]=Head[u];
	Tar[cnt]=v;
	Len[cnt]=len;
	Head[u]=cnt;
}
