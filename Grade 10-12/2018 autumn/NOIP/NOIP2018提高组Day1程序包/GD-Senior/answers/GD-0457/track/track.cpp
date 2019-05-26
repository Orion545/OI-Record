using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 50000
int n,m;
struct EDGE{
	int to,len;
	EDGE *las;
} e[N*2+1];
int ne;
EDGE *last[N+1];
int lensum;

int dis[N+1];
void get_dis(int x,int fa){
	for (EDGE *ei=last[x];ei;ei=ei->las)
		if (ei->to!=fa){
			dis[ei->to]=dis[x]+ei->len;
			get_dis(ei->to,x);
		}
}

bool lian_ok(int lim){
	int num=0;
	for (int i=1,sum=0;i<n;++i){
		for (EDGE *ei=last[i];ei;ei=ei->las)
			if (ei->to==i+1){
				sum+=ei->len;
				if (sum>=lim)
					sum=0,num++;
				break;
			}
	}
	return num>=m;
}

bool flower_ok(int lim){
	int i,num=0;
	for (i=n;i>=2;--i)
		if (dis[i]>=lim)
			num++;
		else
			break;
	if (i==1 || i==2)
		return num>=m;
	int j=int(lower_bound(dis+2,dis+i,lim-dis[i])-dis);
	for (;i>j;--i){
		while (j<i && dis[i]+dis[j]<lim)
			++j;
		if (j<i)
			num++,j++;
	}
	return num>=m;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool is_lian=1,is_flower=1;
	for (int i=1;i<n;++i){
		int u,v,len;
		scanf("%d%d%d",&u,&v,&len);
		if (u+1!=v)
			is_lian=0;
		if (u!=1)
			is_flower=0;
		++ne;
		e[ne].to=v,e[ne].len=len,e[ne].las=last[u],last[u]=e+ne;
		++ne;
		e[ne].to=u,e[ne].len=len,e[ne].las=last[v],last[v]=e+ne;
		lensum+=len;
	}
	if (m==1){
		dis[1]=0;
		get_dis(1,0);
		int mx=1;
		for (int i=2;i<=n;++i)
			if (dis[i]>dis[mx])
				mx=i;
		dis[mx]=0;
		get_dis(mx,0);
		int ans=0;
		for (int i=1;i<=n;++i)
			ans=max(ans,dis[i]);
		printf("%d\n",ans);
		return 0;
	}
	if (is_lian){
		int l=1,r=lensum/m,res=0;
		while (l<=r){
			int mid=l+r>>1;
			if (lian_ok(mid))
				l=(res=mid)+1;
			else
				r=mid-1;
		}
		printf("%d\n",res);
		return 0;
	}
	if (is_flower){
		get_dis(1,0);
		sort(dis+2,dis+n+1);
		int l=1,r=lensum/m,res=0;
		while (l<=r){
			int mid=l+r>>1;
			if (flower_ok(mid))
				l=(res=mid)+1;
			else
				r=mid-1;
		}
		printf("%d\n",res);
	}
	return 0;
}
