#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 1073741823
#define min(a,b) (a<b?a:b)
using namespace std;
const int N=5E4+5;
struct Edge{
	int from,to,nxt,val;
}p[N*2];
int lst[N],a[N],len=0,x,y,z;
int dis[N],Tag=1,Max,rt,n,m;
void Add(int x,int y,int z){
	p[++len].to=y;
	p[len].from=x;
	p[len].nxt=lst[x];
	p[len].val=z;
	lst[x]=len;
}
void Get(int x,int pre){
	if (dis[x]>Max){
		Max=dis[x];
		rt=x;
	}for(int j=lst[x];j;j=p[j].nxt){
		int that=p[j].to;
		if (that!=pre){
			dis[that]=dis[x]+p[j].val;
			Get(that,x);
		}
	}
}
bool pd(int x){
	int cnt=0,tmp=0;
	for(int i=1;i<=n-1;i++){
		cnt+=a[i];
		if (cnt>=x){
			cnt=0;
			tmp++;
		}
	}return tmp>=m;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++){
		scanf("%d%d%d",&x,&y,&a[i]);
		Add(x,y,a[i]);Add(y,x,a[i]);
		if (y!=x+1) Tag=0;
	}if (m==1){
		Max=-INF;dis[1]=0;Get(1,0);
		Max=-INF;dis[rt]=0;Get(rt,0);
		printf("%d\n",Max);
		return 0;
	}if (Tag){
		int l=0,r=INF,ret=0;
		while (l<=r){
			int mid=(l+r)/2;
			if (pd(mid)){
				l=mid+1;
				ret=mid;
			}else
				r=mid-1;
		}printf("%d\n",ret);
		return 0;
	}
	return 0;
}
