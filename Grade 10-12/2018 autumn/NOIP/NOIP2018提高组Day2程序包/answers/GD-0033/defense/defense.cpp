#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,c,a,b,d,w[2010],map[2010][2010],f[2010];
bool p[2010];

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %c%d",&n,&m,&c,&a);
	for (int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for (int i=1;i<=n-1;i++){
		scanf("%d %d",&b,&d);
		map[b][d]=map[d][b]=1;
	}
	int g,x,h,y;
	for (int i=1;i<=m;i++){
		scanf("%d %d %d %d",&g,&x,&h,&y);
		memset(f,0x7f,sizeof(f));
		memset(p,0,sizeof(p));
		if (x==0&&y==0){
			if (map[x][y]==1)
				printf("-1");
			else {
				p[g]=true;
				p[h]=true;
			}
		}
		else if(x==0&&y==1){
			p[g]=true;
		}
		else if (x==1&&y==0){
			p[h]=true;
		}
		if (!p[1]) f[1]=w[1];
		f[0]=0;
		for (int i=2;i<=n;i++){
			if (!p[i]){
				f[i]=min(f[i-1],f[i-2]+w[i]);
			}
			else{
				f[i]=f[i-1];
			}
		}
		printf("%d",f[n]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
