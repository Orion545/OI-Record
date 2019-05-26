#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N=105;

int t,n,a[N],k;
bool flag[N];

bool dfs(int t,int num){
	if (t==k){
		if (!num) return 1;
		else return 0;
	}
	if (flag[t]) return dfs(t+1,num);
	for (int i=0;;i++){
		if (num-a[t]*i<0) return 0;
		if (dfs(t+1,num-a[t]*i)) return 1;
	}
}

bool cmp(int i,int j){
	return i<j;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	while (t--){
		memset(flag,0,sizeof(flag));
		cin>>n;
		int cnt=0;
		for (int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n,cmp);
		int ans=0;
		for (k=1;k<=n;k++){
			if (!dfs(1,a[k])){
				cnt++;
			}
			else flag[k]=1;
		}
		cout<<cnt<<"\n";
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
