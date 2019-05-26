#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int> > p;
int n,m,ta,tb,tc;
p tu[50001];
int mat[6][6]={};
int bcj[6];
int vis[6]={};
int dis[50001];
int spai=0;
int spbi=0;
int res=0;

int search(int st){
	vis[st]=1;
	int r=0;
	for (int i=1;i<=n;i++){
		if ((!vis[i])&&mat[st][i]>0){
			r=max(r,mat[st][i]+search(i));
		}
	}
	return r;
	vis[st]=0;
}

int main(){
	freopen("track1.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	if (n<=5&&m==1){
		for (int i=1;i<=n-1;i++){
			scanf("%d%d%d",&ta,&tb,&tc);
			mat[ta][tb]=tc;
			mat[tb][ta]=tc;
		}
		for (int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			res=max(res,search(i));
		}
		printf("%d",res);
		return 0;
	}
	
	for (int i=1;i<=n-1;i++){
		scanf("%d%d%d",&ta,&tb,&tc);
		tu[i]=p(tc,make_pair(ta,tb));
		if (ta==1) spai++;
		if (tb=ta+1) spbi++;
		dis[tb]=tc;
	}
	sort(tu+1,tu + n);
	if (spai==n-1){
		int mmin=999999999;
		int r=n-1,l=n-2*m;
		while (l<r){
			mmin=min(mmin,tu[r].first+tu[l].first);
			l++;r--;
		}
		printf("%d",mmin);
	}else if(spbi==n-1){
		
	}
	return 0;
}
