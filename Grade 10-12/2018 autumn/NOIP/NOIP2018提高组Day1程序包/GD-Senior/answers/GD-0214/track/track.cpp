#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char ch;
void read(int&n)
{
	for(ch=getchar();ch<'0' || ch>'9';ch=getchar());
	for(n=0;'0'<=ch && ch<='9';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
}
const int N=50003;
int n,m,x,y,z,nxt[N*2],to[N*2],v[N*2],lst[N],tot,ans;
int dep[N],mxd[N],ls,rs,d[N],dis[N],mxdd;
int f[1003][1003],g[1003],s[1003][1003],fv[1003];
int l,r,mid;
int id,mx;
int q[N],head,tail;
bool bz[N];
int max(int a,int b){return a>b?a:b;}
void ins(int x,int y,int z)
{
	nxt[++tot]=lst[x];
	to[tot]=y;v[tot]=z;
	lst[x]=tot;
}
void bfs(int st)
{
	memset(dep,0,sizeof(dep));
	memset(dis,0,sizeof(dis));
	for(head=0,dep[q[tail=1]=st]=1;head<tail;)
	{
		x=q[++head];
		for(int i=lst[x];i;i=nxt[i])
			if(dep[to[i]]==0)dep[to[i]]=dep[x]+1,dis[to[i]]=dis[x]+v[i],q[++tail]=to[i];
	}
}
int check(int m)
{
	memset(f,0,sizeof(f));
	memset(s,0,sizeof(s));
	memset(g,0,sizeof(g));
	for(int i=n;i;i--)
	{
		x=q[i];ls=rs=0;
		mxd[x]=dep[x];
		for(int j=lst[x];j;j=nxt[j])
			if(dep[to[j]]>dep[x])
			{
				mxd[x]=max(mxd[x],mxd[to[j]]);
				if(ls==0)ls=to[j];else rs=to[j];
			}else fv[x]=v[j];
		
		for(int j=1;j<=mxd[x]-dep[x];j++)
			f[x][j]=f[ls][j-1]+g[rs],s[x][j]=s[ls][j-1]+fv[ls];
		if(rs)
		{
			for(int j=1;j<=mxd[x]-dep[x];j++)
				if(f[x][j]<f[rs][j-1]+g[ls] || (f[x][j]==f[rs][j-1]+g[ls] && s[x][j]<s[rs][j-1]+fv[rs]))
					f[x][j]=f[rs][j-1]+g[ls],s[x][j]=s[rs][j-1]+fv[rs];
		}
		y=z=0;f[x][0]=g[ls]+g[rs];
		for(int j=mxd[ls]-dep[ls];j+1;j--)
		{
			for(;y<=mxd[rs] && s[rs][y]+s[ls][j]+fv[ls]+fv[rs]<m;y++)z=max(z,f[rs][y]);
			f[x][0]=max(f[x][0],f[ls][j]+z);
			if(s[rs][y]+s[ls][j]+fv[ls]+fv[rs]>=m)f[x][0]=max(f[x][0],f[ls][j]+f[rs][y]+1);
		}
		for(int j=0;j<=mxd[x]-dep[x];j++)
			g[x]=max(g[x],f[x][j]+(s[x][j]+fv[x]>=m));
	}
	return g[q[1]];
}
void dg(int x,int y,int z,int len)
{
	if(z<=ans)return;
	if(y>m)
	{
		ans=z;
		return;
	}
	for(int i=lst[x];i;i=nxt[i])
		if(bz[i>>1])
		{
			bz[i>>1]=0;
			dg(to[i],y,z,len+v[i]);
			bz[i>>1]=1;
		}
	for(int i=1;i<=n;i++)
		dg(i,y+1,min(z,len),0);
}
int check_(int m)
{
	int lst=0,s=0;
	for(int i=1;i<=n;i++)
		if(dis[q[i]]-dis[lst]>=m)s++,lst=i;
	return s;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	read(n);read(m);tot=1;
	for(int i=1;i<n;i++)
		read(x),read(y),read(z),r=r+z,ins(x,y,z),ins(y,x,z),d[x]++,d[y]++,mxdd=max(mxdd,max(d[x],d[y]));
	if(n>10 && n<=15)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			memset(bz,1,sizeof(bz));
			dg(i,1,2147483647,0);
		}
		printf("%d",ans);
		return 0;
	}
	if(m==1)
	{
		bfs(1);mx=0;
		for(int i=1;i<=n;i++)
			if(dis[i]>mx)mx=dis[i],id=i;
		bfs(id);mx=0;
		for(int i=1;i<=n;i++)
			if(dis[i]>mx)mx=dis[i],id=i;
		printf("%d",mx);
		return 0;
	}
	if(mxdd==2)
	{
		for(int i=1;i<=n;i++)
			if(d[i]==1){bfs(i);break;}
		for(l=0,r=r/m+1;l<r;)
		{
			mid=(l+r)>>1;
			if(check_(mid)<m)r=mid;else l=mid+1,mx=mid;
		}
		if(check_(l)>=m)mx=max(mx,l);
		printf("%d",mx);
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(d[i]==1){bfs(i);break;}
	for(l=0,r=r/m+1;l<r;)
	{
		mid=(l+r)>>1;
		if(check(mid)<m)r=mid;else l=mid+1,mx=mid;
	}
	if(check(l)>=m)mx=max(mx,l);
	printf("%d",mx);
	return 0;
}
