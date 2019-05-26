#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	int x,y,z,next;
}a[110000];

struct nodee
{
	int fa,son;
}tr[55000];

int last[55000],b[55000],c[55000],d[550000],vis[55000];

int i,j,k,m,n,o,p,js,jl,jk,pd=233,pdd=233,x,y,z,len=0,l=0,r=0,mid,u,v;

void ins(int x,int y,int z)
{
	len++;
	a[len].x=x;a[len].y=y;a[len].z=z;
	a[len].next=last[x];last[x]=len;
}

bool my_check(int u)
{
	jl=0;js=0;
	for(int i=1;i<n;i++)
	{
		jl=jl+b[i];
		if(jl>=u)
		{
			jl=0;
			js++;
		}
	}
	if(js>=m)return(true);
	else return(false);
}

int dfs(int u)
{
	for(int k=last[u];k;k=a[k].next)
	{
		v=a[k].y;
		if(v!=tr[u].fa)
		{
			tr[v].fa=u;
			tr[u].son++;
			dfs(v);
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
		if(v!=tr[u].fa)
		{
			c[rr]=findd(v)+a[k].z;
			rr++;
		}
	}
	sort(c+ll,c+rr);
	rr--;
	
	while(c[rr]>=mid && rr>=ll)
	{
		js++;
		vis[rr]=1;
		rr--;
	}
	
	for(int i=ll;i<rr;i++)
	{
		for(int j=i+1;j<=rr;j++)
	    {
		    if(c[i]+c[j]>=mid && vis[j]==0 && vis[i]==0)
		    {
		    	vis[j]=1;vis[i]=1;
		    	js++;
		    	break;
		    }
	    }
	}
	
	for(int i=rr;i>=ll;i--)
	if(vis[i]==0)return(c[i]);
	
	return(0);
	
}

bool our_check(int u)
{
	memset(c,0,sizeof(c));
	memset(vis,0,sizeof(vis));
	js=0;
	findd(1);
	if(js>=m)return(true);
	else return(false);
}

int main()
{
	FILE *fin,*fout;
	fin=fopen("track.in","rb");
	fout=fopen("track.out","wb");
	fscanf(fin,"%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		fscanf(fin,"%d%d%d",&x,&y,&z);
		b[x]=z;r+=z;
		if(x!=1 && y!=1)pd=0;
		if(y-x!=1)pdd=0;
		ins(x,y,z);
		ins(y,x,z);
	}
	
	if(pd==233)
    {
    	memset(b,0,sizeof(b));
    	jl=0;
    	for(int k=last[1];k;k=a[k].next)
    	{
    		jl++;
    		b[jl]=a[k].z;
    	}
    	
    	sort(b+1,b+jl+1);
    	
    	fprintf(fout,"%d",b[jl-m+1]);
    	fclose(fin);
	    fclose(fout);
	    return 0;
    }
    
    
    
    if(pdd==233)
    {
    	l=0;r=r+1;
    	while(r-l>1)
    	{
    		mid=(l+r)/2;
    		if(my_check(mid)==true)l=mid;
    		else r=mid;
    	}
    	fprintf(fout,"%d",l);
    	fclose(fin);
	    fclose(fout);
	    return 0;
    }
    
    dfs(1);
    
    d[1]=1;
    for(int i=2;i<=n;i++)
    {
    	d[i]=d[i-1]+tr[i-1].son;
    }
    
    l=0;r=r+1;
    while(r-l>1)
    {
    	mid=(l+r)/2;
    	if(our_check(mid)==true)l=mid;
    	else r=mid;
    }
    
    fprintf(fout,"%d",l);
    
	fclose(fin);
	fclose(fout);
	return 0;
}
