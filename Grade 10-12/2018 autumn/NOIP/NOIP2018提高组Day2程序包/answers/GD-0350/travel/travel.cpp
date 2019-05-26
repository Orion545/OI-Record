//60
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,head[5100],next[50100],to[50100],st;
bool been[5100];
void dfs(int num,int deep)
{
	if (deep > n) return;
	for (int i = head[num];i != 0;i = next[i])
		if (!been[to[i]])
		{
			been[to[i]] = true;printf("%d ",to[i]);
			dfs(to[i],deep + 1);
		}
}
void push(int s,int t)
{
	int temp;//bool flag = false;
	st++;
	to[st] = t;
	temp = head[s];
	if ((to[temp] > t)||(temp == 0)) {next[st] = temp;head[s] = st;}
	else
	{
		while (t > to[next[temp]]) 
		{
			if (next[temp] == 0) {break;}
			temp = next[temp];
		}
		next[st] = next[temp];next[temp] = st;
	}
//	flag = false;
	st++;
	to[st] = s;
	temp = head[t];
	if ((to[temp] > s)||(temp == 0)) {next[st] = temp;head[t] = st;}
	else
	{
		while (s > to[next[temp]]) 
		{
			if (next[temp] == 0) {break;}
			temp = next[temp];
		}
		next[st] = next[temp];next[temp] = st;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	st = 0;
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
	memset(been,0,sizeof(been));
	memset(to,0,sizeof(to));
	for (int i = 1;i <= m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		push(u,v);
	}
	been[1] = true;printf("1 ");
	dfs(1,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
