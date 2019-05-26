#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN=50005;
int n,m;
long long totall;
int edge[MAXN],nex[MAXN*2],to[MAXN*2],wi[MAXN*2],sz=1;
int lll[MAXN];

int adde(int a,int b,int w){
	to[sz]=b;
	nex[sz]=edge[a];
	wi[sz]=w;
	edge[a]=sz;
	sz++;
}

int fst=1,ffdis=0;
int dfs_d(int node,int fa,int dis){
	if(dis>ffdis){
		fst=node;
		ffdis=dis;
	}
	for(int ind=edge[node];ind;ind=nex[ind]){
		int dst=to[ind];
		if(dst==fa)continue;
		dfs_d(dst,node,dis+wi[ind]);
	}
}

void solvem1(){
	dfs_d(1,0,0);
	int n1=fst;
	dfs_d(fst,0,0);
	int n2=fst;
	cout<<ffdis<<endl;
}

bool checkl(int x){
	int ct=0,cur=0;
	for(int i=1;i<n;i++){
		int a=lll[i];
		cur+=a;
		if(cur>=x){
			cur=0;ct++;
		}
	}
	return ct>=m;
}

void solvel(){
	long long l=0,r=totall/m;
	while(l<r){
		long long mid=(l+r+1)/2;
		if(checkl((int)mid))l=mid;
		else r=mid-1;
	}
	cout<<r;
}


int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	int mne=10000000;
	bool isl=true;
	for(int i=1;i<n;i++){
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		adde(a,b,w),adde(b,a,w);
		mne=min(mne,w);
		if(b!=a+1)isl=false;
		lll[a]=w;
		totall+=w;
	}
	if(m==1){
		solvem1();
	}else if(m==n-1){
		cout<<mne<<endl;
	}else if(isl){
		solvel();
	}
	return 0;
}
