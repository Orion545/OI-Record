#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N=5e4+10,INF=5e8+10;
int n,m,mid,tot,cnt;
int head[N],val[N],g[N];
vector<int>son[N],res;

inline int read()
{
	int ret=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c^48),c=getchar();
	return ret;
}

struct Tway{int v,w,nex;}e[N<<1];
inline void add(int u,int v,int w)
{
	e[++tot]=(Tway){v,w,head[u]};head[u]=tot;
	e[++tot]=(Tway){u,w,head[v]};head[v]=tot;
}

void dfs(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa) continue;
		val[v]=e[i].w;dfs(v,x);
		son[x].pb(g[v]);
	}
	sort(son[x].begin(),son[x].end());
	int sz=son[x].size(),l=0,r=sz-1;
	if(!sz) {g[x]=val[x];return;}
	//printf("wehavebef:");for(int i=l;i<=r;++i) printf("%d ",son[x][i]); puts("");
	while(r>=0 && son[x][r]>=mid) son[x][r]=0,++cnt,--r;
	//printf("wehavenow:");for(int i=l;i<=r;++i) printf("%d ",son[x][i]); puts("");
	if(r>=1 && son[x][r]*2>=mid)
	{
		res.clear();int hv=0;
		while(l<r && son[x][r]+son[x][l]<mid) res.pb(son[x][l]),++l;
		if(l==r) res.pb(son[x][r]);
		if(l<r)
		{
			if(l<r-1 && son[x][r-1]+son[x][l]>=mid) 
			{
				hv=son[x][r];son[x][r]=0;
				--r;son[x][l]=son[x][r]=0;
				--r;++l;++cnt;
			} 
			if(l==r) res.pb(son[x][r]);
			while(l<r)
			{
				while(l<r && son[x][r]+son[x][l]<mid) res.pb(son[x][l]),++l;
				if(l<r)
				{
					//printf("merge:%d %d\n",son[x][l],son[x][r]);
					son[x][l]=son[x][r]=0;
					++cnt,++l,--r;
				}	
				if(l==r) res.pb(son[x][l]);
			}
			sort(res.begin(),res.end());
			
			int tt=res.size();
			//printf("%d hv:%d\n",x,hv);
			//printf("res: ");for(int i=0;i<tt;++i) printf("%d ",res[i]); puts("");
			if(tt>0) 
			{
				if(res[tt-1]+hv>=mid) res[tt-1]=0,hv=0,--tt,++cnt;
			}
			for(int i=0;i<tt;++i) g[x]=max(g[x],res[i]);
		}
		for(int i=0;i<(int)res.size();++i) g[x]=max(g[x],res[i]);
		g[x]=max(g[x],hv);	
	}
	else if(r>=0) g[x]=max(g[x],son[x][r]);
	g[x]+=val[x];
	//printf("%d %d\n",x,g[x]);
}

inline bool check()
{
	//printf("check:%d\n",mid);
	memset(g,0,sizeof(g));cnt=0;
	for(int i=1;i<=n;++i) son[i].clear();
	dfs(1,0);
	if(cnt>=m) return 1;
	return 0;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	n=read();m=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
	}
	int l=1,r=INF,ans=1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check()) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",ans);
	//cerr<<clock()<<endl;
	
	return 0;
}
