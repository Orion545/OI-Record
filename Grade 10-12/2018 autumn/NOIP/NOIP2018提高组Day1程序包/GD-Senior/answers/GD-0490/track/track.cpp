#include<cstdio>
#include<fstream>
#include<algorithm>
#include<cstring>
using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;

ifstream fin("track.in");
ofstream fout("track.out");

const int N=5e4+10,M=1e5+10;
int l=0,r=5e8,mid;
int f[N],g[N],d[N];
int n,m,x,y,z;
int to[M],nex[M],st[N],len[M];
int uses[N],tot;

struct Alen{int val,pre,suf,id;}q[N];

void link(int x,int y,int z){
	static int t;
	nex[++t]=st[x],to[t]=y,st[x]=t,len[t]=z;
}

void MAX(int&x,int y){
	if(y>x)x=y;
}

void ERASE(int&p,int tp){
	q[p].val=0;
	if(!q[p].pre){
		p=q[p].suf;
		q[p].pre=0;
		return;
	}
	if(!q[p].suf){
		p=q[p].pre;
		q[p].suf=0;
		if(tp==1)p=0;
		return;
	}
	q[q[p].pre].suf=q[p].suf;
	q[q[p].suf].pre=q[p].pre;
	p=q[p].suf;
}

int Getpre(int x,int y){
	if(q[x].pre==y)return q[y].pre;
	return q[x].pre;
}
void tree_dp(int x,int ls,int lim){
	int cnt=0;
	for(int k=st[x];k;k=nex[k])
		if(to[k]-ls){
			tree_dp(to[k],x,lim);
			f[x]+=f[to[k]];
		}
		
	for(int k=st[x];k;k=nex[k])
		if(to[k]-ls)
			d[++cnt]=g[to[k]]+len[k];
		
	sort(d+1,d+cnt+1);
	
	while(d[cnt]>=lim&&cnt>0)
		++f[x],--cnt;
	
	if(!cnt)return;
	if(cnt==1){
		g[x]=d[1];return;
	}
		
	int pt=cnt,now=1;
	rep(i,1,cnt)
		if(d[i]+d[1]>=lim){pt=i;break;}
	
	q[1].val=d[1],q[1].pre=0,q[1].suf=2;
	rep(i,2,cnt-1)
		q[i].val=d[i],q[i].pre=i-1,q[i].suf=i+1;
	q[cnt].val=d[cnt],q[cnt].pre=cnt-1,q[cnt].suf=0;
	rep(i,1,cnt)q[i].id=i;
	
	++tot;
	
	rep(i,1,cnt){
		q[0].val=0;
		if(pt==now){
			if(q[pt].suf)pt=q[pt].suf;
			else pt=q[pt].pre;
		}
		if(!pt)break;
		if(!now)break;
		if(q[pt].val+d[i]>=lim){
			while(Getpre(pt,now)&&q[Getpre(pt,now)].val+d[i]>=lim)
				pt=Getpre(pt,now);
			uses[q[pt].id]=tot,uses[q[now].id]=tot;
			ERASE(pt,0),ERASE(now,1);
			++f[x];
		}
	}
	
	rep(i,1,cnt)if(uses[i]!=tot)
		MAX(g[x],d[i]);
}

int main(){
	fin>>n>>m;
	rep(i,1,n-1){
		fin>>x>>y>>z;
		link(x,y,z),link(y,x,z);
	}
	
	while(l<r){
		memset(f,0,sizeof f),memset(g,0,sizeof g);
		mid=l+r+1>>1;
		tree_dp(1,0,mid);
		if(f[1]>=m)l=mid;
		else r=mid-1;
	}
	
	fout<<l;
	return 0;
}

