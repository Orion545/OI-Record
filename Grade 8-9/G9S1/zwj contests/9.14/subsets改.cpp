#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int n,a[30],l[120000],r[120000],totl,totr,ans;
bool vis[10010];
vector<int>set[10010];
void dfs1(int k,int sum,int s){
	if(k>(n/2+1)) return;
//	cout<<"dfs 1 "<<k<<ends<<sum<<ends<<s<<endl;
	if(k==n/2+1){
//		cout<<"	renew"<<endl;
		bool flag=0;
		if(vis[s]==0) goto jump;
		for(int i=0;i<set[s].size();i++) if(abs(sum)==set[s][i]){flag=1;break;} 
		jump:if(!flag) l[++totl]=abs(sum),set[s].push_back(abs(sum));vis[s]=1;
		return;
	}
	dfs1(k+1,sum,s);
	dfs1(k+1,sum+a[k],s|(1<<(k-1)));
	dfs1(k+1,sum-a[k],s|(1<<(k-1)));
}
void dfs2(int k,int sum,int s){
	if(k<n/2) return;
//	cout<<"dfs 2 "<<k<<ends<<sum<<ends<<s<<endl;
	if(k==n/2){
//		cout<<"	renew"<<endl;
		bool flag=0;
		if(vis[s]==0) goto jump;
		for(int i=0;i<set[s].size();i++) if(abs(sum)==set[s][i]){flag=1;break;} 
		jump:if(!flag) r[++totr]=abs(sum),set[s].push_back(abs(sum)),vis[s]=1;
		return;
	}
	dfs2(k-1,sum,s);
	dfs2(k-1,sum+a[k],s|(1<<(n-k)));
	dfs2(k-1,sum-a[k],s|(1<<(n-k)));
}
int main(){
	int i,j,p1,p2,tmp1,tmp2;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs1(1,0,0);
	memset(vis,0,sizeof(vis));
	for(i=0;i<=(1<<(n/2+1));i++) set[i].clear();
	dfs2(n,0,0);
	sort(l+1,l+totl+1);sort(r+1,r+totr+1);
//	for(i=1;i<=totl;i++) cout<<l[i]<<ends;cout<<endl;
//	for(i=1;i<=totr;i++) cout<<r[i]<<ends;cout<<endl;
	p1=2;p2=2;
	while(l[p1]==0) p1++;
	while(r[p2]==0) p2++;
	ans+=((p1-1)*(p2-1)-1);
	while(p1<=totl){
		if(l[p1]>r[p2]){
			p2++;continue;
		}
		if(l[p1]<r[p2]){
			p1++;continue;
		}
		tmp1=p1;tmp2=p2;
		while(r[p2]==l[tmp1]) p2++;
		while(l[p1]==r[tmp2]) p1++;
		ans+=(p1-tmp1)*(p2-tmp2);
	} 
	printf("%d",ans);
}
