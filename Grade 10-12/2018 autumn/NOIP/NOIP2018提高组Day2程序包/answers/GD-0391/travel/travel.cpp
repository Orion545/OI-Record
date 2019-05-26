#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> g[5001];
vector<int> hu;
int n,m,sta[5001],sh=0,fa[5001];
bool visit[5001],huan[5001],op;
int zdx[5001],zda[5001],xu,xv,zdh;bool anop;
void dfs(int u){if(!visit[u])cout<<u<<" ";
	visit[u]=true;
	int d[g[u].size()],head=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!visit[v]){
			head++;
			d[head]=v;
		}
	}
	sort(d+1,d+1+head);
	for(int i=1;i<=head;i++){
		dfs(d[i]);
	}
}

void dfs2(int u){//cout<<u<<endl;
	if(op)return;
	visit[u]=true;sta[++sh]=u;
	for(int i=0;i<g[u].size();i++){
		if(op)return;
		int v=g[u][i];
		if(!visit[v]){
			fa[v]=u;
			dfs2(v);
		}
		else if(v!=fa[u]){
			int m;//cout<<u<<" "<<v<<endl;
			do{
				m=sta[sh];
				//cout<<m<<" "<<v<<endl;
				hu.push_back(m);
				//huan[m]=true;
				sh--;
			}while(m!=v);
			op=1;
		}
	}
	sh--;
}
void dfs3(int u){if(!visit[u])zdx[++zdh]=u;
	visit[u]=true;
	int d[g[u].size()],head=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(u==xu&&v==xv||u==xv&&v==xu)continue;
		if(!visit[v]){
			head++;
			d[head]=v;
		}
	}
	sort(d+1,d+1+head);
	for(int i=1;i<=head;i++){
		dfs3(d[i]);
	}
}
/*int huan1,huan2;
int huanop;int cle=0;
void dfs3(int u){if(!visit[u])cout<<u<<" ";
	if(huanop==0&&huan[u])huanop++;
	if(u==huan1)huan1=0;
	if(u==huan2)huan2=0;
	visit[u]=true;
	int d[g[u].size()+2],head=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!visit[v]){
			head++;
			d[head]=v;
			if(!huan[v]){
				cle++;
			}
			if(huanop==1){
				if(huan[v]){
					if(huan1==0)huan1=v;
					else huan2=v;
				}
			}
		}
	}
//	if(u==3)cout<<huanop<<" "<<huan[u]<<" "<<huan2<<endl;
//	if(huanop==2&&huan[u]){
//		if(huan1)head++,d[head]=huan1;
//		if(huan2)head++,d[head]=huan2;
//	}
	if(huanop==1)huanop++;
if(u==64){cout<<u<<":";for(int i=1;i<=head;i++)cout<<d[i]<<" ";cout<<endl;}
	sort(d+1,d+1+head);
//	if(u==41)cout<<cle;
	for(int i=1;i<=head;i++){
		if(huanop==2&&huan[u]){
			if(cle==0){
				if(huan1&&huan1<d[i]){
					dfs3(huan1);
					dfs3(d[i]);
				}
				else if(huan2&&huan2<d[i]){
					dfs3(huan2);
					dfs3(d[i]);
				}
				else dfs3(d[i]);
			}
			else{
				if(!huan[d[i]])cle--;
				dfs3(d[i]);
			}
		}
		else{
				if(!huan[d[i]])cle--;
				dfs3(d[i]);
		}
	}
}*/

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(m==n-1){
		dfs(1);
	}
	else{
		fa[1]=0;op=0;
		dfs2(1);
		memset(visit,0,sizeof(visit));zdh=0;anop=0;
		xu=hu[hu.size()-1],xv=hu[0];
		dfs3(1);
		for(int i=1;i<=n;i++){
			zda[i]=zdx[i];
		}
		for(int i=0;i<hu.size()-1;i++){
			//cout<<i<<endl;
			memset(visit,0,sizeof(visit));zdh=0;anop=0;
			xu=hu[i],xv=hu[i+1];
			dfs3(1);
			for(int i=1;i<=n;i++){
				if(zdx[i]<zda[i]){
					anop=1;break;
				}
				if(zdx[i]>zda[i]){
					break;
				}
			}
			if(anop){
				for(int i=1;i<=n;i++){
					zda[i]=zdx[i];
				}
			}
		}
		for(int i=1;i<=n;i++)cout<<zda[i]<<" ";
	//	huanop=0;
		//dfs3(1);
	}
	
	
	return 0;
}
/*
7 7
1 4
4 3
4 5
4 2
5 6
3 6
5 7
*/
