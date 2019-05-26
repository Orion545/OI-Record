#include<cstdio>
#include<iostream>
#include<cstring>
#include<cctype>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<bitset>

using namespace std;

#define N 5005
#define REP(i,a,b)	for(int i=a;i<=b;i++)
#define DOW(i,a,b)	for(int i=a;i>=b;i--)
#define CL(a,b)	memset(a,b,sizeof(a))


struct edge{
	int fr,to,nex,id;
}E[N<<1];

int head[N];
void add(int i,int j){
	static int t=0;
	E[++t]=(edge){i,j,head[i]};
	head[i]=t;
}

priority_queue<int,vector<int>,greater<int> > que;

int vis[N],ans[N];

vector<int> vec[N];

int L,dfn[N],low[N],cnt,sta[N],top,fg,in[N],bl[N],S[N];

void tarjan(int now,int fa){
	dfn[now]=low[now]=++cnt;
	sta[++top]=now;
	for(int i=head[now];i;i=E[i].nex){
		if(E[i].to!=fa){
			if(!dfn[E[i].to])tarjan(E[i].to,now),low[now]=min(low[now],low[E[i].to]);
			else if(!in[E[i].to])low[now]=min(low[now],dfn[E[i].to]);
		}
	}
	if(low[now]==dfn[now]){
		int p=0,siz=0;
		L++;
		do{
			p=sta[top--];
			in[p]=1,bl[p]=L;
		}while(p!=now);
		S[L]=siz;
	}
}


int Fg,CC,ta[N];
int dfs(int now){
	vis[now]=1;
	vec[now].clear();
	ans[++CC]=now;
	if(Fg==0&&ta[CC]<ans[CC])return 1;
	if(ta[CC]>ans[CC])Fg=1;
	for(int i=head[now];i;i=E[i].nex)
		if(E[i].id!=fg&&!vis[E[i].to])
			vec[now].push_back(E[i].to);
	sort(vec[now].begin(),vec[now].end());
	REP(i,0,(int)vec[now].size()-1)if(dfs(vec[now][i]))return 1;
	return 0;
}



int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	freopen("travel.in","w",stdout);
	
	int n,m;
	scanf("%d %d",&n,&m);
	REP(i,1,m){
		int x,y;
		scanf("%d %d",&x,&y);
		add(x,y);add(y,x);
	}
	CL(ta,0x3f);
//	dij();
	if(m==n-1){
		fg=0x3f3f3f3f;
		dfs(1);
		REP(i,1,n)printf("%d ",ans[i]);
		return 0;
	}
	tarjan(1,0);
	int Cnt=0;
	for(int i=1;i<=2*m;i+=2)if(bl[E[i].fr]==bl[E[i].to])E[i].id=E[i+1].id=++Cnt;
	REP(i,1,Cnt){
		fg=i;
		Fg=0,CC=0;
		CL(vis,0);
		if(dfs(1));
		else REP(j,1,n)ta[j]=ans[j];
//		REP(j,1,n)printf("%d ",ta[j]);
//		printf("\n");
	}
	
	REP(i,1,n)printf("%d ",ta[i]);
	
	
	
	return 0;
}
