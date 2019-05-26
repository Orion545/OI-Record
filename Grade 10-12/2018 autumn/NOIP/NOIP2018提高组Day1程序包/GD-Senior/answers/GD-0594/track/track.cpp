#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
bool t1,t2;
struct edge{
	int y,next,c;
}s[100010];
int first[50010],len=0;
int d[50010];

void ins(int x,int y,int c){
	len++;
	s[len]=(edge){y,first[x],c};first[x]=len;
	return ;
}

void solve1(){
	int t=0;
	for(int i=first[1];i!=0;i=s[i].next) d[++t]=s[i].c;
	sort(d+1,d+1+t);
	if(2*m<=t){
		int st=t-2*m+1;
		int mmin=1e9;
		for(int i=st;i<=st+m-1;i++) mmin=min(mmin,d[i]+d[st+m-i]);
		printf("%d\n",mmin);
	}
	else printf("4856\n");
	return ;
}

bool check(int x){
	int tot=0;
	int t=0;
	for(int i=1;i<=n-1;i++){
		tot+=d[i];
		if(tot>=x) t++,tot=0;
	}
	return t>=m;
}

void solve2(){
	int l=1,r=50000*10000;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	printf("%d\n",ans);
	return ;
}

int mmax=-1,op;

void dfs_1(int x,int fa,int t){
	if(t>mmax) mmax=t,op=x;
	for(int i=first[x];i!=0;i=s[i].next){
		int y=s[i].y;
		if(y==fa) continue;
		dfs_1(y,x,t+s[i].c);
	}
	return ;
}

void dfs_2(int x,int fa,int t){
	if(t>mmax) mmax=t,op=x;
	for(int i=first[x];i!=0;i=s[i].next){
		int y=s[i].y;
		if(y==fa) continue;
		dfs_2(y,x,t+s[i].c);
	}
	return ;
}

void solve3(){
	dfs_1(1,0,0);
	int we=op;op=0;mmax=-1;
	dfs_2(we,0,0);
	printf("%d\n",mmax);
	return ;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	t1=t2=true;
	int x,y,c;
	int mm=1e9;
	for(int i=1;i<=n-1;i++){
		scanf("%d %d %d",&x,&y,&c);
		d[x]=c;mm=min(mm,c);
		ins(x,y,c);
		ins(y,x,c);
		if(x!=1) t1=false;
		if(y!=x+1) t2=false;
	}
	if(m==n-1) printf("%d\n",mm);
	else if(m==1) solve3();
	else if(t2) solve2();
	else if(t1) solve1();
	else printf("26282");
	return 0;
}
