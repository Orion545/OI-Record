//40
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,p[500100],head[500100],next[1000100],to[1000100],st,tot,ans;
bool been[500100],flag[500100];
char type[5];
bool check()
{
	for (int i = 1;i <= n;i++)
		if (!flag[i]) 
		{
			for (int j = head[i];j != 0;j = next[j])
			{
				if (!flag[to[j]]) return false;
			}
		}	
	return true;
}
void work(int num)
{
	if ((num > n)||(tot > ans)) return;
	if (check()) {ans = tot;return;}
	for (int i = (num + 1);i <= n;i++)
		if (!been[i])
		{
			been[i] = true;flag[i] = true;tot += p[i];
			work(i);
			been[i] = false;flag[i] = false;tot -= p[i];
		}
}
void push(int s,int t)
{
	st++;
	to[st] = t;
	next[st] = head[s];
	head[s] = st;
	st++;
	to[st] = s;
	next[st] = head[t];
	head[t] = st;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>type;st = 0;
	for (int i = 1;i <= n;i++) scanf("%d",p +i );
	for (int i = 1;i <= (n - 1);i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		push(u,v);
	}
	for (int i = 1;i <= m;i++)
	{
		memset(been,0,sizeof(been));
		memset(flag,0,sizeof(flag));
		tot = 0;ans = 0x7fffffff;
		int x1,y1,x2,y2;
		bool flag2 = false;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		been[x1] = true;
		if (y1 == 1)
		{
			flag[x1] = true;tot += p[x1];
		}
		been[x2] = true;
		if (y2 == 1)
		{
			flag[x2] = true;tot += p[x2];
		}
		if ((y1 == 0)&&(y2 == 0)) 
			for (int i = head[x1];i != 0;i = next[i]) if (to[i] == x2) {flag2 = true;break;}
		if (!flag2) {work(0);printf("%d\n",(ans == 0x7fffffff ? -1 : ans));}
		else printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
