#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100010
#define LL long long
#define P(a) putchar(a)
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
struct note{
	int to,next;
}edge[N<<1];
int tot,head[N];
LL f[N][2],h[N],ans;
LL pre[N][2],suf[N][2];
LL hp[N],hs[N];
int fa[N],du[N];
int n,m,q,i,j,k,l;
int u,v,p[N];
int u1,u2,v1,v2;
int bz[N];
char s[3];
LL Min(LL x,LL y){return x<y?x:y;}
int read(){
	int fh=0,rs=0;char ch=0;
	while((ch<'0'||ch>'9')&&(ch^'-'))ch=getchar();
	if(ch=='-')fh=1,ch=getchar();
	while(ch>='0'&&ch<='9')rs=(rs<<3)+(rs<<1)+(ch^'0'),ch=getchar();
	return fh?-rs:rs;
}
void write(int x){
	if(x>9)write(x/10);
	P(x%10+'0');
}
void lb(int x,int y){
	edge[++tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
	du[y]++;
}
void dg(int x){
	int i;
	if(bz[x]==-1){
		f[x][0]=0;
	    f[x][1]=p[x];
	}else
	if(bz[x]==0){
		f[x][0]=0;
	}else{
		f[x][1]=p[x];
	}
	for(i=head[x];i;i=edge[i].next)
	    if(fa[x]^edge[i].to){
	    	fa[edge[i].to]=x;
	    	dg(edge[i].to);
	    	if(bz[x]!=1)
	    	f[x][0]+=f[edge[i].to][1];
	    	if(bz[x]!=0)
	    	f[x][1]+=h[edge[i].to];
	    }
	h[x]=Min(f[x][0],f[x][1]);
}
void dgs(int x){
	int i;
	if(bz[x]==-1){
		suf[x][0]=0;
	    suf[x][1]=p[x];
	}else
	if(bz[x]==0){
		suf[x][0]=0;
	}else{
		suf[x][1]=p[x];
	}
	for(i=head[x];i;i=edge[i].next){
		if(edge[i].to==x-1){
			dgs(edge[i].to);
		    suf[x][0]+=suf[edge[i].to][1];
			suf[x][1]+=hs[edge[i].to];
		}
	}
	hs[x]=Min(suf[x][0],suf[x][1]);
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();m=read();scanf("%s\n",s);
	fo(i,1,n)p[i]=read();
	fo(i,1,n-1){
		u=read();v=read();
		lb(u,v);lb(v,u);
	}
	fo(j,1,n){
	    h[j]=20000000000;
		f[j][0]=f[j][1]=20000000000;
		bz[j]=-1;
	}
	dg(1);
	if(n<=2000){
		fo(i,1,m){
		    fo(j,1,n){
		    	h[j]=20000000000;
		    	f[j][0]=f[j][1]=20000000000;
		    	bz[j]=-1;
		    }
		    u1=read();u2=read();v1=read();v2=read();
		    bz[u1]=u2;
		    bz[v1]=v2;
		    dg(1);
		    if(h[1]>10000000000)printf("-1\n");
		    else printf("%lld\n",h[1]);
    	}
		return 0;
	}
	if(s[0]=='A'&&s[1]=='2'){
		dgs(n);
		fo(i,1,m){
			u1=read();u2=read();v1=read();v2=read();
			if(u1>v1){
				swap(u1,v1);
				swap(u2,v2);
			}
			if(!u2&&!v2){
				printf("-1\n");
				continue;
			}
			if(!u2&&v2){
				ans=suf[u1-1][1]+h[v1+1]+p[v1];
				printf("%lld\n",ans);
				continue;
			}
			if(u2&&!v2){
				ans=hs[u1-1]+f[v1+1][1]+p[u1];
				printf("%lld\n",ans);
				continue;
			}
			if(u2&&v2){
				ans=hs[u1-1]+h[v1+1]+p[u1]+p[v1];
				printf("%lld\n",ans);
				continue;
			}
		}
		return 0;
	}
	return 0;
}
