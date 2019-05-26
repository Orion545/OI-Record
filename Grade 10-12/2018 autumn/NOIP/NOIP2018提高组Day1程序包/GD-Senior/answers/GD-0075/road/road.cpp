#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	x=(flg?-x:x);
}

int n,w[100010];
#define lson (cur<<1)
#define rson (cur<<1|1)
#define mid ((l+r)>>1)
struct Node{
	int minn;
}node[400010];
void build(int cur,int l,int r)
{
	if (l==r)
	{
		node[cur].minn=w[l];
		return;
	}
	build(lson,l,mid); build(rson,mid+1,r);
	node[cur].minn=min(node[lson].minn,node[rson].minn);
}
struct Rec{
	int cur,l,r;
}rec[210];
int rectop;
int query(int cur,int l,int r,int ql,int qr)
{
	if (l==ql&&r==qr)
	{
		rec[++rectop]=(Rec){cur,l,r};
		return node[cur].minn;
	}
	if (qr<=mid) return query(lson,l,mid,ql,qr);
	if (ql>mid) return query(rson,mid+1,r,ql,qr);
	return min(query(lson,l,mid,ql,mid),query(rson,mid+1,r,mid+1,qr));
}
int stk[100010];
void dfs(int cur,int l,int r)
{
	if (l==r)
	{
		stk[++(*stk)]=l;
		return;
	}
	if (node[lson].minn==node[cur].minn) dfs(lson,l,mid);
	if (node[rson].minn==node[cur].minn) dfs(rson,mid+1,r);
}

typedef long long ll;
ll ans;
void slv(int l,int r,int gt)
{
	rectop=0;
	int tmp=query(1,1,n,l,r);
	ans+=tmp-gt;
	(*stk)=0;
	for (int i=1;i<=rectop;i++)
		if (node[rec[i].cur].minn==tmp)
			dfs(rec[i].cur,rec[i].l,rec[i].r);
	if (stk[1]!=l) slv(l,stk[1]-1,tmp);
	for (int i=2;i<=(*stk);i++) if (stk[i-1]+1!=stk[i]) slv(stk[i-1]+1,stk[i]-1,tmp);
	if (stk[(*stk)]!=r) slv(stk[(*stk)]+1,r,tmp);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	read(n);
	for (int i=1;i<=n;i++) read(w[i]);
	build(1,1,n);
	slv(1,n,0);
	printf("%lld\n",ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
