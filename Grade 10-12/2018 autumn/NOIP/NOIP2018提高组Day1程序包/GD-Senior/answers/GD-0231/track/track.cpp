#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	int x,y,c,next;
}a[210000];int len,last[151000];
void ins(int x,int y,int c){
	len++;
	a[len].x=x;a[len].y=y;a[len].c=c;
	a[len].next=last[x];last[x]=len;
}
int l,r,mid;
int n,m,fa[151000];

void findfa(int x)
{
	for (int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if (fa[x]!=y){
			fa[y]=x;
			findfa(y);
		}
	}
}
int f1[151000],f2[151000];//多少赛道;可以往上多长.
int jl[151000];int jllen=0;
bool jl2[151000];
int af[151000],be[151000];
void treedp(int x)
{
	for (int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if (fa[x]!=y)treedp(y);
	}
	int ans1=0;jllen=0;
	for (int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if (fa[x]!=y){
			ans1+=f1[y];
			if (f2[y]+a[k].c>=mid)ans1++;
			else{
				jllen++;
				jl[jllen]=f2[y]+a[k].c;
			}
		}
	}

	sort(jl+1,jl+jllen+1);
	for (int i=0;i<=jllen;i++)af[i]=i+1,be[i]=i-1;
	int rr=jllen;
	for (int ll=1;ll<=jllen;ll=af[ll]){
		if (ll==rr) rr=af[rr];
		while (rr>jllen)rr=be[rr];
		while ((jl[be[rr]]+jl[ll]>=mid)&&be[rr]>ll)rr=be[rr];
		while ((jl[rr]+jl[ll]<mid)&&rr<=jllen)rr=af[rr];
		if (rr>jllen)continue;
		if (ll==rr)  continue;
		if (jl[ll]+jl[rr]>=mid){
			ans1++;
			af[be[ll]]=af[ll];be[af[ll]]=be[ll];ll=be[ll];
			af[be[rr]]=af[rr];be[af[rr]]=be[rr];rr=be[rr];
		}
	}
	f1[x]=ans1;f2[x]=0;
	for (int i=af[0];i<=jllen;i=af[i]){
		if (af[i]>jllen)f2[x]=jl[i];
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	len=0;memset(last,0,sizeof(last));
	memset(fa,-1,sizeof(fa));
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int x,y,c;scanf("%d%d%d",&x,&y,&c);
		ins(x,y,c);ins(y,x,c);
	}
	fa[1]=0;findfa(1);
	l=1;r=10000*50000;
	int jlmid=0;
	while (l<=r){
		mid=(l+r)/2;
		treedp(1);
		if (f1[1]>=m){
			jlmid=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%d\n",jlmid);
	return 0;
}

