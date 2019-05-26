#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[30];
bool dfs(int k,int times){
//	cout<<k<<ends<<times<<endl;
	int t,re=(!(times%2));
	if((k<n&&a[k]==0&&a[k+1]==0)||(k==n&&a[k]==0&&a[1]==0)) return !(times%2);
	if(a[k]){
		if(a[k]>1){
			t=a[k];a[k]=1;
			if(times%2) re|=dfs((k==1)?n:k-1,times+1);
			else re&=dfs((k==1)?n:k-1,times+1);
			a[k]=t;
		}
		t=a[k];a[k]=0;
		if(times%2) re|=dfs((k==1)?n:k-1,times+1);
		else re&=dfs((k==1)?n:k-1,times+1);
		a[k]=t;
	}
	int nk=((k==n)?1:k+1);
	if(a[nk]){
		if(a[nk]>1){
			t=a[nk];a[nk]=1;
			if(times%2) re|=dfs(nk,times+1);
			else re&=dfs(nk,times+1);
			a[nk]=t;
		}
		t=a[nk];a[nk]=0;
		if(times%2) re|=dfs(nk,times+1);
		else re&=dfs(nk,times+1);
		a[nk]=t;
	}
//	if(times%2&&re){
//		cout<<"	success!\n	";
//		for(int i=1;i<=n;i++) cout<<a[i]<<ends;cout<<endl;
//	}
	return re;
}
int main(){
	freopen("cycle.in","r",stdin);
	freopen("cycle.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==1){
		printf("NO");return 0;
	} 
	bool ans=dfs(n,1);
	if(ans) printf("YES");
	else printf("NO");
}
