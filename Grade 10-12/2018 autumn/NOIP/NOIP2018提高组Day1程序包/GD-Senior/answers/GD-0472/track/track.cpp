#include<cstdio>
using namespace std;
int a[1000][1000],dis[1000][1000],b[1000];
int n,m,ans;

int solve(int src){
	int st[1000],tr[1000],td; tr[0]=src;
	int L=0; bool bb=true,bd;
	while(bb){
		L++; st[L]=0; bd=true;
		while(bd){
			st[L]++;
			if(st[L]<=b[tr[L-1]]){
				tr[L]=a[tr[L-1]][st[L]];
				if(tr[L]==tr[L-1]) break;
				if(b[tr[L]]==1){
					td=0;
					for(int i=1;i<=L;i++)	td=td+a[tr[i-1]][b[st[i]]];
					if(td>ans) ans=td;
				}
			} else {
				L--; if(L<1){bb=false;bd=false;break;} 
			}
		}
	}
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y,z; ans=-1;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		b[x]++; b[y]++;
		a[x][b[x]]=y; a[y][b[y]]=x;
		dis[x][b[x]]=z; dis[y][b[y]]=z;
	}
	//for(int i=1;i<=n;i++){for(int j=1;j<=n;j++) printf("%3d ",dis[i][j]);printf("\n");}
	for(int i=1;i<=n;i++){
		if(b[i]==1) solve(i);
	}
	printf("%d",ans);
	fclose(stdout);
	return 0;
}
