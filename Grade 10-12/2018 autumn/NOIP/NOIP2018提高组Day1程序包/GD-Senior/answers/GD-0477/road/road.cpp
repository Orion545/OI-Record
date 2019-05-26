#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=100100;
int n,ans,a[N],v[N];

void dfs(int l,int r){
	if (l>r) return;
	int mn=1e9;
	for (int i=l;i<=r;i++)
		mn=min(mn,a[i]);
	ans+=mn;int lst=l;
	for (int i=l;i<=r;i++)
		a[i]-=mn;
	for (int i=l;i<=r;i++)
		if (a[i]==0 && !v[i]) 
			dfs(lst,i-1),lst=i+1,v[i]=1;
	dfs(lst,r);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",a+i);
	dfs(1,n);
	printf("%d\n",ans);
}
