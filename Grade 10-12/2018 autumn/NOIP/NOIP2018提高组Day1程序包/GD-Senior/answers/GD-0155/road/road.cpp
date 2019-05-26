#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int d[100010],ans[100010];
int n,sum=0;
void dfs(int l,int r,int fix){
	if(l==r){
		sum=sum+(d[l]-fix);
		return ;
	}
	int minn=999999,p;
	for(int i=l;i<=r;i++){
		if(d[i]<minn){
			minn=d[i];
			p=i;
		}
	}
	sum=sum+(minn-fix);
	fix=minn;
	if(l<=p-1) dfs(l,p-1,fix);
	if(p+1<=r) dfs(p+1,r,fix);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    scanf("%d",&n);
	for(int i=1;i<=n;i++){
	scanf("%d",&d[i]);
	}
	dfs(1,n,0);
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
