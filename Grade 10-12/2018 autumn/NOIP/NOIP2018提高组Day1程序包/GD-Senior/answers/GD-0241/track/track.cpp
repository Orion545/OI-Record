#include<iostream>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<set>
#include<vector>
//#include<ctime>
#define mp make_pair
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,mid,first[50010],cnte=1,flag;
struct edge{
	int to,next,w;
}a[100010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
int dp[50010],cnt[50010];
multiset<int>s[50010];
vector<pair<int,int> >x[50010];
//int ttot,tt1;
void dfs(int u,int f){
	int i,v;
	multiset<int>::iterator cur,nex;
	vector<pair<int,int> >::iterator it;
	pair<int,int>tmpp;
	
//	cout<<"dfs "<<u<<' '<<f<<'\n';fflush(stdout);
	
	s[u].clear();x[u].clear();
	cnt[u]=0;dp[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
		if(flag) return;
		
//	tt1=clock();
		cnt[u]+=cnt[v];
		if(dp[v]+a[i].w>=mid) cnt[u]++;
		else{
			s[u].insert(dp[v]+a[i].w);
			x[u].push_back(mp(dp[v]+a[i].w,0));
		}
		if(cnt[u]>=m){flag=1;return;}
//	ttot+=clock()-tt1;
	}
//	tt1=clock();
	sort(x[u].begin(),x[u].end());
//	ttot+=clock()-tt1;
	if(!s[u].size()) return;
//	cout<<"begin processing "<<u<<' '<<s[u].size()<<'\n';fflush(stdout);
	for(i=0;i<x[u].size();i++){
		
//		cout<<"	check "<<u<<' '<<x[u][i].first<<' '<<x[u][i].second<<'\n';fflush(stdout);
		
		if(x[u][i].second==0){
			cur=s[u].lower_bound(x[u][i].first);
		}
		
		if(x[u][i].second) continue;
		
		s[u].erase(cur);
		
		nex=s[u].lower_bound(mid-x[u][i].first);
//		cout<<"	getnex "<<(nex==s[u].end())<<'\n';fflush(stdout);
		if(nex==s[u].end()){
			s[u].insert(x[u][i].first);
			continue;
		}
//		cout<<"	nex is "<<(*nex)<<'\n';fflush(stdout);
//		assert((*nex)>=x[u][i].first);
		
		tmpp=mp((*nex),0);
		it=upper_bound(x[u].begin(),x[u].end(),tmpp);
		it--;
//		assert(it->second==0);
		
		x[u][i].second=1;
		it->second=1;
		
		s[u].erase(nex);
		
		cnt[u]++;
		if(cnt[u]>=m){flag=1;return;}
	}
	if(cnt[u]>=m) flag=1;
	if(s[u].size()){
		nex=s[u].end();nex--;
		dp[u]=(*nex);
	}
//	cout<<"finish dfs "<<u<<' '<<cnt[u]<<' '<<s[u].size()<<' '<<dp[u]<<'\n';
	return;
}
bool solve(){
	flag=0;
//	ttot=0;
	dfs(1,0);
//	cout<<"solve "<<mid<<' '<<cnt[1]<<' '<<flag<<' '<<ttot<<'\n';fflush(stdout);
	return flag;
}
int main(){
//	int ts1=clock();
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2,t3,fff=1,ff2=1;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
		if((t1!=t2+1)&&(t2!=t1+1)) ff2=0;
		if(t1!=1&&t2!=1) fff=0;
	}
	int l=1,r=1e9;
	if(fff) r=2e4;
	if(!ff2) r=1e8;
	while(l<r){
		mid=(l+r)>>1;mid++;
		if(solve()) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
//	cout<<clock()-ts1<<'\n';
//	mid=26282;
//	cout<<"solve check "<<solve()<<'\n';
	return 0;
}
