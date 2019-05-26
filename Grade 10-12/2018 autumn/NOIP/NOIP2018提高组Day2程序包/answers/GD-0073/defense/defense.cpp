#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<stack>
#define mod 1000000007
#define inf 2147483647
using namespace std;
typedef long long ll;
int n,m,ans,u,v,t1,x,t2,y,p[100001];
bool mp[1001][1001],used[1001];
char s[5];
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		u--,v--;
		mp[u][v]=mp[v][u]=true;
	}
	for(int i=1;i<=m;i++){
		ans=inf;
		scanf("%d%d%d%d",&t1,&x,&t2,&y);
		t1--,t2--;
		if(mp[t1][t2]&&!x&&!y){
			puts("-1");
			continue;
		}
		for(int i=0;i<(1<<n);i++){
			bool ok=true;
			int tmp=0;
			for(int j=0;j<n;j++)used[j]=false;
			for(int j=0;j<n;j++){
				if((1<<j)&i){
					tmp+=p[j+1];
					used[j]=true;
				}
			}
			if(used[t1]^x||used[t2]^y)continue;
			for(int xx=0;xx<n;xx++){
				for(int yy=0;yy<n;yy++){
					if(mp[xx][yy]&&!used[xx]&&!used[yy]){
						ok=false;
						break;
					}
				}
				if(!ok)break;
			}
			if(!ok)continue;
			ans=min(ans,tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
}
