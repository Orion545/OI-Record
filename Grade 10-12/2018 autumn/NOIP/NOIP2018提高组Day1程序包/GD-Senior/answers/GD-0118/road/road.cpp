#include<cstdio>
#include<iostream>

#define maxn 100005

using namespace std;

int n;
int d[maxn];
int pre[maxn],nxt[maxn];

int heap[maxn],cnt_heap;

int ans;

void shift_up(int x)
{
	while (x>1)
	{
		if (d[heap[x]]>d[heap[x>>1]]) swap(heap[x],heap[x>>1]);
		else break;
		x>>=1;
	}
}

void shift_down(int x)
{
	int i;
	while ((x<<1)<=cnt_heap)
	{
		i=(x<<1);
		if (i<cnt_heap&&d[heap[i+1]]>d[heap[i]]) i++;
		if (d[heap[x]]<d[heap[i]]) swap(heap[x],heap[i]);
		else break;
		x=i;
	}
}

void add_heap(int x)
{
	heap[++cnt_heap]=x;
	shift_up(cnt_heap);
}

void del_root()
{
	heap[1]=heap[cnt_heap];
	cnt_heap--;
	shift_down(1);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int i,j;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		add_heap(i);
		nxt[i]=i+1;
		pre[i]=i-1;
	}
	
	nxt[0]=1;
	pre[n+1]=n;
	
	for(;n;n--)
	{
		i=heap[1];
		if (d[nxt[i]]>d[pre[i]]) j=nxt[i];
		else j=pre[i];
		
		ans+=d[i]-d[j];
		nxt[pre[i]]=nxt[i];
		pre[nxt[i]]=pre[i];
		del_root();
	}
	
	printf("%d\n",ans);
	return 0;
}
