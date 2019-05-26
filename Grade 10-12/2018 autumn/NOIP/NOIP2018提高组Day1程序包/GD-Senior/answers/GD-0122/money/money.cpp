#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[10001],T,del[10001];
int gc,gcl,pc;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int f[50001],x;
int dfs(int v){
	if(f[v]+1) return f[v];
	int flag=0,i;
	for(i=1;i<=x;i++){
		if(del[i]) continue;
		if(v<a[i]/gcl) break;
		if(dfs(v-a[i]/gcl)==1){
			flag=1;break;
		}
	}
	return f[v]=flag;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	while(T--){
		memset(del,0,sizeof(del));
		int i,j,ans;
		cin>>n;
		if(n==1){
			cout<<1<<endl;
			continue;
		}
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		gcl=a[1];
		for(i=2;i<=n;i++) gcl=gcd(gcl,a[i]);
		for(i=1;i<=n;i++) a[i]/=gcl;	
		sort(a+1,a+n+1);
		gcl=a[1];
		for(i=2;i<=n;i++){
			if(a[i]%a[i-1]==0){
				del[i]=1;continue;
			}
			gc=gcd(a[i],gcl);
			if(gc<gcl){
				gcl=gc;
				continue;
			}else{
				for(j=1;j<=a[i];j++) f[j]=-1;
				for(j=1;j<i;j++) if(!del[i]) f[a[j]/gcl]=1;
				f[0]=1;
				x=i-1;
				if(dfs(a[i]/gcl)){
					del[i]=1;continue;
				}
			}
		}
		ans=n;
		for(i=1;i<=n;i++) if(del[i]) ans--;
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
