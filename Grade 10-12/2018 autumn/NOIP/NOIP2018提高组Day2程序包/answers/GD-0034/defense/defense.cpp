#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
inline int readin()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
const int maxn=300005;
int n,m,head[maxn<<1],nxt[maxn<<1],v[maxn<<1],nume=2,mark[maxn];
void addedge(int x,int y)
{
	v[nume]=y,nxt[nume]=head[x],head[x]=nume++;
	v[nume]=x,nxt[nume]=head[y],head[y]=nume++;
}
ll p[maxn],f[maxn][3],inf=(ll)maxn*maxn;
inline ll getmin(ll x,ll y){return x<y?x:y;}
void dp(int u,int fa)
{
	f[u][0]=0,f[u][1]=p[u],f[u][2]=0;
	ll savemin=inf;
	bool leaf=true,all0=true;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=fa)
		{
			leaf=false,dp(v[i],u);
			f[u][0]+=getmin(f[v[i]][0],f[v[i]][1]);
			if(f[v[i]][0]<f[v[i]][1])
				savemin=getmin(savemin,f[v[i]][1]-f[v[i]][0]);
			else all0=false;
			f[u][1]+=getmin(f[v[i]][0],getmin(f[v[i]][1],f[v[i]][2]));
			f[u][2]+=f[v[i]][0];
		}
	if(all0) f[u][0]+=savemin;
	if(leaf) f[u][0]=inf;
	
	if(mark[u]==0) f[u][1]=inf;
	if(mark[u]==1) f[u][0]=f[u][2]=inf;
	//cout<<u<<" "<<f[u][0]<<" "<<f[u][1]<<" "<<f[u][2]<<endl;
}
char type[5];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(mark,-1,sizeof mark);
	n=readin(),m=readin(),scanf("%s",type);
	for(int i=1;i<=n;i++) p[i]=readin();
	int x,y,a,b;
	for(int i=1;i<n;i++) x=readin(),y=readin(),addedge(x,y);
	for(int i=1;i<=m;i++)
	{
		//memset(f,0,sizeof f);
		a=readin(),x=readin(),b=readin(),y=readin();
		mark[a]=x,mark[b]=y;
		if(!x&&!y)
		{
			bool flag=false;
			for(int j=head[a];j;j=nxt[j])
				if(v[j]==b)
				{
					flag=true;
					break;
				}
			if(flag)
				{
					printf("-1\n");
					mark[a]=mark[b]=-1;
					continue;
				}
		}
		dp(1,0);
		printf("%lld\n",getmin(f[1][0],f[1][1]));
		mark[a]=mark[b]=-1;
	}
}
