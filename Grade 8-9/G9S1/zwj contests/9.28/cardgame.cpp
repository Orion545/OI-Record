#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set> 
using namespace std;
int max(int l,int r){return (l>r)?l:r;};
int n,a[50010],f[50010],g[50010],ans=0;
bool b[100100];
set<int>x,y;
int main(){
	freopen("cardgame.in","r",stdin);
	freopen("cardgame.out","w",stdout); 
	int i;
	set<int>::iterator it;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]=1;
	}
	for(i=1;i<=(n<<1);i++){
		if(!b[i]) x.insert(i),y.insert(-i);
	}
	for(i=1;i<=n;i++){
		it=x.upper_bound(a[i]);
		if(it!=x.end()) x.erase(*it),f[i]=f[i-1]+1;
		else f[i]=f[i-1];
	}
	for(i=n;i>=1;i--){
		it=y.upper_bound(-a[i]);
		if(it!=y.end()) y.erase(*it),g[i]=g[i+1]+1;
		else g[i]=g[i+1];
	}
	for(i=0;i<=n;i++) ans=max(ans,f[i]+g[i+1]);
	printf("%d",ans);
}
