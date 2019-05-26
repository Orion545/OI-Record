#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 50005;

int n,m;
struct edge{
	int x,l,nxt;
}e[N*2];
int h[N],tot;

void inse(int x,int y,int l){e[++tot].x=y;e[tot].l=l;e[tot].nxt=h[x];h[x]=tot;}

int fa[N],dep[N];
int lef[N],rig[N];
int co[N];

void dfs(int x){
	for(int p=h[x];p;p=e[p].nxt)
	if (!dep[e[p].x]){
		dep[e[p].x]=dep[x]+1;
		fa[e[p].x]=x;
		rig[e[p].x]=lef[x];
		lef[x]=e[p].x;
		co[e[p].x]=e[p].l;
		dfs(e[p].x);
	}
}

int pv;
int cnt;
int val[N];
int key[N],k;
int pre[N],nxt[N];
bool used[N];

void getans(int x){
	for(int y=lef[x];y;y=rig[y])getans(y);
	k=0;
	for(int y=lef[x];y;y=rig[y])key[++k]=val[y]+co[y];
	sort(key+1,key+1+k);
	fo(i,0,k)used[i]=0;
	fo(i,1,k)pre[i]=nxt[i]=0;
	int now=0,w=0,lst=0;
	fo(i,1,k){
		int v=key[i];
		if (v>=pv){
			used[i]=1;
			cnt++;
			continue;
		}
		if (!now||key[w]+v<pv){
			now++;
			if (now==1)	w=lst=i;
			else{
				nxt[lst]=i;
				pre[i]=lst;
				lst=i;
			}
			if (w!=lst)w=nxt[w];
		}
		else{
			while(pre[w]&&key[pre[w]]+v>=pv)w=pre[w];
			used[w]=used[i]=1;
			cnt++;
			now--;
			if (!now)lst=w=0;
			else{
				int wl=pre[w],wr=nxt[w];
				if (wl)nxt[wl]=wr;
				if (wr)pre[wr]=wl;
				if (!wr)lst=w=wl;
				else w=wr;
			}
		}
	}
	val[x]=0;
	fd(i,k,0)if (!used[i]){val[x]=key[i];break;}
}

bool check(int mid){
	pv=mid,cnt=0;
	getans(1);
	return cnt>=m;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=get();m=get();
	fo(i,1,n-1){
		int x=get(),y=get(),l=get();
		inse(x,y,l);
		inse(y,x,l);
	}
	dep[1]=1;
	dfs(1);
	int l=1,r=5e8,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if (check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
