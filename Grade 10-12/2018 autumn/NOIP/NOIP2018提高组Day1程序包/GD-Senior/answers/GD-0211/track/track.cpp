#include<cstdio>
#include<iostream>
#include<cctype>
#include<cstring>
#include<map>
#include<cstdio>
#include<iostream>
#include<cctype>
#include<cstring>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
char *FS,*FT,BB[1<<12];
//#define _()	(FS==FT&&(FT=(FS=BB)+fread(BB,1,1<<12,stdin),FS==FT)?EOF:*FS++)
#define _() getchar()
int read(){
	int i=1,x=0;
	char ch=_();
	while(!isdigit(ch)){
		if(ch==EOF)exit(0);
		if(ch=='-')i=-1;
		ch=_();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=_();
	}
	return i*x;
}

#define REP(i,a,b)	for(int i=a;i<=b;i++)
#define DOW(i,a,b)	for(int i=a;i>=b;i--)
#define INF 0x3f3f3f3f
#define N 100005
#define CL(a,b)	memset(a,b,sizeof(a))

struct edge{
	int to,nex,val;
}E[N<<1];

int head[N];
void add(int i,int j,int v){
	static int t=1;
	E[++t]=(edge){j,head[i],v};
	head[i]=t;
}

int dis[N],MID,ans[N];
//vector<int> vec[N];
multiset<int> s[N];

void dfs(int now,int fa){
//	printf("%d %d\n",now,fa);
	ans[now]=0;
	dis[now]=0;
//	s[now].clear();
//	vec[now].clear();
	for(int i=head[now];i;i=E[i].nex){
		if(E[i].to!=fa){
			dfs(E[i].to,now);
			if(dis[E[i].to]+E[i].val<MID)s[now].insert(dis[E[i].to]+E[i].val);
			else ans[now]++;
//			vec[now].push_back(dis[E[i].to]+E[i].val);
			ans[now]+=ans[E[i].to];
		}
	}
//	if(!vec[now].size())return;
	if(s[now].empty())return;
	while(!s[now].empty()){
		multiset<int>::iterator it=s[now].begin();
		s[now].erase(it);
		multiset<int>::iterator F=s[now].lower_bound(MID-*it);
//		printf("%d %d\n",*it,*F);
		if(F!=s[now].end())ans[now]++,s[now].erase(F);
		else dis[now]=*it;
	}
//	sort(vec[now].begin(),vec[now].end());
//	int head=0,tail=(int)vec[now].size()-1;
//	while(tail>=0&&vec[now][tail]>=MID)tail--,ans[now]++;
//	while(head<tail){
//		
////		printf("%d %d\n",head,tail);
//		if(vec[now][tail]+vec[now][head]>=MID)tail--,head++,ans[now]++;
//		else dis[now]=vec[now][head],head++;
//	}
//	if(head==tail)dis[now]=vec[now][head];
//	dis[now]=vec[now][tail];
//	if(dis[now]>=MID)dis[now]=0,ans[now]++;
}



int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n=read(),m=read(),l=0,r=0,A=0;
	REP(i,1,n-1){
		int x=read(),y=read(),z=read();
		r+=z;
		add(x,y,z);add(y,x,z);
	}
//	MID=22;
	while(l<=r){
		MID=(l+r)/2;
		dfs(1,0);
//		printf("\n--------------------------\n%d\n",MID);
//		REP(i,1,n)printf("%d ",ans[i]);
//		printf("\n");
//		REP(i,1,n)printf("%d ",dis[i]);
		if(ans[1]>=m)A=MID,l=MID+1;
		else r=MID-1;
	}
	printf("%d",A);
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

