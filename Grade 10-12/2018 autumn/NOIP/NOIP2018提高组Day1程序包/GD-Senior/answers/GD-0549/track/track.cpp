#include<cstdio>
#define N 50005
int head[N],tu[2*N][3],w=1;
void star(int a,int b,int v){
	 tu[w][0]=a;tu[w][1]=v;tu[w][2]=head[b];head[b]=w;w++;
	 tu[w][0]=b;tu[w][1]=v;tu[w][2]=head[a];head[a]=w;w++;
}
int ma,map;
void dfs1(int a,int fa,int l){
	 if(ma<l) ma=l,map=a;
	 for(int i=head[a];i;i=tu[i][2]){
	 	int to=tu[i][0];if(to==fa) continue;
	 	dfs1(to,a,l+tu[i][1]);
	 }
}
int main(){
	freopen("track.in","r",stdin); 
	freopen("track.out","w",stdout);
	int n,m,minb=0x7f;
	scanf("%d %d",&n,&m);
	int x,y,z;
	for(int n1=1;n1<n;n1++){
		scanf("%d %d %d",&x,&y,&z);
		star(x,y,z);
		if(z<minb) minb=z;
	}
	if(m==n-1) {printf("%d\n",minb);return 0;}
	if(m==1){
		dfs1(1,0,0);
		ma=0;
		dfs1(map,0,0);
		printf("%d\n",ma);
		return 0;
	}
}

