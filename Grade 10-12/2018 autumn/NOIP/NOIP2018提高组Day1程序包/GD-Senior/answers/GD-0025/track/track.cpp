#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<fstream>
#define maxn 500005
#define cin fin
#define cout fout
using namespace std;
ifstream fin ("track.in");
ofstream fout("track.out");
int n,m;
struct edge{
	int from,to,next,weight;
};struct edge e[maxn];int cnt_e=0;
int head[maxn];
void adde(int start,int end,int weight){
	cnt_e++;
	e[cnt_e].from=start,e[cnt_e].to=end,e[cnt_e].weight=weight,e[cnt_e].next=head[start];
	head[start]=cnt_e;
}
int fa[maxn],top[maxn],deep[maxn],siz[maxn];
void dfs1(int x,int fath,int dep){
	fa[x]=fath,deep[x]=dep,siz[x]=0;
	int maxson=-1;
	for(int i=head[x];i;i=e[i].next){
		int to=e[i].to,weight=e[i].weight;
		if(to==fath) continue;
		dfs1(to,x,dep+1);
		if(siz[to]+weight>maxson){
			maxson=siz[to]+weight;
			siz[x]=siz[to]+weight;
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n-1;i++){
			int start,end,weight;
			cin>>start>>end>>weight;
			adde(start,end,weight);
			adde(end,start,weight);
		}
		dfs1(1,0,1);
		int max1=0,max2=0;
		bool flag=false;
		for(int i=head[1];i;i=e[i].next){
			int to=e[i].to,weight=e[i].weight,si=siz[to];
			if(si+weight==siz[1]&&flag==false){
				flag=true;
				continue;
			}
			max1=max(max1,si+weight);
		}
		cout<<max1+siz[1]<<endl;
	}
	return 0;
}
