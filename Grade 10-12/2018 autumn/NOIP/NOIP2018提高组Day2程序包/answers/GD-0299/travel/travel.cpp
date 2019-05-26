#include<cstdio>
#define INF 2147483647
#define N 5010
using namespace std;
int n,m,p,q,ans[N],a[N],b[N],num,h[N],tot,c[N],mn,w;
struct Edge{
	int p,q,n;
}e[N*2];
void ljb(int p,int q){
	e[++num].n=h[p];
	e[num].p=p;
	e[num].q=q;
	h[p]=num;
}
void Dfs(int x,int fa){
	ans[++tot]=x;
	b[x]=1;
	for(int j=1;j<=c[x];j++){
		mn=INF;
		for(int i=h[x];i!=0;i=e[i].n){
			if(e[i].q==fa||b[e[i].q])continue;
			if(e[i].q<mn){
				mn=e[i].q;
				w=e[i].q;
			}
		}
		Dfs(w,x);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&p,&q);
		ljb(p,q);
		ljb(q,p);
		c[p]++;
		c[q]++;
	}
	if(m==n-1){
//		for(int i=1;i<=n;i++)printf("%d ",c[i]);
//		printf("\n");
		for(int i=2;i<=n;i++)c[i]--;
		Dfs(1,0);
		for(int i=1;i<=tot;i++)printf("%d ",ans[i]);
	}
	else {
		b[1]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(!b[j]||a[j])continue;
				a[j]=1;
				ans[i]=j;
				for(int k=h[j];k!=0;k=e[k].n){
					if(a[e[k].q]||b[e[k].q]==1)continue;
					b[e[k].q]=1;
				}
				break;
			}
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	}
	
}
