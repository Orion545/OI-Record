#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int T,n,m;
int a[105];
bool tag;
void dfs(int k,int cnt){
	if(a[k]==cnt) {
		tag=1;
		return ;
	}
	if(cnt>a[k]) return ;
	for(register int i=k-1;i>=1;i--){
		dfs(k,cnt+a[i]);
		if(tag) return ;
	}
	return ;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		m=n;
		for(register int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(register int i=2;i<=n;i++){
			tag=0;
			dfs(i,0);
			if(tag) m--;
		}
		cout<<m<<endl;
	}
	return 0;
}
