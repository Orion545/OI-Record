#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define fo(i,x,y) for(int i=x;i<=y;i++)
#define fd(i,x,y) for(int i=x;i>=y;i--)
using namespace std;

const int maxn=100007,maxm=maxn*2;

int n,m,fi[maxn],ne[maxm],la[maxm],tot,a[maxn];
void add(int a,int b){
	tot++;
	ne[tot]=fi[a];
	la[tot]=b;
	fi[a]=tot;
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char ch[10];
	scanf("%d%d%s",&n,&m,&ch);
	fo(i,1,n) scanf("%d",&a[i]);
	fo(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	fo(i,1,m){
		int x,xx,y,yy;
		scanf("%d%d%d%d",&x,&xx,&y,&yy);
		int ans=0x7fffffff;
		fo(j,0,(1<<n)-1)
			if ((j>>x-1&1)==xx && (j>>y-1&1)==yy){
				bool ok=true;
				int cos=0;
				fo(v,1,n)
					if (j>>v-1&1) cos+=a[v];
					else{
						bool az=false;
						for(int k=fi[v];k;k=ne[k]) az|=(j>>la[k]-1&1);
						if (!az) ok=false;
					}
				if (ok) ans=min(ans,cos);
			}
		if (ans==0x7fffffff) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
