#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
#define maxn 50010
struct edge{
	int v,w,next;
}edges[maxn<<1];
int head[maxn],n,m;
long long sum;
void ins(int u,int v,int w){
	static int cnt=0;
	edges[++cnt]=(edge){v,w,head[u]};
	head[u]=cnt;
}
namespace part_m_1{
	long long dis[maxn];
	void farest(int x){
		for(int i=head[x];i;i=edges[i].next){
			int y=edges[i].v;
			if(dis[y]==0){
				dis[y]=dis[x]+edges[i].w;
				farest(y);
			}
		}
	}
	void mian(){
		dis[1]=0;
		memset(dis,0,sizeof dis);
		farest(1);
		int far=1;
		for(int i=2;i<=n;i++)
			if(dis[far]<dis[i])
				far=i;
		memset(dis,0,sizeof dis);
		farest(far);
		long long ans=0;
		for(int i=1;i<=n;i++)
			if(ans<dis[i])
				ans=dis[i];
		printf("%lld\n",ans);
		return ;
	}
};
bool line=true;
namespace part_line{
	
	int dis[maxn];
	bool check(long long x){
		long long lens=0;
		int cnt=0;
		for(int i=1;i<n;i++){
			if((lens+=dis[i])>=x){
				++cnt;
				lens=0;
			}
		}
		return (cnt>=m);
	}
	void mian(){
		long long l=1,r=sum,ans=0;
		while(l<=r){
			long long mid=(l+r)>>1;
			if(check(mid)){
				l=mid+1;
				ans=mid;
			}else r=mid-1;
		}
		printf("%lld\n",ans);
	}
};
bool flower=true;
namespace part_flower{
	long long dis[maxn];
	typedef set<long long>::iterator iter;
	bool check(long long x){
		set<long long> st;
		int cnt=0;
		for(int i=2;i<=n;i++)
			st.insert(dis[i]);
		while(st.empty()==false){
		/*	for(iter i=st.begin();i!=st.end();i++)
				printf("%lld ",*i);
			printf("\n");*/
			iter t=st.begin();
			if(t==st.end())
				break;
			long long qt=*t;
			st.erase(qt);
			if(qt>=x){
				++cnt;
				continue;
			}
			iter match=st.lower_bound(x-qt);
		//	printf("\n");
		//	printf("%lld ",*t);
			if(match!=st.end()){
				st.erase(*match);
				cnt++;
			//	printf("%lld\n",*match);
			}
		//	printf("\n");
		}
	//	printf("%d",cnt);
		return (cnt>=m);
	}
	void mian(){
	//	printf("%d\n",check(13));
		long long l=1,r=sum,ans=0;
		while(l<=r){
			long long mid=(l+r)>>1;
		//	printf("%lld %lld %lld\n",l,r,mid);
			if(check(mid)){
				l=mid+1;
				ans=mid;
			}else r=mid-1;
		}
		printf("%lld\n",ans);
	}
};
int max_road=0;
int main(void)
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(v!=u+1) line=false;
		if(u!=1) flower=false;
		sum+=w;
		max_road=max(max_road,w);
		part_line::dis[u]=w;
		part_flower::dis[v]=w;
		ins(u,v,w),ins(v,u,w);
	}
	if(m==1){
		part_m_1::mian();
		return 0;
	}
	if(line){
		part_line::mian();
		return 0;
	}
	if(flower){
		part_flower::mian();
		return 0;
	}
	printf("%d\n",max_road);
 	return 0;
}
/*
9 4
1 2 1
2 3 5
3 4 2
4 5 6
5 6 7
6 7 1
7 8 5
8 9 6
*/
/*
6 2
1 2 1
1 3 6
1 4 9
1 5 4
1 6 8
*/
