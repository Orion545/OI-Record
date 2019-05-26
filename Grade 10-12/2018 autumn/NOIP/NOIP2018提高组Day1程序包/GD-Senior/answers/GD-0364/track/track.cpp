#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,ed[100010],nxt[100010],len[100010],tot,last[50010],dis[50010],u,v,got[50010],bian[50010];
long long tota,lef,righ;
bool bo,f[50050];
void add(int x,int y,int z)
{
	ed[++tot]=y;
	len[tot]=z;
	nxt[tot]=last[x];
	last[x]=tot;
}

void dfs(int x)
{
	if (dis[x]>dis[v]) v=x;
	for (int i=last[x];i;i=nxt[i]){
		int y=ed[i];
		if (dis[y]||y==u) continue;
		dis[y]=dis[x]+len[i];
		dfs(y);
	}
}

bool check(long long t)
{
	long long nown=0;int cnt=0;
	for (int i=1;i<=n-1;i++){
		nown+=got[i];
		if (nown>=t) nown=0,cnt++;
	}
	if (cnt>=m) return true;
	return false;
}

bool pd(int t)
{
	int l=1,r=n-1,cnt=0;
	for (int i=1;i<=n-1;i++)
		f[i]=false;
//	printf("start\n");
	while (r>=1){
		if (f[r]){
			r--;continue;
		}
		if (bian[r]>=t){
		//	printf("bian[r]=%d r=%d\n",bian[r],r);
			cnt++;f[r]=true;r--;continue;
		}
		//bool bo=true;
		while (l<=n-1){
			if (f[l]||l==r){
				l++;
				continue;
			}
			if (bian[l]+bian[r]<t){
				l++;continue;
			}
		//	printf("l=%d r=%d bl=%d br=%d\n",l,r,bian[l],bian[r]);
			f[l]=f[r]=true;cnt++;l++;break;
		}
		r--;
	}
//	printf("over t=%d cnt=%d\n",t,cnt);
	
	if (cnt>=m) return true;else return false;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	tot=0;
	righ=0;lef=100000;
	bo=true;
	for (int i=1;i<=n-1;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (z<lef) lef=z;
		got[x]=z;
		bian[i]=z;
		righ+=z;
		add(x,y,z);
		add(y,x,z);
		if ((y-x!=1)&&(x-y!=1)) bo=false;
	}
	if (m==1){
		for (int i=1;i<=n;i++)
			dis[i]=0;
		u=v=1;
		dfs(1);
		u=v;
		for (int i=1;i<=n;i++)
			dis[i]=0;
		dfs(u);
		printf("%d",dis[v]);
	}
	else if (bo){
		while (lef<righ){
			long long mid=(1+lef+righ)>>1;
			if (check(mid)) lef=mid;
			else righ=mid-1;
		}
		printf("%lld",lef);
	}
	else if (m==n-1){
		printf("%lld",lef);
	}
	else{
		sort(bian+1,bian+n);
		int l=bian[1];int r=bian[n-1]+bian[n-2];
		while (l<r){
			int mid=(l+r+1)>>1;
			if (pd(mid)) l=mid;
			else r=mid-1;
		//	printf("yes1 \n");
		}
		printf("%d",l);
	}
	return 0;
}
