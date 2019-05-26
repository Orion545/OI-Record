#include<cstdio>
using namespace std;
struct arr{
	int x,y,w,next;
}edge[70000];
int tot,n,m,ls[70000],ans,p[70000];

int add(int x,int y,int w){
	edge[++tot].x=x; edge[tot].y=y; edge[tot].w=w;
	edge[tot].next=ls[edge[tot].x]; ls[edge[tot].x]=tot;
	edge[++tot].x=y; edge[tot].y=x; edge[tot].w=w;
	edge[tot].next=ls[edge[tot].x]; ls[edge[tot].x]=tot;
}

int ma(int x,int y){
	if (x>y) return x;
	return y;
}

int ss(int x,int w,int e){
	int i=ls[x];
	p[x]=e;
	ans=ma(w,ans);
	while (i!=0){
		if (p[edge[i].y]!=e)
			ss(edge[i].y,w+edge[i].w,e);
		i=edge[i].next;
	}
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int mi=20000,sum=0;
	for (int i=1;i<n;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		if (w<mi) mi=w;
		sum+=w;
		add(x,y,w);
	}
	if (m==n-1)
		printf("%d\n",mi);
	else
	if (m==1){
		int e=0;
		for (int i=1;i<=n;i++)
			ss(i,0,++e);
		printf("%d\n",ans);
	}
	else printf("%d\n",sum/m);
	fclose(stdin);fclose(stdout);
}
