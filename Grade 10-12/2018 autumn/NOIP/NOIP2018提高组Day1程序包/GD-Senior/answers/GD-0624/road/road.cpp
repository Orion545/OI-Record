#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
#define rep(a,b,c) for (int a=b;a<=c;a++)
#define per(a,b,c) for (int a=b;a>=c;a--)
const int N=100010;
int n,a[N],p[N],zuo[N],you[N],hav[N],ans,tot;
int cmp(int x,int y){
	return a[x]>a[y];	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i);
	rep(i,1,n) p[i]=zuo[i]=you[i]=i;
	sort(p+1,p+1+n,cmp);
	int l=1,r=0;
	per(dep,10000,1){
		while (a[p[r+1]]==dep) ++r;
		rep(i,l,r){
			int x=p[i];
			hav[x]=1;
			++tot;
			if (hav[x-1]){
				int l1=zuo[x-1],r1=you[x-1],
					l2=zuo[x],r2=you[x];
				zuo[r2]=l1;
				you[l1]=r2;
				--tot;
			}
			if (hav[x+1]){
				int l1=zuo[x],r1=you[x],
					l2=zuo[x+1],r2=you[x+1];
				zuo[r2]=l1;
				you[l1]=r2;
				--tot;
			}
		}
		ans+=tot;
		l=r+1;
	}
	printf("%d\n",ans);
	return 0;
}

