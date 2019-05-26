#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<stack>
#define M 30005
using namespace std;

int n,m=0;
int num[105]={0},vis[M]={0};

void sub(){
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
	scanf("%d",&n); vis[0]=1; int ans=0;
	for(int i=1;i<=n;i++)scanf("%d",num+i);
	sort(num+1,num+n+1); m=num[n];
	for(int i=1;i<=n;i++){
		int x=num[i];
		if(vis[x]) continue;
		for(int j=x;j<=m;j++){
			vis[j]|=vis[j-x];
		}
		ans++;
	}
	cout<<ans<<endl;
}
	

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int cas; scanf("%d",&cas);
	while(cas--) sub();
}
