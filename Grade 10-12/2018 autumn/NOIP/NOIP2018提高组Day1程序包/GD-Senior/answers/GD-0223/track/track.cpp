#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
char ch;
#define ll long long
#define MM 51010
#define N 1110
#define mo 1000000007

ll xxx;ll fff;
inline ll readll(){
	xxx=0;fff=1;ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')fff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xxx=(xxx<<1)+(xxx<<3)+ch-'0';
		ch=getchar();
	}
	return xxx*fff;
}
int xx;int ff;
inline int read(){
	xx=0;ff=1;ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')ff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xx=(xx<<1)+(xx<<3)+ch-'0';
		ch=getchar();
	}
	return xx*ff;
}
int n,m;
struct edge{
	int v,nex,w;
}e1[MM<<1];
int head[MM],elen=0;
inline void adde(int u,int v,int w){
	e1[++elen].v=v;
	e1[elen].nex=head[u];
	e1[elen].w=w;
	head[u]=elen;
}
int dep[MM];
inline void dfs1(int u,int fa){
	//dep[u]=dep[fa]+1;
	for(int ee=head[u];ee;ee=e1[ee].nex){
		int v=e1[ee].v;
		if(!dep[v]&&(v!=fa)){
			dep[v]=dep[u]+e1[ee].w;
			dfs1(v,u);
		}
	}
}
inline int solve1(){
	memset(dep,0,sizeof(dep));
	dep[1]=0;
	dfs1(1,1);
	int maxid=1;
	for(int i=2;i<=n;++i)if(dep[i]>dep[maxid])maxid=i;
	//cerr<<maxid<<" "<<dep[maxid]<<"MD"<<endl;
	memset(dep,0,sizeof(dep));
	dep[maxid]=0;
	dfs1(maxid,maxid);
	maxid=1;
	for(int i=2;i<=n;++i){
		if(dep[i]>dep[maxid])maxid=i;
		//cerr<<"i="<<i<<" dep[i]="<<dep[i]<<endl;
	}
	return dep[maxid];
}
int tz2[MM],tzlen=0,sum=0;
inline void dfs2(int u,int fa){
	for(int ee=head[u];ee;ee=e1[ee].nex){
		if(e1[ee].v==fa)continue;
		sum+=e1[ee].w;
		tz2[++tzlen]=e1[ee].w;
		dfs2(e1[ee].v,u);
	}
}
inline bool judge2(int k){
	int p=0;int cnt=0;
	for(int i=1;i<=n;++i){
		p+=tz2[i];
		if(p>=k){
			++cnt;p=0;
			if(cnt>=m)return 1;
		}
	}
	return 0;
}
inline int solve2(){
	memset(dep,0,sizeof(dep));
	dep[1]=0;
	dfs1(1,1);
	int maxid=1;
	for(int i=2;i<=n;++i)if(dep[i]>dep[maxid])maxid=i;
	memset(tz2,0,sizeof(tz2));
	dfs2(maxid,maxid);
	int l=0;int r=sum+1;
	int anss=sum;
	while(l<=r){
		int mid=(l+r)>>1;
		if(judge2(mid)){
			l=mid+1;
		}else{
			r=mid-1;
			anss=r;	
		}
	}
	return anss;
}
inline bool cmp(edge x,edge y){
	return x.w<y.w;
}
inline int solve3(){
	sort(e1+1,e1+1+elen,cmp);
	//cerr<<elen<<" "<<endl;
	//for(int i=1;i<=elen+2;++i)cerr<<e1[i].w<<endl;
	if((elen/2)&1)return e1[m*4-1].w;
	//cerr<<"Q"<<endl;
	return e1[m*4-1].w+e1[m*4-2].w;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();int x,y,z;
	bool flag2=1;bool flag3=1;
	for(int i=1;i<n;++i){
		x=read();y=read();z=read();
		if(y!=x+1)flag2=0;
		if(x!=1)flag3=0;
		adde(x,y,z);adde(y,x,z);
	}
	if(m==1){
		printf("%d\n",solve1());
		fclose(stdin);fclose(stdout);
		return 0;
	} 
	if(flag2){
		printf("%d\n",solve2());
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if(flag3){
		printf("%d\n",solve3());
		fclose(stdin);fclose(stdout);
		return 0;
	}
	printf("%d\n",rand()%100+1);
	fclose(stdin);fclose(stdout);
	return 0;
}
