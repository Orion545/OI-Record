#include<stdio.h>
#include<algorithm>

using namespace std;

int n,m;
int edge[5010][2]={0};
int edgenum[5010]={0};
int index[5010]={0};
int liantong[10010]={0};
int visited[5010]={0};

void dfs(int father,int son){
	printf("%d ",son);
	visited[son]=1;
	int i,j,k;
	for(i=index[son]-edgenum[son];i<index[son];i++){
		if(liantong[i]==father) continue;
		if(visited[liantong[i]]==1) continue;
		dfs(son,liantong[i]);
	}	
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	int i,j,k;
	int x,y;
	for(i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		edge[i][0]=x;
		edge[i][1]=y;
		edgenum[x]++;
		edgenum[y]++;
	}
	index[1]=1;
	for(i=2;i<=n;i++){
		index[i]=index[i-1]+edgenum[i-1];
	}
	/*for(i=1;i<=n;i++){//######################
		printf("%d ",index[i]);		
	}
	printf("\n");//##########################*/
	for(i=1;i<=m;i++){
		x=edge[i][0];
		y=edge[i][1];
		liantong[index[x]]=y;
		liantong[index[y]]=x;
		index[x]++;
		index[y]++;
	}
	
	for(i=1;i<=n;i++){
		sort(liantong+index[i]-edgenum[i],liantong+index[i]);
	}
	/*for(i=1;i<=2*m;i++){//######################
		printf("%d ",liantong[i]);		
	}
	printf("\n");//##########################*/
	dfs(0,1);	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
