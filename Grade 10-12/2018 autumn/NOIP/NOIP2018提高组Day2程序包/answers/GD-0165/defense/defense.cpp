#include<cstdio>
#include<cstring>
#define fo(i,x,y) for(int i=x;i<=y;i++)
#define min(a,b) ((a)<(b)) ? (a):(b)
#define ll long long
using namespace std;
const int N=1e5+5;
const ll Inf=1e13+7;
int d[N<<2][4],c[N],n,m,x,y,p[N],mm,x1,x2,b1,b2;
ll f[N][4];
char s[5];
void ins(int x,int y){
	d[++mm][1]=x; d[mm][2]=y; d[mm][3]=c[x]; c[x]=mm;
}
void dg(int x,int z){
	bool bz=1; ll y=0,l=0;
	for(int k=c[x];k;k=d[k][3]) {
		if (d[k][2]==z) continue; 
		bz=0; dg(d[k][2],x);
		if (d[k][2]==x1) { 
			if (b1==0) y=Inf; else y+=f[d[k][2]][1]; 
			l+=f[d[k][2]][b1];
		} else
		if (d[k][2]==x2) {
			if (b2==0) y=Inf; else y+=f[d[k][2]][1]; 
			l+=f[d[k][2]][b2];
		} else 
		l+=min(f[d[k][2]][0],f[d[k][2]][1]),y+=f[d[k][2]][1];
	}
	if (bz) {
		if (x1==x && b1) f[x][1]=p[x]; else
		if (x2==x && b2) f[x][1]=p[x]; else f[x][1]=p[x],f[x][0]=0;
	} else
	{
		if (y<Inf) f[x][0]=y; f[x][1]=l+p[x];
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d",&n,&m); scanf("%s",s+1);
	fo(i,1,n) scanf("%d",&p[i]);
	fo(i,1,n-1) {
		scanf("%d %d",&x,&y); ins(x,y); ins(y,x);
	}
	bool bz;
	while (m) {
		scanf("%d %d %d %d",&x1,&b1,&x2,&b2);
		memset(f,50,sizeof(f)); m--;
		dg(1,0); bz=1;
		if (f[1][0]>=Inf && f[1][1]>=Inf) bz=0; 
		else  {
			if (x1==1) { if (f[1][b1]>=Inf) bz=0; else printf("%lld\n",f[1][b1]); } else
			if (x2==1) { if (f[1][b2]>=Inf) bz=0; else printf("%lld\n",f[1][b2]); } else
			printf("%lld\n",min(f[1][0],f[1][1]));
		}
		if (!bz) printf("-1\n");
	}
}
