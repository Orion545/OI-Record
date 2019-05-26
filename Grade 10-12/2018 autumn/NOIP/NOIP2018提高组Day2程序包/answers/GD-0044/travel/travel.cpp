#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

#define F(i,x,y) for(int i=x;i<=y;++i)

using namespace std;

const int M=5010;


int read(){
	char ch=getchar();
	int x=0;
	while(!(ch>='0'&&ch<='9')) ch=getchar();
	while((ch>='0'&&ch<='9')) x=x*10+ch-'0',ch=getchar();
	
	return x;
}
int a[M][M],n,m,b[M];
bool col[M];


bool vis[M],fir;

void Link(int x,int y){
	a[x][++b[x]]=y;
}
void dfs(int u){
	vis[u]=true;
	int Mm;
	while(1){
		Mm=9999999;
		F(i,1,b[u]){
			if(vis[a[u][i]]) continue;
			Mm=min(Mm,a[u][i]);
		}
		if(Mm!=9999999){
			printf(" %d",Mm);
			dfs(Mm);

		}
		else break;
	}	
}
int used=0,Ro;
int min(int x,int y){
	return x<y?x:y;
}
bool pd(int u){
	F(i,1,b[u]){
		if(vis[a[u][i]]||col[a[u][i]]) continue;
		return false;
	}
	return true;
}
void dfs2(int u,int x){
	vis[u]=true;
	if((col[u]&&fir==false)){
		fir=true;
		used=1;
	}
	int Mm,M22;
	while(1){
		Mm=9999999,M22=9999999;
		F(i,1,b[u]){
			if(vis[a[u][i]]) continue;
			if(Mm>a[u][i]) M22=Mm,Mm=a[u][i];
			else if(M22>a[u][i]) M22=a[u][i];
		}
		if(Mm!=9999999){
			
			if(Mm>x&&used&&col[Mm]&&pd(u)){
				
				used=0;
				return;
			}
			printf(" %d",Mm);
			if(!col[Mm]) dfs2(Mm,9999999);
			else {
				if(M22==9999999) dfs2(Mm,(x));
				else dfs2(Mm,M22);
			}
			
		}
		else break;
	}	
}
int dep[M],up[M];
void pre(int u,int x){
	dep[u]=dep[x]+1;
	up[u]=x;
	
	F(i,1,b[u]){
		if(a[u][i]==x) continue;
		pre(a[u][i],u);
	}
	
}

int fa[M];
int G(int x){
	return x==fa[x]?x:fa[x]=G(fa[x]);
}


void LCA(int x,int y){
	
	if(dep[x]>dep[y]) swap(x,y);
	while(dep[x]<dep[y]) col[y]=true,y=up[y];
	while(x!=y){
		col[x]=true,x=up[x];
		col[y]=true,y=up[y];
	}
	col[x]=true;
}
void work1(){
	int hx,hy;
	fir=false;
	
	F(i,1,n) fa[i]=i;
	
	F(i,1,m){
		int x=read(),y=read();
		
		if(G(x)==G(y)) hx=x,hy=y;
		else{
			fa[G(x)]=G(y);
			
			Link(x,y),Link(y,x);
		}
		
	}
	pre(1,0);
	int tx=hx,ty=hy;
	LCA(hx,hy);
	Link(tx,ty),Link(ty,tx);
	printf("1");
	dfs2(1,9999999);
}
void work2(){
	F(i,1,m){
		int x=read(),y=read();
		
		b[x]++,b[y]++;
		a[x][b[x]]=y,a[y][b[y]]=x;
	}
	memset(vis,false,sizeof(vis));
	printf("1");
	dfs(1);
}
int main(){
	memset(col,false,sizeof(col));
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	
	
	if(m==n) work1();
	else work2();
	
	return 0;
}
