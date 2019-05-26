#include<bits/stdc++.h>
using namespace std;
int n,m,i,u,o,cnt,h[5010],c[5010],k[5010][5010],j[5010],l[5010],vv[5010],v[5010];
queue<int> q;
struct e{
	int to,nxt;
}e[5010];
void add(int x,int y){
	e[++cnt].to=y;
	e[cnt].nxt=h[x];
	h[x]=cnt;
}
void work(int x){
	cout<<x<<" ";
	for(j[x]=1;j[x]<=l[x];j[x]++){
		if(k[x][j[x]]){
		work(k[x][j[x]]);			
		}
	}
}
void cl(int y,int z){
	for(i=1;i<=l[z];i++){
		if(k[z][i]==y){
			k[z][i]=0;
			return ;
		}
	}
}
void fs(int x){
	vv[x]=1;c[x]=c[v[x]]+1;
	for(i=h[x];i;i=e[i].nxt){
		if((c[e[i].to]==0||c[e[i].to]>c[x])){
			if(v[e[i].to]==0){
				k[x][++l[x]]=e[i].to;
				v[e[i].to]=x;	
			}else if(e[i].to<x){
				if(x<v[e[i].to]){
					k[x][++l[x]]=e[i].to;
					cl(e[i].to,v[e[i].to]);
					v[e[i].to]=x;
				}
			}else{
				if(x>v[e[i].to]){
					k[x][++l[x]]=e[i].to;
					cl(e[i].to,v[e[i].to]);
					v[e[i].to]=x;
				}
			}
		}
	}
	sort(k[x]+1,k[x]+1+l[x]);
	for(j[x]=1;j[x]<=l[x];j[x]++){
		if(vv[k[x][j[x]]]==0&&k[x][j[x]]){
			fs(k[x][j[x]]);		
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>u>>o;
		add(u,o);
		add(o,u);
	}
	q.push(1);
	fs(1);
	work(1);
	return 0;
}
