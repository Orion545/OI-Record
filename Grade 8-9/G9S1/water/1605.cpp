#include<iostream>
#include<cstdio>
using namespace std;
bool vis[20];
int main(){
	int n,k,i,j,t;scanf("%d%d",&n,&k);
	j=0;
	for(i=1;i<=n;i++){
		for(t=1;t<=k;){
			j++;
			if(j==n+1) j=1;
			if(vis[j]) continue;
			t++;
		}
		printf("%d ",j);vis[j]=1;
	}
}
