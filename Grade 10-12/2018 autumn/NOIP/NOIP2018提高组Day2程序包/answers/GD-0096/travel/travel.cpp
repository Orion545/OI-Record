#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct trnode{
	int x,y;
}tr[41000];
struct node{
	int x,y,next;
}a[21000];int len,last[21000];
void ins(int x,int y){
	a[++len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
int cmp(const void *xx,const void *yy){
	trnode n1=*(trnode *)xx;
	trnode n2=*(trnode *)yy;
	return n2.y-n1.y;
}
bool bk[21000];
int ans[21000],sum=0;
void dfs(int x){
	bk[x]=false;ans[++sum]=x;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(bk[y]) dfs(y);
	}
}
int fa[21000],hs,he,h[21000];
void dfs2(int x,int fa2){
	bk[x]=false;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(bk[y]) fa[y]=x,dfs2(y,x);
		else if(fa2!=y&&hs==0) hs=x,he=y;
	}
}
void dfs3(int x){
	ans[++sum]=x;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(fa[y]==x) dfs3(y);
	}
}
int mymax(int x,int y) {return x>y?x:y;}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<=m;i++) scanf("%d%d",&tr[i].x,&tr[i].y);
	for(int i=1;i<=m;i++) tr[i+m].x=tr[i].y,tr[i+m].y=tr[i].x;
	qsort(tr+1,2*m,sizeof(trnode),cmp);
	for(int i=1;i<=2*m;i++) ins(tr[i].x,tr[i].y);
	
	if(m==n-1){
		memset(bk,true,sizeof(bk));dfs(1);
		for(int i=1;i<=n;i++){
			if(i<n) printf("%d ",ans[i]);
			else printf("%d\n",ans[i]);
		}
	}
	else{
		memset(fa,0,sizeof(fa));hs=he=0;
		memset(bk,true,sizeof(bk));dfs2(1,0);
		int max=hs,id=hs;
		while(id!=he){
			if(id>hs) max=id;
			id=fa[id];
		}
		int id2=hs;
		while(id2!=max) h[++h[0]]=id2,id2=fa[id2];
		for(int i=h[0];i>=1;i--) fa[fa[h[i]]]=h[i];
		if(max!=hs) fa[hs]=he;
		dfs3(1);
		for(int i=1;i<=n;i++){
			if(i<n) printf("%d ",ans[i]);
			else printf("%d\n",ans[i]);
		}
	}
	return 0;
}
