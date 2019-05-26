#include<bits/stdc++.h>
#define MAXN 5001
using namespace std;

int n,m,tu,tv,visited=0;
int shuju=0;
int vis[MAXN],tmp[MAXN],fv[MAXN],inhuan[MAXN];
vector<int> bian[MAXN],pah;
int pc=0,pst=0,ped=0;

void search(int p,int fro,bool incir){
	pah.push_back(p);
	vis[p]=1;
	for (int i=0;i<bian[p].size();i++){
		int nxt=0;
		bool nex=incir;
		if (shuju){
			if (p==pc&&bian[p][i]==pst){
				nex=true;
			}
			if (incir&&inhuan[bian[p][i]]&&bian[p][i]>ped)return;
		}
		if (!vis[bian[p][i]]){
			search(bian[p][i],p,nex);
		}
	}
}

void findcir(int p,int fat){
	vis[p]=1;
	fv[p]=fat;
	for (int i=0;i<bian[p].size();i++){
		if (ped)return;
		if (fat!=bian[p][i]){
			if (vis[bian[p][i]]){
				ped=p;
				inhuan[ped]=1;
				pc=bian[p][i];
				pst=fat;
				while (fv[pst]!=pc){
					inhuan[pst]=1;
					pst=fv[pst];
				}
				inhuan[pst]=1;
			}else{
				findcir(bian[p][i],p);
			}
		}
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	memset(vis,0,sizeof(vis));
	memset(inhuan,0,sizeof(inhuan));
	ios::sync_with_stdio(false);
	cin>>n>>m;
	if (n==m) shuju=1;
	for (int i=1;i<=m;i++){
		cin>>tu>>tv;
		bian[tu].push_back(tv);
		bian[tv].push_back(tu);
	}
	for (int i=1;i<=n;i++){
		if (bian[i].size()>1){
			for (int j=0;j<bian[i].size();j++){
				tmp[j]=bian[i][j];
			}
			sort(tmp,tmp+bian[i].size());
			for (int j=0;j<bian[i].size();j++){
				bian[i][j]=tmp[j];
			}
		}
	}
	if (shuju) {
		findcir(1,0);memset(vis,0,sizeof(vis));
	}
	search(1,0,false);
	for (int i=0;i<n;i++) cout<<pah[i]<<" ";
	cout<<endl;
	return 0;
}
