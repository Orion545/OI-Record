#include<bits/stdc++.h>
using namespace std;
int n,m;
int lian[5001][5001];
bool f[5001];
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')w=-1;
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c&15);
		c=getchar();
	}
	return x*w;
}
void dfs(int x){
	printf("%d ",x);
	for(int i=1;i<=lian[x][0];i++){
		if(!f[lian[x][i]]){
			f[lian[x][i]]=1;
			dfs(lian[x][i]);
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		lian[u][++lian[u][0]]=v;
		lian[v][++lian[v][0]]=u;
    }
    for(int i=1;i<=n;i++){
	    sort(lian[i]+1,lian[i]+1+lian[i][0]);
    }
    f[1]=1;
    dfs(1);
	return 0;
}
