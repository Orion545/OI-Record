#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5E3+5;
struct Edge{
	int from,to,nxt,w;
}p[N*2],w[N*2];
int d[N],tot=0,lst[N],deg[N],Ans[N],len=0;
int q[N],bz[N*2],Tag[N],cir[N],n,m,x,y;
bool cmp(Edge a,Edge b){
	if (a.from<b.from) return 1;
	if (a.from>b.from) return 0;
	return a.to>b.to;
}
void Add(int x,int y,int z){
	p[++len].to=y;
	p[len].from=x;
	p[len].nxt=lst[x];
	p[len].w=z;
	lst[x]=len;
}
void Turpo(){
	int tail=0;
	for(int i=1;i<=n;i++)
		if (deg[i]==1)
			q[++tail]=i;
		else
			Tag[i]=1;
	for(int head=1;head<=tail;head++){
		int now=q[head];
		for(int j=lst[now];j;j=p[j].nxt){
			int that=p[j].to;
			if (!Tag[that])
				continue;
			deg[that]--;
			if (deg[that]==1){
				q[++tail]=that;
				Tag[that]=0;
			}
		}
	}for(int i=1;i<=n;i++)
		if (Tag[i])
			cir[++cir[0]]=i;
}
void solve(int x,int pre){
	d[++tot]=x;
	for(int j=lst[x];j;j=p[j].nxt){
		if (bz[p[j].w]) continue;
		int that=p[j].to;
		if (that!=pre){
			solve(that,x);
		}
	}
}
void Merge(){
	for(int i=1;i<=n;i++)
		if (d[i]>Ans[i]) return;
	memcpy(Ans,d,sizeof(Ans));
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(Ans,0x7f,sizeof(Ans));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		w[i*2-1].from=x;w[i*2-1].to=y;w[i*2-1].w=i;
		w[i*2].from=y;w[i*2].to=x;w[i*2].w=i;
		deg[x]++;deg[y]++;
	}sort(w+1,w+m*2+1,cmp);
	for(int i=1;i<=m*2;i++)
		Add(w[i].from,w[i].to,w[i].w);
	Turpo();
	if (m==n-1){
		solve(1,0);
		for(int i=1;i<=tot;i++)
			printf("%d ",d[i]);
	}else{
		int tmp=cir[1],pre;
		for(int j=lst[tmp];j;j=p[j].nxt)
			if (Tag[p[j].to]){
				pre=p[j].to;
				break;
			}
		for(int i=1;i<=cir[0];i++){
			for(int j=lst[tmp];j;j=p[j].nxt){
				int that=p[j].to;
				if (Tag[that]&&that!=pre){
					bz[p[j].w]=1;tot=0;
					solve(1,0);
					Merge();
					bz[p[j].w]=0;
					pre=tmp;tmp=that;
					break;
				}
			}
		}for(int i=1;i<=n;i++)
			printf("%d ",Ans[i]);
	}
	return 0;
}
