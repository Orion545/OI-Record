#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
using namespace std;
int n,m,x,y,z,sl,fh,flg1,flg2,ans,a[50010];
int rt,vis[50010],dis[50010];
int t,h[50010];
struct Tre
{
	int to,val,nxt;
}e[100010];
queue<int> q;
set<int> st;
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
void add(int u,int v,int w)
{
	e[++t]=(Tre){v,w,h[u]};h[u]=t;
	e[++t]=(Tre){u,w,h[v]};h[v]=t;
}
void bfs(int S)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	q.push(S);vis[S]=1;int u,v;
	while(!q.empty())
	{
		u=q.front();q.pop();
		if(dis[u]>ans)
		{
			ans=dis[u];
			rt=u;
		}
		for(int i=h[u];i;i=e[i].nxt)
			if(!vis[v=e[i].to])
			{
				dis[v]=dis[u]+e[i].val;
				vis[v]=1;
				q.push(v);
			}
	}
}
void dfs(int u)
{
	int v;
	for(int i=h[u];i;i=e[i].nxt)
		if((v=e[i].to)==u+1)
			a[u]=e[i].val,dfs(v);
}
bool check1(int s)
{
	int num=0,sum=0;
	for(int i=1;i<n;++i)
	{
		sum+=a[i];
		if(sum>=s) sum=0,num++;
		if(num>=m) return 1;
	}
	return num>=m;
}
bool check2(int s)
{
	int num=0;st.clear();
	set<int>::iterator j;
	for(int i=2;i<=n;++i)
	{
		j=st.lower_bound(s-a[i]);
		if(j!=st.end()) num++,st.erase(j);
		else if(a[i]>=s) num++;
		else st.insert(a[i]);
		if(num>=m) return 1;
	}
	return num>=m;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=rd();m=rd();flg1=flg2=1;
	for(int i=1;i<n;++i) x=rd(),y=rd(),z=rd(),add(x,y,z),flg1&=(y==x+1),flg2&=(x==1);
	if(m==1)
	{
		bfs(1);ans=0;
		bfs(rt);
		printf("%d\n",ans);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if(flg1)
	{
		dfs(1);
		int mid,l=1,r=500000000;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check1(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%d\n",ans);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if(flg2)
	{
		for(int i=h[1];i;i=e[i].nxt) a[e[i].to]=e[i].val;
		int mid,l=1,r=500000000;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check2(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%d\n",ans);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
