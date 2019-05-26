#include<bits/stdc++.h>
using namespace std;
const int maxn=50000;
int n,m,u,v;
long long l=0,r=0,mid,lens[maxn+100];
struct road{
	int to;
	long long val;
}o;
vector <road> to[maxn+100];
struct fc{
	int rodcnt,nod;
	long long nowroad;
}dp[maxn+100];
void dfs(int x,int f,const long long &len){
	int siz=to[x].size(),cnt=0;
	for(int i=0;i<siz;i++){
		road t=to[x][i];
		if(t.to!=f){
			dp[t.to].nod=dp[x].nod+(++cnt);
		    dfs(t.to,x,len);
		    dp[x].rodcnt+=dp[t.to].rodcnt;
		    if(dp[t.to].nowroad+t.val>=len){dp[x].rodcnt++;cnt--;}
		    else{lens[dp[t.to].nod]=dp[t.to].nowroad+t.val;}
		}
	}
	sort(lens+dp[x].nod+1,lens+dp[x].nod+cnt+1);
	int i=dp[x].nod+cnt;
	int j=dp[x].nod+1;
	while(i>j){
		if(lens[i]+lens[j]>=len){dp[x].rodcnt++;lens[i--]=0;lens[j++]=0;}
		else{j++;}
	}
	for(i=dp[x].nod+cnt;i>=dp[x].nod+1;i--){
	    dp[x].nowroad=max(lens[i],dp[x].nowroad);
		lens[i]=0;
	}
}
bool check(long long len){
	for(int i=0;i<=n;i++){lens[i]=0;dp[i].nod=0;dp[i].rodcnt=0;dp[i].nowroad=0;}
	dfs(1,0,len);
	if(dp[1].rodcnt>=m) return true;
	else return false;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%lld",&u,&v,&o.val);
		r+=o.val;
	    o.to=u;to[v].push_back(o);
	    o.to=v;to[u].push_back(o);
	}
	while(l!=r){
		mid=(l+r+1)>>1;
		if(check(mid)){l=mid;}
		else{r=mid-1;}
	}
	printf("%lld\n",l);
	return 0;
}
