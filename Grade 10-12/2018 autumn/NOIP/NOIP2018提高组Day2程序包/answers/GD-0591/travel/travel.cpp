#include<cstdio>
#include<cstring>
#define rg register
#define il inline
#define For(i,a,b) for(rg int i=(a);i<=(b);i++)
#define rep(i,n) for(rg int i=0;i<(n);i++)
typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;

//freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);

il void read(int &x){
	x=0;char c=getchar();int f=1;
	while((c<'0'||c>'9')&&(c!=EOF)){if(c=='-')f=-1;c=getchar();}
	if(c==EOF)return;
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}

const int N=5010;



int n,m;

il int min(int a,int b){return a>b?b:a;}
il int max(int a,int b){return a<b?b:a;}
il int abs(int a){return a>0?a:-a;}


bool map[N][N];
bool vis[N];
void dfs(int x){
	vis[x]=1;printf("%d ",x);
	For(i,1,n)if((!vis[i])&&(map[x][i]))dfs(i);
}


int s,t;
bool cd[N][N];
int fa[N];
int f(int x){
	if(x==fa[x])return x;
	return fa[x]=f(fa[x]);
}
int cp[N],tp;
bool incp[N];
bool findc(int x){
	if(x==t)return 1;
	vis[x]=1;
	For(i,1,n)if((!vis[i])&&(map[x][i])){
		if(findc(i)){
			cd[x][i]=cd[i][x]=1;cp[++tp]=i;
			return 1;
		}
	}
	return 0;
}

void dfs2(int x){
	if(x>t)return;
	vis[x]=1;printf("%d ",x);
	For(i,1,n)if((!vis[i])&&(map[x][i]))dfs(i);
}

void dfs3(int x){
	if((incp[x])&&(x>t))return;
	vis[x]=1;printf("%d ",x);
	For(i,1,n)if((!vis[i])&&(map[x][i]))dfs(i);
}


int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	
	read(n);read(m);
	if(m<n){
		For(i,1,m){
			int u,v;read(u);read(v);map[u][v]=map[v][u]=1;
		}
		dfs(1);return 0;
	}
	
	For(i,1,n)fa[i]=i;
	
	For(i,1,m){
			int u,v;read(u);read(v);
			int uu=f(u),vv=f(v);
			if(uu==vv){s=u;t=v;continue;}
			fa[vv]=uu;
			map[u][v]=map[v][u]=1;
		}
		
	findc(s);cp[++tp]=s;
	memset(vis,0,sizeof vis);
	if(tp==n){
		map[s][t]=map[t][s]=1;
		s=t=0x3f3f3f3f;
		For(i,1,n)if(map[1][i]){
			if(i<s){t=s;s=i;}else
			if(i<t)t=i;
		}
		dfs2(1);dfs(t);
		return 0;
	}
	int pjz=0;
	For(i,1,tp){incp[cp[i]]=1;pjz+=cp[i];}
	if(incp[1]){
		map[s][t]=map[t][s]=1;
		s=t=0x3f3f3f3f;
		For(i,1,n)if(map[1][i]&&incp[i]){
			if(i<s){t=s;s=i;}else
			if(i<t)t=i;
		}
		dfs3(1);dfs(t);
		return 0;
	}
	pjz/=tp;
	For(i,2,tp){
		if(abs(cp[i]-cp[i-1])>pjz)map[cp[i]][cp[i-1]]=map[cp[i-1]][cp[i]]=0;break;}
	map[s][t]=map[t][s]=1;
	dfs(1);
	
	return 0;
}




