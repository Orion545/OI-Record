#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fd(i,a,b) for(i=a;i>=b;i--)
#define fb(i,x) for(i=last[x];i;i=next[i])
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int maxN=5e3+10,maxM=1e4+10;
bool ma[maxN][maxN],bz[maxN],bz1;
int a[maxN],n,i,m,last[maxN],next[maxM],tov[maxM],tot,pre[maxN],x,y,tail,
las[maxN],nex[maxN],tovv[maxN],tott,j,ru,map[maxN][maxN],t,fa[maxN],
hu[maxN],mx;
void ins(int x,int y){tov[++tot]=y,next[tot]=last[x],last[x]=tot;
}
void ins1(int x,int y){tovv[++tott]=y,nex[tott]=las[x],las[x]=tott;
}
void dfs(int x,int fx){
	int i,y;
	pre[++pre[0]]=x;
	a[0]=0;
	fo(i,1,map[x][0]){
		y=map[x][i];
		if (y!=fx && (!ma[x][y])) a[++a[0]]=y;
	}
	if (!a[0]) return;
	sort(a+1,a+a[0]+1);
	fd(i,a[0],1) ins1(x,a[i]);
	for(i=las[x];i;i=nex[i]){
		y=tovv[i];
		dfs(y,x);
	}
}
void dfs1(int xx,int fx){
	int ii,yy;
	bz[xx]=true;
	fa[xx]=fx;
	if (bz1)return;
	fo(ii,1,map[xx][0]){
		yy=map[xx][ii];
		if (yy!=fx){
			if (!bz[yy]) dfs1(yy,xx);
			else {
				if (bz1) return;
				for(j=xx;j!=yy;j=fa[j])hu[++hu[0]]=j;				
				hu[++hu[0]]=yy;
				mx=hu[0]+1;
				fo(i,1,hu[0]-1) mx=(hu[i]>hu[mx])?i:mx;
				if (hu[1]<hu[hu[0]-1]){
					j=1;
					while (hu[j+1]<hu[hu[0]-1]) j++;
					ma[hu[j]][hu[j+1]]=ma[hu[j+1]][hu[j]]=true;
				}else{
					j=hu[0]-1;
					while (hu[j-1]<hu[1]) j--;
					ma[hu[j]][hu[j-1]]=ma[hu[j-1]][hu[j]]=true;
				}
				bz1=true;
			}
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m)
		scanf("%d%d",&x,&y),ins(x,y),ins(y,x),map[x][++map[x][0]]=y,map[y][++map[y][0]]=x;
	if (m==n-1){
		dfs(1,0);
	}
	if (m==n){
		dfs1(1,0);
		dfs(1,0);
	}
	fo(i,1,pre[0]-1) printf("%d ",pre[i]);
	printf("%d\n",pre[pre[0]]);
	return 0;
}

