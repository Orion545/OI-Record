#include <cstdio>
#include <iostream>
using namespace std;
int n,m;
int i,j,a,b;
int head[5001],cnt,vis[5001],v[5001];
int G[5001][5001];
int con[5001];
void mergesort(int z,int l,int r) {
	if(l==r) return;
	int mid=(l+r)/2;
	mergesort(a,l,mid);
	mergesort(z,mid+1,r);
	int w[5001],e=l,x=l,y=mid+1;
	while(x<=mid && y<=r)
	if(G[z][x]<G[z][y]) w[e++]=G[z][x++];
	else w[e++]=G[z][y++];
	while(x<=mid) w[e++]=G[z][x++];
	while(y<=r) w[e++]=G[z][y++];
	for(int u=l;u<=r;u++)
	G[z][u]=w[u];
}
void dfs(int pos,int last,int loc) {
	if(con[pos]==0 && !vis[pos]) {
		cout<<pos<<' ';
		vis[pos]=1;
		con[G[pos][1]]--;
		v[G[last][loc+1]]=0;
		if(!vis[G[pos][1]]);
		dfs(G[pos][1],pos,1);
		return;
	}
	else {
		for(int k=1;k<=G[pos][0];k++) {
			if(!vis[G[pos][k]]) {
				int x=G[pos][k];
				for(int o=k+1;o<=G[pos][0];o++)
				if(!vis[G[pos][o]]) {
					v[G[pos][o]]=1;
					break;
				}
				for(int p=1;p<=G[x][0];p++) {
					if(!vis[G[x][p]] && v[G[x][p]] && G[x][p]<x) {
						v[G[x][p]]=0;
						if(!vis[pos]) {
							for(p=1;p<=G[pos][0];p++)
							con[G[pos][p]]--;
							cout<<pos<<' ';
							vis[pos]=1;
						}
						return ;
					}
				}
				if(!vis[pos]) {
					for(int p=1;p<=G[pos][0];p++)
					con[G[pos][p]]--;
					cout<<pos<<' ';
					vis[pos]=1;
				}
				dfs(x,pos,k);
			}
		}
		return;
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	cin>>m;
	for(i=0;i<m;i++) {
		cin>>a>>b;
		G[a][0]++;
		G[a][G[a][0]]=b;
		G[b][0]++;
		G[b][G[b][0]]=a;
		con[a]++;
		con[b]++;
	}
	for(i=1;i<=n;i++) {
		mergesort(i,1,G[i][0]);
	}
	for(i=1;i<=n;i++) {
		if(!vis[i])
			dfs(i,i,0);
	}
	return 0;
}
/*
5 4
1 2
2 3
3 4
4 5

5 4
1 2
3 4
4 5
5 1

5 5
1 2
2 3
3 4
4 5
5 1

3 2
1 2
3 2

3 3
1 2
2 3
3 1

4 3
1 2
1 4
3 4

6 6
1 2
2 3
1 3
2 4
4 5
4 6

6 6
1 2
2 3
3 4
1 4
3 6
2 5

*/
