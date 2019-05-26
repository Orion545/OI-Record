#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5e4+10;
int mp[N*2],t[N*2],lst[N],d[N],o,ln;
int dt[N],cnt[N],a[N],bz[N],f[N],n,m;
void Tp(){
	int en=0;
	for(int i=1;i<=n;i++)
		if(cnt[i]==1){
			bz[i]=1;
			dt[++en]=i;
		}
	for(int st=1;st<=en;st++){
		int x=dt[st];
		for(int c=lst[x];c;c=t[c]){
			int y=mp[c];
			if(bz[y])continue;
			cnt[y]--;
			if(cnt[y]==1){
				bz[y]=1;
				dt[++en]=y;
			}
		}
	}
}
int get1(int x,int la){
	if(bz[x])return x;
	for(int c=lst[x];c;c=t[c]){
		int y=mp[c];
		if(y==la)continue;
		int p=get1(y,x);
		if(p)return p;
	}
	return 0;
}
void dfs(int x,int la){
	printf("%d ",x);
	int st=d[0];
	for(int c=lst[x];c;c=t[c]){
		int y=mp[c];
		if(y==la||y==-1)continue;
		d[++d[0]]=y;
	}
	sort(d+st+1,d+d[0]+1);
	for(int i=st+1;i<=d[0];i++)
		dfs(d[i],x);
	d[0]=st;
}
void dfs1(int x,int la,int cp){
	for(int c=lst[x];c;c=t[c]){
		int y=mp[c];
		if(y==la||(!bz[y]))continue;
		if(y<cp)dfs1(y,x,cp);
		else{
			mp[c]=mp[c^1]=-1;
			o=0;
		}
		if(!o)return;
	}
}
void work(int rt){
	int m1=0,m2=0;
	for(int c=lst[rt];c;c=t[c]){
		int y=mp[c];
		if(bz[y]){
			if(!m1)m1=c;
			else m2=c;
		}
	}
	if(mp[m1]>mp[m2])swap(m1,m2);
	o=1;
	dfs1(mp[m1],rt,mp[m2]);
	if(o)mp[m2]=mp[m2^1]=-1;
}
void add(int x,int y){
	mp[++ln]=y;t[ln]=lst[x];lst[x]=ln;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	ln=1;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
		cnt[x]++;cnt[y]++;
	}
	if(m==n-1){
		dfs(1,0);
		return 0;
	}
	Tp();
	for(int i=1;i<=n;i++)bz[i]=1-bz[i];
	int p=get1(1,0);
	int m1=0,m2=0;
	work(p);
//	mp[m1]=-1;
	dfs(1,0);
	return 0;
}
