#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int n,m;
int u[10010],v[10010],head[5003],next[10010],tr[5010],vis[5010];
int main(){
	int i,j,k,kk,lo,mi;
	memset(head,-1,sizeof head);
	memset(vis,0,sizeof vis);
	ifstream fin;
	fin.open("travel.in");
	fin>>n>>m;
	for(i=1;i<=m;i++){
		fin>>u[i]>>v[i];
		u[m+i]=v[i],v[m+i]=u[i];
		next[i]=head[u[i]];
		head[u[i]]=i;
		next[m+i]=head[v[i]];
		head[v[i]]=m+i;
	}
	fin.close();
	tr[1]=1;lo=1;vis[1]=1;
	while(lo<n){
	mi=5010;
		for(k=lo;k>=1;k--){
			kk=head[tr[k]];
			while(kk!=-1){
				if(!vis[v[kk]]) mi=min(mi,v[kk]);
				kk=next[kk];
			}
			if(mi!=5010) break;
		}
		tr[++lo]=mi;vis[mi]=1;
	}
	ofstream fout;
	fout.open("travel.out");
	for(i=1;i<=lo;i++) fout<<tr[i]<<" ";
	fout.close();
	return 0;
}
