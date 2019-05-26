#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int m,n,ans[100010],p[100010],ct,x[10010],y[10010],r[100010];
vector<int>v[100010];
void dfs1(int x,int fa){
	ans[++ct]=x;
	if(ct>n+5)return;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=fa)
			dfs1(v[x][i],x);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==n-1){
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(int i=1;i<=n;i++)
			sort(v[i].begin(),v[i].end());
		dfs1(1,0);
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++)
			r[i]=1e9;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&x[i],&y[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				v[j].clear();
			for(int j=1;j<=n;j++)
				if(j!=i){
					v[x[j]].push_back(y[j]);
					v[y[j]].push_back(x[j]);
				}
			for(int j=1;j<=n;j++)
				sort(v[j].begin(),v[j].end());
			ct=0;
			dfs1(1,0);
			if(ct<n||ct>n)continue;
			int ok=1;
			for(int j=1;j<=n;j++)
				if(r[j]<ans[j]){
					ok=0;
					break;
				}
				else if(r[j]>ans[j])break;
			if(ok){
				for(int j=1;j<=n;j++)
					r[j]=ans[j];
			}
		}
		for(int i=1;i<=n;i++)
			printf("%d ",r[i]);
		return 0;
	}
}
