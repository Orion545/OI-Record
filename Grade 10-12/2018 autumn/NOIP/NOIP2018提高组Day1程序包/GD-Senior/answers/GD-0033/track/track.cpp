#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,k,map[1010][1010],d[1010][1010],maxn;

void floyd(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			for (int k=1;k<n;k++)
				if (d[i][j]<d[i][k]+map[k][j])
					d[i][j]=d[i][k]+map[k][j];
		}
	}
}


int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	int a,b,c;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			map[i][j]=-999999;
			if (i==j) d[i][j]=0;
			else d[i][j]=-999999;
		}
	for (int i=1;i<=n-1;i++){
		scanf("%d %d %d",&a,&b,&c);
		map[a][b]=map[b][a]=c;
	}
	if (m==1) floyd();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			maxn=max(maxn,d[i][j]);
	printf("%d",maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
