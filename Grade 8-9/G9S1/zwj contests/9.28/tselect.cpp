#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	int num,fa;
	vector<int>son;
}a[510];
int n,x,f[510][510][2]; 
void dfs(int u){
	f[u][0][0]=0;f[u][0][1]=a[u].num;
	int i,j,k,v;
	for(i=1;i<=n;i++) f[u][i][0]=f[u][i][1]=-1000000000;
	for(i=0;i<a[u].son.size();i++){
		v=a[u].son[i];
		dfs(v);
		for(j=n;j>=0;j--){
			for(k=0;k<=j;k++){
				if(k>=1) f[u][j][1]=max(f[u][j][1],f[u][j-k][1]+f[v][k-1][1]);
				f[u][j][1]=max(f[u][j][1],f[u][j-k][1]+f[v][k][0]);
				f[u][j][0]=max(f[u][j][0],f[u][j-k][0]+max(f[v][k][0],f[v][k][1]));
			}
		}
	}
}
int main(){
	freopen("tselect.in","r",stdin);
	freopen("tselect.out","w",stdout);
	int i,j,t1,t2,ans=-1;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++){
		scanf("%d%d",&t1,&t2);
		a[i].num=t1;a[i].fa=t2;
		a[t2].son.push_back(i);
	}
	dfs(0);
	for(i=0;i<=n;i++){
		if(f[0][i][0]>=x) ans=i;
	}
	printf("%d",ans);
} 
