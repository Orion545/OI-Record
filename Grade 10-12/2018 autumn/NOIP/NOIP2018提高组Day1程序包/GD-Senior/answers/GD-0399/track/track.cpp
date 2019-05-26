#include<bits/stdc++.h>
#define pbk push_back
#define pft push_front
using namespace std;

const int maxn = 1e5 + 10;
const int INF  = 0x3f3f3f3f;

inline int read()
{
	int x=0;char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+(c^48);
	return x;
}

int n,m,en=1,head[maxn];

struct edge{
	int v,n,l;
}e[maxn];

inline void addedge(int u,int v,int l)
{
	e[en].v=v;e[en].l=l;e[en].n=head[u];head[u]=en++;
	e[en].v=u;e[en].l=l;e[en].n=head[v];head[v]=en++;
}

void input()
{
	int i,u,v,l;
	
	n=read();m=read();
	for(i=1;i<n;i++)
	{
		u=read();v=read();l=read();
		addedge(u,v,l);
	}
}

int Lim,tot;
int f[maxn];
//deque<int> Q;

struct MyDeq{
	int l,r,a[maxn];
	
	MyDeq(){l=r=0;}
	inline void clear(){l=r=0;}
	inline int size(){return r-l;}
	inline int front(){return a[l];}
	inline int back(){return a[r-1];}
	inline void srt(){sort(a+l,a+r);}
	inline void pbk(int x){a[r++]=x;}
	inline void pop_front(){l++;}
	inline void pop_back(){r--;}
}Q;

void dfs(int x,int fa)
{
	int i,lst,to;
	
	f[x]=0;
	for(i=head[x];i;i=e[i].n) if(e[i].v!=fa) dfs(e[i].v,x);
	//printf("At %d\n",x);
	for(i=head[x];i;i=e[i].n) if(e[i].v!=fa) Q.pbk(f[e[i].v]+e[i].l),Q.pbk(0);
	//if(x==1) cerr<<clock()<<' ';
	//sort(Q.begin(),Q.end());
	Q.srt();
	//if(x==1) cerr<<clock()<<endl;
	
	lst=-INF;to=-1;
	while(Q.size()>1)
	{
		while(Q.size()>1 && Q.front()+Q.back()<Lim) 
		{
			f[x]=max(f[x],Q.front());
			Q.pop_front();
		}
		if(Q.size()<=1) break;
		tot++;
		if(lst+Q.back()<Lim) to=Q.back();lst=Q.front();
		Q.pop_front();Q.pop_back();
	}
	if(Q.size()) 
	{
		if(lst+Q.front()>=Lim) f[x]=max(f[x],to);
		else                   f[x]=max(f[x],Q.front());
	}
	Q.clear();
}

void solve()
{
	int l=0,r=INF;
	
//	Lim=10;
//	dfs(1,0);
//	cerr<<f[1]<<endl;
	
	while(l+1<r)
	{
		Lim=(l+r)>>1;
		tot=0;
		dfs(1,0);
		if(tot>=m) l=Lim;
		else       r=Lim;
	}
	cout<<l<<endl;
	
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	input();
	solve();
	
	return 0;
}
