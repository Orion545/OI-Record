#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int g[100100],head[100100],a,cnt=0,xx,b,yy;
bool visit[100100];
long long f[100100][2];
struct ed{
	int to,nex;
}edge[201000];
void add(int x,int y)
{
	cnt++;
	edge[cnt].to=y;
	edge[cnt].nex=head[x];
	head[x]=cnt;
}
long long DFS(int x,int can)
{
	visit[x]=1;
	if (f[x][can]) return f[x][can];
	long long an=0;
	if (can==1) an=g[x];
	for (int i=head[x];i;i=edge[i].nex){
	
		if (visit[edge[i].to]) continue;
		//
		if (edge[i].to==b&&yy==1) {
			long long uu=DFS(edge[i].to,1);
			an+=uu;
		}
		else if (edge[i].to==b&&yy==0) {
			if (can==0) return 1e13;
			long long uu=DFS(edge[i].to,0);
			an+=uu;
		}
		else {
			//printf("%d DFS %d\n",x,edge[i].to);
			long long uu=DFS(edge[i].to,0),vv=DFS(edge[i].to,1);
			if (can==0) an+=vv;
			else an+=min(uu,vv);
			//printf("nowans=%lld\n",an);
		}
	}
	f[x][can]=an;
	//printf("f[%d][%d]=%lld\n",x,can,an);
	visit[x]=0;
	return an;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	char typ[5];
	scanf("%d%d%s",&n,&m,typ);
	for (int i=1;i<=n;i++) scanf("%d",&g[i]);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for (int i=1;i<=m;i++){
		memset(visit,0,sizeof(visit));
		memset(f,0,sizeof(f));
		scanf("%d%d%d%d",&a,&xx,&b,&yy);
		long long ann=DFS(a,xx);
		printf("%lld\n",ann<=1e11?ann:-1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
