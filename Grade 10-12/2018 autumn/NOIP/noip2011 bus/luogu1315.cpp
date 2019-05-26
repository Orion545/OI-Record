/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
#define end DEEP_DARK_FANTASY
#define next VAN_YOU_SEE
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
int n,m,k;
int dis[30010],pred[30010],tim[30010],op[30010],ed[30010];
int wait[30010],end[30010],enter[30010],ans,g[30010];
void solve(){
	int i,tmp,maxn,pos;
	while(k){
		k--;
		g[n]=g[n-1]=n;
		for(i=n-2;i>=1;i--){
			if(enter[i+1]>wait[i+1]) g[i]=g[i+1];
			else g[i]=i+1;
		}
		maxn=-1;pos=0;
		for(i=1;i<n;i++){
			tmp=end[g[i]]-end[i];
			if(tmp>maxn&&dis[i]>0){
				maxn=tmp;pos=i;
			}
		}
		if(maxn==-1) break;
		ans-=maxn;
		dis[pos]--;
//		cout<<maxn<<' '<<ans<<'\n';
		for(i=2;i<=n;i++) enter[i]=max(enter[i-1],wait[i-1])+dis[i-1];
	}
}
int main(){
//	freopen("in.in","r",stdin);
	n=read();m=read();k=read();int i;
	for(i=1;i<n;i++) dis[i]=read(),pred[i+1]=pred[i]+dis[i];
	for(i=1;i<=m;i++){
		tim[i]=read();op[i]=read();ed[i]=read();
		wait[op[i]]=max(wait[op[i]],tim[i]);
		end[ed[i]]++;
	}
	
	for(i=1;i<=n;i++) end[i]+=end[i-1];
	enter[1]=wait[1];
	for(i=2;i<=n;i++) enter[i]=max(enter[i-1],wait[i-1])+dis[i-1];
	ans=0;
	for(i=1;i<=m;i++) ans+=enter[ed[i]]-tim[i];
	
//	cout<<ans<<'\n';
	solve();
	printf("%d\n",ans);
}
