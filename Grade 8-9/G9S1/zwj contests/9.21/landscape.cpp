#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector> 
#include<cmath>
#define inf 0x7fffffff
#define ll long long
using namespace std;
vector<int>row[2000100];
int n,x,y,z,minn=inf,maxn=0;
ll re1[100100],re2[100100],cnt[2001000];
void dp(vector<int> &k,ll re[]){
	ll m=k.size(),prei=0,prej=0,lrange=10000000000LL,i=-2,j;
	for(j=1;j<m;j+=2){
		if(j>1) prej+=z*abs(k[j-2]-k[j-1]),lrange+=z*abs(k[j-2]-k[j-1]);
		while(i+2<j&&x+y<=z*abs(k[j]-k[i+2])){
			i+=2;
			if(i>0) prei+=z*abs(k[i]-k[i-1]);
			lrange=min(lrange,x+y+prej-prei+((i>0)?re[i-1]:0));
		}
		re[j]=min(lrange,z*abs(k[j]-k[j-1])+((j>1)?re[j-2]:0));
	}
	return;
}
int solve(vector<int> &k,int cost){
	int m=k.size(),i;
	if(m==0) return 0;
	if(m==1) return cost;
	dp(k,re1);
	reverse(k.begin(),k.end());
	dp(k,re2);
	reverse(re2,re2+m);
	if(m%2==0) return re1[m-1];
	ll re=cost+min(re1[m-2],re2[1]);
	for(i=2;i<=m-3;i+=2) re=min(re,cost+re1[i-1]+re2[i+1]);
	return re;
}
int main(){
	int i,j,a,b,c,dep,last,cur=1000000;
	scanf("%d%d%d%d",&n,&x,&y,&z);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		dep=max(a,b)-min(a,b);
		c=((a>b)?-1:1);
		if(i==1) last=c;
		while(dep--){
			if(dep==max(a,b)-min(a,b)-1&&last!=c) cur+=0;
			else cur+=c;
			row[cur].push_back(i);
			cnt[cur]+=c;
			minn=min(minn,cur);maxn=max(maxn,cur);
		}
		last=c;
	}
//	for(i=minn;i<=maxn;i++){
//		for(j=0;j<row[i].size();j++) cout<<row[i][j]<<ends;
//		cout<<endl;
//	}
	ll ans=0;
	for(i=minn;i<=maxn;i++){
		ans+=solve(row[i],((cnt[i]>0)?x:y));
	}
	printf("%d",ans);
}
