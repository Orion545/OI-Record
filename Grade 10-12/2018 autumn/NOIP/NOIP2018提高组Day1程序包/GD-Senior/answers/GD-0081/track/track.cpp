#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;++i)
typedef long long ll;
char cch;
inline int rd(){
	int x=0,fl=1;
	cch=getchar();
	while(cch>'9'||cch<'0'){
		if(cch=='-') fl=-1;cch=getchar();
	}
	while(cch>='0'&&cch<='9') x=(x<<1)+(x<<3)+cch-'0',cch=getchar();
	return fl*x;
}
const int N=5e4+3;
struct abc{
	int to,nxt,w;
}e[N<<1];
int head[N],vec[N],pos,cnt;
bool fl[N];
inline void adde(int u,int v,int w){
	e[++cnt].to=v,e[cnt].w=w,e[cnt].nxt=head[u],head[u]=cnt;
	e[++cnt].to=u,e[cnt].w=w,e[cnt].nxt=head[v],head[v]=cnt;
}
#define pr pair<int,int>
#define fir first
#define sec second
#define mpr make_pair
pr dfs(int u,int fa,int val){
	int t3,t2,sum=0,t=pos;
	pr tmp;
	for(int i=head[u];i;i=e[i].nxt) if(e[i].to!=fa){
		tmp=dfs(e[i].to,u,val);
		sum+=tmp.sec,vec[++pos]=tmp.fir+e[i].w,fl[pos]=0;
	}
	sort(vec+t+1,vec+pos+1);
	rep(i,t+1,pos) if(!fl[i]){
		if(vec[i]>=val){
			++sum;continue;
		}
		t2=val-vec[i];
		t3=lower_bound(vec+1+t,vec+pos+1,t2)-vec;
		while((fl[t3]||t3==i)&&t3<pos) ++t3;
		if(t3<=pos&&t3!=i&&!fl[t3]&&(vec[i]+vec[t3])>=val) ++sum,fl[i]=fl[t3]=1;
	}
	for(int i=pos;i>t;--i) if(!fl[i]){
		pos=t;return mpr(vec[i],sum);
	}
	pos=t;
	return mpr(0,sum);
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n=rd(),m=rd(),u,v,w;
	pr tmp;
	rep(i,2,n) u=rd(),v=rd(),w=rd(),adde(u,v,w);
	int l=0,r=500000000,mid=15,ans;
	while(l<=r){
		mid=l+r>>1;
		tmp=dfs(1,0,mid);
		if(tmp.sec>=m) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d",ans);
}
/*
9 3 
1 2 6
2 3 3
3 4 5
4 5 10
6 2 4
7 2 9
8 4 7
9 4 4
*/

/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7
*/
