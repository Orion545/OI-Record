#include<bits/stdc++.h>
using namespace std;
const int sz=25527;
int a[333];
bool c[sz];
int n,T,m,ans;
void work(){
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	m=a[n],ans=0;
	c[0]=1;
	for(int i=1;i<=n;i++){
		if(!c[a[i]]){
			ans++;
			for(int j=0;j<=m-a[i];j++) c[j+a[i]]=c[j]|c[j+a[i]];
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--) work();
}
