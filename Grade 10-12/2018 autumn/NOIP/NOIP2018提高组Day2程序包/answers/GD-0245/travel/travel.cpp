#include<cstdio>
#include<cstring>

using namespace std;
int k,m,du[10000],data[100000],tot,u,v,n,i,j,bz[10000],dep[10000],map[5010][5010];

int check(int x,int k){
	int i,y;
	for (i=1;i<=map[x][0];i++){
		y=map[x][i];
		if (dep[y]>dep[x])
			continue;
		if (!bz[y])
			return check(y,k);
	}
	if (x>=k)
		return 0;
	return 1;	
}

void dfs(int x){
	bz[x]=1;
	printf("%d ",x);
	int i,y;
	for (i=1;i<=map[x][0];i++){
		y=map[x][i];
		if (bz[y])
			continue;
		if (du[y]==1)
			dfs(y);
		else{
			if (!check(y,y))
				dfs(y);
			else
				du[y]--;
		}
	}	
}

void qsort(int l,int r,int k){
	int i=l,j=r,mid=map[k][(l+r)/2],temp;
	while (i<=j){
		while (map[k][i]<mid)
			i++;
		while (map[k][j]>mid)
			j--;
		if (i<=j){
			temp=map[k][i];
			map[k][i]=map[k][j];
			map[k][j]=temp;
			i++;
			j--;
		}
	}
	if (l<j)
		qsort(l,j,k);
	if (r>i)
		qsort(i,r,k);
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		map[u][0]++;
		map[u][map[u][0]]=v;
		map[v][0]++;
		map[v][map[v][0]]=u;
	}
	for (i=1;i<=n;i++)
		qsort(1,map[i][0],i);
	i=0;
	j=1;
	data[1]=1;
	dep[1]=0;
	memset(bz,0,sizeof(bz));
	bz[1]=1;
	while (i<j){
		i++;
		u=data[i];
		for (k=1;k<=map[u][0];k++){
			v=map[u][k];
			if (!bz[v]){
				bz[v]=1;
				j++;
				data[j]=v;
				dep[v]=dep[u]+1;
			}
			if (dep[v]>dep[u])
				du[v]++;
		}
	}
	memset(bz,0,sizeof(bz));
	dfs(1);
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
