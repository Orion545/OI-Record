/* 
ID: marcoli2 
LANG: C++ 
TASK: barn1
*/  
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,s,a[210],gap[210];
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	int i,ans;
	scanf("%d%d%d",&n,&s,&m);
	if(n>=m){
		printf("%d\n",m);return 0;
	}
	for(i=1;i<=m;i++) scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	ans=a[m]-a[1]+1;
	for(i=1;i<m;i++) gap[i]=a[i+1]-a[i];
	sort(gap+1,gap+m,cmp);
	for(i=1;i<n;i++) ans-=(gap[i]-1);
	printf("%d\n",ans);
}
