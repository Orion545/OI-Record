#include<cstdio>
#include<cctype>
#include<algorithm>
#include<set>

using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	x=(flg?-x:x);
}
typedef long long ll;
typedef pair<int,int> P;
set<P> st;

int n,m;
int w[100010];
struct Edge{
	int to,nxt;
}edge[200010];
int cnt,last[100010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
ll dp[100010][2];
int A,X,B,Y;
ll dfs(int cur,int x,int fat)
{
	if (~dp[cur][x]) return dp[cur][x];
	if (cur==A&&x!=X||cur==B&&x!=Y) return dp[cur][x]=10000000000000LL;
	if (x)
	{
		dp[cur][x]=w[cur];
		for (int i=last[cur];i;i=edge[i].nxt)
			if (edge[i].to!=fat)
			{
				dp[cur][x]+=min(dfs(edge[i].to,0,cur),dfs(edge[i].to,1,cur));
			}
		return dp[cur][x];
	}
	dp[cur][x]=0;
		for (int i=last[cur];i;i=edge[i].nxt)
			if (edge[i].to!=fat)
			{
				dp[cur][x]+=dfs(edge[i].to,1,cur);
			}
		return dp[cur][x];
}
void slv1()
{
	while (m--)
	{
		for (int i=1;i<=n;i++) dp[i][0]=dp[i][1]=-1;
		read(A);read(X);read(B);read(Y);
		if (A>B) swap(A,B),swap(X,Y);
		if (!Y&&!X&&st.count((P){A,B})){puts("-1");continue;}
		printf("%lld\n",min(dfs(1,0,0),dfs(1,1,0))>=10000000000000LL?-1:min(dfs(1,0,0),dfs(1,1,0)));
	}
}

#define mid (l+r>>1)
#define lson (cur<<1)
#define rson (cur<<1|1)
struct Node{
	ll aa,ab,ba,bb;   //00
}node[400010];
Node merge(Node x,Node y)
{
	return (Node){min(x.aa+y.ba,x.ab+y.aa),min(x.aa+y.bb,x.ab+y.ab),min(x.ba+y.ba,x.bb+y.aa),min(x.ba+y.bb,x.bb+y.ab)};
}
void build(int cur,int l,int r)
{
	if (l==r) return node[cur]=(Node){10000000000000LL,10000000000000LL,10000000000000LL,w[l]},void();
	build(lson,l,mid); build(rson,mid+1,r);
	node[cur]=merge(node[lson],node[rson]);
	
}
Node query(int cur,int l,int r,int ql,int qr)
{
	if (l==ql&&r==qr) return node[cur];
	if (qr<=mid) return query(lson,l,mid,ql,qr);
	if (ql>mid) return query(rson,mid+1,r,ql,qr);
	return merge(query(lson,l,mid,ql,mid),query(rson,mid+1,r,mid+1,qr));
}
void slv2()
{
	build(1,1,n);
	while (m--)
	{
		read(A);read(X);read(B);read(Y);
		if (A>B) swap(A,B),swap(X,Y);
		if (!Y&&!X&&st.count((P){A,B})){puts("-1");continue;}
		if (X&&Y)
		{
			Node tmp;
			ll res=0;
			if (A!=1)
			{
				tmp=query(1,1,n,1,A-1);
				res+=min(tmp.aa,min(tmp.ab,min(tmp.bb,tmp.ba)));
			}
			tmp=query(1,1,n,A+1,B-1);
			res+=min(tmp.aa,min(tmp.ab,min(tmp.bb,tmp.ba)));
			if (B!=n)
			{
				
				tmp=query(1,1,n,B+1,n);
				res+=min(tmp.aa,min(tmp.ab,min(tmp.bb,tmp.ba)));
			}
			printf("%lld\n",res);
			continue;
		}
		if (!X&&Y)
		{
			Node tmp;
			ll res=0;
			if (A!=1)
			{
				tmp=query(1,1,n,1,A-1);
				res+=min(tmp.ab,tmp.bb);
			}
			tmp=query(1,1,n,A+1,B-1);
			res+=min(tmp.bb,tmp.ba);
			if (B!=n)
			{
				tmp=query(1,1,n,B+1,n);
				res+=min(tmp.aa,min(tmp.ab,min(tmp.bb,tmp.ba)));
			}
			printf("%lld\n",res);
			continue;
		}
		if (X&&!Y)
		{
			Node tmp;
			ll res=0;
			if (A!=1)
			{
				tmp=query(1,1,n,1,A-1);
				res+=min(tmp.aa,min(tmp.ab,min(tmp.bb,tmp.ba)));
			}
			tmp=query(1,1,n,A+1,B-1);
			res+=min(tmp.ab,tmp.bb);
			if (B!=n)
			{
				tmp=query(1,1,n,B+1,n);
				res+=min(tmp.bb,tmp.ba);
			}
			printf("%lld\n",res);
			continue;
		}
			Node tmp;
			ll res=0;
			if (A!=1)
			{
				tmp=query(1,1,n,1,A-1);
				res+=min(tmp.ab,tmp.bb);
			}
			tmp=query(1,1,n,A+1,B-1);
			res+=tmp.bb;
			if (B!=n)
			{
				tmp=query(1,1,n,B+1,n);
				res+=min(tmp.bb,tmp.ba);
			}
			printf("%lld\n",res);
	}
}
char tp[10];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	read(n);read(m);scanf("%s",tp);
	for (int i=1;i<=n;i++) read(w[i]);
	for (int i=1,x,y;i<n;i++)
	{
		read(x);read(y);
		if (x>y) swap(x,y);
		st.insert((P){x,y});
		addedge(x,y);
	}
	if (n<=2000&&m<=2000)
	{
		slv1();
		
		fclose(stdin); fclose(stdout);
		return 0;
	}
	if (tp[0]=='A')
	{
		slv2();
		
		fclose(stdin); fclose(stdout);
		return 0;
	}
		slv1();
		
		fclose(stdin); fclose(stdout);
		return 0;
}
