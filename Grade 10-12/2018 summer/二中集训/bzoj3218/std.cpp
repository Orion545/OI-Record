#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
#define M 200200
#define S 0
#define T 200199
#define INF 0x3f3f3f3f
#define P1(x) ((x)*2-1)
#define P2(x) ((x)<<1)
using namespace std;
 
int n,m,cnt;
long long ans;
 
namespace Max_Flow{
	struct abcd{
		int to,f,next;
	}table[1001001];
	int head[M],tot=1;
	int dpt[M];
	void Add(int x,int y,int z)
	{
		table[++tot].to=y;
		table[tot].f=z;
		table[tot].next=head[x];
		head[x]=tot;
	}
	void Link(int x,int y,int z)
	{
		cout<<"	add "<<x<<' '<<y<<' '<<z<<'\n';
		assert(y!=(n<<1)+1);
		Add(x,y,z);
		Add(y,x,0);
	}
	bool BFS()
	{
		static int q[M];
		int i,r=0,h=0;
		memset(dpt,-1,sizeof dpt);
		dpt[S]=1;q[++r]=S;
		while(r!=h)
		{
			int x=q[++h];
			for(i=head[x];i;i=table[i].next)
				if(table[i].f&&!~dpt[table[i].to])
				{
					dpt[table[i].to]=dpt[x]+1;
					q[++r]=table[i].to;
					if(table[i].to==T)
						return true;
				}
		}
		return false;
	}
	int Dinic(int x,int flow)
	{
		int i,left=flow;
		if(x==T) return flow;
		for(i=head[x];i&&left;i=table[i].next)
			if(table[i].f&&dpt[table[i].to]==dpt[x]+1)
			{
				int temp=Dinic(table[i].to,min(left,table[i].f) );
				left-=temp;
				table[i].f-=temp;
				table[i^1].f+=temp;
			}
		if(left) dpt[x]=-1;
		return flow-left;
	}
	
}
 
struct Segtree{
	Segtree *ls,*rs;
	int val,num;
	void* operator new (size_t,Segtree *_,Segtree *__,int ___)
	{
		static Segtree mempool[M],*C=mempool;
		C->ls=_;
		C->rs=__;
		C->val=___;
		C->num=++cnt;
		return C++;
	}
	Segtree* Build_Tree(int x,int y,int pos,int from)
	{
		cout<<"Build "<<x<<' '<<y<<' '<<pos<<' '<<from<<' '<<num<<' '<<val<<'\n';
		using namespace Max_Flow;
		int mid=x+y>>1;
		
		Segtree *re;
		if(x==y)
			re=new (0x0,0x0,val+1) Segtree;
		else if(pos<=mid)
			re=new (ls->Build_Tree(x,mid,pos,from),rs,val+1) Segtree;
		else
			re=new  (ls,rs->Build_Tree(mid+1,y,pos,from),val+1) Segtree;
		Link(from,re->num,INF);
		Link(num,re->num,INF);
		return re;
	}
	void Get_Ans(int x,int y,int l,int r,int to)
	{
		using namespace Max_Flow;
		int mid=x+y>>1;
		if(!val) return ;
		if(x==l&&y==r)
		{
			Link(num,to,INF);
			return ;
		}
		if(r<=mid) ls->Get_Ans(x,mid,l,r,to);
		else if(l>mid) rs->Get_Ans(mid+1,y,l,r,to);
		else ls->Get_Ans(x,mid,l,mid,to),rs->Get_Ans(mid+1,y,mid+1,r,to);
	}
}*tree[5050];
 
 
 
int main()
{
	freopen("10.in","r",stdin);
	freopen("std.out","w",stdout);
	using namespace Max_Flow;
 
	int i,a,b,w,l,r,p;
 
	cin>>n;cnt=P2(n);
	tree[0]=new (0x0,0x0,0) Segtree;
	tree[0]->ls=tree[0]->rs=tree[0];
 
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d%d%d",&a,&b,&w,&l,&r,&p);
		Link(S,P1(i),w);
		Link(P1(i),T,b);
		tree[i]=tree[i-1]->Build_Tree(0,1000000000,a,P1(i) );
		tree[i-1]->Get_Ans(0,1000000000,l,r,P2(i) );
		Link(P2(i),P1(i),p);
		ans+=w+b;
	}
 
	while( BFS() )
		ans-=Dinic(S,INF);
 
	cout<<ans<<endl;
	return 0;
}

