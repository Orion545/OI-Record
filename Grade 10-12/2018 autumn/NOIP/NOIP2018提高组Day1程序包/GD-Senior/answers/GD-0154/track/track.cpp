#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define N 50010
#define P(a) putchar(a)
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
struct note{
	int to,next,val;
}edge[N<<1];
int tot,head[N];
bool p1,p2,p3;
int a[N];
int du[N],fa[N],fx[N];
int son[N][2];
int bian[N];
int vl,vr,vm,va,lian[N];
int i,j,k,l,n,m,ans,cnt;
int dep[N],mx,rt;
int u,v,w,T,gx,w1;
int u3,v3,u4,v4,tv;
int f[N],g[N][2];
int dfn[N],tar[N],siz[N];
int read(){
	int rs=0,fh=0;char ch=0;
	while((ch<'0'||ch>'9')&&(ch^'-'))ch=getchar();
	if(ch=='-')fh=1,ch=getchar();
	while(ch>='0'&&ch<='9')rs=(rs<<3)+(rs<<1)+(ch^'0'),ch=getchar();
	return fh?-rs:rs;
}
void write(int x){
	if(x>9)write(x/10);
	P(x%10+'0');
}
void lb(int x,int y,int z){
	edge[++tot].to=y;
	edge[tot].next=head[x];
	edge[tot].val=z;
	head[x]=tot;
	du[x]++;
}
void dg(int x){
	int i;
	for(i=head[x];i;i=edge[i].next)
	    if(fa[x]^edge[i].to){
	    	fa[edge[i].to]=x;
	    	dep[edge[i].to]=dep[x]+edge[i].val;
	    	dg(edge[i].to);
	    }
}
void dg1(int x){
	int i,g0=0;
	dfn[x]=++T;tar[T]=x;
	siz[x]=1;
	for(i=head[x];i;i=edge[i].next)
	    if(fa[x]^edge[i].to){
	    	fa[edge[i].to]=x;
	    	son[x][g0]=edge[i].to;
	    	dep[edge[i].to]=dep[x]+edge[i].val;
	    	fx[edge[i].to]=g0;
	    	dg1(edge[i].to);
	        siz[x]=siz[x]+siz[edge[i].to];
	        g0++;
		} 
}
bool cmp(int x,int y){return x>y;}
int Max(int x,int y){return x>y?x:y;}
void dp(int x){
	int i,u2,v2;
	for(i=head[x];i;i=edge[i].next)
	    if(edge[i].to^fa[x]){
	    	dp(edge[i].to);
	    	tv=f[x];
	    	fo(u2,dfn[x],dfn[edge[i].to]-1){
	    		fo(v2,dfn[edge[i].to],dfn[edge[i].to]+siz[edge[i].to]-1){
	    			u4=tar[u2];
	    			v4=tar[v2];
	    			w1=dep[u4]+dep[v4]-2*dep[x];
	    			if(w1<vm)continue;
	    			if(u4==x)gx=f[v4]+tv;else gx=f[u4]+f[v4];
	    			u3=u4,v3=v4;
	    			while(u3^x){
	    				if(fa[u3]^x){
	    					gx=gx+g[fa[u3]][fx[u3]];
	    				}
					    u3=fa[u3];
					}
					while(v3^x){
						if(fa[v3]^x){
	    					gx=gx+g[fa[v3]][fx[v3]];
	    				}
						v3=fa[v3];
					}
					f[x]=Max(f[x],gx+1);
	    		}
	    		if(fx[edge[i].to]==1&&u4==x){
	    			g[x][0]=f[x]-g[x][1];
	    		}
	    	}
	    	if(fx[edge[i].to]==0){
	    		g[x][1]=f[x];
	    	}
	    }
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();
	p1=p2=p3=0;
	fo(i,1,n-1){
		u=read(),v=read(),w=read();
		lb(u,v,w);lb(v,u,w);
		if(u^1)p1=1;
		if(v-u!=1)p2=1;
	}
	if(m==1){
		dep[1]=0;
		dg(1);
		mx=0;
		fo(i,1,n)if(dep[i]>dep[mx])mx=i;
		v=mx;
		dep[v]=0;
		fo(i,1,n)fa[i]=0; 
		dg(v);
		mx=0;
		fo(i,1,n)if(dep[i]>mx)mx=dep[i];
		write(mx);
		return 0;
	}
	if(!p1){
		fo(i,1,n-1)bian[i]=edge[i<<1].val;
		sort(bian+1,bian+n+1,cmp);
		ans=bian[m];
		if(m+1<=n-1){
			if(bian[m]+bian[m+1]>=bian[m-1])
			ans=bian[m-1];
		}
		write(ans);
		return 0;
	}
	if(!p2){
		fo(i,1,n-1)lian[i]=edge[i<<1].val;
		ans=0;
		vl=0,vr=1000000000;
		while(vl<=vr){
			vm=(vl+vr)>>1;
			va=0;
			cnt=0;
			fo(i,1,n-1){
				va=va+lian[i];
				if(va>=vm){
					va=0;
					cnt=cnt+1;
				}
			}
			if(cnt<m)vr=vm-1;else ans=vm,vl=vm+1;
		}
		write(ans);
		return 0;
	}
	fo(i,1,n)if(du[i]>3)p3=1;
	if(!p3){
		fo(i,1,n)if(du[i]==1){
			rt=i;
			break;
		}
		ans=0;
		vl=0,vr=1000000000;
		fo(i,1,n)fa[i]=0;
		dep[rt]=0;
		dg1(rt); 
		while(vl<=vr){
			vm=(vl+vr)>>1;
			fo(i,1,n){
				f[i]=0;
				g[i][0]=g[i][1]=0;
			}
			dp(rt);
			if(f[rt]<m)vr=vm-1;else ans=vm,vl=vm+1;
		}
		write(ans);
		return 0;
	}
	return 0;
}
