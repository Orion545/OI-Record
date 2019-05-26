#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	int x,y,next;
}a[110000];

int dfn[110000],last[110000],fa[110000],son[110000],c[110000],d[110000],vis[110000],ans[110000],deep[110000],jru[110000],jrv[110000];
int i,j,k,m,n,o,p,js,jl,jk,tot,x,y,u,v,len=0,mi,uu,vv,pd,fau,fav,jrr,uuu,vvv,zx,ma=0,qv,qu,mu,mv,jr;

void ins(int x,int y)
{
	len++;
	a[len].x=x;a[len].y=y;
	a[len].next=last[x];
	last[x]=len;
}

int dfs(int u)
{
	for(int k=last[u];k;k=a[k].next)
	{
		v=a[k].y;
		if(fa[u]!=v)
		{
			fa[v]=u;
			son[u]++;
			dfs(v);
		}
	}
	return 0;
}

int find(int u)
{
	int ll=d[u],rr=d[u];
	for(int k=last[u];k;k=a[k].next)
	{
		v=a[k].y;
		if(vis[v]==0 && fa[v]==u)
		{
			c[rr]=v;
			rr++;
		}
	}
	sort(c+ll,c+rr);rr--;
	for(int i=ll;i<=rr;i++)
	if(vis[c[i]]==0)
	{
		jl++;vis[c[i]]=1;
		dfn[jl]=c[i];
		find(c[i]);
	}
	return 0;
}

int dfss(int u)
{
	vis[u]=1;
	for(int k=last[u];k;k=a[k].next)
	{
		v=a[k].y;
		if(fa[u]!=v)
		{
			if(vis[v]==1)
			{
				uu=u;
				vv=v;
				continue;
			}
			fa[v]=u;
			son[u]++;
			deep[v]=deep[u]+1;
			dfss(v);
		}
	}
	return 0;
}

int findd(int u)
{
	int ll=d[u],rr=d[u];
	for(int k=last[u];k;k=a[k].next)
	{
		v=a[k].y;
		if(u==uuu && v==vvv)continue;
		if(v==uuu && u==vvv)continue;
		if(vis[v]==0)
		{
			c[rr]=v;
			rr++;
		}
	}
	sort(c+ll,c+rr);rr--;
	for(int i=ll;i<=rr;i++)
	if(vis[c[i]]==0)
	{
		jl++;vis[c[i]]=1;
		dfn[jl]=c[i];
		findd(c[i]);
	}
	return 0;
}

int main()
{
	FILE *fin,*fout;
	fin=fopen("travel.in","rb");
	fout=fopen("travel.out","wb");
	fscanf(fin,"%d%d",&n,&m);
	memset(vis,0,sizeof(vis));
	memset(dfn,0,sizeof(dfn));
	memset(fa,0,sizeof(fa));
	memset(son,0,sizeof(son));
	if(m==n-1)
	{
		for(int i=1;i<=m;i++)
		{
			fscanf(fin,"%d%d",&x,&y);
		    ins(x,y);
		    ins(y,x);
		}
		dfs(1);
		d[1]=1;
		for(int i=2;i<=n;i++)d[i]=d[i-1]+son[i-1];
		jl=1;dfn[1]=1;vis[1]=1;
		find(1);
		for(int i=1;i<=n;i++)fprintf(fout,"%d ",dfn[i]);
		
		
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			fscanf(fin,"%d%d",&x,&y);
		    ins(x,y);
		    ins(y,x);
		}
		dfss(1);
		d[1]=1;
		for(int i=2;i<=n;i++)d[i]=d[i-1]+son[i-1]+5;
		
		if(deep[uu]<deep[vv])
		{
			o=uu;
			uu=vv;
			vv=o;
		}
		
		jr=1;
		jru[1]=uu;
		jrv[1]=vv;
	    
		while(deep[uu]>deep[vv])
		{
			jr++;
			jru[jr]=uu;
			jrv[jr]=fa[uu];
			uu=fa[uu];	
		}
		while(uu!=vv)
		{
			jr++;
			jru[jr]=uu;
			jrv[jr]=fa[uu];
			uu=fa[uu];
            jr++;
			jru[jr]=vv;
			jrv[jr]=fa[vv]; 
			vv=fa[vv];
		}
		
		for(int k=1;k<=jr;k++)
		{
			uuu=jru[k];
			vvv=jrv[k];
			memset(vis,0,sizeof(vis));
		    memset(dfn,0,sizeof(dfn));
		    memset(c,0,sizeof(c));
		    jl=1;dfn[1]=1;vis[1]=1;
		    findd(1);pd=0;
		    for(int i=1;i<=n;i++)
		    {
			    if(dfn[i]<ans[i] || ans[i]==0)
		    	{
				    pd=1;
				    break;
			    }
			    if(dfn[i]>ans[i] || dfn[i]==0)
			    {
				    pd=2;
				    break;
		    	}
		    }
		    if(pd==1)for(int i=1;i<=n;i++)ans[i]=dfn[i];
		}
		for(int i=1;i<=n;i++)fprintf(fout,"%d ",ans[i]);		
		
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
