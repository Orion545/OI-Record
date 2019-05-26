#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	x=(flg?-x:x);
}

int n,m;
struct Edge{
	int to,nxt,val;
}edge[100010];
int cnt,last[50010];
inline void addedge(int x,int y,int v)
{
	edge[++cnt]=(Edge){y,last[x],v},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y],v},last[y]=cnt;
}

bool chk1()
{
	return m==1;
}
int dis[50010];
int que[50010],hd,tl;
bool vis[50010];
void slv1()
{
	hd=tl=0;
	que[++tl]=1;
	dis[1]=0;
	while (hd<tl)
	{
		int u=que[++hd];
		vis[u]=true;
		for (int i=last[u];i;i=edge[i].nxt)
			if (!vis[edge[i].to])
				dis[edge[i].to]=dis[u]+edge[i].val,que[++tl]=edge[i].to;
	}
	int S,maxdis=-1;
	for (int i=1;i<=n;i++)
		if (dis[i]>maxdis) maxdis=dis[i],S=i;
		
	hd=tl=0; memset(vis,false,sizeof vis);
	que[++tl]=S;
	dis[S]=0;
	while (hd<tl)
	{
		int u=que[++hd];
		vis[u]=true;
		for (int i=last[u];i;i=edge[i].nxt)
			if (!vis[edge[i].to])
				dis[edge[i].to]=dis[u]+edge[i].val,que[++tl]=edge[i].to;
	}
	maxdis=-1;
	for (int i=1;i<=n;i++)
		maxdis=max(maxdis,dis[i]);
	printf("%d\n",maxdis);
}

bool flg2=true;
bool chk2()
{
	return flg2;
}
int w[50010];
bool chk(int x)
{
	int num=0,mtot=0;
	for (int i=1;i<n;i++)
	{
		num+=w[i];
		if (num>=x) mtot++,num=0;
	}
	return mtot>=m;
}
void slv2()
{
	for (int i=1;i<n;i++)
		for (int j=last[i];j;j=edge[j].nxt)
			if (edge[j].to==i+1)
			{
				w[i]=edge[j].val;
				break;
			}
//	printf("%d\n",chk(3));
	int l=1,r=500000000,mid;
	while (l<r)
	{
		mid=l+r+1>>1;
//		printf("check %d\n",mid);
		if (chk(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}

bool flg3=true;
bool chk3()
{
	return flg3;
}
//#define mid (l+r>>1)
#define lson (cur<<1)
#define rson (cur<<1|1)
struct Node{
	int siz;
}node[40010];
void update(int cur,int l,int r,int pos,int val)
{
	node[cur].siz+=val;
	if (l==r) return;
	int mid=l+r>>1;
	if (pos<=mid) return update(lson,l,mid,pos,val);
	update(rson,mid+1,r,pos,val);
}
struct Rec{
	int cur,l,r;
}rec[210];
int rectop;
void clr(int cur,int l,int r)
{
	node[cur].siz=0;
	if (l==r) return;
	int mid=l+r>>1;
	clr(lson,l,mid); clr(rson,mid+1,r);
}
int query(int cur,int l,int r,int ql,int qr)
{
	if (l==ql&&r==qr)
	{
		rec[++rectop]=(Rec){cur,l,r};
		return node[cur].siz;
	}
	int mid=l+r>>1;
	if (qr<=mid) return query(lson,l,mid,ql,qr);
	if (ql>mid) return query(rson,mid+1,r,ql,qr);
	return query(lson,l,mid,ql,mid)+query(rson,mid+1,r,mid+1,qr);
}
int dfs(int cur,int l,int r)
{
	if (l==r) return l;
	int mid=l+r>>1;
	if (node[lson].siz) return dfs(lson,l,mid);
	return dfs(rson,mid+1,r);
}
bool chck(int x)
{
//	printf("check %d\n",x);
	int res=0;
	clr(1,1,10000);
	for (int i=1;i<n;i++) update(1,1,10000,w[i],1);
	for (int i=1;i<n;i++)
	{
		rectop=0;
		if (!query(1,1,10000,w[i],w[i])) continue;
		if (w[i]>=x)
		{
//			printf("for %d w %d  ok\n",i,w[i]);
			res++;
			update(1,1,10000,w[i],-1);
			continue;
		}
		int tmp=x-w[i];
		if (tmp>10000) continue;
		rectop=0;
		if (!query(1,1,10000,tmp,10000)) continue;
		update(1,1,10000,w[i],-1);
		for (int j=1;j<=rectop;j++)
			if (node[rec[j].cur].siz)
			{
				int pos=dfs(rec[j].cur,rec[j].l,rec[j].r);
//				printf("for %d w %d find %d\n",i,w[i],pos);
				res++;
				update(1,1,10000,pos,-1);
				break;
			}
	}
	return res>=m;
}
void slv3()
{
	for (int i=1;i<=cnt;i+=2)
		w[(i+1)>>1]=edge[i].val/*,printf("w %d = %d\n",(i+1>>1),w[(i+1)>>1])*/;
//	sort(w+1,w+n);
	int l=1,r=20000,mid;
//	chck(3);
	while (l<r)
	{
		mid=l+r+1>>1;
		if (chck(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}

//int Bse;
//int dp[1001][1001];
//bool vis[1001][1001];
//int dfs(int cur,int fat,int k)
//{
//	if (vis[cur][k]) return dp[cur][k];
//	int soncnt=0;
//	for (int i=last[cur];i;i=edge[i].nxt)
//		if (edge[i].to!=fat)
//			cnt++;
//	if (!cnt)
//	{
//		
//	}
//}
//void slv4()
//{
//	
//}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	int wtot=0;
	read(n);read(m);
	for (int i=1,x,y,z;i<n;i++)
	{
		read(x);read(y);read(z);
		if (x+1!=y) flg2=false;
		if (x!=1) flg3=false;
		addedge(x,y,z);
		wtot+=z;
	}
	
	if (chk1())
	{
		slv1();
		fclose(stdin); fclose(stdout);
		return 0;
	}
	
	if (chk2())
	{
		slv2();
		fclose(stdin); fclose(stdout);
		return 0;
	}
	
	if (chk3())
	{
		slv3();
		fclose(stdin); fclose(stdout);
		return 0;
	}
	
	printf("%d\n",wtot/m);
	fclose(stdin); fclose(stdout);
	return 0;
}
