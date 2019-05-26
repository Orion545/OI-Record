#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int INF=2005;
const int maxlong=10000000;
using namespace std;
int m,n,x,y,x_,y_,p;
int a[INF][INF],map[INF][INF],val[100005],f[100005][3];
char c;
inline void add(int x,int y){
	a[x][++a[x][0]]=y;
	a[y][++a[y][0]]=x;
	map[x][y]=1;
	map[y][x]=1;
}
int abs(int x,int y){
	if (x-y>=0) return x-y; else return y-x;
}
int min(int x,int y){
	if (x<y) return x; else return y;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m); cin>>c; scanf("%d",&p);
	for (int i=1;i<=n;++i) scanf("%d",&val[i]);
	if (c=='A'){
		for (int i=1;i<n;++i) scanf("%d%d",&x,&y);
		for (int u=1;u<=m;++u){
			scanf("%d%d%d%d",&x,&x_,&y,&y_);
			if (x>y){
				int t=x; x=y; y=t;
				t=x_; x_=y_; y_=t;
			}
			if (abs(x-y)==1&&x_==0&&y_==0){
				printf("-1\n");
				continue;
			}
			memset(f,127,sizeof(f));
			if (y==n){
				if (y_==1) f[n][1]=val[n];
				else f[n][0]=0;
			}
			else{
				f[n][0]=0;
				f[n][1]=val[n];
			}
			for (int i=n-1;i>=1;--i){
				if (x==i&&y==i+1){
					if (x_==1) f[i][x_]=f[i+1][y_]+val[i];
					else f[i][x_]=f[i+1][y_];
				}
				else if (x==i&&y!=i+1){
					if (x_==1) f[i][x_]=min(f[i+1][0],f[i+1][1])+val[i];
					else f[i][x_]=f[i+1][1];
				}
				else if (x!=i&&y==i+1){
					if (y_==1){
						f[i][0]=f[i+1][y_];
						f[i][1]=f[i+1][y_]+val[i];
					}
					else f[i][1]=f[i+1][y_]+val[i];
				}
				else{
					f[i][0]=f[i+1][1];
					f[i][1]=min(f[i+1][0],f[i+1][1])+val[i];
				}
			}
			//printf("%d %d\n",f[4][0],f[4][1]);
			printf("%d\n",min(f[1][1],f[1][0]));
		}
	}
	return 0;
}
