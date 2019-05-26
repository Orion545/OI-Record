#include<cstdio>
#include<map>
#include<string>
#include<vector>
using namespace std;
int n,m,road[5005],dfsx[5005],arrive[5005],yj,num;
vector<int>lj[5005];
map<pair<int,int>,int>used;
void getroad(){
	int yes=0;
	for(int i=1;i<=n;i++){
		if(dfsx[i]<road[i]){
			yes=1;
			break;
		}
	}
	if(yes)
	for(int i=1;i<=n;i++)
		road[i]=dfsx[i];
}
int minn(int dc,int l){
	for(int i=1;i<l;i++)
		if(dfsx[i]<road[i])return 1;
	if(road[l]>=dc)return 1;
	return 0;
}
void dfs(int u){    //µ±Ç°µã
	if(yj==n){
		getroad();
		return;
	}
	for(int i=lj[u].size()-1;i>=0;i--){
		if(minn(lj[u][i],yj+1)&&!used[make_pair(u,lj[u][i])]){
			used[make_pair(u,lj[u][i])]=1;
			int yes=0;
			if(arrive[lj[u][i]]==0)arrive[lj[u][i]]=1,dfsx[++yj]=lj[u][i],yes=1;
		//	printf("%dto%d---%d\n",u,lj[u][i],yj);
			dfs(lj[u][i]);
			if(yes)yj--,arrive[lj[u][i]]=0;
			used[make_pair(u,lj[u][i])]=0;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		lj[u].push_back(v);
		lj[v].push_back(u);
	}
	/*for(int i=1;i<=n;i++){
		for(int j=0;j<lj[i].size();j++)
			printf("%dto%d ",i,lj[i][j]);
		printf("\n");
	}*/
	memset(road,88,sizeof(road));
	yj=1;
	dfsx[1]=1;
	arrive[1]=1;
	dfs(1);
	for(int i=1;i<=n;i++)
		printf("%d ",road[i]);
	return 0;
}
