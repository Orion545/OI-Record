#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 5001
//noip sro CCF orz
//CCF wan sui , qiu gei gao fen
//CCF wan sui , qiu gei sheng yi
using namespace std;
void read(int &x){
	char c;int f=1;x=0;c=getchar();
	while(c>57||c<48){if(c==45)f=-1;c=getchar();}
	while(c>=48&&c<=57){x=x*10+c-48;c=getchar();}
	x*=f;
}

int n,m;
int dis[N][N],tot[N];
void dfs1(int u,int fa){
	printf("%d ",u);
	sort(dis[u]+1,dis[u]+tot[u]+1);
	for(int i=1;i<=tot[u];i++){
		int v=dis[u][i];
		if(v!=fa)dfs1(v,u);
	}
}
void solve1(){
	for(int i=1;i<n;i++){
		int u,v;
		read(u);read(v);
		dis[u][++tot[u]]=v;
		dis[v][++tot[v]]=u;
	}
	dfs1(1,0);
}

int sum=0;
int dfn[N],low[N];
bool b[N][N]={0};
void Tarjan(int u,int fa){
	dfn[u]=low[u]=++sum;
	for(int i=1;i<=tot[u];i++){
		int v=dis[u][i];
		if(v!=fa){
			if(!dfn[v]){
				Tarjan(v,u);
				low[u]=min(low[u],low[v]);
			}else low[u]=min(low[u],dfn[v]);
			if(dfn[u]<low[v]){
				b[u][v]=b[v][u]=1;
			}
		}
	}
}

int cnt=0;
int Ans[N]={0};
void dfs2(int u,int fa,int sp,int tp){
	Ans[++cnt]=u;
	for(int i=1;i<=tot[u];i++){
		int v=dis[u][i];
		if((sp==u&&tp==v)||(sp==v&&tp==u))continue;
		if(v!=fa)dfs2(v,u,sp,tp);
	}	
}
int S[N],T[N];
int ansf[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	read(n);read(m);
	//60pts
	if(m==n-1){solve1();return 0;}
	
	//100pts
	if(m==n){
		memset(ansf,0x3f,sizeof(ansf));
		for(int i=1;i<=m;i++){
			int u,v;
			read(u);read(v);
			S[i]=u;T[i]=v;
			dis[u][++tot[u]]=v;
			dis[v][++tot[v]]=u;
		}
		for(int i=1;i<=n;i++)
			sort(dis[i]+1,dis[i]+tot[i]+1);
		Tarjan(1,0);//find not gebian 
		for(int i=1;i<=m;i++){
			if(b[S[i]][T[i]])continue;
			else{
				cnt=0;
				//cout<<S[i]<<" "<<T[i]<<endl;
				dfs2(1,0,S[i],T[i]);
			}
			
			bool flag=0;
			/*for(int j=1;j<=n;j++)
				cout<<Ans[j]<<" ";
			cout<<endl;*/
			
			for(int j=1;j<=n;j++){
				if(Ans[j]<ansf[j]){
					flag=1;break;
				}else if(Ans[j]>ansf[j])break;
			}
			if(flag){
				for(int j=1;j<=n;j++)
					ansf[j]=Ans[j];
			}	
		}
		for(int i=1;i<=n;i++)printf("%d ",ansf[i]);
		//cout<<b[4][6]<<endl;
	}
	
	return 0;
	
	fclose(stdin);
	fclose(stdout);
}
/*
m=n-1
6 5
1 3
2 3
2 5
3 4
4 6


m=n
6 6
1 3
2 3
2 5
3 4
4 5
4 6
*/
