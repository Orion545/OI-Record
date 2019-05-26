#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int head[100000],a[500000],al[500000],aw[500000],an=0;
int e[110000],en=0;
void addline(int u,int v,int w){
	a[an]=v;
	aw[an]=w;
	al[an]=head[u];
	head[u]=an;
	an++;
	return;
}

int len1[100000];
void dfs1(int now,int father){
	int v;
	for(int l=head[now];l!=-1;l=al[l]){
		v=a[l];
		if(v==father)continue;
		len1[v]=len1[now]+aw[l];
		dfs1(v,now);
	}
	return;
}
void solve1(){
	len1[1]=0;
	dfs1(1,0);
//	for(int i=1;i<=n;i++)cout<<len1[i]<<" ";
//	cout<<endl;
	int k=1,max_len=0;
	for(int i=1;i<=n;i++)
		if(len1[i]>max_len){
			k=i;max_len=len1[i];
		}
	len1[k]=0;
	dfs1(k,0);
//	for(int i=1;i<=n;i++)cout<<len1[i]<<" ";
//	cout<<endl;
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,len1[i]);
	printf("%d\n",ans);
	return;
}


void solve2(){
	int ans=2147483647>>1;
	sort(e+1,e+1+en);
	if(m*2<=en){
		int i,j;
		i=en-(m*2)+1;j=en;
		for(int i1=1;i1<=m;i1++){
			ans=min(ans,e[i]+e[j]);
			i++;j--;
		}
	}
	else{
		int k=en-m;
		int i,j;
		i=1;j=k*2;
		for(int i1=1;i1<=k;i1++){
			ans=min(ans,e[i]+e[j]);
			i++;j--;
		}
		for(int i=2*k+1;i<=en;i++)
			ans=min(ans,e[i]);
	}
	printf("%d\n",ans);
	return;
}


bool judge3(int G){
	int sum=0;
	int cnt=0;
	for(int i=1;i<=en;i++){
		sum+=e[i];
		if(sum>=G){
			cnt++;
			sum=0;
		}
	}
	if(cnt>=m)return true;
	else return false;
}
void solve3(){
	int L=20000,R=0,M;
	for(int i=1;i<=en;i++){
		L=min(L,e[i]);
		R+=e[i];
	}
	int ans=0;
	while(L<=R){
		M=(L+R)/2;
		if(judge3(M)){
			ans=max(ans,M);
			L=M+1;
		}
		else{
			R=M-1;
		}
	}
	printf("%d\n",ans);
	return;
}
int main(){
	//case2 ai=1 case3 bi=ai+1
	bool case2=1,case3=1;
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,-1,sizeof(head));
	memset(al,-1,sizeof(al));
	scanf("%d%d",&n,&m);
	int u,v,w;
	for(int i=1;i<=n-1;i++){
		scanf("%d%d%d",&u,&v,&w);
		if(u>v)swap(u,v);
		addline(u,v,w);
		addline(v,u,w);
		e[++en]=w;
		if(u!=1)case2=0;
		if(v!=u+1)case3=0;
	}
	if(m==1){
		solve1();
		return 0;
	}
	if(case2){
		solve2();
		return 0;
	}
	if(case3){
		solve3();
		return 0;
	}
	return 0;
}
