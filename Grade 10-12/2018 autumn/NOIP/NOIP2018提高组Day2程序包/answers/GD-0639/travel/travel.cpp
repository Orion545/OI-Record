#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
#include <bitset>
using namespace std;
inline int read()
{
	int f=1,k=0;char c=getchar();
	while (c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
const int maxn=5010;
int last[maxn],fa[maxn],ans[maxn],store[maxn],top,ring[maxn],cnt,mn=1e9,/*MN[maxn],*/aw;
bitset<maxn>vis,in_ring;
struct mc{int too,nxt;}e[maxn<<1];
struct zmc{int a,b;}edge[maxn<<1];
bool flag;
inline int min(const int a,const int b){return a<b?a:b;}
void predfs(const int cur)
{
	store[++top]=cur;
	vis[cur]=1;
	for (int i=last[cur];i&&!flag;i=e[i].nxt)
	if (e[i].too!=fa[cur])
	{
		if (vis[e[i].too]&&!flag)
		{
			flag=1;
			int tmp=top;
			do
			{
				ring[++cnt]=store[tmp];
				vis[store[tmp]]=0;
			}while (store[tmp--]!=e[i].too);
			return;
		}
		fa[e[i].too]=cur,predfs(e[i].too);
	}
	vis[cur]=0;
	--top;
}
//void get(const int cur,const int fa)
//{
////	cout <<"cur:"<<cur<<endl;;
//	MN[cur]=cur;
//	for (int i=last[cur];i;i=e[i].nxt)
//	if (e[i].too!=fa)get(e[i].too,cur),MN[cur]=min(MN[cur],MN[e[i].too]);
//}
set<pair<int,int> >S[maxn];
void solve(const int cur,const int fa)
{
	S[cur].clear();
	ans[++aw]=cur;
//	int now=0;
	for (int i=last[cur];i;i=e[i].nxt)
	if (e[i].too!=fa)
	{
		if (e[i].too==mn)S[cur].insert(make_pair(ring[1],e[i].too));
		else S[cur].insert(make_pair(e[i].too,e[i].too));
	}
	for (set<pair<int,int> >::iterator it=S[cur].begin();it!=S[cur].end();++it)solve((*it).second,cur);
}
int cmp1[maxn],cmp2[maxn],final[maxn];
signed main()
{
//	S[1].insert(make_pair(2,2));
//	S[1].insert(make_pair(1,1));
//	for (set<pair<int,int> >::iterator it=S[1].begin();it!=S[1].end();++it)cout<<(*it).second;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(final,0x3f,sizeof(final));
	int n=read(),m=read();
	for (int i=1,a,b;i<=m;i++)
	edge[i].a=a=read(),edge[i].b=b=read(),e[i<<1].too=b,e[i<<1].nxt=last[a],last[a]=i<<1,
	e[i<<1|1].nxt=last[b],last[b]=i<<1|1,e[i<<1|1].too=a;
	predfs(1);
//	cout << cnt <<e
	if (!cnt)
	{
//		get(1,0);
		solve(1,0);
		for (int i=1;i<=aw;i++)printf("%d ",ans[i]);
		return 0;
	}
//	puts(">>>");
int ct=cnt;
	for (int baga=1;baga<=cnt;baga++)
	{aw=0;
	top=0;
//		cout << baga<<endl;
		memset(last,0,sizeof(last));
		int tot=0;
		for (int i=1;i<=m;i++)
		{
			int a=edge[i].a,b=edge[i].b;
			
			if ((a==ring[baga]&&b==ring[baga+1>ct?1:baga+1])||(b==ring[baga]&&a==ring[baga+1>ct?1:baga+1]))continue;
			e[++tot].nxt=last[a],e[tot].too=b,last[a]=tot;
			e[++tot].nxt=last[b],e[tot].too=a,last[b]=tot;
		}
//		cout <<"::";
//		get(1,0);
		solve(1,0);
		bool ok=1;
		for (int i=1;i<=aw;i++)
		if (ans[i]>final[i])ok=0;
		if (ok)
		for (int i=1;i<=aw;i++)
		final[i]=ans[i];
	}
	for (int i=1;i<=aw;i++)printf("%d ",final[i]);
}
