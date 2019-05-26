#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

#define maxn 50005

using namespace std;

struct edge_type
{
	int to,w,next;
}e[maxn<<1];
int head[maxn];

int parent[maxn];

int n,m;
int u,v,w;

int L,R,Z;

int cnt[maxn],len[maxn];
int lrx[maxn],cnt_lrx;
bool flag[maxn];

char ch;
void get_num(int &x)
{
	x=0;
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^'0');
		ch=getchar();
	}
}

void add_e(int u,int v,int w,int x)
{
	e[x].to=v;
	e[x].w=w;
	e[x].next=head[u];
	head[u]=x;
}

void dfs(int x)
{
	int i,j,tmp=0;
	
	for(i=head[x];i;i=e[i].next)
	{
		if (parent[x]==e[i].to) continue;
		parent[e[i].to]=x;
		
		dfs(e[i].to);
		cnt[x]+=cnt[e[i].to];
	}
	
	cnt_lrx=0;
	for(i=head[x];i;i=e[i].next)
	{
		if (parent[x]==e[i].to) continue;
		
		if (len[e[i].to]+e[i].w>=Z) cnt[x]++;
		else {
			lrx[++cnt_lrx]=len[e[i].to]+e[i].w;
			flag[cnt_lrx]=false;
		}
	}
	sort(lrx+1,lrx+1+cnt_lrx);
	for(i=cnt_lrx-1,j=1;i>j;i--,j++)
	{
		while (lrx[i]+lrx[j]<Z&&i>j) j++;
		if (j==i) break;
		tmp++;
	}
	
	if (tmp*2!=cnt_lrx-1)
	{
		tmp=0;
		for(i=cnt_lrx,j=1;i>j;i--,j++)
		{
			while (lrx[i]+lrx[j]<Z&&i>j) j++;
			if (i==j) break;
			flag[i]=flag[j]=true;
			tmp++;
		}
		for(;i>0;i--)
			if (!flag[i]) break;
		len[x]=lrx[i];
	}else len[x]=lrx[cnt_lrx];
	cnt[x]+=tmp;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	int i;
	
	get_num(n);
	get_num(m);
	for(i=1;i<n;i++)
	{
		get_num(u);
		get_num(v);
		get_num(w);
		add_e(u,v,w,i*2-1);
		add_e(v,u,w,i*2);
		R+=w;
	}
	
	R++;
	L=1;
	while (R-L>1)
	{
		Z=((L+R)>>1);
		
		memset(cnt,0,sizeof(cnt));
		memset(len,0,sizeof(len));
		dfs(1);
		if (cnt[1]>=m) L=Z;
		else R=Z;
	}
	
	printf("%d\n",L);
	
	return 0;
}
