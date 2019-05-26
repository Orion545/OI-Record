#include<cstring>
#include<cstdio>
#define N 5010
#define fo(i,a,b) for(int i=a,_E_=b;i<=_E_;++i)
#define fd(i,a,b) for(int i=a,_E_=b;i>=_E_;--i)
using namespace std;

int n,m,fir[N],nex[N+N],to[N+N],top=1,t,r[N],sta[N],tot,bel[N],fa[N];
bool vis[N],pas[N];
struct road{int x,y;}l[N+N];

#define link(x,y) to[++top]=y,nex[top]=fir[x],fir[x]=top
void rsort(){
	int t=0;
	fo(i,1,n)for(int j=fir[i];j;j=nex[j])l[++t]=(road){to[j],i};
	memset(fir,0,sizeof fir);top=0;
	fd(i,t,1)link(l[i].x,l[i].y);
}
void print(int x){
	printf("%d ",x);vis[x]=1;
	for(int i=fir[x];i;i=nex[i])if(!vis[to[i]])print(to[i]);
}
void dg(int x){
	vis[x]=1;sta[++tot]=x;
	for(int i=fir[x];i;i=nex[i])if(!pas[i>>1]){
		pas[i>>1]=1;if(vis[to[i]]){
			int las=tot+1;
			do r[++t]=sta[--las];while(sta[las]!=to[i]);
		}else dg(to[i]);
	}--tot;
}
void go(int x,int F){
	vis[x]=1;bel[x]=F;
	for(int i=fir[x];i;i=nex[i])if(!vis[to[i]])fa[to[i]]=x,go(to[i],F);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	fo(i,1,m){
		int x,y;scanf("%d %d",&x,&y);link(x,y);link(y,x);
	}
	if(m==n-1){
		rsort();print(1);
	}else{
		dg(1);
		memset(vis,0,sizeof vis);
		fo(i,1,t)vis[r[i]]=1;
		fo(i,1,t)go(r[i],i);
		memset(vis,0,sizeof vis);
		rsort();
		if(r[bel[1]]!=1){
			for(int i=fir[1];i;i=nex[i])if(to[i]>fa[1])vis[to[i]]=1;
			vis[r[bel[1]]]=1;print(1);
		}
		int x=bel[1],le=(x+t-2)%t+1,ri=x%t+1;
		if(r[le]<r[ri]){
			int u=le;while(r[u]<r[ri])u=(u+t-2)%t+1;
			vis[r[u]]=1;vis[r[ri]]=1;print(r[x]);vis[r[u]]=0;print(r[ri]);
		}else{
			int u=ri;while(r[u]<r[le])u=u%t+1;
			vis[r[u]]=1;vis[r[le]]=1;print(r[x]);vis[r[u]]=0;print(r[le]);
		}
		if(r[bel[1]]!=1){
			for(int i=fir[1];i;i=nex[i])if(to[i]>fa[1])print(to[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
