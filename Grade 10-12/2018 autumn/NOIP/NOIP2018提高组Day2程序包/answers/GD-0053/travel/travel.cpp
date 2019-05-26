#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,cnt=0,head[5050],ans[5050],tot=0,left[5050],right[5050];
short tmp[5050][5050];
bool visit[5050];
struct ed{
	int to,nex;
}edge[10100];
void add(int x,int y)
{
	cnt++;
	edge[cnt].to=y;
	edge[cnt].nex=head[x];
	head[x]=cnt;
}
void DFS(int x)
{
	//printf("now:%d\n",x);
	int s=0;
	ans[++tot]=x;
	for (int i=head[x];i;i=edge[i].nex)
	if (visit[edge[i].to]==0) tmp[x][++s]=edge[i].to,visit[edge[i].to]=1;
	sort(tmp[x]+1,tmp[x]+s+1);
	//for (int i=1;i<=s;i++) printf("%d ",tmp[x][i]);printf("\n");
	for (int i=1;i<=s;i++) DFS(tmp[x][i]);//;,printf("%d DFS %d\n",x,tmp[x][i]);
}
void DFS2(int x,int y,int turn,int have,int nt)
{
	if (have==n) return;
	int u,v;
	if (visit[left[x]]) u=right[x];
	else u=left[x];
	if (visit[left[y]]||(left[y]==u&&have==1)) v=right[y];
	else v=left[y];
	//printf("%d %d %d %d(%d %d)\n",x,y,u,v,turn,nt);
	if (turn==1){
		visit[v]=1;
		ans[++tot]=v;
		DFS2(x,v,1,have+1,nt);
	}
	else if (turn==2){
		visit[u]=1;
		ans[++tot]=u;
		DFS2(u,y,2,have+1,nt);
	}
	else if (u<v){
		visit[u]=1;
		ans[++tot]=u;
		int nn,kk=0;
		if (nt==0) nn=2;
		else if (nt==1) kk=2;
		DFS2(u,y,kk,have+1,nn);
	}
	else{
		visit[v]=1;
		ans[++tot]=v;
		int nn,kk=0;
		if (nt==0) nn=1;
		else if (nt==2) kk=1;
		DFS2(x,v,kk,have+1,nn);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==m){
		for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if (left[x]) right[x]=y;
		else left[x]=y;
		if (left[y]) right[y]=x;
		else left[y]=x;}
		ans[++tot]=1;
		visit[1]=1;
		DFS2(1,1,0,1,0);
		if (tot<n){
			for (int i=1;i<=n;i++)
			printf("%d ",i);
			return 0;
		}
		for (int i=1;i<=tot;i++)
		printf("%d ",ans[i]);
		return 0;
	}
	memset(visit,0,sizeof(visit));
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	visit[1]=1;
	DFS(1);
	for (int i=1;i<=tot;i++)
	printf("%d ",ans[i]);
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
