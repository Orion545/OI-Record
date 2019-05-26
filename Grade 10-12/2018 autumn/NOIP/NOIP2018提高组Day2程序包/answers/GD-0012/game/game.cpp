#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int S=(1<<8)+5,Mo=1e9+7;

void inc(int &x,int y) {x=x+y>=Mo?x+y-Mo:x+y;}

int n,m,g[S][9][S],f[2][S][9],trs[S][9][S],len[S][9];

int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(s,0,(1<<n)-1)
		fo(lim,1,n)
			fo(t,0,(1<<n)-1) {
				bool ok=1;
				fo(i,0,n-2) if ((t&(1<<i))&&!(s&(1<<i+1))) {ok=0;break;}
				fo(j,lim,n-1) if (!(t&(1<<j-1))&&(s&(1<<j))) {ok=0;break;}
				if (ok) {
					int k=lim;
					fo(j,1,lim-1) if (((t&(1<<j-1))>0)==((s&(1<<j))>0)) {k=j+1;break;}
					len[s][lim]++;
					trs[s][lim][len[s][lim]]=t;
					g[s][lim][len[s][lim]]=k;	
				}
			}
	fo(s,0,(1<<n)-1) f[0][s][n]=1;
	int p=0,q=1;
	fo(i,1,m-1) {
		fo(s,0,(1<<n)-1) fo(lim,1,n) f[q][s][lim]=0;
		fo(s,0,(1<<n)-1)
			fo(lim,1,n)
				if (f[p][s][lim]) 
					fo(j,1,len[s][lim]) {
						int t=trs[s][lim][j],k=g[s][lim][j];
						inc(f[q][t][k],f[p][s][lim]);
					}
		swap(p,q);
	}
	int ans=0;					
	fo(s,0,(1<<n)-1) fo(i,1,n) inc(ans,f[p][s][i]);
	printf("%d\n",ans);
	return 0;
}
